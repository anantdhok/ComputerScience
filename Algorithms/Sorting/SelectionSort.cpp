#include<bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

vector<int> SelectionSort(vector<int> list) {
    for (int i = 0; i < list.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < list.size(); j++)
            if (list[min] > list[j])
                min = j;
        Swap(list[i], list[min]);
    }
    return list;
}

int main() {
    vector<int> data{ 1, 5, 2, 7, 4, 8, 3, 0, 9};
    cout << "\n Initial : ";
    for (int i : data)
        cout << i << " ";
    cout << "\n Sorted : ";
    for (int i : SelectionSort(data))
        cout << i << " ";
    return 0;
}
