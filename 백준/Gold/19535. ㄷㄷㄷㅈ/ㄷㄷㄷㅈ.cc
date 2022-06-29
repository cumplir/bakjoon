#include<iostream>
#include<vector>
#include<utility>

using namespace std;
int N;
int dp[300001][4];
int dsum = 0,gsum=0;
vector<int> v[300001];
vector<int> tree[300001];
void makeTree(int cur, int parent);

void input() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	makeTree(1, 0);
	for (int i = 1; i <= N; i++) {
		int cnt=v[i].size();
		dp[i][0] = 1;
		if (cnt >= 3) {
			gsum += ((cnt * (cnt - 1) * (cnt - 2))/6);
		}
	}
}


void makeTree(int cur,int parent) {
	for (int i = 0; i < v[cur].size(); i++) {
		if (v[cur][i] == parent) continue;
		tree[cur].push_back(v[cur][i]);
		makeTree(v[cur][i], cur);
	}
}

void dfs(int cur,int parent) {
	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		dfs(next,cur);
		dsum += (tree[next].size() * (tree[cur].size()-1));
	}
	for (int i = 0; i < 3; i++) {
		dp[parent][i+1] += dp[cur][i];
	}
	dsum += dp[cur][3];
}

int main() {
	input();
	dfs(1, 0);
	int D = dsum, G = 3*gsum;
	if (D == G)
		cout << "DUDUDUNGA" << endl;
	if (D > G)
		cout << "D" << endl;
	if (D < G)
		cout << "G" << endl;
}