#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
  double x;
  double y;
};

double distance(const Point p) {
  return (double)sqrt(p.x * p.x + p.y * p.y);
}

void selection_sort(vector<Point> &T) {
  for (size_t i = 0; i < T.size() - 1; i++) {
    size_t min_index = i;
    for (size_t j = i + 1; j < T.size(); j++) {
      if (distance(T[j]) < distance(T[min_index])) min_index = j;
    }
    if (min_index != i) {
      swap(T[i], T[min_index]);
    }
  }
}

void bubble_sort(vector<Point> &T) {
  size_t s = T.size();
  for (size_t i = 0; i < s - 1; i++) {
    for (size_t j = 0; j < s - i - 1; j++) {
      if (distance(T[j+1]) < distance(T[j])) swap(T[j], T[j+1]);
    }
  }
}

void insertion_sort(vector<Point> &T) {
  for (size_t i = 1; i < T.size(); i++) {

    Point key = T[i];
    double key_distance = distance(key);
    int j = i - 1;
    while (j >= 0 && key_distance < distance(T[j])) {
      T[j+1] = T[j];
      j--;
    }
    T[j+1] = key;
  }
}

void display(vector<Point> T) {
  for (Point p: T) cout << "(" << p.x << ", " << p.y << ")";
  cout << endl;
}

void reset_vector(vector<Point> &T) {
  T = {{3, 4}, {1, 2}, {0, 0}, {2, 2}};
}

int main() {
  vector<Point> T = {{3, 4}, {1, 2}, {0, 0}, {2, 2}};
  cout << "Selection Sort\nUnsorted: "; display(T);
  selection_sort(T);
  cout << "Sorted:   "; display(T); cout << "\n";
  reset_vector(T);
  cout << "Bubble Sort\nUnsorted: "; display(T);
  bubble_sort(T);
  cout << "Sorted:   "; display(T); cout << "\n";
  reset_vector(T);
  cout << "Insertion Sort\nUnsorted: "; display(T);
  insertion_sort(T);
  cout << "Sorted:   "; display(T);
  return 0;
}

// Boualleg Kaissar :)