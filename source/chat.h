
/* Slash Chat Header file
 *
 * By-
 * Veerendra Rajkumar - 163233
 * Aakash Sahu - 163221
 * Naga Teja - 163227
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<wordexp.h>
#include<fcntl.h>


void error(void);

char **get_input(char *input);

char *line(void);

char *string(void);

void print(char* line);

void rprint(char* line);

void notify(char *scr);

void display(FILE* fp,char* reci,char* user);

FILE* chatfile(char* reci,char* user);

void chat(FILE* fp,char* reci,char* user,char** sa);

void empty (void);

void fprint(FILE* fp, char* line);

