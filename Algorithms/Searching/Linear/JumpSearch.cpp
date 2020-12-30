#include<bits/stdc++.h>
using namespace std;

int JumpSearch(int key, vector<int> data) {
    int i = 0, p = 0;

    while (data[i] < key) {
        if (i >= data.size()) {
            break;
        }
        p = i;
        i += sqrt(data.size());
    }

    while (i >= p) {
        if (data[i] == key) {
            break;
        }
        i -= 1;
    }

    return (data[i] == key) ? i : -1;
}

int main() {
    int key = 4;
    vector<int> data{ 1, 5, 2, 7, 4, 8, 3, 0, 9};
    sort(data.begin(), data.end());

    cout << "\n Sorted List : ";
    for (int i : data) {
        cout << i << " ";
    }

    cout << "\n At index : " <<  JumpSearch(key, data);
    return 0;
}