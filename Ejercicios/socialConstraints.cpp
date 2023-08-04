#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define maxN 22

int n, m, p[10];
int a[maxN], b[maxN], c[maxN];

bool accepted() {
    for (int i = 0; i < m; i++) {
        if (c[i] > 0 && abs(p[a[i]] - p[b[i]]) > c[i])
            return false;
        if (c[i] < 0 && abs(p[a[i]] - p[b[i]]) < -c[i])
            return false;
    }
    return true;
}

int main() {
    while (cin >> n >> m && (n + m)) {
        for (int i = 0; i < m; i++)
            cin >> a[i] >> b[i] >> c[i];
        for (int i = 0; i < n; i++)
            p[i] = i;
        int res = 0;
        do {
            if (accepted()) res++;
        } while (next_permutation(p, p + n));
        cout << res << endl;
    }
    return 0;
}
