#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct Stack {
	int top, capacity;
	int *arr;

	Stack(int size) {
		top = -1;
		capacity = size;
		arr = new int[size];
	}

	~Stack() {
		delete[] arr;
	}

	int isEmpty() {
		if (top < 0)
			return 1;
		return 0;
	}

	int isFull() {
		if (top >= capacity - 1)
			return 1;
		return 0;
	}

	void push() {
		int d = 0;
		while (d == 0) {
			if (isFull()) {
				cout << "\n Stack is Full.";
				getch();
				break;
			}
			else {
				cout << "\n Enter the data : ";
				cin >> d;
				top++;
				arr[top] = d;
			}
			cout << " Push Data Again? (0/1) : ";
			cin >> d;
		}
	}

	void pop() {
		int d = 0;
		while (d == 0) {
			if (isEmpty()) {
				cout << "\n Stack is Empty.";
				getch();
				break;
			}
			else {
				cout << "\n Popped Data : " << arr[top] << endl;
				top--;
			}
			cout << " Pop Data Again? (0/1) : ";
			cin >> d;
		}
	}

	void display() {
		if (isEmpty())
			cout << "\n Stack is Empty.";
		else {
			int d = top;
			cout << "\n Stack - ";
			while (d >= 0)
				cout << arr[d--] << "\t";
		}
		getch();
	}
};

int main() {
	int c = 0;
	Stack s(5);
	while (true) {
	lb: system("cls");
		cout << "\n Stack \n 1.Push Data \n 2.Pop Data \n 3.Display \n 4.Exit \n Enter the Choice : ";
		cin >> c;
		switch (c) {
			case 1: s.push();
					break;
			case 2: s.pop();
					break;
			case 3:	s.display();
					break;
			case 4: exit(0);
			default: goto lb;
		}
	}
	return 0;
}
