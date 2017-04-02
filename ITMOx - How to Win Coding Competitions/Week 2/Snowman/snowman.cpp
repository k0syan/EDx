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
  std::vector<std::stack<int>> stacks;
  std::stack<int> s;
  s.push(0);
  stacks.push_back(s);
  
  for (int i = 0; i < n; ++i) {
    int index, action;
    cin >> index >> action;
    std::stack<int> tmp = stacks[index];
    if (action == 0) {
      tmp.pop();
    } else {
      tmp.push(action);
    }
    
    stacks.push_back(tmp);
  }
  
  return 0;
}
