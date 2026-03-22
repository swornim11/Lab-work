#include <iostream>
using namespace std;

void print(int a[], int n) {
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
}

void heapify(int a[], int n, int i) {
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    int temp;

    if(left<n && a[left]>a[largest])
        largest=left;

    if(right<n && a[right]>a[largest])
        largest=right;

    if(largest!=i) {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}

int main() {
    int a[50], n, i, temp;

    cout << "===== Swornim Maharjan =====\n";
    cout << "=== Heap Sort ===\n";

    cout << "Enter number of elements: ";
	cin >> n;

    for(i=0;i<n;i++)
        cin >> a[i];

    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(i=n-1;i>=0;i--) {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;

        heapify(a,i,0);

        cout << "Pass: ";
        print(a,n);
    }

    return 0;
}
