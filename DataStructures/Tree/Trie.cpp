#include <bits/stdc++.h>
using namespace std;

const int ALPHABETS = 26;

struct node {
    struct node *child[ALPHABETS];
    bool end;
} *root, *current;

struct node *create() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->end = false;
    for (int i = 0; i < ALPHABETS; i++)
        newnode->child[i] = NULL;
    return newnode;
}

void insert(string word) {
    current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (!current->child[index])
            current->child[index] = create();
        current = current->child[index];
    }
    current->end = true;
}

bool search(string word) {
    current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (!current->child[index])
            return false;
        current = current->child[index];
    }
    return (current != NULL && current->end);
}

int main() {
    root = create();
    vector<string> words{"the", "a", "there", "answer", "any", "by", "bye", "their"};
    
    for (string i: words)
        insert(i);

    search("the") ? cout << "Found" << endl : cout << "Not Found" << endl;
    search("these") ? cout << "Found" << endl : cout << "Not Found" << endl;
    return 0;
}
