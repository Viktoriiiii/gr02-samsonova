#include <stdio.h> // FILE, fopen(), fclose(), fgets()
#include <string.h> // strlen(), strcpy()

#define max_txt 256

struct letter 
{
    char let;
    int ind;
};

int main()
{
    FILE *f1 = fopen("extask21-a-in.txt", "r");
    FILE *f2 = fopen("extask21-c-out.txt", "w+");

    int i = 1;
    
    while (1)
    {
        char s[max_txt];
        if (fgets(s, max_txt, f1) == NULL) break;
        
        char *c = strchr(s, '\n');
        if (c != NULL) *c = '\0';
        
        fprintf(f2, "%d %s\n", i, s);
        i++;
    }
    fprintf(f2, "number of lines = %d", i-1);

    fclose(f1);    
    
    // counting characters
    struct letter let_count[256];
    
    for (int i = ' '; i <= '~'; i++)
    {
        let_count[i - ' '].let = i;
        let_count[i - ' '].ind = 0;
    }

    FILE *f3 = fopen("extask21-c-in.txt", "r");
    while (1)
    {
        char s[max_txt];
        if (fgets(s, max_txt, f3) == NULL) break;
        
        char *c = strchr(s, '\n');
        if (c != NULL) *c = '\0';
        
        int ls = strlen(s);
        for (int i = 0; i < ls; i++)
        {
            char c = s[i];
            for (int j = 0; j < 95; j++)
                if (c == let_count[j].let) let_count[j].ind++;
        }
    }
    fclose(f3);

    int min = let_count[0].ind;
    int max = let_count[0].ind;
    for (int i = 0; i < 95; i++)
    {
        if (let_count[i].ind > max) max = let_count[i].ind;
        if (let_count[i].ind < min && let_count[i].ind > 0) min = let_count[i].ind;    
        if (let_count[i].ind > 0)
            fprintf(f2, "\n%c - %d", let_count[i].let, let_count[i].ind);        
    }
    fprintf(f2, "\n");

    fprintf(f2, "least encountered characters: ");
    for (int i = 0; i < 95; i++)
        if (let_count[i].ind == min && let_count[i].ind > 0) fprintf(f2, " %c", let_count[i].let);
    
    fprintf(f2, "\n");
    fprintf(f2, "most common characters: ");
    for (int i = 0; i < 95; i++)
        if (let_count[i].ind == max  && let_count[i].ind > 0) fprintf(f2, " %c", let_count[i].let);

    fclose(f2);
    return 0;
}
