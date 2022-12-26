#include <iostream>
#include<vector>
using namespace std;

vector<int> v;
int* arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (arr[i] > v[v.size() - 1]) {
			v.push_back(arr[i]);
		}
		else {
			int m = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[m] = arr[i];
		}
	}
	cout << v.size();
}