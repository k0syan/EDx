#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

typedef unsigned long long ull;  
  
int main() {
    ull n;
    cin >> n;
    
    if (n == 1) {
      cout << 0;
    } else if (n == 2) {
      cout << 1;
    } else {
      if (n % 2 == 1) {
        cout << (n - (n / 2) - 1) * (n / 2 + 1);
      } else {
        cout << (n - (n / 2)) * (n / 2);
      }
    }
    cout << '\n';
    
    return 0;
}
