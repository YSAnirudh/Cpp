#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int> array) {
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < array.size(); i++) {
        currSum = max(array[i], currSum + array[i]);
        maxSum = max(currSum, maxSum);
    }

    return maxSum;
}