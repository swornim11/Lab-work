#include <iostream>
#include <bitset>
using namespace std;

void binaryDivision(int dividend, int divisor) {
    const int n = 8;       // number of bits
    int A = 0;             // accumulator
    int Q = dividend;      // dividend
    int M = divisor;       // divisor

    cout << "\nInitial Values:\n";
    cout << "A = " << bitset<8>(A)
         << ", Q = " << bitset<8>(Q)
         << ", M = " << bitset<8>(M) << "\n\n";

    // Table Header
    cout << "Step\tOperation\t\tA\t\tQ" << endl;
    cout << "----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        // Left shift A and Q together
        A = (A << 1) | ((Q & 0x80) >> 7);
        Q = (Q << 1) & 0xFF;

        // Subtract M from A
        A = A - M;

        string operation;
        if (A < 0) {
            Q = Q & ~1;   // set Q0 = 0
            A = A + M;    // restore A
            operation = "Subtract & Restore";
        } else {
            Q = Q | 1;    // set Q0 = 1
            operation = "Subtract & Keep";
        }

        cout << i+1 << "\t" 
             << operation << "\t" 
             << bitset<8>(A & 0xFF) << "\t" 
             << bitset<8>(Q & 0xFF) << endl;
    }

    cout << "\nFinal Result:\n";
    cout << "Quotient (Q) = " << Q << endl;
    cout << "Remainder (A) = " << A << endl;
}

int main() {
    int dividend, divisor;

    cout << "---Swornim Maharjan---" << endl;

    cout << "\nEnter dividend (0-255): ";
    cin >> dividend;
    cout << "Enter divisor (1-255): ";
    cin >> divisor;

    if (divisor == 0) {
        cout << "Error! Division by zero." << endl;
        return 1;
    }
    if (dividend < 0 || dividend > 255 || divisor < 0 || divisor > 255) {
        cout << "Please enter values in 0-255 range." << endl;
        return 1;
    }

    binaryDivision(dividend, divisor);

    return 0;
}
