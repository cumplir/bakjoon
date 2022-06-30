#include<iostream>

using namespace std;

int segmentTree[1500001];
int tmp[1000001];
int N;
long long inputseg(int l, int r, int sl, int sr, int node);
void update(int node, int l, int r, int idx);
void input(){
	int a;
	cin >> N;
	long long sum = 0;
	for (int i = 1; i <=N; i++) {
		cin >> a;
		tmp[a] = i;
	}
	for (int i = 1; i <=N; i++) {
		cin >> a;
		sum+=inputseg(1, N, tmp[a]+1,N,1);
		update(1,1,N,tmp[a]);
	}
	cout << sum << endl;
}

long long inputseg(int l, int r, int sl, int sr,int node) {
	//cout << node << endl;
	long long answer = 0;
	if (sl > r || sr < l) return 0;
	if (sl <= l && r <= sr) {
		answer= segmentTree[node];
		return answer;
	}
	int mid = (l + r) / 2;
	answer= inputseg(l, mid, sl, sr, node * 2) + inputseg(mid + 1, r, sl, sr, node * 2 + 1);
	return answer;
}

void update(int node, int l, int r, int idx) {
	if (l <= idx && idx <= r) {
		segmentTree[node] += 1;
		if (l!= r) {
			int mid = (l + r) / 2;
			update(node * 2, l, mid, idx);
			update(node * 2 + 1, mid + 1, r, idx);
		}
	}
}

void print() {
	for (int i = 1; i < 2 * N; i++)
		cout << segmentTree[i] << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
}