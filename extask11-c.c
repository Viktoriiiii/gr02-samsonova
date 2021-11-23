
#include <stdio.h>
#include <stdlib.h>

int main()
{
    #define rows 25
    #define cols 5
    
    int tab[rows][cols];
    
    #define mark0 2
    #define mark1 5
    
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            tab[y][x] = mark0 + rand() % (mark1 - mark0 + 1);
    
    float avg[cols];
    
    for (int x = 0; x < cols; x++)
    {
        int s = 0;
        for (int y = 0; y < rows; y++)
            s += tab[y][x];
        avg[x] = s / (float) rows;
    }
    
    printf("\033[1;31mnum");
    for (int x = 0; x < cols; x++)
        printf("\t%d", x + 1);
    printf("\n");
    for (int y = 0; y < rows; y++)
    {
        printf("\033[1;35m%d\033[0m", y + 1);
        for (int x = 0; x < cols; x++)
            printf("\t%d", tab[y][x]);
        printf("\n");
    }

    printf("\033[1;31mavg\033[0m");
    for (int x = 0; x < cols; x++)
            printf("\t\033[1;32m%.2f\033[0m", avg[x]);
    printf("\n");

    printf("\033[1;31mworst average: \033[0m");
    float min = avg[0];
    for (int x = 0; x < cols; x++)
        if (avg[x] < min) min = avg[0];

    for (int x = 0; x < cols; x++)
        if (min == avg[x]) printf("\n\033[1;34m%d subject with avg = %.2f\033[0m", x+1, min);

    printf("\n");

    printf("\033[1;31msub\t2\t3\t4\t5\033[0m\n");
    for (int x = 0; x < cols; x++)
    {        
        int two = 0;
        int three = 0;
        int four = 0;
        int five = 0;
        for (int y = 0; y < rows; y++)
        {
            int co = tab[y][x];
            switch (co)
            {
                case 2: two++; break;
                case 3: three++; break;
                case 4: four++; break;
                case 5: five++; break;
            }        
        }
        printf("\033[1;35m%d\033[0m\t%d\t%d\t%d\t%d\n", x+1, two, three, four, five);
        two = 0; three = 0; four = 0; five = 0;        
    }   

    return 0;
}
