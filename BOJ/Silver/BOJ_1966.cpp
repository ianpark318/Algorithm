#include <bits/stdc++.h>
using namespace std;

int T, N, M;

deque<pair<int, int>> printer;

int findMax() {
    int Max = -987654321;
    for(auto e : printer) {
        if(e.second > Max) Max = e.second;
    }
    return Max;
}

int main() {
    cin >> T;
    int seq;
    for(int i = 0; i < T; i++) {
        int seq = 1;
        printer.clear();
        cin >> N >> M;
        for(int j = 0; j < N; j++) {
            int p;
            cin >> p;
            printer.push_back({j, p});
        }
        while(!printer.empty()) {
            int maxprio = findMax();
            if(printer.front().second < maxprio) {
                pair<int, int> temp = {printer.front().first, printer.front().second};
                printer.pop_front();
                printer.push_back(temp);
            }
            else {
                if(printer.front().first == M)
                    cout << seq << endl;
                printer.pop_front();
                seq++;
            }
        }
    }
}
