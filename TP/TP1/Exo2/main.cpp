#include <iostream>

using namespace std;

size_t frequency(int T[], const size_t size, const int target) {
  size_t occur = 0;
  for (size_t i = 0; i < size; i++) {
    if (T[i] == target) occur++;
  }
  return occur;
}

void sort_by_frequancy(int T[], const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    size_t min_i = i;
    for (size_t j = i+1; j < size; j++) {
      size_t min_freq = frequency(T, size, T[min_i]);
      size_t j_freq = frequency(T, size, T[j]);
      if (
        (j_freq < min_freq) ||
        ((min_freq == j_freq) && T[j] < T[min_i])
      )
      min_i = j;
    }
    swap(T[i], T[min_i]);
  }
}

void bubble_sort_by_frequancy(int T[], const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = 0; j < size - i - 1; j++) {
      size_t next_freq = frequency(T, size, T[j+1]);
      size_t j_freq = frequency(T, size, T[j]);
      if (
        (j_freq > next_freq) ||
        (j_freq == next_freq && T[j+1] < T[j])
      ) {
        swap(T[j], T[j+1]);
      }
    }
  }
}

void insertion_sort_by_frequancy(int T[], const size_t size) {
  for (size_t i = 1; i < size; i++) {
    int key = T[i];
    size_t key_freq = frequency(T, size, key);
    int j = i-1;
    size_t j_freq;
    while(j >= 0 && (key_freq < (j_freq = frequency(T, size, T[j])) || (key_freq == j_freq && key < T[j]))) {
      T[j+1] = T[j];
      j--;
    }
    T[j+1] = key;
  }
}

void display(int T[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << T[i] << " ";
  }
  cout << endl;
}

int main() {
  int T[] = {4, 5, 6, 5, 4, 3};
  size_t size = sizeof(T)/sizeof(int);
  display(T, size);
  insertion_sort_by_frequancy(T, size);
  display(T, size);
  return 0;
}

// Bouallg Kaissar :)