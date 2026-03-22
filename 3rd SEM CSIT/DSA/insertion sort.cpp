#include <iostream>
using namespace std;

int main() {
    int a[50], n, i, j, key;

    cout << "===== Swornim Maharjan =====\n";
    cout << "=== Insertion Sort ===\n";

    cout << "Enter number of elements: ";
    cin >> n;

    for(i=0;i<n;i++)
        cin >> a[i];

    for(i=1;i<n;i++) {
        key = a[i];
        j = i-1;

        while(j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;

        cout << "Pass " << i << ": ";
        for(int k=0;k<n;k++)
            cout << a[k] << " ";
        cout << endl;
    }

    return 0;
}
