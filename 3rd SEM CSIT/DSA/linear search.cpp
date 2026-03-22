#include <iostream>
using namespace std;

int main() {
    int a[50], n, key, i;
    cout<<"===== Swornim Maharjan =====\n"; 
    cout<<"=== Linear Search ===\n";
    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter element to search: ";
    cin>>key;

    for(i=0;i<n;i++) {
        if(a[i]==key) {
            cout<<"Element found at position "<<i+1;
            return 0;
        }
    }

    cout<<"Element not found";
}
