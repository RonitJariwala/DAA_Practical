#include<stdio.h>
#include<conio.h>
int main() {
    int a[2][2], b[2][2], c[2][2], i, j, p, q, r, s, t, u, v;

    printf("\nEnter elements for 1st matrix:\n");
    for(i = 0; i < 2; i++) {
	for(j = 0; j < 2; j++) {
	    scanf("%d", &a[i][j]);
	}
    }

    printf("Matrix 1 is:\n");
    for(i = 0; i < 2; i++) {
	for(j = 0; j < 2; j++) {
	    printf("%d\t", a[i][j]);
	}
	printf("\n");
    }

    printf("\nEnter elements for 2nd matrix:\n");
    for(i = 0; i < 2; i++) {
	for(j = 0; j < 2; j++) {
	    scanf("%d", &b[i][j]);
	}
    }

    printf("Matrix 2 is:\n");
    for(i = 0; i < 2; i++) {
	for(j = 0; j < 2; j++) {
	    printf("%d\t", b[i][j]);
	}
	printf("\n");
    }

    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q = b[0][0] * (a[1][0] + a[1][1]);
    r = a[0][0] * (b[0][1] - b[1][1]);
    s = a[1][1] * (b[1][0] - b[0][0]);
    t = (a[0][0] + a[0][1]) * b[1][1];
    u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    v = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = p + s - t + v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p + r - q + u;

    printf("\nProduct achieved using Strassen matrix is:\n");
    for(i = 0; i < 2; i++) {
	for(j = 0; j < 2; j++) {
	    printf("%d\t", c[i][j]);
	}
	printf("\n");
    }
    getch();
    return 0;
}
