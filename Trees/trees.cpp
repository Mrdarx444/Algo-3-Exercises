#include <iostream>

using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};

typedef node *Node;

Node createNode(const int _data) {
  Node E = new node;
  E->left = E->right = nullptr;
  E->data = _data;
  return E;
}

void fill_tree(const Node parent = nullptr, const int left_data = 0, const int right_data = 0) {
  if (parent == nullptr) {
    cout << "function fill_tree(): No parent found.\n";
    return;
  }
  
  parent->left = createNode(left_data);
  parent->right = createNode(right_data);

  bool left_forward = false, right_forward = false;
  cout << "Wan't to contenue left?: ";
  cin >> left_forward;
  if (left_forward) {
    int next_left_data = 0, next_right_data = 0;
    cout << "Enter Left: ";
    cin >> next_left_data;
    cout << "Enter right: ";
    cin >> next_right_data;
    fill_tree(parent->left, next_left_data, next_right_data);
  }
  cout << "Wan't to contenue right?: ";
  cin >> right_forward;
  if (right_forward) {
    int next_left_data = 0, next_right_data = 0;
    cout << "Enter Left: ";
    cin >> next_left_data;
    cout << "Enter right: ";
    cin >> next_right_data;
    fill_tree(parent->right, next_left_data, next_right_data);
  }
}

void display_tree(Node parent = nullptr) {
  if (parent == nullptr) return;
  cout << parent->data << " ";
  display_tree(parent->left);
  display_tree(parent->right);
}

int main() {
  Node root = createNode(100);
  fill_tree(root, 99, 98);
  display_tree(root);
  return 0;
}
