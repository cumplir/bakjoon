#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

#define INF 1e17
using namespace std;
int N;
int arr[81];
bool found = false;
bool CheckNum(int n) {
	for (int i = 1; i <= (n / 2); i++) {
		bool check = false;
		for (int j = 0; j < i; j++) {
			if (arr[n - j] != arr[n - i - j])//다른게 하나라도 있으면 길이 i에서는 좋은수열
				check = true;
		}
		if (!check) return false;//다른게 하나도 없는 경우
	}
	return true;
}

void solve(int cnt) {
	if (found) return;
	if(cnt>1&&!CheckNum(cnt-1)) return;
	if (cnt-1 == N) {
		found = true;
		for (int i = 1; i <= N; i++) cout << arr[i];
		return;
	}

	for (int i = 1; i < 4; i++) {
		arr[cnt] = i;
		solve(cnt + 1);
	}
}
int main() {
	cin >> N;
	solve(1);
}