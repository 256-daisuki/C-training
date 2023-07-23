#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

void saveFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (file) {
        fputs(content, file);
        fclose(file);
        printf("File saved successfully!\n");
    } else {
        printf("Failed to save file.\n");
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    char filename[100];
    char c;

    printf("Command Line Text Editor\n");
    printf("Press Ctrl + x to exit and Ctrl + s to save.\n");

    while (1) {
        printf("Enter text (Ctrl + x to exit, Ctrl + s to save):\n");

        int index = 0;
        while ((c = getchar()) != EOF && index < MAX_BUFFER_SIZE - 1) {
            buffer[index++] = c;

            // Check for Ctrl + x (exit)
            if (c == 24) { // 24 is the ASCII value of Ctrl + x
                printf("Exiting editor...\n");
                return 0;
            }

            // Check for Ctrl + s (save)
            if (c == 19) { // 19 is the ASCII value of Ctrl + s
                printf("Enter filename to save: ");
                scanf("%s", filename);
                buffer[index] = '\0'; // Null-terminate the content
                saveFile(filename, buffer);
                break;
            }
        }

        buffer[index] = '\0'; // Null-terminate the content
        printf("Text entered:\n%s\n", buffer);
    }

    return 0;
}
