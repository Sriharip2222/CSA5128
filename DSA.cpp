#include <stdio.h>
#include <stdlib.h>
int modexp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int modinv(int a, int m) {
    for (int x = 1; x < m; x++) if ((a * x) % m == 1) return x;
    return -1;
}
int main() {
    int p = 23, q = 11, h = 2;
    int g = modexp(h, (p - 1) / q, p);  
    int x = 6;                          
    int y = modexp(g, x, p);          
    printf("Public key (y): %d\n", y);
    int k = 4;  
    int r = modexp(g, k, p) % q;
    if (r == 0) { printf("Invalid r\n"); return 0; }
    int m = 9;
    int k_inv = modinv(k, q);
    int s = (k_inv * (m + x * r)) % q;
    if (s == 0) { printf("Invalid s\n"); return 0; }
    printf("Signature: (r=%d, s=%d)\n", r, s);
    int w = modinv(s, q);
    int u1 = (m * w) % q;
    int u2 = (r * w) % q;
    int v = ((modexp(g, u1, p) * modexp(y, u2, p)) % p) % q;
    if (v == r)
        printf("Signature is VALID\n");
    else
        printf("Signature is INVALID\n");

    return 0;
}