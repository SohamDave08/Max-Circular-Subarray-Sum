#include <bits/stdc++.h>
using namespace std;

int KadaneAlgorithm(int A[], int n)
{
    int maxCurr = 0;
    int maxGlobal = INT_MIN;

    for(int i=0; i<n; i++)
    {
        maxCurr = max(A[i], maxCurr+A[i]);
        if(maxCurr > maxGlobal)
            maxGlobal = maxCurr;
    }
    return maxGlobal;
}

int main()
{
    int n; cin>>n;
    int A[n];
    for(int i=0; i<n; i++)
        cin>>A[i];

    int WrapSum;
    int NonWrapSum;
    int TotalSum = 0;

    NonWrapSum = KadaneAlgorithm(A, n);

    for(int i=0; i<n; i++)
    {
        TotalSum += A[i];
        A[i] = -A[i];
    }

    WrapSum = TotalSum + KadaneAlgorithm(A, n);

    int ANSWER = max(WrapSum, NonWrapSum);
    cout<<ANSWER;
    return 0;
}