#include "commands.h"
#include "inputs.h"
#include "colors.h"

char *input;
char *args[1024];


void print_dir() {
    char cwd[1024];

    if(getcwd(cwd, sizeof(cwd)) == NULL){
        perror("cwd failed");
        exit(0);
    }

    printf("%s%s", BOLD_BLUE, cwd);
}

int main() {
    while(1){
        print_dir();
        printf(">%s ", WHITE);
        input = read_line();
        parse_input(input, args);
        handle_command(args);
        printf("\n");
    }
    return 0;
}