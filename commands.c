#include "commands.h"

void cmd_echo(char **args) {
    for(int i = 1; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
}

void cmd_ls(char **args) {
    pid_t pid = fork();

    if(pid < 0){
        perror("fork");
        return;
    }

    if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}


void handle_command(char **args) {
    if(args[0] == NULL) return;

    if(strcmp(args[0], "echo") == 0) {
        cmd_echo(args);
    }

    if(strcmp(args[0], "ls") == 0) {
        cmd_ls(args);
    }
}
