#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct node {
  int data;
  struct node *next, *prev;
} *root, *current, *previous, *head, *traverse;

struct node *create() {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  cout << "\n Enter the data : ";
  cin >> newnode->data;
  newnode->next = newnode->prev = NULL;
  return newnode;
}

int size() {
  int size = 0;
  traverse = root;
  while (traverse != NULL) {
    traverse = traverse->next;
    size++;
  }
  return size;
}

void insert() {
  int c = 0;
  head = root;
  system("cls");
  cout << "\n Insert Node \n 1.At the Begining \n 2.In Between \n 3.At the End \n Enter the Choice : ";
  cin >> c;
  current = create();
  switch (c) {
    case 1: current->next = head;
            head->prev = current;
            root = current;
            break;
    case 2: cout << "\n Enter the Index : ";
            cin >> c;
            if (c > size() || c == 1 || c < 0)
              break;
            for (int i = 1; i < c - 1; i++)
              head = head->next;
            current->next = head->next;
            current->next->prev = current;
            head->next = current;
            current->prev = head;
            break;
    case 3: while (head->next != NULL)
              head = head->next;
            head->next = current;
            current->prev = head;
            break;
    default: return;
  }
}

void remove() {
  int c = 0;
  head = current = root;
  system("cls");
  cout << "\n Remove Node \n 1.From the Begining \n 2.In Between \n 3.From the End \n Enter the Choice : ";
  cin >> c;
  switch (c) {
    case 1: if (head->next == NULL)
              root = NULL;
            else {
              root = head->next;
              root->prev = NULL;
            }
            free(head);
            break;
    case 2: if (head->next == NULL)
              root = NULL;
            else {
              cout << "\n Enter the Index : ";
              cin >> c;
              if (c > size() || c == 1 || c < 0)
                break;
              for (int i = 1; i < c - 1; i++)
                head = head->next;
              current = head->next;
              head->next = head->next->next;
              head->next->prev = head;
            }
            free(current);
            break;
    case 3: if (head->next == NULL)
              root = NULL;
            else {
              while (head->next->next != NULL)
                head = head->next;
              current = head->next;
              head->next = NULL;
            }
            free(current);
            break;
    default: return;
  }
}

void reverse() {
  current = root;
  while (current->next != NULL) {
    head = current->next;
    current->next = current->prev;
    current->prev = head;
    current = head;
  }
  head = current->next;
  current->next = current->prev;
  current->prev = head;
  root = current;
}

void sortedInsert(struct node *newnode) {
  if (newnode == root) {
    head = root;
    head->next = head->prev = NULL;
  }
  else if (head == NULL || head->data >= newnode->data) {
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
  }
  else {
    previous = head;
    while (previous->next != NULL && previous->next->data <= newnode->data)
      previous = previous->next;
    newnode->next = previous->next;
    newnode->prev = previous;
    if (previous->next != NULL)
      newnode->next->prev = newnode;
    previous->next = newnode;
  }
}

void insertionSort() {
  current = root;
  while (current != NULL) {
    traverse = current->next;
    sortedInsert(current);
    current = traverse;
  }
  root = head;
}

void initialize() {
  int n = 0;
  cout << "\n Enter the number of nodes : ";
  cin >> n;
  if (n <= 0)
    return;
  for (int i = 0; i < n; i++) {
    system("cls");
    if (root == NULL)
      root = head = create();
    else {
      head = root;
      while (head->next != NULL)
        head = head->next;
      head->next = create();
      head->next->prev = head;
    }
  }
}

void display(struct node *head) {
  cout << "\n Head";
  while (head != NULL) {
    cout << " = " << head->data;
    head = head->next;
  }
  getch();
  return;
}

void update() {
  int c = 0;
  system("cls");
  cout << "\n 1.Insert Node \n 2.Remove Node \n 3.Reverse List \n 4.Sort List \n Enter the Choice : ";
  cin >> c;
  switch (c) {
    case 1: insert();
            break;
    case 2: remove();
            break;
    case 3: reverse();
            break;
    case 4: insertionSort();
            break;
    default: return;
  }
}

int main() {
  int c = 0;
  while (true) {
  lb: system("cls");
    cout << "\n Doubly Linked List \n 1.Create \n 2.Update \n 3.Display \n 4.Exit \n Enter the Choice : ";
    cin >> c;
    switch (c) {
      case 1: initialize();
              break;
      case 2: if (root == NULL) {
                cout << "\n Linked list is empty, define linked list first.";
                initialize();
                if (root == NULL)
                  break;
              }
              update();
              break;
      case 3: if (root == NULL) {
                cout << "\n Linked list is empty, define linked list first.";
                initialize();
                if (root == NULL)
                  break;
              }
              display(root);
              break;
      case 4: exit(0);
      default: goto lb;
    }
  }
  return 0;
}
