#include <stdio.h>
#include <stdlib.h>

#define vmin 10
#define vmax 20

int n, m;

void show(int a[n][m])
{
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
            printf("%d\t", a[y][x]);
        printf("\n");
    }
    printf("\n");
}

void fill_one(int a[n][m])
{
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            a[y][x] = vmin + rand() % (vmax - vmin + 1);
    printf("\nfirst: \n");
    show(a);    
}

void fill_two(int b[n][m])
{
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            b[y][x] = vmin + rand() % (vmax - vmin + 1);
    
    printf("\nsecond: \n");
    show(b);
}

void add(int c1[n][m], int a[n][m], int b[n][m])
{
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            c1[y][x] = a[y][x] + b[y][x];

    printf("\nadd: \n");
    show(c1);
}

void sub(int c2[n][m], int a[n][m], int b[n][m])
{
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            c2[y][x] = a[y][x] - b[y][x];

    printf("\nsub: \n");
    show(c2);
}

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

    int choice = 0;
    do
    {
        printf("0 - exit\n");
        printf("1 - fill 1 array with random and show\n");
        printf("2 - fill 2 array with random and show\n");
        printf("3 - show add\n");
        printf("4 - show sub\n");
        printf("choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: fill_one(a); break;
            case 2: fill_two(b); break;
            case 3: add(c1, a, b); break;
            case 4: sub(c2, a, b); break;
        }
    }
    while (choice != 0);

    return 0;
}
