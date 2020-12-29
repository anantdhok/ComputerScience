#include<bits/stdc++.h>
using namespace std;

int Search(int key, vector<int> data) {
    int i = 0;

    while (i < data.size()) {
        if (data[i] == key) {
            break;
        }
        i += 1;
    }

    return (i == 0 || (i != data.size())) ? i : -1;
}

int main() {
    int key = 4;
    vector<int> data{ 1, 5, 2, 7, 4, 8, 2, 0, 8};
    cout << "\n At index : " << Search(key, data);
    return 0;
}
