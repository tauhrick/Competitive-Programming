package main

import (
  "fmt"
  "bufio"
  "os"
)

var in *bufio.Reader
var out *bufio.Writer

type Pair struct {
  row, col int
}

var dr = [4]int{0, 0, 1, -1}
var dc = [4]int{-1, 1, 0, 0}
var tile = [4]string{"><", "<>", "^v", "v^"}

var n, m int
var grid [][]byte

func Read() {
  fmt.Fscanf(in, "%d %d\n", &n, &m)
  grid = make([][]byte, n)
  for i := 0; i < n; i++ {
    grid[i] = make([]byte, m)
    for j := 0; j < m; j++ {
      fmt.Fscanf(in, "%c", &grid[i][j])
    }
    fmt.Fscanln(in)
  }
}

var deg_loc []Pair
var deg [][]int
var empty_cells = 0

func Solve() {
  Precompute()
  for i := 0; i < len(deg_loc); i++ {
    r, c := deg_loc[i].row, deg_loc[i].col
    if deg[r][c] != 1 {
      continue
    }
    for d := 0; d < 4; d++ {
      rr := r + dr[d]
      cc := c + dc[d]
      if Empty(rr, cc) {
        deg[r][c], deg[rr][cc] = 0, 0
        grid[r][c] = tile[d][0]
        grid[rr][cc] = tile[d][1]
        empty_cells -= 2
        for dd := 0; dd < 4; dd++ {
          rrr := rr + dr[dd]
          ccc := cc + dc[dd]
          if Empty(rrr, ccc) {
            deg[rrr][ccc]--
            if deg[rrr][ccc] == 1 {
              deg_loc = append(deg_loc, Pair{rrr, ccc})
            }
          }
        }
      }
    }
  }
  if empty_cells > 0 {
    fmt.Fprintln(out, "Not unique")
    return
  }
  for r := 0; r < n; r++ {
    for c := 0; c < m; c++ {
      fmt.Fprintf(out, "%s", string(grid[r][c]))
    }
    fmt.Fprintln(out)
  }
}

func Precompute() {
  deg = make([][]int, n)
  deg_loc = make([]Pair, 0, n * m)
  for r := 0; r < n; r++ {
    deg[r] = make([]int, m)
    for c := 0; c < m; c++ {
      if grid[r][c] == '.' {
        empty_cells++
        for d := 0; d < 4; d++ {
          rr := r + dr[d]
          cc := c + dc[d]
          if Empty(rr, cc) {
            deg[r][c]++
          }
        }
        if deg[r][c] == 1 {
          deg_loc = append(deg_loc, Pair{r, c})
        }
      }
    }
  }
}

func Empty(rr, cc int) bool {
  return 0 <= rr && rr < n && 0 <= cc && cc < m && grid[rr][cc] == '.'
}

func main() {
  in = bufio.NewReader(os.Stdin)
  out = bufio.NewWriter(os.Stdout)
  Read()
  Solve()
  out.Flush()
}
