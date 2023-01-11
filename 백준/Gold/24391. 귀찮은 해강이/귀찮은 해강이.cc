#include<iostream>
#include<vector>
using namespace std;
vector<int> v[100001];
bool visited[100001];
int dp[100001];
void dfs(int cur,int cnt)
{
	visited[cur] = true;
	dp[cur] = cnt;
	for (int i = 0; i < v[cur].size(); i++)
	{
		if(!visited[v[cur][i]])
			dfs(v[cur][i], cnt);
	}
}
int main()
{
	cin.tie(0);
	int N, M;
	int num;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt = 1;
	for (int i = 1; i <=N; i++)
	{
		if (dp[i] == 0)
		{
			dfs(i, cnt++);
		}
	}
	int answer = 0;
	int pre;
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
		{
			pre = num;
			cin >> num;
			if (dp[num] != dp[pre])
			{
				answer++;
			}
		}
		else
		{
			cin >> num;
		}
	}
	cout << answer << endl;
}