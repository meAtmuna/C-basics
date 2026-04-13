# include <stdio.h>
# include <stdlib.h>

#define LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    
    if (argc < 2)
    {
        printf("Usage: word_counter <fileName>\n");
        
        return 1;
    }  
    
    for (int i = 1; i < argc; i++)
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
    
        while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
        {
            lines++;
    
            int currentLength = 0;
            
            for (size_t j = 0; buffer[j] != '\0'; j++)
            {
                const char current = buffer[j];
                
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
        
        printf("\nFile: %s\n", argv[i]);
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Longest line: %d characters\n", maxLineLength);
        
        fclose(filePointer);
    }

    return 0;
}