# include <stdio.h>
# include <stdlib.h>

#define LINE_LENGTH 1024

int main() {
    FILE *filePointer = fopen("repeated.txt", "r");

    char buffer[LINE_LENGTH];
    int lines = 0, words = 0;
    char lastChar = ' ';

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
    {
        lines++;

        for (size_t i = 0; buffer[i] != '\0'; i++)
        {
            const char current = buffer[i];
            
            if ((current == ' ' || current == '\n' || current == '\t') &&
                (lastChar != ' ' && lastChar != '\n' && lastChar != '\t'))
            {
                words++;
            }

            lastChar = current;
        }
        
    }

    if (lastChar != ' ' && lastChar != '\n' && lastChar != '\t')
    {
        words++;
    }


    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);

    return 0;
}