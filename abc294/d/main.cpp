#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/abc294/tasks/abc294_b
int main () {
    int p;
    int e;
    int min_not_visit_index = 0;

    cin >> p;
    cin >> e;

    vector<bool> people(p, false);
    for (int i = 0; i < e; i++) {
        int command;
        cin >> command;

        switch (command) {
            case 1:
                break;

            case 2:
                int index;
                cin >> index;
                index--;
                people[index] = true;

                // 受付に来た人が一番小さい値の人だったら、
                // まだ受付に来ていない人の最小値を更新する
                if (index == min_not_visit_index) {
                    for (int j = min_not_visit_index + 1; j < p; j++) {
                        if (!people[j]) {
                            min_not_visit_index = j;
                            break;
                        }
                    }
                }
                break;

            case 3:
                cout << min_not_visit_index + 1 << endl;
                break;
        }
    }
}