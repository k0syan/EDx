#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

int main() {
  int n;
  cin >> n;
  
  bool practice = false, theory = false;
  
  int *p = new int[n];
  int *t = new int[n];
  
  int max = 0;
  
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  
  for (int i = 0; i < n; ++ i) {
    if (p[i] > t[i]) {
      max += p[i];
      practice = true;
    } else {
      max += t[i];
      theory = true;
    }
  }
  
  if (practice && theory) {
    cout << max << '\n';
  } else {
    cout << "Vay qu ara" << '\n';
  }
  
  delete [] p;
  delete [] t;
  
  return 0;
}
