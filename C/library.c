#include<stdio.h>
#include<string.h>

#define DEFAULT "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

void addition() {
    int price, pages;
    char name[100], author[100], buffer;
    FILE *file = fopen("library.txt", "a");

    printf("\nEnter book name: ");
    gets(name);
    printf("Enter author name: ");
    gets(author);
    printf("Enter price: ");
    scanf("%d", &price);
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    fflush(stdin);

    if (!file) {
        printf("Error: Failed to save changes to library!\n");
        return;
    }
    
    fprintf(file, "\n%s\n%s\n%d %d", name, author, price, pages);
    printf("Book added to library successfully.\n");
    fclose(file);
}

int traverse(int display) {
    int price, pages, count = 0;
    char name[100], author[100], buffer;
    FILE *file = fopen("library.txt", "r");

    if (!file) {
        printf("Error: Failed to access library database!\n");
        return -1;
    }

    while (fgetc(file) != EOF) {
        count++;
        fscanf(file, "%[^\n] %[^\n] %d %d", name, author, &price, &pages);

        if(display)
            printf("\n{ "\
                GREEN"id"DEFAULT": "YELLOW"%d"DEFAULT", "\
                GREEN"name"DEFAULT": "YELLOW"%s"DEFAULT", "\
                GREEN"author"DEFAULT": "YELLOW"%s"DEFAULT", "\
                GREEN"price"DEFAULT": "YELLOW"%d"DEFAULT", "\
                GREEN"pages"DEFAULT": "YELLOW"%d"DEFAULT" }",\
                count, name, author, price, pages);
    }

    if(count == 0 && display)
        printf("Library is empty!");
    fclose(file);
    return count;
}

void alter(int modify) {
    int id, price, pages, mod_price, mod_pages, index = 0;
    char name[100], author[100], mod_name[100], mod_author[100];
    FILE *file1 = fopen("library.txt", "r");
    FILE *file2 = fopen("temp.txt", "w");

    if (!file1 || !file2) {
        printf("Error: Failed to access library database!\n");
        return;
    }

    printf("Enter book id: ");
    scanf("%d", &id);
    fflush(stdin);
    
    if(modify) {
        printf("\nEnter book name: ");
        gets(mod_name);
        printf("Enter author name: ");
        gets(mod_author);
        printf("Enter price: ");
        scanf("%d", &mod_price);
        printf("Enter number of pages: ");
        scanf("%d", &mod_pages);
        fflush(stdin);
    }

    while (fgetc(file1) != EOF) {
        index++;
        fscanf(file1, "%[^\n] %[^\n] %d %d", name, author, &price, &pages);
        if(id != index)
            fprintf(file2, "\n%s\n%s\n%d %d", name, author, price, pages);
        else if(modify)
            fprintf(file2, "\n%s\n%s\n%d %d", mod_name, mod_author, mod_price, mod_pages);
    }

    fclose(file1);
    fclose(file2);
    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (modify)
        printf("Book modified successfully.\n");
    else
        printf("Book deleted successfully.\n");
}

void main() {
    char choice = '\0';
    FILE *file = fopen("library.txt", "r");

    if (!file) {
        fclose(file);
        file = fopen("library.txt", "w");
    }
    
    fclose(file);
    printf("\t*** Library Management System ***\n");

    while (choice != '6') {
        printf("\n1: Add a Book; 2: Library Details; 3: Modify; 4: Delete; 5: Count; 6: Exit;");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);
        fflush(stdin);

        switch (choice) {
        case '1':
            addition();
            break;
        case '2':
            traverse(1) != -1 ? printf("\n") : -1;
            break;
        case '3':
            alter(1);
            break;
        case '4':
            alter(0);
            break;
        case '5':
            printf("No. of books: %d\n", traverse(0));
            break;
        case '6':
            printf("Program Terminated!\n");
            break;
        default:
            choice = (choice == '\n') ? ' ' : choice;
            printf("Warning: Invalid choice! %c is not a valid option!\n", choice);
        }
    }
}
