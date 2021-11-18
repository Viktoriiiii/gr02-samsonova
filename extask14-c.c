// поиск по проценту
// успешный поиск - всю инфу о счете вывести

// run with gcc extask14-c.c --std=c99 -Wno-deprecated-declarations && (cat extask14-c-in.txt | ./a.out)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record
{
    int acc;
    char fio[32];
    float sum;
    int prc;
    float res;
};

#define rows 3
struct record tab[rows];

void input1()
{
    int count = 0;
    int n = 0;
    char tem[100];
    printf("input № account: ");
    fgets(tem, 10, stdin);
    count = atoi(tem);
    for (int i = 0; i < rows; i++)
    {
        if (tab[i].acc == count)
        {
            printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio, tab[i].sum, tab[i].prc, tab[i].res);
            n++;
        }        
    }    
    if (n < 1) printf("not found\n");
}

void input2()
{
    printf("input lastname: ");
    char query[50];
    fgets(query, 50, stdin);
    char *p = strchr(query, '\n');
    if (p != NULL) *p = 0;
    p = strchr(query, '\r');
    if (p != NULL)  *p = 0;
    
    int n = 0;
    for (int i = 0; i < rows; i++)
    {
        char temp[50];
        strcpy(temp, tab[i].fio);
        char *p = strtok(temp, " ");
        if (strcmp(query, p) == 0) 
        {
            printf("\n");
            printf("%s\t%d\t%.2f\t%d\t%.2f\n", tab[i].fio, tab[i].acc, tab[i].sum, tab[i].prc, tab[i].res);
            n++;
        }
    }
    if (n < 1) printf("not found\n");    
}

void input3()
{
    int count = 0;
    int n = 0;
    char tem[100];
    printf("bank percent: ");
    fgets(tem, 10, stdin);
    count = atoi(tem);
    for (int i = 0; i < rows; i++)
    {
        if (tab[i].prc == count)
        {
            printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio, tab[i].sum, tab[i].prc, tab[i].res);
            n++;
        }        
    }    
    if (n < 1) printf("not found\n");
}

int main()
{
    char tmp[32];
    for (int i = 0; i < rows; i++)
    {
        printf("[record %d]\n", i);
        
        printf("acc: ");
        gets(tmp);
        tab[i].acc = atoi(tmp);

        printf("fio: ");
        gets(tab[i].fio);
        
        printf("sum: ");
        gets(tmp);
        tab[i].sum = atof(tmp);
        
        printf("%%: ");
        gets(tmp);
        tab[i].prc = atoi(tmp);

        printf("\n");
    }
    
    for (int i = 0; i < rows; i++)
        tab[i].res = tab[i].sum + (tab[i].sum + tab[i].prc) * 0.12f;

    for (int i = 0; i < rows; i++)
        printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio, tab[i].sum, tab[i].prc, tab[i].res);
    
    int choise = 0;
    char te[10];
    do
    {        
        char te[10];
        printf("0 - exit\n");
        printf("1 - № счета\n");
        printf("2 - fio\n");
        printf("3 - bank percent\n");
        printf("search: ");
        fgets(te, 10, stdin);
        choise = atoi(te);
        switch(choise)
        {
            case 1: input1(); break;
            case 2: input2(); break;
            case 3: input3(); break;
        }
    }
    while(choise != 0);

    return 0;
}
