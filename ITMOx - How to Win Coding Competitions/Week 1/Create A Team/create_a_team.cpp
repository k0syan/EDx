#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <cmath>
#include <iomanip>

int main() {
  int s[3][3];
  double maximum = 0;
  
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    int a = s[i][0];
    for (int j = 0; j < 3; ++j) {
      if (i != j) {
        int b = s[j][1];
        for (int k = 0; k < 3; ++k) {
          if (k != i && k != j) {
            int c = s[k][2];
            double total = sqrt(a * a + b * b + c * c);
            if (total > maximum) {
              maximum = total;
            }
          }
        }
      }
    }
  }
  
  cout << std::setprecision(17) << maximum << '\n';
  return 0;
}
