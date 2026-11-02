#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

size_t count_digits(const int x) {
  if (!x) return 0;
  return 1 + count_digits(x/10);
}

int reverse_digits(int x) {
  int sorted_x = 0;
  int power = count_digits(x) - 1;
  while (x > 0) {
    sorted_x += (x%10) * (int)pow(10, power);
    x /= 10;
    power--;
  }
  return sorted_x;
}

void sort_digits(int &x) {
  vector<short> digits;
  while (x > 0) {
    digits.push_back(x%10);
    x /= 10;
  }

  for (short i: digits) cout << i;
  cout << endl;

  size_t s = digits.size();
  for (size_t i = 0; i < s - 1; i++) {
    size_t min_i = i;
    for (size_t j = i + 1; j < s; j++) {
      if (digits[j] < digits[min_i]) min_i = j;
    }
    swap(digits[i], digits[min_i]);
  }

  for (size_t i = 0; i < s; i++) {
    x += digits[i] * pow(10, s - i - 1);
  }

}

int main() {
  int x = 539421;
  sort_digits(x);
  cout << x << '\n';
  return 0;
}

// Boualleg Kaissar :)