#include <stdio.h>
#define MAX_SIZE 1000

void combSort(int a[], int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &a[j]);
        combSort(a, num);
    }
    return 0; 
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}

/* comb sort 함수 */
void combSort(int a[], int n)
{
    int  gap = n, countCmpOps = 0, countSwaps = 0;  // 비교 연산자 실행 횟수 // swap 함수 실행 횟수
    float shrink = 1.3; 
    bool isSorted=false;

    while (isSorted == false)
    {
        gap = gap / shrink;
        if (gap <= 1)
        {
            gap = 1;
            isSorted = true;
        }
        int i = 0;
        while (i + gap < n)
        {
            countCmpOps++;
            if (a[i] > a[i + gap])
            {
                swap(&a[i], &a[i+gap]);
                countSwaps++;
                isSorted = false;
            }
            i++;
        }
    }


    printf("%d %d \n", countCmpOps, countSwaps);
}