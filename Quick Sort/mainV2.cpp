#include <iostream>
#include <vector>

using namespace std;

// Lomuto Partition Model

int partition(int T[], int start, int end) {
  int pivot = T[end]; // Hard-coded

  int i = start-1;

  for (int j = start; j < end; j++) {
    if (T[j] < pivot) swap(T[++i], T[j]);
  } 

  swap(T[i+1], T[end]);

  return (i+1);
}

void quickSort(int T[], const int start, const int end) {
  if (start < end) {
    int pivot = partition(T, start, end);
    quickSort(T, start, pivot-1);
    quickSort(T, pivot+1, end);
  }
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