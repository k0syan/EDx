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

typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;
  std::vector<std::pair<std::stack<int>, ull>> actions;
  std::stack<int> s;
  s.push(0);
  std::pair<std::stack<int>, ull> p(s, 0);
  actions.push_back(p);
  
  ull total = 0;
  for (int i = 0; i < n; ++i) {
    int index;
    ull action;
    cin >> index >> action;
    std::stack<int> tmp = actions[index].first;
    ull weight = actions[index].second;
    if (action == 0) {
      weight -= tmp.top();
      tmp.pop();
    } else {
      tmp.push(action);
      weight += action;
    }
    total += weight;
    std::pair<std::stack<int>, ull> p(tmp, weight);
    actions.push_back(p);
  }
  
  cout << total << '\n';
  
  return 0;
}
