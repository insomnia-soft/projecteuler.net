/*
    projecteuler.net

    Highly divisible triangular number
    Problem 12

    The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

    Let us list the factors of the first seven triangle numbers:

         1: 1
         3: 1,3
         6: 1,2,3,6
        10: 1,2,5,10
        15: 1,3,5,15
        21: 1,3,7,21
        28: 1,2,4,7,14,28

    We can see that 28 is the first triangle number to have over five divisors.

    What is the value of the first triangle number to have over five hundred divisors?
*/


#include <stdio.h>
#include <stdlib.h>

int divisors_count(int broj) {
    int i = 1;
    int count = 0;

    while (i <= broj) {
        if (broj % i == 0) {
            count++;
        }
        i++;
    }

    if (count > 500) {
        return 1;
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    int count = 0;
    int i = 1;
    int tmp = 0;

    printf("Please wait.\n");

    do {
        tmp += i;
        i++;
    } while (!divisors_count(tmp));

    printf("%d\n", tmp);
    system("PAUSE");
    return 0;
}
