#include <iostream>

void Merge(int* arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    MergeSort(arr, left, middle);
    MergeSort(arr, middle + 1, right);

    Merge(arr, left, middle, right);
}

int main() {
    int arr[] = { 9, 3, 5, 1, 8, 2, 7, 4, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    MergeSort(arr, 0, n - 1);

    std::cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
