#include <bits/stdc++.h> 

using namespace std;

int N, K;
int A[100], B[100];
int arr[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
    }

    for(int i = 0 ; i < K ; i++)
    {
        for(int j = A[i]; j <= B[i]; j++)
        {
            arr[j]++;
        }
    }
    int mx = INT_MIN;
    for(int i = 0 ; i < N ; i++)
    {
        mx = max(mx, arr[i]);
    }

    cout << mx;

    return 0;
}