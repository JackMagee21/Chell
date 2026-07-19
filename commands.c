#include "commands.h"

void cmd_echo(char **args) {
    for(int i = 1; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
}


void handle_command(char **args) {
    if(args[0] == NULL) return;

    if(strcmp(args[0], "echo") == 0) {
        cmd_echo(args);
    }
}
