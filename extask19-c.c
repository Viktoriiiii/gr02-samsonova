#include <stdio.h>
#include <string.h>

int main()
{
    int nq;
    printf("how many questrions? input: ");
    scanf("%d", &nq);
    
    FILE *f = fopen("extask19-c-test.txt", "a");
    fprintf(f, "%d\n", nq);
    
    int i = 0;
    do
    {
        int corr;
        int nans; 
        char gg[2];
        printf("how many answer options and correct answer number: ");
        scanf("%d %d", &nans, &corr);
        scanf("%c", gg);
        fprintf(f, "%d %d\n", nans, corr);
        
        char que[100];
        printf("write questions %d: ", i+1);
        fgets(que, 100, stdin);
        fprintf(f, "%s", que);
        
        for (int j = 0; j < nans; j++)
        {
            char answ[25];
            printf("option %d: ", j+1);
            fgets(answ, 25, stdin);
            fprintf(f, "%s", answ);
        }
        i++;
    }
    while (i < nq);
    
    fclose(f);
    
    return 0;
}
