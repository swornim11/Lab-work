#include <iostream>
#include <bitset>
using namespace std;

// Add & Shift Algorithm (Unsigned)
int addAndShift(int multiplicand, int multiplier) {
    int product = 0;
    for(int i = 0; i < 8; i++) {
        if(multiplier & 1) {
            product += multiplicand;
        }
        multiplicand <<= 1;
        multiplier >>= 1;
    }
    return product;
}

// Booth's Algorithm (Signed)
int boothAlgorithm(int multiplicand, int multiplier) {
    int n = 8;           // number of bits
    int A = 0;           // accumulator
    int Q = multiplier;  // multiplier
    int M = multiplicand; // multiplicand
    int Q_1 = 0;

    for(int i = 0; i < n; i++) {
        int lastQ = Q & 1;
        if(lastQ == 1 && Q_1 == 0) {
            A = A - M;
        } else if(lastQ == 0 && Q_1 == 1) {
            A = A + M;
        }

        // Arithmetic right shift A and Q together
        int combined = (A << n) | (Q & 0xFF); // combine A and Q
        combined >>= 1;                        // arithmetic shift
        // update A and Q after shift
        A = (combined >> n);
        Q = combined & 0xFF;
        Q_1 = lastQ;
    }

    return (A << n) | (Q & 0xFF); // final product
}

int main() {
    int multiplicand, multiplier;

    cout << "---Swornim Maharjan---" << endl;
    cout << "Enter multiplicand: ";
    cin >> multiplicand;
    cout << "Enter multiplier: ";
    cin >> multiplier;

    cout << "\n--- Multiplication using Add & Shift ---\n";
    int product1 = addAndShift(multiplicand, multiplier);
    cout << multiplicand << " * " << multiplier << " = " << product1 << endl;

    cout << "\n--- Multiplication using Booth's Algorithm ---\n";
    int product2 = boothAlgorithm(multiplicand, multiplier);
    cout << multiplicand << " * " << multiplier << " = " << product2 << endl;

    return 0;
}
