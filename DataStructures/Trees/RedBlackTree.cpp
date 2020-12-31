#include <bits/stdc++.h>
#include <conio.h>
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

void swapLinks(struct node *a, struct node *b) {
  if (a->parent == NULL)
    root = b;
  else if (a == a->parent->left)
    a->parent->left = b;
  else
    a->parent->right = b;
  b->parent = a->parent;
}

struct node *minimum(struct node *head) {
  while (head->left != NULL)
    head = head->left;
  return head;
}

struct node *maximum(struct node *head) {
  while (head->right != NULL)
    head = head->right;
  return head;
}

struct node *successor(struct node *head) {
  if (head->right != NULL)
    return minimum(head->right);

  current = head->parent;
  while (current != NULL && head == current->right) {
    head = current;
    current = current->parent;
  }
  return current;
}

struct node *pRedecessor(struct node *head) {
  if (head->left != NULL)
    return maximum(head->left);

  current = head->parent;
  while (current != NULL && head == current->left) {
    head = current;
    current = current->parent;
  }
  return current;
}

void rotateLeft(struct node *head, struct node *grand) { 
  current = grand->right; 
  grand->right = current->left; 
  if (grand->right != NULL) 
    grand->right->parent = grand; 
  current->parent = grand->parent; 

  if (grand->parent == NULL) 
    head = current; 
  else if (grand == grand->parent->left) 
    grand->parent->left = current; 
  else
    grand->parent->right = current; 

  current->left = grand; 
  grand->parent = current; 
} 
  
void rotateRight(struct node *head, struct node *node) { 
  current = node->left; 
  node->left = current->right; 
  if (node->left != NULL) 
    node->left->parent = node; 
  current->parent = node->parent; 

  if (node->parent == NULL) 
    head = current; 
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

  while ((newnode != head) && (newnode->color != Black) && (newnode->parent->color == Red)) { 
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
          rotateLeft(head, parent); 
          newnode = parent; 
          parent = newnode->parent; 
        } 
        rotateRight(head, grand); 
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
          rotateRight(head, parent); 
          newnode = parent; 
          parent = newnode->parent;
        } 
        rotateLeft(head, grand); 
        swap(parent, grand); 
        newnode = parent; 
      } 
    } 
  }
  head->color = Black; 
} 

struct node *balanceTreeRemove(struct node *head, struct node *newnode) {
  while (newnode != head && newnode->color == Red) {
    if (newnode == newnode->parent->left) {
      current = newnode->parent->right;
      if (current->color == Black) {
        current->color = Red;
        newnode->parent->color = Black;
        rotateLeft(head, newnode->parent);
        current = newnode->parent->right;
      }
      else if (current->left->color == Red && current->right->color == Red) {
        current->color = Black;
        newnode = newnode->parent;
      }
      else {
        if (current->right->color == Red) {
          current->left->color = Red;
          current->color = Black;
          rotateRight(head, current);
          current = newnode->parent->right;
        }
        current->color = newnode->parent->color;
        newnode->parent->color = Red;
        current->right->color = Red;
        rotateLeft(head, newnode->parent);
        newnode = head;
      }
    }
    else {
      current = newnode->parent->left;
      if (current->color == Black) {
        current->color = Red;
        newnode->parent->color = Black;
        rotateRight(head, newnode->parent);
        current = newnode->parent->left;
      }
      else if (current->right->color == Red && current->right->color == Red) {
        current->color = Black;
        newnode = newnode->parent;
      }
      else {
        if (current->left->color == Red) {
          current->right->color = Red;
          current->color = Black;
          rotateLeft(head, current);
          current = newnode->parent->left;
        }
        current->color = newnode->parent->color;
        newnode->parent->color = Red;
        current->left->color = Red;
        rotateRight(head, newnode->parent);
        newnode = head;
      }
    }
  }
  newnode->color = Red;
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
  balanceTreeInsert(head, node);
  return head;
}

struct node *remove(struct node *head, int key) {
  struct node *grand = NULL;
  struct node *uncle = NULL;

  while (head != NULL) {
    if (head->data == key)
      current = head;
    else if (head->data <= key)
      head = head->right;
    else if (head->data >= key)
      head = head->left;
  }

  grand = current;
  Color temp = grand->color;
  if (current->left == NULL) {
    uncle = current->right;
    swapLinks(current, current->right);
  }
  else if (current->right == NULL) {
    uncle = current->left;
    swapLinks(current, current->left);
  }
  else {
    grand = minimum(current->right);
    temp = grand->color;
    uncle = grand->right;
    if (grand->parent == current)
      uncle->parent = grand;
    else {
      swapLinks(grand, grand->right);
      grand->right = current->right;
      grand->right->parent = grand;
    }
    swapLinks(current, grand);
    grand->left = current->left;
    grand->left->parent = grand;
    grand->color = current->color;
  }
  free(current);
  if (temp == 0)
    head = balanceTreeRemove(head, uncle);
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
    cout << " " << head->data << "(" << head->color << ")\t";
    inorder(head->right);
  }
  return;
}

void preorder(struct node *head) {
  if (head != NULL) {
    cout << " " << head->data << "(" << head->color << ")\t";
    preorder(head->left);
    preorder(head->right);
  }
  return;
}

void postorder(struct node *head) {
  if (head != NULL) {
    postorder(head->left);
    postorder(head->right);
    cout << " " << head->data << "(" << head->color << ")\t";
  }
  return;
}

int main() {
  int c = 0, d = 0;
  while (true) {
  lb: system("cls");
    cout << "\n Red Black Tree \n 1.Insert Node \n 2.Remove Node \n 3.Search Node \n 4.Display Inorder \n 5.Display Preorder \n 6.Display Postorder \n 7.Exit \n Enter the Choice : ";
    cin >> c;
    switch (c) {
      case 1: current = create();
              root = insert(root, current);
              break;
      case 2: cout << "\n Enter the data to be removed : ";
              cin >> d;
              if (root != NULL)
                root = remove(root, d);
              else {
                cout << "\n Tree is Empty.";
                getch();
              }
              break;
      case 3: cout << "\n Enter the data to search : ";
              cin >> d;
              if (root != NULL)
                (search(root, d) != NULL) ? cout << "\n Data present in Tree." : cout << "\n Data not present in Tree.";
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 4: if (root != NULL)
                inorder(root);
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 5: if (root != NULL)
                preorder(root);
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 6: if (root != NULL)
                postorder(root);
              else
                cout << "\n Tree is Empty.";
              getch();
              break;
      case 7: exit(0);
      default: goto lb;
    }
  }
  return 0;
}
