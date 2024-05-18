#include <iostream>
#include <cmath>
using namespace std;

int n, count = 0;
int x[15];

void print() {
    cout << "\n\nThe column vector is:\n\n";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << "\t";
    }
    cout << "\n\nSolution " << ++count << ":\n\n";
    
    // Print column numbers for reference
    for (int i = 1; i <= n; i++) {
        cout << "\t" << i;
    }
    cout << endl;

    // Print the board
    for (int i = 1; i <= n; i++) {
        cout << i;
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << "\tQ";
            else
                cout << "\t0";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_safe(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i || (fabs(x[j] - i) == fabs(k - j))) {
            return false;
        }
    }
    return true;
}

void nqueen(int k, int n) {
    for (int col = 1; col <= n; col++) {
        if (is_safe(k, col)) {
            x[k] = col;
            if (k == n) {
                print();
            } else {
                nqueen(k + 1, n);
            }
        }
    }
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> n;
    if (n < 1) {
        cout << "Number of queens must be at least 1.\n";
        return 1;
    }
    nqueen(1, n);
    if (count == 0) {
        cout << "No solutions found for " << n << " queens.\n";
    }
    return 0;
}
