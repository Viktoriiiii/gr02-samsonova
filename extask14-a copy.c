// меню с поиском, по фио владельца или по номеру счета 1.24
// успешный поиск - всю инфу о счете вывести

// run with gcc extask13-a.c --std=c99 -Wno-deprecated-declarations && (cat extask13-a-in.txt | ./a.out)

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
    printf("input № account\n");
    scanf("%d", count);
    for (int i = 0; i < rows; i++)
        if (tab[i].acc == count)
        printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio, tab[i].sum, tab[i].prc, tab[i].res);

}

void input2()
{
    char tmp1[30];
    printf("fio: ");
    gets(tmp1);
}

int ch = 0;

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
    do
    {
        printf("search: \n");
        printf("0 - exit\n");
        printf("1 - № счета\n");
        printf("2 - fio\n");
        scanf("%d", &choise);
        switch(choise)
        {
            case 1: ch = 1; input1(); break;
            case 2: ch = 2; input2(); break;
        }
    }
    while(choise != 0)

    return 0;
}
