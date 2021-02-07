#include<bits/stdc++.h>
using namespace std;

int BinarySearchImperative(int key, vector<int> data) {
    int l = 0, m = 0, h = data.size();
    while (l <= h) {
        m = (l + h) / 2;
        if (data[m] == key)
            return m;
        else if (data[m] < key)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int BinarySearchRecurssive(int key, vector<int> data, int l, int h) {
    int m = (l + h) / 2;
    if (l <= h) {
        if (data[m] == key)
            return m;
        else if (data[m] < key)
            return BinarySearchRecurssive(key, data, m + 1, h);
        else
            return BinarySearchRecurssive(key, data, l, m - 1); 
    }
    return -1;
}

int main() {
    int key = 4;
    vector<int> data{ 1, 5, 2, 7, 4, 8, 3, 0, 9};
    sort(data.begin(), data.end());
    cout << "\n Sorted List : ";
    for (int i : data)
        cout << i << " ";
    cout << "\n At index : " << BinarySearchImperative(key, data);
    cout << "\n At index : " << BinarySearchRecurssive(key, data, 0, data.size()-1);
    return 0;
}
