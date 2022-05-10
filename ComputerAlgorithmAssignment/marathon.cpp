#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> p;

int N, M;
vector<p> vertex[26];
vector<string> answer;
bool visited[26] = {false, };

bool cmp(const p& e1, const p& e2) {
	return e1.second < e2.second;
}

void backtrack(char v, int dist, string path) {
	path.push_back(v);
	for (int i = 0; i < vertex[v - 'a'].size(); i++) {
		char next_v = vertex[v - 'a'][i].first;
		int next_w = vertex[v - 'a'][i].second;
		if (dist + next_w > 42) return;
		if (next_v == 'a' && dist + next_w == 42) {
			answer.push_back(path);
			return;
		}
		if (!visited[next_v - 'a']) {
			visited[next_v - 'a'] = true;
			backtrack(next_v, dist + next_w, path);
			visited[next_v - 'a'] = false;
		}
	}
}

string getAnsPath(const vector<string>& v) {
	string answer = "";
	for (auto i : v) {
		if (i.size() > answer.size())
			answer = i;
		else if (i.size() == answer.size())
			answer = i < answer ? i : answer;
	}
	return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	char v1, v2;
	int w;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> w;
		vertex[v1 - 'a'].push_back({ v2, w });
		vertex[v2 - 'a'].push_back({ v1, w });
	}
	for (int i = 0; i < 26; i++)
		sort(vertex[i].begin(), vertex[i].end(), cmp);

	visited[0] = true;
	backtrack('a', 0, "");
	if (answer.empty())
		cout << "None";
	else {
		string ans = getAnsPath(answer);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
	}
}
