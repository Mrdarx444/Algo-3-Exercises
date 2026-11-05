#include <iostream>
#include <string>

using namespace std;

struct node {
  char c;
  node *next;
};

typedef node *Node;

struct Stack {
  Node head;
  size_t size;
  size_t capacity;
};

Node createNode(const char _c) {
  Node E = new node;
  E->next = nullptr;
  E->c = _c;
  return E;
}

void display(Stack s) {
  Node current = s.head;
  cout << "TOP\n";
  while (current) {
    cout << '\'' << current->c << '\'' << "\n";
    current = current->next;
  }
  cout << "\n";
}

bool stack_empty(Stack s) {
  return (s.size <= 0 && s.head == nullptr);
}

bool is_full(Stack s) {
  return (s.size >= s.capacity);
}

bool check_closed(const char c1, const char c2) {
  bool is_closed = false;
  if (
    (c1 == '(' && c2 == ')') ||
    (c1 == '[' && c2 == ']') ||
    (c1 == '{' && c2 == '}') ||
    (c1 == '<' && c2 == '>')
  ) is_closed = true;
  return is_closed;
}

char stack_pop(Stack *s) {
  if (stack_empty(*s)) {
    return '\0';
  }

  Node temp = s->head;
  char c = temp->c;
  s->head = s->head->next;
  delete temp;
  (s->size)--;
  return c;
}

bool check_and_push(Stack *s, const char _c) {
  if (is_full(*s)) return false;

  if (!stack_empty(*s) && check_closed(s->head->c, _c)) {
    stack_pop(s);
    return false;
  }

  Node E = createNode(_c);

  E->next = s->head;
  s->head = E;
  (s->size)++;
  return true;
}

bool check_syntax(const string syntax) {
  Stack s = {nullptr, 0, 1024};

  for (size_t i = 0; i < syntax.length(); i++) {
    check_and_push(&s, syntax[i]);
  }
  return stack_empty(s);
}

int main() {
  string syntax = "";

  cout << "Enter syntax -<>-()-{}-[]-: ";
  getline(cin >> ws, syntax);

  cout << "The sentence " << "\""+syntax+"\"" << " is "; 

  if (check_syntax(syntax)) cout << "Valid\n";
  else cout << "Not Valid\n";

  return 0;
}


// Boualleg Kaissar :)