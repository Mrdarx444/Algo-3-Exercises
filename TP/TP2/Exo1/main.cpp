#include <iostream>

using namespace std;

struct tree {
  int data;
  tree *left;
  tree *right;
};

typedef tree *Tree;

Tree createElement(const int _data) {
  Tree E = new tree;
  E->data = _data;
  E->left = E->right = nullptr;
  return E;
}

// Ignore Repetetive values
Tree insertBST(Tree root, const int value) {
  if (root == nullptr) {
    return createElement(value);
  }

  if (value < root->data) {
    root->left = insertBST(root->left, value);
  } else if (value > root->data) {
    root->right = insertBST(root->right, value);
  }

  return root;
}

Tree createBST(int T[], int s) {
  Tree root = nullptr;

  for (int i = 0; i < s; i++)
    root = insertBST(root, T[i]);

  return root;
}

void GRD(Tree root) {
  if (root == nullptr) return;
  GRD(root->left);
  cout << root->data << " ";
  GRD(root->right);
}

int main() {
  int T[] = {0,0,0,0};

  int s = 7;

  Tree BST = createBST(T, s);

  GRD(BST);

  return 0;
}
