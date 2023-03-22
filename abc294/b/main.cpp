#include <iostream>
#include <string>
using namespace std;

// https://atcoder.jp/contests/abc294/tasks/abc294_b
int main () {
    int h;
    int w;

    cin >> h;
    cin >> w;

    int input[h][w];
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int n;
            cin >> n;
            input[y][x] = n;
        }
    }


    for (int y = 0; y < h; y++) {
        string str(w, '.');
        for (int x = 0; x < w; x++) {
            if (input[y][x] != 0) {
                str[x] = char('A' + input[y][x] - 1);
            }
        }
        cout << str << endl;
    }
}