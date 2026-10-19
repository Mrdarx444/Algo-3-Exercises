#include <iostream>

using namespace std;

void sort_even_first(int T[], const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    int min_i = i;
    for (size_t j = i+1; j < size; j++) {
      if (
        (T[j] % 2 == 0 && T[min_i] % 2 != 0) ||
        ((T[j] % 2 == T[min_i] % 2) && T[j] < T[min_i])
      )
      min_i = j;
    }
    swap(T[i], T[min_i]);
  }
}

void display(int T[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << T[i] << " ";
  }
  cout << endl;
}

int main() {
  int T[] = {5, 2, 8, 1, 4, 7, 6};
  size_t size = sizeof(T)/sizeof(int);
  display(T, size);
  sort_even_first(T, size);
  display(T, size);
  return 0;
}

// Boualleg Kaissar :)