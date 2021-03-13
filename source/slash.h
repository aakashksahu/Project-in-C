//This is header file used for project Slash shell.

//By veerendra 163233,Aakash 163221,Nagateja 163227

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>
# define MAXLEN 15
# include <sys/wait.h>
# include<ctype.h>
#include<wordexp.h>
#include<unistd.h>
#include<readline/readline.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>


int errno;

//extern const char *suser_txt={"/tmp/Slash/.confedential"};
struct user
{
 char uid[MAXLEN];
 char passwd[MAXLEN];
 int dy,mn,yr,log;
 //struct tm tme;
 time_t logtime;
};                                       //This is structure for user's information
typedef struct user us;

//________________________________________________________


struct status
{
    char who[MAXLEN];
    time_t senttime;
    int flash;
};                                       //This is structure for status of the mails 
typedef struct status status;


//___________________________________________________________

struct node
{
 int data;                                //This is structure for linked list which is used in mail.c
 struct node* next; 
};
typedef struct node* list;

struct history 
{
 char word[25];   
 int len;                                //This is structure for user's history which is used to store-
};                                       //-user's history of commands. 
typedef struct history hist;

//Definitions of the below functions are present in func.c

void quote(void);
void strrev(char a[]);
void getpasswd(char a[]);
int ucmp(us a,us b);
void print(FILE *f1);
void wits(void);
int isleapyear(int year);
int daysover(int day,int mon,int year);
int daysleft(int day,int mon,int year);
void strcat3(char a[],char b[],char c[],char d[]);
void strcat2(char a[],char b[],char c[]);
int find(list l,int a);
void insatend(list l,int a);
void displ(FILE *f1,char a[]);
void printeof(FILE *f1,char *a);
void login(void);
void error(void);
int ne(char s[]);
void expe(char input[]);
void prompt();
int is_pipe(char *input);
int is_redirect(char *input);
void execute(char* arg);
int  redirect(char *input);
void clrscr();



