#include <iostream>
using namespace std;

int main() {
    int a[50], n, i, j, gap, temp;

    cout << "===== Swornim Maharjan =====\n";
    cout << "=== Shell Sort ===\n";

    cout << "Enter number of elements: ";
    cin >> n;

    for(i=0;i<n;i++)
        cin >> a[i];

    for(gap=n/2; gap>0; gap/=2) {

        for(i=gap;i<n;i++) {
            temp=a[i];

            for(j=i; j>=gap && a[j-gap]>temp; j-=gap)
                a[j]=a[j-gap];

            a[j]=temp;
        }

        cout << "Gap " << gap << " Pass: ";
        for(i=0;i<n;i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
