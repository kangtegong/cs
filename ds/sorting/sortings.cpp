#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 삽입 정렬 (Insertion Sort)
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 선택 정렬 (Selection Sort)
void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 버블 정렬 (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 퀵 정렬 (Quick Sort)
vector<int> quickSort(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    int pivot = arr[arr.size() / 2];
    vector<int> left, right, middle;
    for (int x : arr) {
        if (x < pivot) left.push_back(x);
        else if (x == pivot) middle.push_back(x);
        else right.push_back(x);
    }
    left = quickSort(left);
    right = quickSort(right);
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

// 병합 정렬 (Merge Sort)
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }
    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);
    return result;
}

vector<int> mergeSort(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    size_t mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

// 힙 정렬 (Heap Sort)
void heapify(vector<int>& arr, size_t n, size_t i) {
    size_t largest = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    size_t n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 정렬 결과 출력
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    vector<int> arrCopy;

    // 삽입 정렬
    arrCopy = arr;
    insertionSort(arrCopy);
    cout << "삽입 정렬: ";
    printArray(arrCopy);

    // 선택 정렬
    arrCopy = arr;
    selectionSort(arrCopy);
    cout << "선택 정렬: ";
    printArray(arrCopy);

    // 버블 정렬
    arrCopy = arr;
    bubbleSort(arrCopy);
    cout << "버블 정렬: ";
    printArray(arrCopy);

    // 퀵 정렬
    arrCopy = arr;
    arrCopy = quickSort(arrCopy);
    cout << "퀵 정렬: ";
    printArray(arrCopy);

    // 병합 정렬
    arrCopy = arr;
    arrCopy = mergeSort(arrCopy);
    cout << "병합 정렬: ";
    printArray(arrCopy);

    // 힙 정렬
    arrCopy = arr;
    heapSort(arrCopy);
    cout << "힙 정렬: ";
    printArray(arrCopy);

    return 0;
}
