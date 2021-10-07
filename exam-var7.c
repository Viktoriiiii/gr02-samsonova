#include <stdio.h>
#include <stdlib.h>

float avgAtt(int *a, int n);

int main()
{
    int n;
    float pass = 4.6f;
    do
    {
        printf("Введите пожалуйста количество оценок аттестата: ");
        scanf("%d", &n);
    }
    while (n < 0 || n > 50);
    
    int *att = (int *) malloc(n * sizeof(int));
    
    printf("Ввод оценок аттестата\n");
    for (int i = 0; i < n; i++)
    {
        printf("Оценка %d: ", i + 1);
        int temp = 0;
        scanf("%d", &temp);
        if (temp > 1 && temp < 6)
                    att[i] = temp;
        else
        {
            printf("Допустимый диапазон значений [2; 5]\n");
            i--;
        }
    }
    
    float ball = avgAtt(att, n);
    printf("Средний балл аттестата: %.2f\n", ball);
    
    if (ball >= 4.6f)
        printf("Поздравляем, со средним баллом %.2f Вы поступите в университет!\n", ball);
    else
        printf("К сожалению, со средним баллом %.2f Вы не поступите в университет.\n", ball);
    
    free(att);
    return 0;
}

float avgAtt(int *a, int n)
{
    float avg = 0.0f;
    float sum = 0.0f;
    
    for (int i = 0; i < n; i++)
        sum += a[i];
    
    avg = sum / n;
    
    return avg;
}