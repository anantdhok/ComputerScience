#include<bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int Fibonacci(int index, int a = 0, int b = 1) {
    if (index == 0)
        return a;
    return Fibonacci(index - 1, b, a+b);
}

int FibonacciSearch(int key, vector<int> data) {
    int i = 0, m = 0, offset = -1;
    while (Fibonacci(m) < data.size())
        m += 1;
    while (Fibonacci(m) > 1) {
        i = min(offset + Fibonacci(m - 2), data.size() - 1);
        if (data[i] < key) {
            m -= 1;
            offset = i;
        }
        else if (data[i] > key)
            m -= 2;
        else
            return i;
    }
    if (Fibonacci(m - 1) && data[offset + 1] == key)
        return (offset + 1);
    return -1;
}

int main() {
    int key = 4;
    vector<int> data{ 1, 5, 2, 7, 4, 8, 3, 0, 9};
    sort(data.begin(), data.end());
    cout << "\n Sorted List : ";
    for (int i : data)
        cout << i << " ";
    cout << "\n At index : " << FibonacciSearch(key, data);
    return 0;
}
