#include <stdio.h>
#include <string.h>

int row_count;

struct table_row
{
    char title[50];
    char mfg[100];
    int year;
    int price;
};

void check(char *pp)
{
    char *p = strchr(pp, '\n');
    if (p != NULL) *p = 0;
    p = strchr(pp, '\r');
    if (p != NULL)  *p = 0;
}

void input_row_k()
{
    printf("input row_count: ");
    scanf("%d", &row_count);
}

void input_row_auto()
{
    row_count = 3;
}

void write_bi_keyboard(struct table_row * row)
{
    for (int i = 0; i < row_count; i++)
        {
            char ggg[2];
            scanf("%c", ggg);
            printf("Name %d: ", i+1);
            fgets(row[i].title, 50, stdin);
            check(row[i].title);
            
            printf("Company %d: ", i+1);
            fgets(row[i].mfg, 100, stdin);
            check(row[i].mfg);
            
            printf("Year %d: ", i+1);
            scanf("%d", &row[i].year);
            
            printf("Price %d: ", i+1);
            scanf("%d", &row[i].price);
        }
    FILE *f = fopen("extask22.bin", "wb+");
    fwrite(row, sizeof(struct table_row), row_count, f);
    fclose(f);
}

void write_bi_auto(struct table_row * row) // filling in the file
{
    strcpy(row[0].title, "Video Adapter");
    strcpy(row[0].mfg, "Nvidia");
    row[0].year = 2020;
    row[0].price = 40000;
    
    strcpy(row[1].title, "Hard Drive");
    strcpy(row[1].mfg, "Western Digital");
    row[1].year = 2019;
    row[1].price = 5000;
    
    strcpy(row[2].title, "Sound Card");
    strcpy(row[2].mfg, "Realtek");
    row[2].year = 2015;
    row[2].price = 1000;
    
    FILE *f = fopen("extask22.bin", "wb+");
    fwrite(row, sizeof(struct table_row), row_count, f);
    fclose(f);
}

void read_b(struct table_row * row)  // read from file
{
    FILE *ff = fopen("extask22.bin", "rb+");
    fread(row, sizeof(struct table_row), row_count, ff);
    fclose(ff);
}

void write_txt(struct table_row * row)  // write in .txt file
{
    FILE *fff = fopen("extask22-b-out.txt", "w+");
    for (int i = 0; i < row_count; i++)
        fprintf(fff, "%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
    fclose(fff);
}

void show_table(struct table_row * row)
{
    for (int i = 0; i < row_count; i++)
        printf("%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
}

void query(struct table_row * row)
{
    char gg[2];
    scanf("%c", gg);
    char query[50];
    printf("query: ");
    fgets(query, 50, stdin);
    
    char *p = strchr(query, '\n');
    if (p != NULL) *p = 0;
    p = strchr(query, '\r');
    if (p != NULL)  *p = 0;
    
    for (int i = 0; i < row_count; i++)
        if (strcmp(row[i].title, query) == 0) puts(row[i].mfg);
}

int main()
{  
    int choice1;
    do
    {
        printf("1 - write data to binary file auto\n");
        printf("2 - write data to binary file from the keyboard\n");
        printf("choice: "); 
        scanf("%d", &choice1);
        switch (choice1)
        {
            case 1: input_row_auto(); break;
            case 2: input_row_k(); break;
        }
    }
    while (choice1 != 1 && choice1 != 2);
    
    struct table_row row[row_count];

    if (choice1 == 1) write_bi_auto(row);
    if (choice1 == 2) write_bi_keyboard(row); 

    int choice;
    do
    {
        printf("0 - exit\n");        
        printf("1 - read from binary file\n");
        printf("2 - write data to txt file\n");
        printf("3 - show table contents\n");
        printf("4 - query\n");
        printf("choice: ");        
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: read_b(row); break;
            case 2: write_txt(row); break;
            case 3: show_table(row); break;
            case 4: query(row); break;
        }
        printf("\n");
    }
    while (choice != 0);
    
    return 0;
}
