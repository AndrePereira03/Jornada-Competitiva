#include <bits/stdc++.h>

using namespace std;

bool palindromo(long long n)
{
    int bin[64];
    int aux = 0;

    while (n > 0) {
        bin[aux++] = n % 2;
        n /= 2;
    }
    
    for (int i = 0; i < aux / 2; i++) {
        if (bin[i] != bin[aux - 1 - i])
            return false;
    }
    return true;
}

int main() {
    long long int n;
    scanf("%lld", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    while (!palindromo(n)) {
        n--;
    }

    cout << n << endl;
    return 0;
}