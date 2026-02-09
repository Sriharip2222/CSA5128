#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int main() {
    long long p = 23; 
    long long g = 5;  
    long long a = 6; 
    long long b = 15; 
    long long A = power(g, a, p); 
    long long B = power(g, b, p); 
    long long secretA = power(B, a, p); 
    long long secretB = power(A, b, p); 
    printf("Alice's public key: %lld\n", A);
    printf("Bob's public key: %lld\n", B);
    printf("Shared secret computed by Alice: %lld\n", secretA);
    printf("Shared secret computed by Bob: %lld\n", secretB);
    return 0;
}
