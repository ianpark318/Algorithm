#include <bits/stdc++.h>
using namespace std;

int A[50], B[50];
int N;

bool desc(int a, int b) {
    return a > b;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >>  A[i];
    for(int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A+N);
    sort(B, B+N, desc);

    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += A[i] * B[i];

    cout << sum;
}
