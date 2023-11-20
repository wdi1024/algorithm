#include <iostream>
#include <cstring>
#define MAX(a,b) (a)>=(b) ? (a) : (b)
#define MAX_LENGTH 101
using namespace std;

char a[10], b[10];

int lcs(char a[], char b[], int m, int n)
{
    if (m==-1 || n==-1)
        return 0;
    else if (m>=0 && n>=0 && a[m]==b[n]){
        return lcs(a,b,m-1,n-1)+1;
    }else if (m>=0 && n>=0 && a[m]!=b[n]){
        int i=lcs(a,b,m,n-1), j=lcs(a,b,m-1,n);
        return MAX(i,j);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m=0, n=0;
        cin >> a >> b;
        m=strlen(a);
        n=strlen(b);
        cout << lcs(a,b,m-1,n-1) << endl;
    }
}


/*
#include <iostream>
#include <cstring>
#define MAX(a,b) (a)>=(b) ? (a) : (b)
using namespace std;

int lcs(string a, string b, int m, int n)
{
    if (m==0 || n==0)
        return 0;
    else if (a[m-1]==b[n-1]){
        return lcs(a,b,m-1,n-1)+1;
    }else{
        int i=lcs(a,b,m,n-1), j=lcs(a,b,m-1,n);
        return MAX(i,j);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        int m=0, n=0;
        cin >> a >> b;
        m=a.length();
        n=b.length();
        cout << lcs(a,b,m,n) << endl;
    }
}
*/