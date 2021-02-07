#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &list, int l, int m, int h) {
    int a = m - l + 1;
    int b = h - m;
 
    vector<int> L(a), R(b);
    for (int i = 0; i < a; i++)
        L[i] = list[l + i];
    for (int j = 0; j < b; j++)
        R[j] = list[m + 1 + j];
 
    int i = 0, j = 0, k = l;
    while (i < a && j < b)
        if (L[i] <= R[j])
            list[k++] = L[i++];
        else
            list[k++] = R[j++];

    while (i < a)
        list[k++] = L[i++];
    while (j < b)
        list[k++] = R[j++];
}

void MergeSort(vector<int> &list, int l, int h) {
    if(l >= h)
        return;
    int m = (l + h) / 2;
    MergeSort(list, l, m);
    MergeSort(list, m + 1, h);
    Merge(list, l, m, h);
}

int main() {
    vector<int> data{ 1, 5, 2, 7, 4, 8, 3, 0, 9};
    cout << "\n Initial : ";
    for (int i : data)
        cout << i << " ";
    MergeSort(data, 0, data.size() - 1);
    cout << "\n Sorted : ";
    for (int i : data)
        cout << i << " ";
    return 0;
}
