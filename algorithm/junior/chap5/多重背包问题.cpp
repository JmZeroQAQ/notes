#include <iostream>
#include <algorithm>

using namespace std;
const int N = 11010;

int n, m;
int v[N], w[N];
int f[2020];

int main() {
    cin >> n >> m;
    
    int a, b, c, cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        
        int k = 1;
        while (c - k >= 0) {
            v[++cnt] = a * k;
            w[cnt] = b * k;
            c -= k;
            k <<= 1;
        }
        
        if (c != 0) {
            v[++cnt] = a * c;
            w[cnt] = b * c;
        }
    }
    
    n = cnt;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;
    return 0;
}
