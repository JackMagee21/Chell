#include <stdio.h>
#include "inputs.h"


char input[1023];

int main() {
    while(input != "exit"){
        printf("> ");
        printf(read_line());
        printf("\n");

    }
    return 0;
}