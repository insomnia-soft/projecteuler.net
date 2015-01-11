/*
    projecteuler.net

    Longest Collatz sequence
    Problem 14

    The following iterative sequence is defined for the set of positive integers:

    n → n/2 (n is even)
    n → 3n + 1 (n is odd)

    Using the rule above and starting with 13, we generate the following sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

    It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

    Which starting number, under one million, produces the longest chain?

    NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	unsigned long i;
	unsigned long max_loops = 0;
	unsigned long max_number = 0;
	unsigned long loop;
	unsigned long broj;

	for (i = 1; i <= 1000000; i++) {
		broj = i;
		loop = 0;

		while (broj != 1) {
			if (broj % 2 == 0) {
				broj /= 2;
            } else {
				broj = broj * 3 + 1;
            }

			loop++;
		}

		if (loop > max_loops) {
			max_loops = loop;
			max_number = i;

			printf("loops: %5d     number: %5d\n", max_loops, i);
		}
	}

	printf("max_number: %d\n", max_number);

	system("PAUSE");
	return 0;
}
