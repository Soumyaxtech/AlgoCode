#include<iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = (mid - l + 1);
    int n2 = (r - mid);
    int arr1[n1], arr2[n2];
    
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }
    
    cout << "Merging arrays: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << "and ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    cout << "Resulting array after merging: ";
    for (int i = l; i <= r; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        
        cout << "Sorting left half: ";
        for (int i = l; i <= mid; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        merge_sort(arr, l, mid);

        cout << "Sorting right half: ";
        for (int i = mid + 1; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "UNSORTED ARRAY:" << endl;
    display(arr, n);

    merge_sort(arr, 0, n - 1);

    cout << "SORTED ARRAY:" << endl;
    display(arr, n);

    return 0;
}
