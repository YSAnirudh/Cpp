#include <iostream>
#include <vector>

using namespace std;

int scanNum() {
    int x;
    printf("Number to find for:");
    scanf("%d", &x);
    return x + 1;
}
int x = scanNum();
#define N x - 1

vector<int> setValues(int size) {
    vector<int> vals;
    int val;
    for (int i = 0; i < size; i++) {
        cout << "Val " << i + 1 << ":"; 
        cin >> val;
        vals.push_back(val);
    }
    return vals;
}

vector<int> results(N, -1);
vector<int> values = setValues(N);

void calcIncSubSeq(vector<int> values, int k) {
    for (int i = 0; i < k; i++) {
        results[i] = 1;
        for (int j = 0; j < i; j++) {
            if (values[j] < values[i]) {
                results[i] = max(results[i], results[j] + 1);
            }
        }
    }
}