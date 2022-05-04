#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];

int main() {
	int M, N;
	cin >> M >> N;
	for(int i = 2; i <= N; i++)
        prime[i] = true;
	for (int i = 2; i <= sqrt(N); i++) {
	    if(prime[i] == false) continue;
	    int j = 2;
		while(i*j <= N) {
            prime[i*j] = false;
            j++;
		}
	}
    for(int i = M; i <= N; i++) {
        if(prime[i])
            printf("%d\n", i);
    }
	return 0;
}
