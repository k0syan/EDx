#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <iterator>
#include <vector>
#include <algorithm>

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  std::vector<ll> matr(n);
  
  for (int i = 0; i < n; ++i) {
    cin >> matr[i];
  }
  
  if (k == 1) {
    cout << "YES\n";
    return 0;
  }
  
  // already checked ones
  std::vector<bool> c(n, false);
  
  for (int i = 0; i < n - k; ++i) {
    if (c[i]) {
      continue;
    }
    
    std::vector<ll> s;
    
    for (int j = i; j < n; j += k) {
      c[j] = true;
      s.push_back(matr[j]);
    }
    
    std::sort(begin(s), end(s));
    int l = 0;
    
    for (int j = i; j < n; j += k) {
      matr[j] = s[l];
      ++l;
    }
  }
  
  bool s = true;
  
  for (int i = 0; i < n - 1; ++i) {
    if (matr[i] > matr[i + 1]) {
      s = false;
      break;
    }
  }
  
  if (s) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  
  return 0;
}
