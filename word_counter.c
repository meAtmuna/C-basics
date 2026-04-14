#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINE_LENGTH 1024

int main(int argc, char *argv[]) {

    clock_t start = clock();

    if (argc >= 2 &&(strcmp(argv[1], "--help") == 0))
    {
        printf("Usage: word_counter <file1> <file2> ...\n");
        printf("Features:\n");
        printf("- Counts lines and words\n");
        printf("- Shows longest line\n");
        printf("- Supports multiple files\n");

        return 0;
    }
    
    
    if (argc < 2)
    {
        printf("Usage: word_counter <fileName>\n");
        
        return 1;
    }

    char *targetWord = NULL;
    
    if (argc >= 3)
    {
        targetWord = argv[argc -1];
    }
    
    int fileLimit = argc;

    if (targetWord)
    {
        fileLimit = argc - 1;
    }
    
    for (int i = 1; i < fileLimit; i++)
    {   
        FILE *filePointer = fopen(argv[i], "r");
        
        if (filePointer == NULL)
        {
            printf("Error opening %s\n", argv[i]);
            continue;
        }
        
        char buffer[LINE_LENGTH];
        int lines = 0, words = 0, maxLineLength = 0;
        char lastChar = ' ';
        
        int targetCount = 0;

        char word[100];
        int index = 0;
        
        while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
        {
            lines++;
    
            int currentLength = 0;
            
            for (size_t j = 0; buffer[j] != '\0'; j++)
            {
                const char current = buffer[j];
                
                currentLength++;     
                if (current != ' ' && current != '\n' && current != '\t')
                {
                    word[index++] = current;
                }
                else
                {
                    if (index > 0)
                    {
                        word[index] = '\0';
        
                        if (targetWord && strcmp(word, targetWord) == 0)
                        {
                            targetCount++;
                        }
                        
                        index = 0;
                    }
                    
                }
                
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
        
        printf("\nFile: %s\n", argv[i]);
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Longest line: %d characters\n", maxLineLength);

        if (targetWord)
        {
            printf("'%s' found: %d times\n", targetWord, targetCount);
        }
        
        fclose(filePointer);
    }
    
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", timeTaken);

    return 0;
}