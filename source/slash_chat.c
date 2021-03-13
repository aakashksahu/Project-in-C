
/* Slash Chat Main file
 *
 * By-
 * Veerendra Rajkumar - 163233
 * Aakash Sahu - 163221
 * Naga Teja - 163227
 */

#include"chat.h"


void main ()
{
    char *input,**sa,*name,*user,*reci,*scr,*exp;
    int i=0,x,y;
    struct stat str;
    extern int errno;
    char *err;
    FILE *fw,*fu,*fr,*tmp;

    exp=expand("~/.Slash");
	if (stat(exp, &str) == -1)                               // Checking whether .Slash directory exists 
    {
        i=mkdir(exp, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); // Else create one
        if(i==-1)
            error;
    }
	
    system("who > ~/.Slash/who");                                           // Obtaining list of loggedin users
    
    input=line();
    name=string();
    scr=string();                                                           // Dynamic allocations
    reci=string();


    exp=expand("~/.Slash/who");
    fw=fopen(exp,"r+");
    exp=expand("~/.Slash/users");
    fu=fopen(exp,"w+");                                // Opening files for parsing the loggedin data
    exp=expand("~/.Slash/rusers");
    fr=fopen(exp,"w+");

    if(fw==NULL||fu==NULL||fr==NULL)
        error();
    printf("\033[2J\033[0;0f");
     printf("\033[1;36m");
    printf("hi %s\n",user=getenv("USER"));
    
    fscanf(fw,"%[^\n]s",input);

    while(!feof(fw))
    {
        sa=get_input(input);
        if(strcmp(sa[0],user))
        {
            while (fscanf(fu,"%s",name)!=EOF)
                if (!strcmp(input,name))
                    break;
            if(strcmp(input,name))                                           // Writing the user names to users file
                fprintf(fu,"\t%s \n",sa[0],sa[1]);
            fprintf(fr,"\t%s %s\n",sa[0],sa[1]);                             // Writing users names and terminals to rusers file
        }
            rewind(fu);
                getc(fw);
            fscanf(fw,"%[^\n]",input);
    }
    
    rewind(fu);
    printf("\033[1;32m");
    printf("\n%s",fu->_IO_write_ptr);                                        // Printing the list of users
    printf("\033[0m");
    reci=readline("Enter the recipient : ");                                 // Taking the recipient name

    rewind(fu);
    while (fscanf(fu,"%s",name)!=EOF)
        if (!strcmp(reci,name))
            break;
    if(strcmp(reci,name))                                                    // Check if reci is loggedin
    {
        printf("User not found");
        exit(1);
    }
    rewind(fr);
    free(input);
    input=line();
    while (fscanf(fr,"%s",name)!=EOF)
        if (!strcmp(reci,name))                                              // Obtaining all the terminals of reci
        {
            fscanf(fr,"%[^\n]",scr);
            strcat(input,scr);
            strcat(input," ");
        }
    sa=get_input(input);                                                     // making an array of terminal names

    fclose(fw);
    fclose(fu);
    fclose(fr);

    tmp=chatfile(reci,user);                                                 // Obtaining the chatfile
    chat(tmp,reci,user,sa);                                                  // Function to chat
}
