#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    #define month 12
    int salary[month];
    
    int inp;
    printf("select salary entry: 1 - random, 2 - keybord input\n");
    scanf("%d", &inp);
    
    if (inp == 1)
    {
        #define salary_low 1000
        #define salary_high 5000
        for (int i = 0; i < month; i++)
        {
            salary[i] = salary_low + rand() % (salary_high - salary_low + 1);
        }
    }
    else if (inp == 2)
    {
        for (int i = 0; i < month; i++)
        {
            int temp;
            do
            {
                printf("month %d: ", i+1);
                scanf("%d", &temp);
            }
            while (temp < 1000 || temp > 5001);
            salary[i] = temp;
        }
    }
    else printf("input is 1 or 2");
    
    for (int i = 0; i < month; i++)
        printf("%9d", i+1);

    printf("\n");
    
    for (int i = 0; i < month; i++)
        printf("%9d", salary[i]);
        
    printf("\n");
    float year_tax = 0.0f;
    for (int i = 0; i < month; i++)
    {
        float tax = salary[i] * 0.02f;
        year_tax += tax;
        printf("%9.2f", tax);
    }
    printf("\n");
    
    int year_sum = 0;
    for (int i = 0; i < month; i++)
        year_sum += salary[i];
    
    float year_avg = year_sum / (float) month;
    
    
    for (int i = 0; i < month; i++)
        printf("%9.2f", fabsf((float)salary[i] - year_avg));
    printf("\n");
        
    printf("year_sum = %d\n", year_sum);
    printf("year_avg = %.2f\n", year_avg);
    
    printf("year_tax = %.2f\n", year_tax);
    
    return 0;
}
