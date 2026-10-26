#include <iostream>
#include <cmath>

using namespace std;

struct Point {
  double x;
  double y;
};

double distance(const Point p, const Point origin = {0, 0}) {
  double d = sqrt(pow((p.x - origin.x), 2) + pow((p.y - origin.y), 2));
  return d;
}

void sort_by_distance(Point T[], const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    size_t min_i = i;
    for (size_t j = i+1; j < size; j++) {
      if (distance(T[j]) < distance(T[min_i]))
        min_i = j;
    }
    swap(T[i], T[min_i]);
  }
}

void bubble_sort_by_distance(Point T[], const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = 0; j < size - i - 1; j++) {
      if (distance(T[j]) > distance(T[j+1])) swap(T[j], T[j+1]);
    }
  }
}

void insertion_sort_by_distance(Point T[], const size_t size) {
  for (size_t i = 1; i < size; i++) {
    Point key = T[i];
    int j = i-1;
    while(j >= 0 && distance(key) < distance(T[j])) {
      T[j+1].x = T[j].x;
      T[j+1].y = T[j].y;
      j--;
    }
    T[j+1] = key;
  }
}

void display(Point T[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << "(" << T[i].x << "," << T[i].y << ") ";
  }
  cout << endl;
}

int main() {
  Point T[] = {{3,4}, {1,2}, {0,0}, {2,2}};
  size_t size = sizeof(T)/sizeof(Point);
  display(T, size);
  insertion_sort_by_distance(T, size);
  display(T, size);
  return 0;
}

// Boualleg Kaissar :)