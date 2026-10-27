#include <iostream>
#include <cmath>

using namespace std;

size_t count_digits(unsigned int n) {
  int count = 0;
  while (n) {
    count++;
    n /= 10;
  }
  return count;
}

void sort_by_digits(unsigned int *n) {
  size_t digits_count = count_digits(*n);
  unsigned short digits[digits_count];
  for (size_t i = 0; i < digits_count; i++) {
    digits[i] = (*n) % 10;
    *n /= 10;
  }
  for (size_t i = 0; i < digits_count - 1; i++) {
    size_t min_i = i;
    for (size_t j = i+1; j < digits_count; j++) {
      if (digits[j] < digits[min_i]) {
        min_i = j;
      }
    }
    swap(digits[i], digits[min_i]);
  }
  *n = 0;
  for (size_t i = 0; i < digits_count; i++) {
    *n += digits[digits_count-i-1] * (int)pow(10, i);
  }
}

int main() {
  unsigned int n = 539421;
  cout << n << endl;
  sort_by_digits(&n);
  cout << n << endl;
  return 0;
}
