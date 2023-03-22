#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/abc294/tasks/abc294_b
int main () {
    int n;
    int m;

    cin >> n;
    cin >> m;

    vector<int> first(n);
    vector<int> second(m);

    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> second[i];
    }

    int index = 1;
    auto second_iterator = second.begin();
    for (int i = 0; i < n; i++) {
        while (first[i] > *second_iterator && second_iterator != second.end()) {
            index++;
            second_iterator++;
        }
        cout << index << ' ';
        index++;
    }
    cout << endl;
    
    index = 1;
    auto first_iterator = first.begin();
    for (int i = 0; i < m; i++) {
        while (second[i] > *first_iterator && first_iterator != first.end()) {
            index++;
            first_iterator++;
        }
        cout << index << ' ';
        index++;
    }
    cout << endl;
}