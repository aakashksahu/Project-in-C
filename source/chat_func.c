
/* Slash Chat Function file
 *
 * By-
 * Veerendra Rajkumar - 163233
 * Aakash Sahu - 163221
 * Naga Teja - 163227
 */

#include"chat.h"

// Function to print error and exit

void error(void)
{
    char *err=strerror(errno);
    printf("\n\tERROR : %s",err);
    exit(1);
}

// Function to parse a string to array of strings using ' ' as separator

char **get_input(char *input)
{
    char **command=(char**)malloc(8 * sizeof(char*));
    char *separator = " ";
    char *parsed;
    int index=0;
    parsed = strtok(input, separator);
    while(parsed!=NULL)
    {
        command[index]=parsed;
        index++;

        parsed = strtok(NULL,separator);
    }
    command[index]=NULL;
    return command;
}

// Function to allocate 80 units of char

char *line(void)
{
    return (char*)calloc(1,80);
}

// Function to allocate 25 units of char

char *string(void)
{
    return (char*)calloc(1,25);
}

// Function to print user's message

void print(char* line)
{
    printf("\033[48;5;27;38;5;16m<| ");
    printf(line);
    printf("\033[0m\n");
    return;
}

// Function to print recipient's message

void rprint(char* line)
{
    int i,x,y;
    char *s;
    rl_get_screen_size(&x,&y);
    i=strlen(line)+3;
//    for(x=0;x<y-i;x++)
  //      printf("%c",' ');
    printf("\033[%dC",y-i);
    printf("\033[48;5;28;38;5;16m");
    printf(line);
    printf(" |>\033[0m\n");
    return;
}

// Function to Send notification to all reci's terminals

void notify(char *scr)
{
    char* usr=getenv("USER"),*sc,*p=line();
    int i,x,y;
    p=strcat(p,"/dev/");
        p=strcat(p,scr);
    FILE* fp;
    fp=fopen(p,"w");

    if(fp!=NULL)
    {
        fprintf(fp,"\033[s\033[1;%df\033[7mSlash Chat Notification\n\033[2;%dfA message from %s\033[0m\033[u",100,100,usr);
        fclose(fp);
    }
    return;
}

// Function to display the chatfile using above functions

void display(FILE* fp,char* reci,char* user)
{
    char *name,*input;
    int i,x,y;
    rl_get_screen_size(&x,&y);
    name=string();
    input=line();
    printf("\033[2J\033[0;0f\033[7m");
    for(i=0;i<y/2-5;i++)
        printf(" ");
    printf("Slash Chat");
    for(i=0;i<y/2-5;i++)
        printf(" ");
    printf("\n\033[0m");
    while(!feof(fp))
    {
        fscanf(fp,"%[^:]",name);
        getc(fp);
        fscanf(fp,"%[^\n]",input);
        getc(fp);
        if (!strcmp(name,reci))
            rprint(input);
        else if (!strcmp(name,user))
            print(input);
    }
    return;
}

// Function to return the chatfile of reci & user

FILE* chatfile(char* reci,char* user)
{
    char *filename;
    FILE* fp;
    struct stat str;
    int i;
    if(strcmp(reci,user)<0)
    {
        filename=line();
        filename=strcat(filename,"/tmp/Slash/chat/");
        filename=strcat(filename,reci);
        filename=strcat(filename,"_");
        filename=strcat(filename,user);
        if (stat(filename, &str) == -1)
        {
            fp=fopen(filename,"a+");
            i=chmod(filename,0777);
            if(i==-1)
                error;
        }
        fp=fopen(filename,"a+");
    }
    else if (strcmp(reci,user)>0)
    {
        filename=line();
        filename=strcat(filename,"/tmp/Slash/chat/");
        filename=strcat(filename,user);
        filename=strcat(filename,"_");
        filename=strcat(filename,reci);
        if (stat(filename, &str) == -1)
        {
            fp=fopen(filename,"a+");
            i=chmod(filename,0777);
            if(i==-1)
                error;
        }
        fp=fopen(filename,"a+");
    }
    return fp;
}

// Function to chat

void chat(FILE* fp,char* reci,char* user,char** sa)
{
    int i=0;
    char *input=line(),c;
    while(1)
    {
        rewind(fp);
        display(fp,reci,user);
        printf("\033[1A");
        empty();
        scanf("%[^\n]",input);
        getchar();
        i=strlen(input);
        if (!strcmp(input,"exit")||!strcmp(input,"Exit"))          // Check if input is exit call
        {
            break;
        }
        if(i!=0)                                                   // Writing message to chatfile
        {
        fprintf(fp,user);
        fprintf(fp,":");
        fprint(fp,input);
        fprintf(fp,"\n");
        input[0]='\0';
        i=0;
        while(sa[i]!=NULL)                                         // Sending notifications
        {
            notify(sa[i]);
            i++;
        }
        }
    }
}

// Empty the current line on the screen

void empty (void)
{
    printf("\033[s");
    printf("                                                                                                                                                                        ");
    printf("\033[u");
}

// Function to expand meta characters

char *expand(char* input)
{
    wordexp_t wrdexp;
    int i=wordexp(input,&wrdexp,WRDE_SHOWERR);
    if (i==-1)
        error;
    return wrdexp.we_wordv[0];
}

// Function to trim arrow keys and write string to chatfile

void fprint(FILE* fp, char* line)
{
    int i=0;
    for(;i<strlen(line);i++)
    {
        if (line[i]==27)
            i+=2;
        else
            fprintf(fp,"%c",line[i]);
    }
}
