#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimizeSum(vector<int> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    if (n % 2 == 0) {
        return (a[n/2] + a[n/2 - 1])/2;
    } else {
        return a[n/2];
    }
}

int minimizeSumOfSquares(vector<int> a) {
    float ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret+= a[i];
    }
    return ret/a.size();
}