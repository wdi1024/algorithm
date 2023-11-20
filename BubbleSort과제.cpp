#include <stdio.h>
#define MAX_SIZE 1000

void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE], b[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &b[j]);
        copyArray(a, b, num);
        bubbleSort(a, num);
        copyArray(a, b, num);
        bubbleSortImproved1(a, num);
        copyArray(a, b, num);
        bubbleSortImproved2(a, num);
        printf("\n");
    }
    return 0; 
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}

/* BubbleSort 함수 */
void bubbleSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0; // swap 함수 실행 횟수
    for (int pass = 1; pass < n; pass++)
        for (int i=1; i<= n - pass; i++)
            if (countCmpOps++>=0 && a[i-1] > a[i])
            {
                swap(&a[i-1], &a[i]);
                countSwaps++;
            }
    // bubble sort 알고리즘 구현
    printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort 함수 - Improved Version 1 */ 
void bubbleSortImproved1(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0; // swap 함수 실행 횟수
    for (int pass = 1; pass < n; pass++)
    {
        bool swapped = false;
        for (int i=1; i<= n - pass; i++)
            if (countCmpOps++>=0 && a[i-1] > a[i])
            {
                swap(&a[i-1], &a[i]);
                countSwaps++;
                swapped=true;
            }
        if (swapped == false)
            break;
    }
    // bubble sort의 개선된 알고리즘 (1) 구현 
    printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort 함수 - Improved Version 2 */ 
void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0; // swap 함수 실행 횟수
    int lastSwappedPos = n;
    for (;lastSwappedPos > 0;)
    {
        int swappedPos = 0;
        for (int i = 1; i < lastSwappedPos; i++)
            if (countCmpOps++>=0 && a[i-1] > a[i])
            {
                swap(&a[i-1], &a[i]);
                countSwaps++;
                swappedPos = i;
            }
        
        lastSwappedPos = swappedPos;
    }
    // bubble sort의 개선된 알고리즘 (2) 구현 
    printf("%d %d ", countCmpOps, countSwaps);
}

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i]; 
}