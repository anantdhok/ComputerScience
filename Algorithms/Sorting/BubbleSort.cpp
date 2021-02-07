#include<bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

vector<int> BubbleSort(vector<int> list) {
    for (int i = 0; i < list.size() - 1; i++)
        for (int j = i + 1; j < list.size(); j++)
            if (list[j] < list[i])
                Swap(list[i], list[j]);
    return list;
}

int main() {
    vector<int> data{ 1, 5, 2, 7, 4, 8, 3, 0, 9};
    cout << "\n Initial : ";
    for (int i : data)
        cout << i << " ";
    cout << "\n Sorted : ";
    for (int i : BubbleSort(data))
        cout << i << " ";
    return 0;
}
