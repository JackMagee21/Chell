#include "inputs.h"

char *read_line(void){
    size_t cap = 128; // Num of allocated bytes
    size_t length = 0; // Num of bytes used so far

    char *buf = malloc(cap);

    if(buf == NULL) return NULL;

    int c; // Declared as an int due to getchar() returns as an int

    while((c = getchar()) != EOF && c != '\n'){ // Reads the char
        
        // Checks if there is still room for the next character
        if(length + 1 >= cap) {
            cap *= 2;
            char *tmp = realloc(buf, cap);

            // Checks if the tmp is null and if so free's from the heap and returns NULL
            if(tmp == NULL){
                free(buf);
                return NULL;
            }

            buf = tmp;
        }
        // Writes the character we read from the buffer position and switchs it into a char
        buf[length++] = (char)c;
    }

    if(c == EOF && length == 0) {
        free(buf);
        return NULL;
    }

    buf[length] = '\0';
    return buf;
}

void parse_input(char* input, char** args){
    int i = 0;

    args[i] = strtok(input, " ");

    while(args[i] != NULL && i < 1023){
        i++;
        args[i] = strtok(NULL, " ");
    }
}