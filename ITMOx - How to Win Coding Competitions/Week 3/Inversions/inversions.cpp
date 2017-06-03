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
unsigned long long inversions_count = 0;

std::vector<int> merge(std::vector<int> first_array, std::vector<int> second_array) {
  std::vector<int> merged;
  int j = 0;
  int i = 0;
  
  for (int k = 0; k < (int) (first_array.size() + second_array.size()); k++) {
    if (i < (int) first_array.size()) {
      if (j < (int) second_array.size()) {
        if (first_array[i] <= second_array[j]) {
          merged.push_back(first_array[i]);
          i++;
        } else {
          inversions_count += first_array.size() - i;
          merged.push_back(second_array[j]);
          j++;
        }
      } else {
        merged.push_back(first_array[i]);
        i++;
      }
    } else {
      merged.push_back(second_array[j]);
      j++;
    }
  }
  return merged;
}

std::vector<int> merge_sort(std::vector<int> numbers, int start, int end) {
  if (end == start) {
    return std::vector<int>{numbers[start]};
  }

  if (end - start < 2) {
    std::vector<int> first_array = {numbers[start]};
    std::vector<int> second_array = {numbers[end]};
    return merge(first_array, second_array);
  }

  return merge(merge_sort(numbers, start, (end + start) / 2), merge_sort(numbers, (end + start) / 2 + 1, end));
}


int main() {
  int n;
  cin >> n;
  std::vector<int> numbers;
  
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    numbers.push_back(tmp);
  }

  std::vector<int> merged = merge_sort(numbers, 0, (int) numbers.size() - 1);
  
  cout << inversions_count << '\n';
  return 0;
}
