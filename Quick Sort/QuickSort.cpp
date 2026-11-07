#include <iostream>
#include <vector>

using namespace std;

size_t fill(vector<int> &arr) {
  int s = 0;
  do {
    cout << "Enter Array Size: ";
    cin >> s;
  } while (s <= 0);

  cin.ignore();

  for (int i = 0; i < s; i++) {
    int value = 0;
    cout << "Enter the " << (i+1) << "-th Element: ";
    cin >> value;
    arr.push_back(value);
  }

  cout << endl;

  return (size_t)s;
}

void display(vector<int> arr) {
  for (int v: arr) cout << v << " ";
  cout << "\n";
}

// Lomuto Partition:
int partition(vector<int> &arr, const int start, const int end, const int pivot) {
  // Recrusive Case:
  if (pivot != end) {
    swap(arr[end], arr[pivot]);
  }

  int j = start;

  for (int i = start; i < end; i++) {
    if (arr[i] < arr[end]) {
      swap(arr[j], arr[i]);
      j++;
    }
  }

  swap(arr[j], arr[end]);

  return j;
}

void quickSort(vector<int> &arr, const int start, const int end) {
  // Base Case:
  if (start >= end) {
    return;
  }

  // Recrusive Case:
  int pivot = partition(arr, start, end, (start+end)/2);

  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end);
}

int main() {
  vector<int> arr = {6, 2, 7, 9, 3, 1, 0, 4, 5, 8, 0};
  //size_t arr_s = fill(arr);
  cout << "Unsorted: "; display(arr);
  quickSort(arr, 0, arr.size()-1);
  cout << "Sorted:   "; display(arr);
  return 0;
}

// Boualleg Kaissar