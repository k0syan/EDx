#ifdef JUDGE
  #include <fstream>
  std::ifstream cin("input.txt");
  std::ofstream cout("output.txt");
#else
  #include <iostream>
  using std::cin;
  using std::cout;
#endif

#include <iomanip>

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  double p = a / 2.0 + b / 2.0 + c / 2.0;
  p = p / 3.0;
  
  cout << std::setprecision(8) << p << '\n';
  
  return 0;
}
