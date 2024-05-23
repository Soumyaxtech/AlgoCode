#include <iostream>
using namespace std;

void display(float arr[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(float arr[], int i, int j) {
    float x = arr[i];
    arr[i] = arr[j];
    arr[j] = x;
}

void sort(float w[], float p[], int n) {
    float p_w[n + 1];
    for (int i = 1; i <= n; i++) {
        p_w[i] = p[i] / w[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (p_w[j] < p_w[j + 1]) {
                swap(p_w, j, j + 1);
                swap(p, j, j + 1);
                swap(w, j, j + 1);
            }
        }
    }
}

float knapsack(float w[], float p[], int n, float W) {
    sort(w, p, n);
    float x[n + 1];
    for (int i = 1; i <= n; i++) {
        x[i] = 0.0;
    }
    float u = W;
    for (int i = 1; i <= n; i++) {
        if (w[i] > u) {
            x[i] = u / w[i];
            break;
        } else {
            x[i] = 1.0;
            u = u - w[i];
        }
    }
    //display(x, n); // Adjust the display function call
    float profit = 0;
    for (int i = 1; i <= n; i++) {
        profit = profit + x[i] * p[i];
    }
    return profit;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    float w[n + 1];
    float p[n + 1];

    cout << "Enter the weights of the items: ";
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    cout << "Enter the profits of the items: ";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    float W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    float profit = knapsack(w, p, n, W);
    cout << "The resulting profits array: ";
    display(p, n);
    cout << "The resulting weights array: ";
    display(w, n);
    cout << "Maximum profit: " << profit << endl;

    return 0;
}
