#include <iostream>
using namespace std;

int main() {
    int a[50], n, key;
    int low=0, high, mid;
    
    cout<<"===== Swornim Maharjan =====\n";
    cout<<"=== Binary Search ===\n";

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter sorted elements:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter element to search: ";
    cin>>key;

    high=n-1;

    while(low<=high) {
        mid=(low+high)/2;

        if(a[mid]==key) {
            cout<<"Element found at position "<<mid+1;
            return 0;
        }
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }

    cout<<"Element not found";
}
