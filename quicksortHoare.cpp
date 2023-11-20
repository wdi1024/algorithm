#include <iostream>

using namespace std;

int hswap=0, hcp=0;
int lswap=0, lcp=0;

void swap(int * a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}

int partition_Hoare(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    do
    {
        do {
            i+=1;
        }while (hcp++>=0 && a[i] < pivot);
        do {
            j-=1;
        } while (hcp++>=0 && a[j] > pivot);
        if (i < j){
            swap(&a[i], &a[j]);
            hswap++;
        }
        else
        {
            return j;
        }
    }while (true);
}

void quicksort_h(int a[], int low, int high)
{
    if (low >= high)
        return;
    int p = partition_Hoare(a, low, high);
    quicksort_h(a, low, p);
    quicksort_h(a, p+1, high);
}

int partition_Lomuto(int a[], int low, int high)
{
    int pivot = a[low];
    int j = low;
    for (int i=low+1; i<=high; i++)
    {
        if (lcp++>=0 && a[i] < pivot){
            j+=1;
            swap(&a[i], &a[j]);
            lswap++;
        }
    }
    int pivot_pos = j;
    swap(&a[pivot_pos], &a[low]);
    lswap++;
    return pivot_pos;
}

void quicksort_l(int a[], int low, int high)
{
    if (low >= high)
        return;
    int p = partition_Lomuto(a, low, high);
    quicksort_l(a, low, p-1);
    quicksort_l(a, p+1, high);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[1000], b[1000];
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for (int i=0; i<n; i++)
            b[i] = a[i];
        quicksort_h(a, 0, n-1);
        quicksort_l(b, 0, n-1);
        printf("%d %d %d %d\n", hswap, lswap, hcp, lcp);
        hswap = lswap = hcp = lcp = 0;
    }
}