#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct Queue {
	int front, rear, capacity;
	int *arr;

	Queue(int size) {
		front = rear = 0;
		capacity = size;
		arr = new int[size];
	}

	~Queue() {
		delete[] arr;
	}

	int isEmpty() {
		if (front == rear)
			return 1;
		return 0;
	}

	int isFull() {
		if (rear > capacity)
			return 1;
		return 0;
	}

	void enqueue() {
		int d = 0;
		while (d == 0) {
			if (isFull()) {
				cout << "\n Queue is Full.";
				getch();
				break;
			}
			else {
				cout << "\n Enter the data : ";
				cin >> arr[rear++];
			}
			cout << " Enqueue Data Again? (0/1) : ";
			cin >> d;
		}
	}

	void dequeue() {
		int d = 0;
		while (d == 0) {
			if (isEmpty()){
				cout << "\n Queue is Empty.";
				getch();
				break;
			}
			else {
				cout << "\n Extacted Data : " << arr[front] << endl;
				for (int d = front; d < rear; d++)
					arr[d] = arr[d + 1];
				rear--;
			}
			cout << " Enqueue Data Again? (0/1) : ";
			cin >> d;
		}
	}

	void display() {
		if (isEmpty())
			cout << "\n Queue is Empty.";
		else {
			cout << "\n Queue - ";
			for (int d = front; d < rear; d++)
				cout << arr[d] << "\t";
		}
		getch();
	}
};

int main() {
	int c = 0;
	Queue q(5);
	while (true) {
	lb: system("cls");
		cout << "\n Queue \n 1.Enqueue Data \n 2.Dequeue Data \n 3.Display \n 4.Exit \n Enter the Choice : ";
		cin >> c;
		switch (c) {
			case 1: q.enqueue();
					break;
			case 2: q.dequeue();
					break;
			case 3:	q.display();
					break;
			case 4: exit(0);
			default: goto lb;
		}
	}
	return 0;
}
