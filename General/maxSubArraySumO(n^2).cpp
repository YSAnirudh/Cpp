#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> array) {
    int maxSum = INT_MIN;

    int currSum = 0;
    for (int i = 0; i < array.size(); i++) {
        currSum = 0;
        for (int j = i; j < array.size(); j++) {
            currSum += array[j];
            if (currSum > maxSum) maxSum = currSum;
        }
    }

    return maxSum;
}
