#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long int modInverse(long long int a, long long int m) {
    a = a % m;
    for (long long int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}
long long int power(long long int x, long long int y, long long int p) {
    long long int res = 1; 
    x = x % p; 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p; 
        y = y >> 1; 
        x = (x * x) % p; 
    }
    return res;
}
void generateKeys(long long int p, long long int q) {
    long long int n = p * q;
    long long int phi = (p - 1) * (q - 1);
    long long int e = 2;
    
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }
    long long int d = modInverse(e, phi);
    printf("Public Key: (e: %lld, n: %lld)\n", e, n);
    printf("Private Key: (d: %lld, n: %lld)\n", d, n);
}
long long int encrypt(long long int msg, long long int e, long long int n) {
    return power(msg, e, n);
}
long long int decrypt(long long int cipher, long long int d, long long int n) {
    return power(cipher, d, n);
}
int main() {
    long long int p = 61, q = 53; 
    generateKeys(p, q);
    long long int msg = 65; 
    long long int e = 17;
    long long int n = p * q; 
    long long int cipher = encrypt(msg, e, n);
    printf("Encrypted Message: %lld\n", cipher);
    long long int d = 413; 
    long long int decryptedMsg = decrypt(cipher, d, n);
    printf("Decrypted Message: %lld\n", decryptedMsg);
    return 0;
}
