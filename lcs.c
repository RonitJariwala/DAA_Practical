#include<stdio.h>
#include<string.h>
#include<conio.h>

int i, j, m, n, c[10][10];
char x[10], y[10], b[10][10];

void print(int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'c') {
        print(i - 1, j - 1);
        printf("%c", x[i - 1]);
    } else if (b[i][j] == 'u')
        print(i - 1, j);
    else
        print(i, j - 1);
}

void lcs() {
    m = strlen(x);
    n = strlen(y);
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 0; j <= n; j++)
        c[0][j] = 0;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
}

void main(){
    printf("Enter 1st sequence:");
    scanf("%s", x);
    printf("Enter 2nd sequence:");
    scanf("%s", y);
    printf("\nTHE LONGEST COMMON SUBSEQUENCE:");
    lcs();
    print(m, n);
    getch();
}
