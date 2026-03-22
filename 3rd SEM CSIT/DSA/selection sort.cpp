#include <iostream>
using namespace std;

int main() {
    int a[50], n, i, j, min, temp;

    cout << "===== Swornim Maharjan =====\n";
    cout << "=== Selection Sort ===\n";

    cout << "Enter number of elements: ";
    cin >> n;

    for(i=0;i<n;i++)
        cin >> a[i];

    for(i=0;i<n-1;i++) {
        min = i;
        for(j=i+1;j<n;j++) {
            if(a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        cout << "Pass " << i+1 << ": ";
        for(int k=0;k<n;k++)
            cout << a[k] << " ";
        cout << endl;
    }

    return 0;
}
