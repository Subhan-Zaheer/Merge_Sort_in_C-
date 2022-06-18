#include<iostream>

using namespace std;
void merging(int arr[], int start, int end, int mid) {
    int i = start, j = mid + 1, k = start;
    int* b = new int[end + 1];
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            b[k] = arr[i];
            i++;
        }
        else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (j <= end) {
        b[k] = *(arr + j);
        k++;
        j++;
    }
    while (i <= mid) {
        b[k] = *(arr + i);
        k++;
        i++;
    }
    for (int a = start; a <= end; a++) {
        *(arr + a) = *(b + a);
    }

}
void mergeSort(int arr[], int start, int end, int size) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid, size);
        mergeSort(arr, mid + 1, end, size);
        merging(arr, start, end, mid);
    }
    //return;
}




int main() {

    int arr[] = {5, 34, 7, 2, 8, 1, 0};
    mergeSort(arr, 0, 6, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}