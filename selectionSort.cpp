#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i,j,min_index;
    for(i=0;i<n-1;i++)
    {
        min_index = i;
        for (j=i+1;j<n;j++)
            if (arr[j]<arr[min_index])
                min_index = j;
        swap(&arr[min_index], &arr[i]);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int i,size;
    int *array;

    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<endl;
    array = new int[size];
    for(i=0;i<size;i++)
    {
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>array[i];
        cout<<endl;
    }

    selectionSort(array,size);
    printArray(array,size);
    return 0;
}

