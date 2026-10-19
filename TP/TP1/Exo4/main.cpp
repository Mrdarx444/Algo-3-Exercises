#include <iostream>
#include <string>

using namespace std;

void display(string T[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << T[i] + " ";
  }
  cout << endl;
}

void sort_by_length(string T[], const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    size_t min_i = i;
    for (size_t j = i+1; j < size; j++) {
      if (T[j].length() < T[min_i].length())
        min_i = j;
    }
    swap(T[i], T[min_i]);
  }
}

int main() {
  string T[] = {"Sorting", "makes", "programs", "efficient", "and", "elegant"};
  size_t size = sizeof(T)/sizeof(string);
  display(T, size);
  sort_by_length(T, size);
  display(T, size);
  return 0;
}
