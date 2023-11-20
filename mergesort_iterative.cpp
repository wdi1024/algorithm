#include <iostream>
#define MAX_SIZE 100
using namespace std;

int comp = 0;
void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];

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

void mergeSort(int a[], int n)
{
    int size = 1;
    while(size < n)
    {
        for (int i=0; i < n; i += 2*size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = (i+2*size-1 > n-1) ? (n-1) : (i+2*size-1);
            if (mid >= n-1)
                break;
            merge(a, low, mid, high);
        }
        size *= 2;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, a[MAX_SIZE];
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);
        mergeSort(a, n);
        printf("%d\n", comp);
        comp=0;
    }
}