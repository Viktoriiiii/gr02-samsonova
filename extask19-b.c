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

#define max_name 30

struct student
{
    char last_name[max_name];
    int n_group;
};

#define max_quest 10
struct quest test[max_quest];

#define n_students
struct student stud;

int main()
{
    FILE *fs = fopen("extask19-out-result.txt", "w+");
    
    printf("input your lastname: ");
    scanf("%s", stud.last_name);
    
    printf("input your group number: ");
    scanf("%d", &stud.n_group);
    
    fprintf(fs, "%s %d ", stud.last_name, stud.n_group);
    
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
    
    int g_result = 0;
    for (int i = 0; i < nq; i++)
    {
        printf("%s", test[i].txt);
        for (int j = 0; j < test[i].nans; j++)
            printf("%s", test[i].ans[j]);
        int c;
        scanf("%d", &c);
        fprintf(fs, "%d ", c);
        if (c == test[i].corr)
        {
            g_result++;
            puts("correct!");
        }
        else puts("wrong!");
    }
    
    printf("correct answer = %d\n", g_result);
    fprintf(fs, "correct answer = %d\n", g_result);
    
    fclose(fs);
    return 0;
}
