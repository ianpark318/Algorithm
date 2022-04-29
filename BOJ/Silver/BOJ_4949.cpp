#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
        string str;
        stack<char> br;
        bool ans = true;
        getline(cin, str);
        if(str[0]=='.')
            break;
        for(int i = 0; i < str.size()-1; i++) {
            if(str[i] == '(' || str[i] =='[') br.push(str[i]);
            else if(str[i] == ')') {
                    if(br.empty() || br.top()=='[') {
                        ans = false;
                        break;
                    }
                    else
                       br.pop();
            }
            else if(str[i] == ']') {
                    if(br.empty() || br.top()=='(') {
                        ans = false;
                        break;
                    }
                    else
                       br.pop();
            }
        }
         if(br.empty() && ans)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
