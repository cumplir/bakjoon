#include <iostream>
using namespace std;

int N,answer=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    int **arr = new int* [N];
    int **dp = new int* [N];

    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
        dp[i] = new int[N];
        for (int j = 0; j < N; j++) {
            dp[i][j] = 0;
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int maxval = 0;
            for (int r = 0; r <=i; r++) 
                for (int c = 0; c <=j; c++) 
                    if (arr[r][c] < arr[i][j]) 
                        maxval = max(maxval, dp[r][c]);
            dp[i][j] = maxval + 1;
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer;
}