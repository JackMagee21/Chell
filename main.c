#include "commands.h"
#include "inputs.h"


char *input;
char *args[1024];

int main() {
    while(input != "exit"){
        printf("> ");
        input = read_line();
        parse_input(input, args);
        handle_command(args);
        printf("\n");
    }
    return 0;
}