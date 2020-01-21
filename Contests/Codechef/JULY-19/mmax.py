def test_case():
  n = int(input())
  k = int(input())
  a = k % n
  if (a == 0):
    print(0)
    return
  b = n - a
  mini, maxi = min(a, b), max(a, b)
  if (mini == maxi):
    print(2 * mini - 1)
  else:
    print(2 * mini)

t = int(input())
for _ in range(t):
  test_case()
