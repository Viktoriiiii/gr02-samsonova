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
    
    return 0;
}
