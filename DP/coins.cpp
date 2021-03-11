#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int scanNum() {
    int x;
    printf("Number to find for:");
    scanf("%d", &x);
    return x + 1;
}
int x = scanNum();
#define N x

vector<int> value(N);
vector<int> ready(N, false);
vector<int> coins = {1,3,5};
int find(int x) {
    if (x < 0) {
        return INT_MAX-1;
    }
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INT_MAX;
    for (auto c : coins) {
        best = min(best, find(x - c)+1);
    }
    value[x] = best;
    ready[x] = true;
    return value[x];
}