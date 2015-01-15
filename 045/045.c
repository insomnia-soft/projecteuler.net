/*
    projecteuler.net

    Triangular, pentagonal, and hexagonal
    Problem 45

    Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
    Triangle 	  	Tn=n(n+1)/2 	  	1, 3, 6, 10, 15, ...
    Pentagonal 	  	Pn=n(3n−1)/2 	  	1, 5, 12, 22, 35, ...
    Hexagonal 	  	Hn=n(2n−1) 	  	1, 6, 15, 28, 45, ...

    It can be verified that T285 = P165 = H143 = 40755.

    Find the next triangle number that is also pentagonal and hexagonal.
*/

#include <stdio.h>
#include <math.h>
#define MAX 100000000

int is_natural(long double n) {
    if (n - (int) n) {
        return 0;
    }

    return 1;
}

int is_pentagonal(long long n) {
    return is_natural((sqrt(24 * n + 1) + 1) / 6);
}

int is_hexagonal(long long n) {
    return is_natural((sqrt(8 * n + 1) + 1) / 4);
}

int main(int argc, char *argv[]) {
    long long i;
    long long tr;
    int counter = 0;

    for (i = 1; i < MAX; i++) {
        tr = i * (i + 1) / 2;

        if (is_pentagonal(tr) && is_hexagonal(tr)) {
            printf("%lld\n", tr);
            counter++;

            if (counter >= 3) {
                break;
            }
        }
    }

    system("PAUSE");
    return 0;
}
