#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// https://atcoder.jp/contests/abc294/tasks/abc294_e
int main () {
    long column_num;
    long first_len;
    long second_len;

    cin >> column_num;
    cin >> first_len;
    cin >> second_len;

    vector<pair<long, long>> first_row(first_len);
    vector<pair<long, long>> second_row(second_len);

    long num;
    long count;
    for (int i = 0; i < first_len; i++) {
        cin >> num;
        cin >> count;
        first_row[i] = make_pair(num, count);
    }

    for (int i = 0; i < second_len; i++) {
        cin >> num;
        cin >> count;
        second_row[i] = make_pair(num, count);
    }

    long result = 0;
    long first_index = 0;
    long second_index = 0;
    long first_num;
    long second_num;
    long first_count;
    long second_count;
    auto first_iterator = first_row.begin();
    auto second_iterator = second_row.begin();

    long i = 1;
    while (i <= column_num) {
        first_num    = get<0>(*first_iterator);
        second_num   = get<0>(*second_iterator);
        first_count  = get<1>(*first_iterator) - first_index;
        second_count = get<1>(*second_iterator) - second_index;

        // 値が一致したとき
        if (first_num == second_num) {
            result += first_count > second_count ? second_count : first_count;
        }

        if (first_count > second_count) {
            first_index += second_count;
            second_iterator++;
            second_index = 0;
            i += second_count;
        } else if (first_count < second_count) {
            second_index += first_count;
            first_iterator++;
            first_index = 0;
            i += first_count;
        } else { // first_count == second_count
            first_iterator++;
            second_iterator++;
            first_index = 0;
            second_index = 0;
            i += first_count;
        }

    }

    cout << result << endl;
}