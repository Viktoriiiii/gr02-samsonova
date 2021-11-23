#include <stdio.h>
#include <stdlib.h>

int n, m;

int main()
{
    do
    {
        printf("n (cols), m (rows) (from 1 to 10): ");
        scanf("%d %d", &n, &m);
    }
    while (n<1 || n>10);

    int a[m][n];
    int b[m][n];

    int c1[m][n];
    int c2[m][n];

    #define vmin 10
    #define vmax 20

    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
        {
            a[y][x] = vmin + rand() % (vmax - vmin + 1);
            b[y][x] = vmin + rand() % (vmax - vmin + 1);
        }

    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
        {
            c1[y][x] = a[y][x] + b[y][x];
            c2[y][x] = a[y][x] - b[y][x];
        }

    printf("first: \n");
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
            printf("%d\t", a[y][x]);
        printf("\n");
    }

    printf("second: \n");
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
            printf("%d\t", b[y][x]);
        printf("\n");
    }

    printf("add: \n");
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
            printf("%d\t", c1[y][x]);
        printf("\n");
    }

    printf("sub: \n");
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
            printf("%d\t", c2[y][x]);
        printf("\n");
    }
    return 0;
}
