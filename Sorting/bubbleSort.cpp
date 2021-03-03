#include <iostream>
#include <vector>

using namespace std;
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array.size() - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[i], array[j]);
            }
        }
    }
}