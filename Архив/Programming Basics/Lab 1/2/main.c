#include <stdio.h>

int main() {
    printf ("(a) %hu\n", 2-3) ;
    printf ("(b) %-4cd%3i\n", 65 , 'A') ;
    printf ("(c) %-7i %c\n" ,12389 , 'a') ;
    printf ("(d) %4.2f\n" ,345.789) ;
    printf ("(e) %#o, %#X\n" ,345 , 345) ;
    printf ("(f) %f\n", .019278912) ;
    printf ("(g) %e\n", .0019278912e-1) ;
    printf ("(h) %g\n", .019278912) ;
    printf ("(i) %8.2f\n", 19.915) ;
    printf ("(j) %8.2e\n", 19.915) ;
    printf ("(k) %8g\n", 19.915) ;
    return 0;
}
