#include <stdio.h>
#include <string.h> // strlen(), size_t
#include <ctype.h>

int main()
{
    char s[256];
    fgets(s, 256, stdin);
    
    char *p = strchr(s, '\n');
    if (p != NULL) p[0] = '\0';
    
    size_t n = strlen(s);
    
    printf("len: %ld\n", n);
    
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (n > 0 && i == 0) 
        {
            char d = toupper(s[0]);
            s[0] = d;
        }
           
//        printf("%d ", s[i]);
        if (s[i] == ' ') m++;
        if (s[i] == ' ' && i < n - 1)
        {
            char d = toupper(s[i + 1]);
            s[i + 1] = d;
        }
    }
    
    if (n > 0) m++;
    printf("words: %d\n", m);
    
    for (int i = 0; i < n; i++)
        printf("%c", s[i]);
    
    printf("\n");
    return 0;
}
