#include <iostream>
using namespace std;

int main() {
    int hash[10]={-1};
    int key, index, n;
    cout<<"===== Swornim Maharjan =====\n";
    cout<<"=== Hashing ===\n";
    cout<<"Enter number of elements: ";
    cin>>n;

    for(int i=0;i<n;i++) {
        cout<<"Enter key: ";
        cin>>key;

        index = key % 10;
        hash[index] = key;
    }

    cout<<"Hash Table:\n";
    for(int i=0;i<10;i++)
        cout<<i<<" -> "<<hash[i]<<endl;
}
