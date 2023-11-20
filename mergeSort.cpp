#include <iostream>

using namespace std;

int comp = 0;

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[high+1];

    for (i=low; i<=high; i++)
        tmp[i] = a[i];
    
    i = k = low;
    j = mid+1;
    while (i<=mid && j<=high)
    {
        if (comp++>=0 && tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }
    while (i<=mid)
        a[k++] = tmp[i++];
    while (j<=high)
        a[k++] = tmp[j++];
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if (low == high)
        return;
    
    mid = (low + high) / 2;

    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);
        mergeSort(a, 0, n-1);
        printf("%d\n", comp);
        comp=0;
    }
    return 0;
}