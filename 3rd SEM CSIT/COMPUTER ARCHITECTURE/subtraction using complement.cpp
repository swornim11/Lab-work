#include <iostream>
#include <bitset>
using namespace std;

// Function to get 1's complement
string onesComplement(int n, int bits = 8) {
    bitset<8> b(n);
    b.flip(); // flip all bits
    return b.to_string();
}

// Function to get 2's complement
string twosComplement(int n, int bits = 8) {
    int twoComp = (~n) + 1;
    bitset<8> b(twoComp);
    return b.to_string();
}

// Function to subtract using 2's complement
int subtractTwosComplement(int a, int b) {
    int twos_b = (~b) + 1; // 2's complement of b
    int result = a + twos_b;
    return result;
}

int main() {
    int a, b;
    cout<<"---Swornim Maharjan---"<<endl;
    cout << "\nEnter first number (minuend): ";
    cin >> a;
    cout << "Enter second number (subtrahend): ";
    cin >> b;

    cout << "\n--- 1's Complement Method ---\n";
    cout << "1's complement of " << b << " = " << onesComplement(b) << endl;

    cout << "\n--- 2's Complement Method ---\n";
    cout << "2's complement of " << b << " = " << twosComplement(b) << endl;

    int result = subtractTwosComplement(a, b);
    cout << a << " - " << b << " = " << result << " (using 2's complement)" << endl;

    return 0;
}
