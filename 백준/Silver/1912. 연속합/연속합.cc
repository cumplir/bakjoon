#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int answer = -1000;
	int* arr = new int[N];
	int* dp = new int[N];
	int max_val = -1000;
	memset(dp, 0, N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	answer = arr[0];
	max_val = arr[0];
	for (int i = 1; i < N; i++) {//선택할 길이
		if (answer + arr[i] > arr[i]) {
			answer = answer + arr[i];
		}
		else {
			answer = arr[i];
		}
		max_val = max(max_val, answer);
	}
	cout << max_val << endl;
}