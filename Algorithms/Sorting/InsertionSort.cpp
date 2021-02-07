#include<bits/stdc++.h>
using namespace std;

vector<int> InsertionSort(vector<int> list) {
    for (int i = 1; i < list.size(); i++) {
        int key = list[i], j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
    return list;
}

int main() {
    vector<int> data{ 1, 5, 2, 7, 4, 8, 3, 0, 9};
    cout << "\n Initial : ";
    for (int i : data)
        cout << i << " ";
    cout << "\n Sorted : ";
    for (int i : InsertionSort(data))
        cout << i << " ";
    return 0;
}
