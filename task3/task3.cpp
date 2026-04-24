#include <iostream>

using namespace std;

using int64 = long long;
using i128 = __int128_t;

// НОД
int64 gcdll(int64 a, int64 b) {
    return b == 0 ? a : gcdll(b, a % b);
}

// печать i128
void printInt128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x > 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (b == 1) {
        cout << "infinity";
        return 0;
    }

    // Стирлинг S(n,k)
    vector<vector<int64>> S(a + 1, vector<int64>(a + 1, 0));
    S[0][0] = 1;

    for (int n = 1; n <= a; n++) {
        for (int k = 1; k <= n; k++) {
            S[n][k] = S[n - 1][k - 1] + k * S[n - 1][k];
        }
    }

    vector<int64> fact(a + 1, 1);
    for (int i = 1; i <= a; i++) fact[i] = fact[i - 1] * i;

    int64 B = b, BB = b - 1;

    i128 num = 0;

    for (int k = 1; k <= a; k++) {
        if (S[a][k] == 0) continue;
        i128 term = (i128)S[a][k] * fact[k] * B;

        // (b-1)^(a-k)
        i128 p = 1;
        for (int i = 0; i < a - k; i++) p *= BB;

        term *= p;
        num += term;
    }

    i128 den = 1;
    for (int i = 0; i < a + 1; i++) den *= BB;

    int64 g = gcdll((int64)num, (int64)den);
    num /= g;
    den /= g;

    printInt128(num);
    cout << "/";
    printInt128(den);

    return 0;
}