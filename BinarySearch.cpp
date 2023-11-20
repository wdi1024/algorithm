#include<iostream>
using namespace std;

int binary(int num[], int left, int right, int k) {
	if(left > right)
		return -1;

    else{
        int half = (left + right) / 2;
        if (k == num[half])
            return half;
        else if (k > num[half])
            return binary(num, half + 1, right, k);
        else
            return binary(num, left, half - 1, k);
    }
}


int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        int l, n;
        scanf("%d %d",&l, &n);
        int num[100];
        for (int i=0; i<l; i++)
            scanf("%d", &num[i]);
        printf("%d\n", binary(num, 0, l-1, n));
    }
}