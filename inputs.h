#ifndef INPUTS_H
#define INPUTS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *read_line(void);
void parse_input(char* input, char** args);

#endif INPUTS_H