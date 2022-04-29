#include <bits/stdc++.h>
using namespace std;

int N, M;
int minCost = 0;
vector<int> sixCost, oneCost;

int main() {
    cin >> N >> M;
    int sixStrings, oneString;
    for(int i = 0; i < M; i++) {
        cin >> sixStrings >> oneString;
        sixCost.push_back(sixStrings);
        oneCost.push_back(oneString);
    }
    sort(sixCost.begin(), sixCost.end());
    sort(oneCost.begin(), oneCost.end());
    minCost += sixCost[0] < 6*oneCost[0] ? sixCost[0] * (N/6) : 6*oneCost[0]*(N/6);
    minCost += sixCost[0] < (N%6)*oneCost[0] ? sixCost[0] : (N%6)*oneCost[0];

    cout << minCost;
}
