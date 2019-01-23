/*
    projecteuler.net
    
    Maximum path sum I
    Problem 18

    By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

    3
    7 4
    2 4 6
    8 5 9 3

    That is, 3 + 7 + 4 + 9 = 23.

    Find the maximum total from top to bottom of the triangle below:

    75
    95 64
    17 47 82
    18 35 87 10
    20 04 82 47 65
    19 01 23 75 03 34
    88 02 77 73 07 63 67
    99 65 04 28 06 16 70 92
    41 41 26 56 83 40 80 70 33
    41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
    70 11 33 28 77 73 17 78 39 68 17 57
    91 71 52 38 17 14 91 43 58 50 27 29 48
    63 66 04 68 89 53 67 30 73 16 69 87 40 31
    04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

    NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

#include <stdio.h>
#define MAX_ROWS 100
#define LINE 10000

int strlength(char *a) {
    int i = 0;
    for (i = 0; *(a + i) != 0; i++);
    return i;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char row[LINE];
    int i, j;
    int rows = 0;
    int curr_row = 0;
    int curr_col = 0;
    int triangle[MAX_ROWS][MAX_ROWS] = {0};
    
    fp = fopen("p018_triangle.txt", "r");
    
    if (fp == NULL) {
        printf("can't open file 'p018_triangle.txt'\n");
        return 0;
    }
    
	while (fgets(row, LINE, fp) != NULL) {
        rows++;
        for (i = 0; i < strlength(row); i++) {
            if (row[i] >= 48 && row[i] <= 57) {
                triangle[curr_row][curr_col] = triangle[curr_row][curr_col] * 10 + row[i] - 48;
            } else {
                curr_col++;
            }
        }
        curr_col = 0;
        curr_row++;
    }
    
    for (i = 1; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0) {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (j < i) {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            else {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
        }
    }

    j = 0;
    for (i = 0; i < rows; i++) {
        if (triangle[rows - 1][i] > j) {
            j = triangle[rows - 1][i];
        }
    }
    
    printf("max = %d\n", j);

    return 0;
}
