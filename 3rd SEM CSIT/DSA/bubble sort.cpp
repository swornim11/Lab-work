#include <iostream>
using namespace std;

int main() {
    int a[50], n, i, j, temp;

    cout << "===== Swornim Maharjan =====\n";
    cout << "=== Bubble Sort ===\n";

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(i=0;i<n;i++)
        cin >> a[i];

    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }

        cout << "Pass " << i+1 << ": ";
        for(int k=0;k<n;k++)
            cout << a[k] << " ";
        cout << endl;
    }

    return 0;
}
