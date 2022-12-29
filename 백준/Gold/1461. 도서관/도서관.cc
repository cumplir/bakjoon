#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MIN(a,b) (a<b)?a:b
int N, M , v1num,v2num;
int arr[51];
vector<int> v1;
vector<int> v2;
vector<int> ans;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < 0) {
			v2.push_back(arr[i]);
		}
		else {
			v1.push_back(-arr[i]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
}

void fund() {
	int sum = 0;
	for (int i = 0; i < v1.size();i++) {
		if (i % M == 0) {
			ans.push_back(v1[i]);
		}
	}

	for (int i = 0; i < v2.size();i++) {
		if (i % M == 0) {
			ans.push_back(v2[i]);
		}
	}
	sort(ans.begin(), ans.end());
	sum = -ans[0];
	for (int i = 1; i < ans.size(); i++) {
		sum += (-ans[i] * 2);
	}
	cout << sum << endl;
}
int main() {
	input();
	fund();
}
