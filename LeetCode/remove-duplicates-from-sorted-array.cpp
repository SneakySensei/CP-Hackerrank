#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << "end" << *(arr.end() - 2) << endl;

    arr.erase(arr.begin() + 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    cout << "end" << *(arr.end() - 2) << endl;
    return 0;
}