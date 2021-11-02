#include <stdio.h>
#include <stdlib.h>

int days_of_month;
int pmin, pmax, pnorm;
int pressure[31];

void key()
{
    for (int i = 0; i < days_of_month; i++)
            scanf("%d", &pressure[i]);
}

void file()
{
    FILE *f = fopen("extask06-in.txt", "r");
    
    if (f == NULL) puts("failed to open file.");
    else
    {
        for (int i = 0; i < days_of_month; i++)
            fscanf(f, "%d", &pressure[i]);
    }
    fclose(f);
}

void randomno()
{
    printf("arr: ");
    for (int i = 0; i < days_of_month; i++)
    {
        if (i % 7 == 0) printf("\n");
        pressure[i] = pmin + rand() % (pmax - pmin + 1);
        printf("%d ", pressure[i]);
    }
    printf("\n");
}

int main()
{
    do
    {
        printf("days_of_month(1-31): ");
        scanf("%d", &days_of_month);
    }
    while (days_of_month <= 0 || days_of_month > 31);
    
    do
    {
        printf("pmin: ");
        scanf("%d", &pmin);
    }
    while (pmin <=0 || pmin > 1000);

    do
    {
        printf("pmax: ");
        scanf("%d", &pmax);
    }
    while (pmax <=0 || pmax > 1000);

    do
    {
        printf("pnorm: ");
        scanf("%d", &pnorm);
    }
    while (pnorm <=0 || pnorm > 1000);
    
    int choice;
    do
    {
        printf("1 - enter array from keyboard\n");
        printf("2 - input array from file\n");
        printf("3 - enter an array randomly\n");
        printf("choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: key(); break;
            case 2: file(); break;
            case 3: randomno(); break;
        }
        printf("\n");
    }
    while (choice < 1 || choice > 3);

    int below = 0;
    int exact = 0;
    int above = 0;
    
    int choice1;
    int day;
    int a = -1;
    printf("remove an array element?(1 - yes, 2 - no)\n");
    scanf("%d", &choice1);
    if (choice1 == 1)
    {
        printf("enter the day: ");
        scanf("%d", &day);
        pressure[day-1] = a;
    }
    else printf("without changes\n");
    
    printf("arr: ");
    for (int i = 0; i < days_of_month; i++)
    {
        if (i % 7 == 0) printf("\n");
        printf("%d ", pressure[i]);
    }
    printf("\n");
    
    for (int i = 0; i < days_of_month; i++)
    {
        if (pressure[i] > a)
        {
            if (pressure[i] < pnorm) below++;
            if (pressure[i] == pnorm) exact++;
            if (pressure[i] > pnorm) above++;
        }
    }

    printf("below: %d\n", below);
    printf("exact: %d\n", exact);
    printf("above: %d\n", above);

    choice1 = 0;
    printf("sort the array?(1 - yes, 2 - no)\n");
    scanf("%d", &choice1);
    if (choice1 == 1)
    {
        for(int i = 1; i < days_of_month; i++)
        for (int j = 0; j < days_of_month - 1; j++)                
        {
            if (pressure[j] > pressure[j + 1])
                {
                    int t = pressure[j];
                    pressure[j] = pressure[j + 1];
                    pressure[j + 1] = t;
                }
        }
        printf("sorted array");
        for (int i = 0; i < days_of_month; i++)
        {
            if (i % 7 == 0) printf("\n");
            printf("%d ", pressure[i]);
        }
        printf("\n");
    }
    else printf("the array was not sorted\n"); 

    return 0;
}
