#include "commands.h"


void cmd_echo(char **args) {
    for(int i = 1; args[i] != NULL; i++) {
        printf("%s", args[i]);
        if(args[i + 1] != NULL) {
            printf(" ");
        }
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

void cmd_mkdir(char **args) {
    if(args[1] == NULL){
        printf("name for directory is currently empty: mkdir <name>");
        return;
    }
    if(args[2] != NULL){
        printf("Unable to create folder due to naming complications\n");
        printf("Command for creating folder is: mkdir <name>");
    }

    char *path = args[1];
    mkdir(path, 0777);
}


void handle_command(char **args) {
    if(args[0] == NULL) return;

    if(strcmp(args[0], "echo") == 0) {
        cmd_echo(args);
    }

    if(strcmp(args[0], "ls") == 0) {
        cmd_ls(args);
    }

    if(strcmp(args[0], "mkdir") == 0) {
        cmd_mkdir(args);
    }
}
