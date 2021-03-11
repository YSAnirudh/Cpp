#include <iostream>
#include <vector>

using namespace std;

vector<bool> knapsackSums(vector<int> vals) {
    int sum = 0;
    for (int i = 0; i < vals.size(); i++) {
        sum += vals[i];
    }
    vector<bool> possible(sum + 1, false);
    possible[0] = true;
    for (int i = 0; i < vals.size(); i++) {
        for (int j = possible.size(); j >= 0; j--) {
            if (j + vals[i] < possible.size() && possible[j]) possible[j + vals[i]] = true;
        }
    }
    return possible;
}