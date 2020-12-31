#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
} *root, *current;

struct node *minimum(struct node *head) {
  while (head->left != NULL)
    head = head->left;
  return head;
}

struct node *create() {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  cout << "\n Enter the data : ";
  cin >> newnode->data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

struct node *insert(struct node *head, struct node *node) {
  if (head == NULL)
    return node;
  else if (head->data > node->data)
    head->left = insert(head->left, node);
  else if (head->data < node->data)
    head->right = insert(head->right, node);
  return head;
}

struct node *remove(struct node *head, int key) {
  if (head->data == key) {
    if (head->left == NULL) {
      current = head->right;
      free(head);
      return current;
    }
    else if (head->right == NULL) {
      current = head->left;
      free(head);
      return current;
    }
    current = minimum(head->right);
    head->data = current->data;
    head->right = remove(head->right, current->data);
  } 
  else if (head->data > key)
    head->left = remove(head->left, key);
  else if (head->data < key)
    head->right = remove(head->right, key);
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
    cout << " " << head->data;
    inorder(head->right);
  }
}

void preorder(struct node *head) {
  if (head != NULL) {
    cout << " " << head->data;
    preorder(head->left);
    preorder(head->right);
  }
}

void postorder(struct node *head) {
  if (head != NULL) {
    postorder(head->left);
    postorder(head->right);
    cout << " " << head->data;
  }
}

int main() {
  int c = 0, d = 0;
  while (true) {
  lb: system("cls");
    cout << "\n Binary Search Tree \n 1.Insert Node \n 2.Remove Node \n 3.Search Node \n 4.Display Inorder \n 5.Display Preorder \n 6.Display Postorder \n 7.Exit \n Enter the Choice : ";
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
