#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 1999999999
using namespace std;
typedef long long ll;
vector<ll> v;
int N, C;
ll tmp = MAX;

bool func(int d) {
	ll sum = 0;
	int cnt = 1;
	tmp = MAX;
	for (int i = 1; i < v.size(); i++) {
		sum += v[i] - v[i - 1];
		if (sum >= d){
			tmp = min(tmp,sum);
			sum = 0;
			cnt++;
		}	
	}
	if (cnt >= C) return true;//값이 작다 -> l= mid+1
	return false;
}
int main() {

	ll ans=0;
	int num;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll l = 1 ,r= v[v.size()-1]-v[0];
	while (l <= r) {
		ll mid = (l+r) / 2;
		if (func(mid)) {
			l = mid + 1;
			ans = tmp;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}