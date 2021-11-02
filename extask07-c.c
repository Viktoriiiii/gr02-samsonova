#include <stdio.h>
#include <stdlib.h>

#define m_max 100
int n;
int *mark;

#define mmin 2
#define mmax 5

float avg_att(int *a, int n)
{
    float avg = 0.0f;
    float sum = 0.0f;
    
    for (int i = 0; i < n; i++)
        sum += mark[i];
    
    avg = sum / n;
    
    return avg;
}

void print()
{
    do
    {
        printf("enter the number of grades certificate: ");
        scanf("%d", &n);
    }
    while (n < 0 || n > m_max);
    mark = (int *) malloc(n * sizeof(int));
}

void key()
{
    print();
    for (int i = 0; i < n; i++)
    {
        printf("grade %d: ", i + 1);
        int temp = 0;
        scanf("%d", &temp);
        if (temp > 1 && temp < 6)
            mark[i] = temp;
        else
        {
            printf("valid range of values [2; 5]\n");
            i--;
        }
    }
}

void file()
{
    n = 10;
    mark = (int *) malloc(n * sizeof(int));
    FILE *f = fopen("extask07-in.txt", "r");
    
    if (f == NULL) puts("failed to open file.");
    else
    {
        for (int i = 0; i < n; i++)
            fscanf(f, "%d", &mark[i]);
    }
    fclose(f);
}

void randomno()
{
    print();
    printf("arr: ");
    for (int i = 0; i < n; i++)
    {
        mark[i] = mmin + rand() % (mmax - mmin + 1);
        printf("%d ", mark[i]);
    }
    printf("\n");
}

int main()
{   
    int choice;
    printf("entering the grades of the certificate\n");
    do
    {
        printf("1 - input from keyboard\n");
        printf("2 - input from file\n");
        printf("3 - input randomly\n");
        printf("choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: key(); break;
            case 2: file(); break;
            case 3: randomno(); break;
        }
      //  printf("\n");
    }
    while (choice < 1 || choice > 3); 
    
    float avg_in;
    do
    {
        printf("enter avg university: ");
        scanf("%f", &avg_in);
    }
    while (avg_in <= 0 || avg_in > 5);

    float avg = avg_att(mark, n);
    printf("yurs avg: %.2f\n", avg);
    
    if (avg >= avg_in)
        printf("Congratulations, with an avg of %.2f you are entering the university!\n", avg);
    else
        printf("Unfortunately, with an avg of %.2f, you will not go to university.\n", avg);
    
    free(mark);
    return 0;
}

