#include <iostream>
#include <vector>

using namespace std;

void quickSort(int T[], int start, int end) {
  if (start >= end) return;
  int i = start-1;
  int j = start;
  while (j < end) {
    if (T[j] < T[end]) {
      swap(T[++i], T[j]);
    }
    j++;
  }
  swap(T[i+1], T[end]);
  quickSort(T, start, i);
  quickSort(T, i+2, end);
}

void display(int T[], int s) {
  for (int i = 0; i < s; i++) {
    cout << T[i] << " ";
  }
  cout << "\n";
}

int main() {
  int T[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
  size_t T_size = sizeof(T)/sizeof(int);
  cout << "Unsorted: "; display(T, T_size);
  quickSort(T, 0, T_size - 1);
  cout << "Sorted:   "; display(T, T_size);
  return 0;
}

// Boualleg Kaissar :)