#include <stdio.h>
#include <stdlib.h>

#define vmin 10
#define vmax 20

int n, m;
int **a;
int **b;
int **c1;
int **c2;

void show(int **e)
{
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
            printf("%d\t", e[y][x]);
        printf("\n");
    }
    printf("\n");
}

void fill_one()
{
    for (int y = 0; y < m; y++)
    {
        a[y] = (int *)malloc(m*sizeof(int));
        for (int x = 0; x < n; x++)
            a[y][x] = vmin + rand() % (vmax - vmin + 1);
    }
    printf("\nfirst: \n");
    show(a);    
}

void fill_two()
{
    for (int y = 0; y < m; y++)
    {
        b[y] = (int *)malloc(m*sizeof(int));
        for (int x = 0; x < n; x++)
            b[y][x] = vmin + rand() % (vmax - vmin + 1);
    }    
    printf("\nsecond: \n");
    show(b);
}

void add()
{
    for (int y = 0; y < m; y++)
    {
        c1[y] = (int *)malloc(m*sizeof(int));
        for (int x = 0; x < n; x++)
            c1[y][x] = a[y][x] + b[y][x];
    }
    printf("\nadd: \n");
    show(c1);
}

void sub()
{
    for (int y = 0; y < m; y++)
    {
        c2[y] = (int *)malloc(m*sizeof(int));
        for (int x = 0; x < n; x++)
            c2[y][x] = a[y][x] - b[y][x];
    }
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

    a = (int **)malloc(n*sizeof(int *));
    b = (int **)malloc(n*sizeof(int *));
    c1 = (int **)malloc(n*sizeof(int *));
    c2 = (int **)malloc(n*sizeof(int *));
    
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
            case 1: fill_one(); break;
            case 2: fill_two(); break;
            case 3: add(); break;
            case 4: sub(); break;
        }
    }
    while (choice != 0);

    for(int i = 0; i < n; i++) 
    {
        free(a[i]);
        free(b[i]);
        free(c1[i]);
        free(c2[i]);
    }
    free(a);
    free(b);
    free(c1);
    free(c2);

    return 0;
}
