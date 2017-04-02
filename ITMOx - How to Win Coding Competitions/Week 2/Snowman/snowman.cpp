#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <stack>
#include <vector>

typedef long long ll;

int main() {
  int n;
  cin >> n;
  std::vector<std::pair<std::stack<int>, int>> actions;
  std::stack<int> s;
  s.push(0);
  std::pair<std::stack<int>, int> p(s, 0);
  actions.push_back(p);
  
  for (int i = 0; i < n; ++i) {
    int index, action;
    cin >> index >> action;
    std::stack<int> tmp = actions[index].first;
    int weight = actions[index].second;
    if (action == 0) {
      weight -= tmp.top();
      tmp.pop();
    } else {
      tmp.push(action);
      weight += action;
    }
    std::pair<std::stack<int>, int> p(tmp, weight);
    actions.push_back(p);
  }
  
  int total = 0;
  for (int i = 0; i <= n; ++i) {
    total += actions[i].second;
  }
  cout << total << '\n';
  
  return 0;
}
