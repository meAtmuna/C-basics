# include <stdio.h>
# include <stdlib.h>

#define LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    
    if (argc < 2)
    {
        printf("Usage: word_counter <fileName>\n");
        
        return 1;
    }

    char *fileName = argv[1];
    
    FILE *filePointer = fopen(fileName, "r");

    if (filePointer == NULL)
    {
        printf("Error: could not open file\n");
        return 1;
    }
    
    char buffer[LINE_LENGTH];
    int lines = 0, words = 0, maxLineLength = 0;
    char lastChar = ' ';

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
    {
        lines++;

        int currentLength = 0;
        
        for (size_t i = 0; buffer[i] != '\0'; i++)
        {
            const char current = buffer[i];
            
            currentLength++;     
            
            if ((current == ' ' || current == '\n' || current == '\t') &&
            (lastChar != ' ' && lastChar != '\n' && lastChar != '\t'))
            {
                words++;
            }
                         
            lastChar = current;
        }
        
        if (currentLength > maxLineLength)
        {
            maxLineLength = currentLength;
        }
    }

    if (lastChar != ' ' && lastChar != '\n' && lastChar != '\t')
    {
        words++;
    }


    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Longest line: %d characters\n", maxLineLength);

    fclose(filePointer);

    return 0;
}