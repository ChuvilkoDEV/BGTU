#include <stdio.h>

int main() {
    char a;             // [-128; 127]
    unsigned char b;    // [0; 255]
    signed int c;       // [-2 147 483 648; 2 147 483 647]
    unsigned int d;     // [0; 4 294 967 295]
    short int e;        // [-32 768; 32767]
    unsigned short f;   // [0; 65535]
    long long g;        // ~9 * e18
    unsigned long long h;  // ~18 * e18
    scanf("%c %c %d %u %hd %hu %lld %llu", &a, &b, &c, &d, &e, &f, &g, &h);
    printf("%c %c %d %u %hd %hu %lld %llu", a, b, c, d, e, f, g, h);
    return 0;
}
