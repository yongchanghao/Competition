#include <bits/stdc++.h>

using namespace std;

bitset<50000> a[10][10];

void solve() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j].reset();
        }
    }

    vector<vector<int>> b(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> b[i][j];
            b[i][j]--;
            a[j][b[i][j]].set(i);
        }
    }

    for (int i = 0; i < N; i++) {
        bitset<50000> c;
        c.set();

        int _ans = 0;
        for (int j = 0; j < M; j++) {
            c &= a[b[i][j]][j];
            if (c.any()) _ans++;
            else break;
        }
        cout << _ans;
        if (i != N - 1) cout << " ";
        else cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
}