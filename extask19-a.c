#include <stdio.h> // FILE, fopen(), fclose(), fscanf(), fgers()

#define max_ans 5
#define max_txt 100

struct quest
{
    int corr;
    int nans;
    char txt[max_txt];
    char ans[max_ans][max_txt];
};

#define max_quest 10
struct quest test[max_quest];

int main()
{
    FILE *f = fopen("extask19-in.txt", "r");
    int nq;
    fscanf(f, "%d", &nq);
    
    for (int i = 0; i < nq; i++)
    {
        fscanf(f, "%d %d\n", &test[i].nans, &test[i].corr);
        fgets(test[i].txt, max_txt, f);
        for (int j = 0; j < test[i].nans; j++)
            fgets(test[i].ans[j], max_txt, f);
    }
    
    fclose(f);
    
    for (int i = 0; i < nq; i++)
    {
        printf("%s", test[i].txt);
        for (int j = 0; j < test[i].nans; j++)
            printf("%s", test[i].ans[j]);
        int c;
        scanf("%d", &c);
        if (c == test[i].corr) puts("correct!");
        else puts("wrong!");
    }
    
    return 0;
}
