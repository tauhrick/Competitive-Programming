#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = INT_MAX - 2;

struct Monster {
  int max_health, start_health, regen;
};

struct Update {
  int time, enemy, health;

  bool operator<(const Update &other) const {
    return time < other.time;
  }
};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, m;
  int64_t bounty, increase, damage;
  vector<Monster> monsters;
  vector<Update> updates;
  vector<int> last_kill_time;
  vector<bool> cant_kill;
  multiset<int> time_max;
  int64_t best = 0;

  void Read() {
    cin >> n >> m;
    cin >> bounty >> increase >> damage;
    monsters.resize(n);
    for (auto &monster : monsters) {
      cin >> monster.max_health >> monster.start_health >> monster.regen;
    }
    updates.resize(m);
    for (auto &update : updates) {
      cin >> update.time >> update.enemy >> update.health;
      --update.enemy;
    }
  }
 
  void Solve() {
    for (auto &monster : monsters) {
      if (monster.regen != 0 && monster.max_health <= damage && increase != 0) {
        cout << -1 << '\n';
        return;
      }
    }
    last_kill_time.resize(n);
    cant_kill.resize(n);
    for (int i = 0; i < n; ++i) {
      last_kill_time[i] = GetTimeMax(monsters[i], 0);
      if (monsters[i].start_health <= damage) {
        time_max.insert(last_kill_time[i]);
      } else {
        cant_kill[i] = true;
      }
    }
    sort(updates.begin(), updates.end());
    for (int i = 0, j = 0; i < m; i = j) {
      AskQueries(updates[i].time);
      while (j < m && updates[j].time == updates[i].time) {
        PerformUpdate(updates[j]);
        ++j;
      }
    }
    AskQueries(INT_MAX);
    for (auto &monster : monsters) {
      if (monster.regen == 0 && monster.start_health <= damage && increase != 0) {
        cout << -1 << '\n';
        return;
      }
    }
    cout << best << '\n';
  }

  int GetTimeMax(Monster monster, int offset) {
    if (monster.start_health > damage) return offset;
    if (monster.regen == 0) {
      return kInf;
    } else {
      return offset + (damage - monster.start_health) / monster.regen;
    }
  }

  void PerformUpdate(Update update) {
    if (!cant_kill[update.enemy]) {
      auto it = time_max.find(last_kill_time[update.enemy]);
      if (it != time_max.end()) {
        time_max.erase(it);
      }
    } else {
      cant_kill[update.enemy] = false;
    }
    monsters[update.enemy].start_health = update.health;
    last_kill_time[update.enemy] = GetTimeMax(monsters[update.enemy], update.time);
    if (update.health <= damage) {
      time_max.insert(last_kill_time[update.enemy]);
    } else {
      cant_kill[update.enemy] = true;
    }
  }

  void AskQueries(int next_update_time) {
    while (!time_max.empty()) {
      int del_time = *time_max.begin();
      if (del_time >= next_update_time) break;
      best = max(best, TryDeletingMonsters(del_time));
      time_max.erase(del_time);
    }
    best = max(best, TryDeletingMonsters(next_update_time - 1));
  }

  int64_t TryDeletingMonsters(int time) {
    return int(time_max.size()) * (bounty + time * increase);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}