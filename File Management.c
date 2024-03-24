#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w"); // Open file in write mode
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File created successfully: %s\n", filename);
    fclose(file); // Close the file
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) // Attempt to delete the file
        printf("File deleted successfully: %s\n", filename);
    else
        printf("Unable to delete the file.\n");
}

void displayFile(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Contents of %s:\n", filename);
    int c;
    while ((c = fgetc(file)) != EOF) // Read characters until end of file
        putchar(c); // Print character to standard output
    fclose(file); // Close the file
}

void modifyFile(const char *filename) {
    FILE *file = fopen(filename, "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter text to append (type 'EOF' on a new line to finish):\n");
    char text[1000];
    while (fgets(text, sizeof(text), stdin) != NULL && strcmp(text, "EOF\n") != 0) {
        fprintf(file, "%s", text); // Append text to file
    }
    fclose(file); // Close the file
}

int main() {
    char filename[100];
    char choice;

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Display contents of a file\n");
        printf("4. Modify contents of a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == '5') {
            printf("Exiting...\n");
            break;
        }

        printf("Enter the filename: ");
        scanf("%s", filename);

        switch(choice) {
            case '1':
                createFile(filename);
                break;
            case '2':
                deleteFile(filename);
                break;
            case '3':
                displayFile(filename);
                break;
            case '4':
                modifyFile(filename);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}



