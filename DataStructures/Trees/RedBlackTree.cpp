#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

enum Color {Red, Black}; 
struct node {
  int data;
  Color color;
  struct node *left, *right, *parent;
} *root, *current;

void swap(struct node *a, struct node *b) {
  Color change = a->color;
  a->color = b->color;
  b->color = change;
}

struct node *minimum(struct node *head) {
  while (head->left != NULL)
    head = head->left;
  return head;
}

struct node *create() {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  cout << "\n Enter the data : ";
  cin >> newnode->data;
  newnode->left = newnode->right = newnode->parent = NULL;
  newnode->color = (root == NULL) ? Black : Red;
  return newnode;
}

void rotateLeft(struct node *node) {
  current = node->right;
  node->right = current->left;
  if (node->right != NULL)
    node->right->parent = node;
  current->parent = node->parent;

  if (node->parent == NULL)
    root = current;
  else if (node == node->parent->left)
    node->parent->left = current;
  else
    node->parent->right = current;

  current->left = node;
  node->parent = current;
}

void rotateRight(struct node *node) {
  current = node->left;
  node->left = current->right;
  if (node->left != NULL)
    node->left->parent = node;
  current->parent = node->parent;

  if (node->parent == NULL)
    root = current;
  else if (node == node->parent->left)
    node->parent->left = current;
  else
    node->parent->right = current;

  current->right = node;
  node->parent = current;
}

void balanceTreeInsert(struct node *head, struct node *newnode) {
  struct node *parent = NULL;
  struct node *uncle = NULL;
  struct node *grand = NULL;

  while ((newnode != root) && (newnode->color != Black) && (newnode->parent->color == Red)) {
    parent = newnode->parent;
    grand = newnode->parent->parent;
    if (parent == grand->left) {
      uncle = grand->right;
      if (uncle != NULL && uncle->color == Red) {
        grand->color = Red;
        parent->color = Black;
        uncle->color = Black;
        newnode = grand;
      }
      else {
        if (newnode == parent->right) {
          rotateLeft(parent);
          newnode = parent;
          parent = newnode->parent;
        }
        rotateRight(grand);
        swap(parent, grand);
        newnode = parent;
      }
    }
    else {
      uncle = grand->left;
      if ((uncle != NULL) && (uncle->color == Red)) {
        grand->color = Red;
        parent->color = Black;
        uncle->color = Black;
        newnode = grand;
      }
      else {
        if (newnode == parent->left) {
          rotateRight(parent);
          newnode = parent;
          parent = newnode->parent;
        }
        rotateLeft(grand);
        swap(parent, grand);
        newnode = parent;
      }
    }
  }
  root->color = Black;
}

struct node *insert(struct node *head, struct node *node) {
  if (head == NULL)
    return node;
  else if (head->data > node->data) {
    head->left = insert(head->left, node);
    head->left->parent = head;
  }
  else if (head->data < node->data) {
    head->right = insert(head->right, node);
    head->right->parent = head;
  }
  return head;
}

struct node *search(struct node *head, int key) {
  if (head->data > key)
    return search(head->left, key);
  else if (head->data < key)
    return search(head->right, key);
  else
    return head;
}

void inorder(struct node *head) {
  if (head != NULL) {
    inorder(head->left);
    cout << " " << head->data << "(" << head->color << ":" << ((head == root) ? 0 : head->parent->data) << ")\t";
    inorder(head->right);
  }
  return;
}

void preorder(struct node *head) {
  if (head != NULL) {
    cout << " " << head->data << "(" << head->color << ":" << ((head == root) ? 0 : head->parent->data) << ")\t";
    preorder(head->left);
    preorder(head->right);
  }
  return;
}

void postorder(struct node *head) {
  if (head != NULL) {
    postorder(head->left);
    postorder(head->right);
    cout << " " << head->data << "(" << head->color << ":" << ((head == root) ? 0 : head->parent->data) << ")\t";
  }
  return;
}

int main() {
  int c = 0, d = 0;
  while (true) {
  lb: system("cls");
    cout << "\n Red Black Tree \n 1.Insert Node \n 2.Search Node \n 3.Display Inorder \n 4.Display Preorder \n 5.Display Postorder \n 6.Exit \n Enter the Choice : ";
    cin >> c;
    switch (c) {
      case 1: current = create();
              root = insert(root, current);
              balanceTreeInsert(current->parent, current);
              break;
      case 2: cout << "\n Enter the data to search : ";
              cin >> d;
              if (root != NULL)
                (search(root, d) != NULL) ? cout << "\n Data present in Tree." : cout << "\n Data not present in Tree.";
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 3: if (root != NULL)
                inorder(root);
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 4: if (root != NULL)
                preorder(root);
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 5: if (root != NULL)
                postorder(root);
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 6: exit(0);
      default: goto lb;
    }
  }
  return 0;
}
