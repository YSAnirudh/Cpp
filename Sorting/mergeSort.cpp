#include <iostream>
#include <vector>

using namespace std;
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void fullMerge(vector<int> array, int low, int mid, int high) 
{
    int ls = mid - low + 1;
    int rs = high - mid;
    vector<int> templ(ls ,0);
    vector<int> tempr(rs, 0);

    for (int i = 0; i < ls; i++) {
        templ[i] = array[i + low];
    }
    for (int i = 0; i < rs; i++) {
        templ[i] = array[i + mid + 1];
    }
    int l = 0, r = 0;
    int mainInd = low;
    while (l < ls || r < rs) {
        if (templ[l] < tempr[r]) {
            array[mainInd] = templ[l];
            l++;
        } else {
            array[mainInd] = templ[l];
            r++;
        }
        mainInd++;
    }

    while (l < ls) {
        array[mainInd] = templ[l];
        l++;
        mainInd++;
    }
    while (r < rs) {
        array[mainInd] = tempr[r];
        r++;
        mainInd++;
    }
}

void mergey(vector<int> array, int low, int high) {
    if (high <= low) return;
    
    int mid = (low + high) / 2;

    mergey(array, low, mid);
    mergey(array, mid + 1, high);
    fullMerge(array, low, mid, high); 
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int* L = (int*)malloc(sizeof(int) * n1), *R = (int*)malloc(sizeof(int) * n1);
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main() {
    int n;
    cin >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
}