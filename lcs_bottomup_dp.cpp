#include <iostream>
#include <cstring>
#define MAX(a,b) (a)>(b) ? (a) : (b)
#define MAX_LENGTH 101
using namespace std;

int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH];


int lengthLCS(char a[], char b[], int m, int n)
{
    int i, j;
    for (i=0; i<=m; i++)
        L[i][0]=0;
    for (i=0; i<=n; i++)
        L[0][i]=0;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        {
            if (a[i-1]==b[j-1]){
                L[i][j] = L[i-1][j-1]+1;
                S[i][j] = 0;
            }
            else{
                L[i][j] = MAX(L[i][j-1], L[i-1][j]);
                if (L[i][j] == L[i][j-1]){
                    S[i][j] = 1;
                }else
                    S[i][j] = 2;
            }
        }
    return L[m][n];
}

void printLCS(char a[], char b[], int m, int n)
{
    if (m==0 || n==0)
        return;
    if(S[m][n] == 0)
    {
        printLCS(a, b, m-1, n-1);
        printf("%c", b[n-1]);
    }
    else if (S[m][n] == 1)
        printLCS(a, b, m, n-1);
    else if (S[m][n] == 2)
        printLCS(a, b, m-1, n);
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char a[MAX_LENGTH], b[MAX_LENGTH];
        int m=0, n=0;
        cin >> a >> b;
        m=strlen(a);
        n=strlen(b);
        cout << lengthLCS(a,b,m,n) << " ";
        printLCS(a,b,m,n); cout << endl;
    }
}