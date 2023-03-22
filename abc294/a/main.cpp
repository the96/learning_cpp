#include <iostream>
using namespace std;

// https://atcoder.jp/contests/abc294/tasks/abc294_a
int main () {
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (auto&& num : input) {
        if (num % 2 != 0)
            continue;

        cout << num << endl;
    }
}