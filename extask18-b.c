#include <stdio.h> // fgets(), sprintf(), puts(), puts()
#include <string.h> // strchr(), strlen()
#include <stdlib.h>

int main()
{
    printf("input the string: ");
    char s[30];
    fgets(s, 30, stdin);
    
    char *n = strchr(s, '\n');
    if (n != NULL) *n = '\0';
    
    char d[100];
    int di = 0;
    
    char o = s[0]; // for matches
    int r = 0; // repeats
    
    int l = strlen(s);
    for (int i = 1; i <= l; i++)
    {
        char c = s[i];
        if (o == c) r++;
        else 
        {
            d[di] = o;
            di++;
        
            if (r > 0)
            {
                int w = sprintf(d + di, "%d", r + 1);
                di += w;
            }
            r = 0;
        }
        o = c;
    }
    
    d[di] = '\0';
    printf("compressed string: ");
    puts(d);
    
    printf("input the string to decompress: ");
    char sd[30]; // string to decompress
    fgets(sd, 30, stdin);
    int ld = strlen(sd); // length string to decompress 
    
    char *nd = strchr(sd, '\n');
    if (nd != NULL) *nd = '\0';
    
    char dd[1000]; // decompressed string
    int ddi = 0;
    int i = 0;
    
    printf("decompressed string: ");
    while (1)
    {
        if (sd[i] == '\0') break;
        if ((sd[i] >= 'a' && sd[i] <= 'z') || (sd[i] >= 'A' && sd[i] <= 'Z'))
        {
            dd[ddi] = sd[i];
            i++;
            ddi++;
        }
        else 
        {
            int dig = 1;
            char didd[4];
            int j = -1;
            int rt = 0;
            while (dig > 0)
            {
                if (!((sd[i] >= 'a' && sd[i] <= 'z') || (sd[i] >= 'A' && sd[i] <= 'Z')))
                {
                    j++;
                    didd[j] = sd[i];                    
                    i++;
                    rt++;
                }
                else dig = 0;
                
            }
            int dddig = atoi(didd);
            for (int k = 1; k < dddig; k++)
            {
                dd[ddi] = sd[i-rt-1];
                ddi++;
            }
        }
    }
     //   если этот символ буква - выводим ее на экран.
     //   иначе (Если это цифра) - продолжаем считывать строку
     //   как только цифры кончаются, выводим букву столько раз, сколько насчитали цифр.
    int ldd = strlen(dd);
    for (int i = 0; i < ddi; i++)
        printf("%c", dd[i]);
    printf("\n");
    
    return 0;
}
