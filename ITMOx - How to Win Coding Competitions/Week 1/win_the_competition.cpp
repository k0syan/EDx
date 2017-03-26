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
#include <algorithm>

int main() {
  int n, i;
  cin >> n;
  
  std::vector<int> times(n);
  for (i = 0; i < n; ++i) {
    cin >> times[i];
  }
  
  std::sort(begin(times), end(times));
  
  int time = 18000;
  int max = 0;
  
  i = 0;
  while (time - times[i] >= 0 && i < n) {
    time -= times[i];
    ++max;
    ++i;
  }
  
  cout << max << "\n";
  
  return 0;
}
