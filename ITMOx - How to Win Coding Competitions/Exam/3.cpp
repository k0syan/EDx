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
#include <iterator>
#include <algorithm>

typedef unsigned long long ull;

struct maximum {
  int index;
  ull number;

  Birthday(ull n, int i) {
    this->number = n;
    this->index = i;
  }

  friend bool operator<(const maximum& a, const maximum& b) {
      return a.number < b.number;
  }
};  

int main() {
    int n;
    ull m;
    cin >> n >> m;
    std::vector<ull> numbers;
    
    for (int i = 0; i < n; ++i) {
      ull tmp;
      cin >> tmp;
      numbers.push_back(tmp);
    }
    
    ull max = 0;
    ull max_index = 0;
    for (int i = 0; i < n; ++i) {
      if (max < numbers[i]) {
        max = numbers[i];
        max_index = i;
      }
    }
    
    ull l = 0;
    for (int i = max_index + 1; i < n; ++i) {
      if (numbers[i] > l) {
        l = numbers[i]; 
      }
    }
    
    if (l + max > m) {
      cout << "No";
    } else {
      cout << "Yes";
    }
    cout << '\n';
    
    return 0;
}
