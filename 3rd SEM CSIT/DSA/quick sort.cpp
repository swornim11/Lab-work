#include <iostream>
using namespace std;

int pass = 1;

void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
}

int partition(int a[], int low, int high, int n)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while(i <= j)
    {
        while(a[i] <= pivot && i <= high)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    cout << "Pass " << pass++ << ": ";
    printArray(a, n);

    return j;
}

void quickSort(int a[], int low, int high, int n)
{
    if(low < high)
    {
        int p = partition(a, low, high, n);
        quickSort(a, low, p-1, n);
        quickSort(a, p+1, high, n);
    }
}

int main()
{
    int a[50], n, i;

    cout << "===== Swornim Maharjan =====\n";
    cout << "=== Quick Sort ===\n";

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(i=0;i<n;i++)
        cin >> a[i];

    quickSort(a,0,n-1,n);


    return 0;
}
