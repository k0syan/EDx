#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <vector>
#include <stack>

int main() {
  int n;
  cin >> n;
  std::vector<int> cups;
  
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    cups.push_back(tmp);
  }
  
  std::stack<int> first;
  int min_depth = 0;
  for (int i = 0; i < n; ++i) {
    if(cups[i]) {
      
    }
  }
  
  return 0;
}
