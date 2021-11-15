#include <stdio.h>
#include <string.h>

// run with gcc extask13-a.c --std=c99 -Wno-deprecated-declarations && (cat extask13-a-in.txt | ./a.out)

struct record
{
    char fio[32];
    char cat[48];
    char num[24];
    char inf[64];
};

#define rows 3
struct record tab[rows];

int main()
{
    for (int i = 0; i < rows; i++)
    {
        printf("[record %d]\n", i);
        
        printf("fio: ");
        gets(tab[i].fio);
        
        printf("cat: ");
        gets(tab[i].cat);
        
        printf("num: ");
        gets(tab[i].num);
        
        printf("inf: ");
        gets(tab[i].inf);
        printf("\n");

    }
    
    printf("\n");

    for (int i = 0; i < rows; i++)
        printf("%s\t%s\t%s\t%s\n", tab[i].fio,tab[i].cat, tab[i].num, tab[i].inf);
    
    printf("search lastname: \n");
    char fio[32];
    gets(fio);

    int n = 0;
    for (int i = 0; i < rows; i++)
    {
        char *p = strtok(tab[i].fio, " ");
        if (strcmp(p, fio) == 0)
        {
            printf("%s\n", tab[i].num);
            printf("%s\n", tab[i].inf);
            n++;
        }
    }

    if (n < 1) printf("not found\n");    

    printf("search for category: \n");
    char cat[32];
    gets(cat);

    n = 0;
    for (int i = 0; i < rows; i++)
    {
        char *p = strtok(tab[i].cat, " ");
        if (strcmp(p, cat) == 0)
        {
            printf("%s\t%s\n", tab[i].fio, tab[i].num);
            n++;
        }
    }
    if (n < 1) printf("not found\n");

    return 0;
}
