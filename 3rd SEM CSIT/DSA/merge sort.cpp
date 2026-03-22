#include <iostream>
using namespace std;

int a[50], n;

void print() {
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
}

void merge(int low, int mid, int high) {
    int i=low, j=mid+1, k=low;
    int temp[50];

    while(i<=mid && j<=high) {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i<=mid)
        temp[k++] = a[i++];

    while(j<=high)
        temp[k++] = a[j++];

    for(i=low;i<=high;i++)
        a[i] = temp[i];

    print();
}

void mergesort(int low, int high) {
    if(low < high) {
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

int main() {

    cout << "===== Swornim Maharjan =====\n";
    cout << "=== Merge Sort ===\n";

    cout << "Enter number of elements: ";
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];

    mergesort(0,n-1);

    return 0;
}
