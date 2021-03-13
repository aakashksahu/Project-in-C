//This file contains all the functions used for the project
//By veerendra 163233,Aakash 163221,Nagateja 163227

#include"slash.h"
//This function prints quote fo the day
void quote(void)
{ 
  FILE *f1;
  int num=0,i=0;
  char a,cnum[10],temp[19];
  f1=fopen("/tmp/Slash/.quotes","r");                   //opens the file that contains quotes
  if(f1==NULL)
  {
      printf("Be happy.Make others happy\n");
      return;
  }
  srand(time(0));
  num=rand();                                 //some random integet is taken and the integet is made like #%d: which is-
  num=num%365;                                //serial no. for the quotes.
  while(num)
  {
   temp[i]=(num%10)+'0';
   num=num/10;
   i++;
  }
  temp[i]='\0';
  strrev(temp);
  cnum[0]='#';
  cnum[1]='\0';
  strcat(cnum,temp);
  temp[0]=':';
  temp[1]='\0';
  strcat(cnum,temp);
  while(fscanf(f1,"%s",temp)!=EOF && strcmp(cnum,temp)!=0);
  while((a=fgetc(f1))!=EOF && a!='#')          //one quote is print on the screen         
      putchar(a);
  fclose(f1);    
}  
//This function prints witty statements

void wits(void)
{ 
  FILE *f1;
  int num=0,i=0;
  char a,cnum[10],temp[19];
  f1=fopen("/tmp/Slash/.wits","r");
  if(f1==NULL)                                        //opens file that contains wits and does the same thing as quotes
  {
      printf("May You live everyday of your life\n");
      return;
  }
  srand(time(0));
  num=rand();
  num=num%560;
  while(num)
  {
   temp[i]=(num%10)+'0';
   num=num/10;
   i++;
  }
  temp[i]='\0';
  strrev(temp);
  cnum[0]='#';
  cnum[1]='\0';
  strcat(cnum,temp);
  temp[0]=':';
  temp[1]='\0';
  strcat(cnum,temp);
  while(fscanf(f1,"%s",temp)!=EOF && strcmp(cnum,temp)!=0);
  while((a=fgetc(f1))!=EOF && a!='#')
      putchar(a);
  fclose(f1);    
}  
//This function reverses the string

void strrev(char a[])
{
 int i=strlen(a),j=0;
 char c[i+1];
 strcpy(c,a);
 while(i)
 {
  a[j]=c[i-1];
  i--;
  j++;
 }
 a[j]='\0';
}
//This function is for masking password

void getpasswd(char a[])
{
 system("stty -echo");
 gets(a);
 system("stty echo");
}

//This function is for comparing 2 structures.

int ucmp(us a,us b)
{
 if(strcmp(a.uid,b.uid)==0 && strcmp(a.passwd,b.passwd)==0)   
  return 0;
 return -1;
}

void clrscr()
{
    printf("\033[2J\033[0;0f");
}

void print(FILE *f1)
{
 if(f1==NULL)
 {
     printf("SORRY.AN ERROR OCCURRED\n");
     exit(0);
 }   
}    

void printeof(FILE *f1,char *a)
{
 f1=fopen(a,"a");
 int i=0;                            //This function prints spaces and lines at end of every mail
 if(f1==NULL)
  return;
 fprintf(f1,"%s","\n\n");
 for(i=0;i<100;i++)
  fprintf(f1,"%c",'-');
 fprintf(f1,"%s","\n\n");
 fclose(f1);
}    



void displ(FILE *f1,char a[])
{
 status st;
 int i=1;
 char mail[15];
 f1=fopen(a,"r");
 if(f1==NULL)                           //This function is to display the status of received mails
  return;   
 while(fread(&st,sizeof(st),1,f1)==1)
 {
  if(st.flash==1)
    strcpy(mail,"FLASH MAIL");
  else
    strcpy(mail,"mail");  
  printf("%d.You have %s from %s on %s\n",i,mail,st.who,ctime(&st.senttime));
  i++;
 }
 if(i==1)
 {
  printf("You have no new mails\n");
  fclose(f1);
  exit(0);
 } 
  fclose(f1);
}


void insatend(list l,int a)
{
 list p=calloc(1,sizeof(list));
 if(p==NULL)
 {printf("sorry");                         //This function inserts an element at the end of a linked list
     return;   }
 while(l->next!=NULL)
  l=l->next;
 l->next=p;
 p->data=a;
}   

int find(list l,int a)
{
 l=l->next;
 while(l!=NULL)
 {                           //This function finds an element in                                                    
  if(l->data==a)             //the list  
   return 1;
  l=l->next;
 }    
 return 0; 
}


//These functions are to concatenate 2 and 3 strings

void strcat2(char a[],char b[],char c[])
{
 strcpy(a,b);
 strcat(a,c);
 return;
}

void strcat3(char a[],char b[],char c[],char d[])
{
 strcpy(a,b);
 strcat(a,c);
 strcat(a,d);
}

//This function counts no.of days left in a year
int daysleft(int day,int mon,int year)
{    
 int d,k=isleapyear(year); 
 if(mon==1)
 {
  if(k==1)    
   d=366-day;
  else
   d=365-day;   
  return d;
 }
 if(mon==2)
 {
  if(k==1)
   d=366-(31+day);
  else
   d=365-(31+day);
  return d;
 }
 if(mon==3)
   return 31-day+30*4+31*5;
 if(mon==4)
  return 30-day+30*3+31*5;
 if(mon==5)
  return 31-day+30*3+31*4;
 if(mon==6)
  return 30-day+30*2+31*4;
 if(mon==7)
  return 31-day+30*2+31*3;
 if(mon==8)
  return 31-day+30*2+31*2;
 if(mon==9)
  return 30-day+30+31*2;
 if(mon==10)
  return 31-day+30+31;
 if(mon==11)
  return 30-day+31;
 if(mon==12)
  return 31-day;
}

//This function counts no. of days over in a year
int daysover(int day,int mon,int year)
{
 if(mon==1)
  return day;
 int k=isleapyear(year);
if(mon==2)
 return 31+day;
if(mon==3)
 return 31+28+k+day;
if(mon==4)
 return 31+28+k+31+day;
if(mon==5)
 return 120+k+day;
if(mon==6)
 return 151+k+day;
if(mon==7)
 return 181+k+day;
if(mon==8)
 return 212+k+day;
if(mon==9)
 return 243+k+day;
if(mon==10)
 return 273+k+day;
if(mon==11)
 return 304+k+day;
if(mon==12)
 return 334+k+day;
}

//This function checks for leap year

int isleapyear(int year)
{
  if (year%400 == 0) 
   return 1;
  else if (year%100 == 0) 
    return 0;
  else if (year%4 == 0) 
    return 1;
  return 0;
}

//This function stores history of commands used in slash

void shistory(char z1[])
{
 hist a;
 char z[39];
 strcpy(z,z1);
 int i=strlen(z1),count=0;
 if(z[0]=='\n')
     return;
 FILE *f1,*f2;
 while(i)
 {
     if(isdigit(z[i]))              //if the commands are in digits it converts into characters
      z[i]=z[i]+'0';
     i--;
 }
 //strcpy(a.word,z);
 char *u,s[30],temp[35];
 u=getenv("USER");
 strcat3(s,"/tmp/Slash/.",u,"history");
 f1=fopen(s,"r");                        //opens temp file and writes the command
 fread(&a,sizeof(a),1,f1);               //history file is opened and contents in it are appended to temp file
  if(strcmp(a.word,z)==0)
  {
      fclose(f1);
      return;
  }
 fclose(f1);
 i=strlen(z1);
 while(count!=i)
 {
     if(z[i]!='\t' && z[i]!='\n' && z[i]!=' ')
         break;
     count++;
 }
 if(i==count)
  return;
 strcpy(temp,s);
 strcat(temp,"temp");
 f1=fopen(s,"r");
 if(f1==NULL)
     return;
 f2=fopen(temp,"w");
 if(f2==NULL)
     return;  
 chmod(temp,0666);
 strcpy(a.word,z1);
 fwrite(&a,sizeof(a),1,f2);
 while(fread(&a,sizeof(a),1,f1)==1)
  fwrite(&a,sizeof(a),1,f2);
 fclose(f1);
 fclose(f2);
 remove(s);
 rename(temp,s);
}    

//This function takes user id and password and checks if the user is registered or not
void login(void)
{
 FILE *f1,*f2;
 int i=3,e=0;
 char s[35],*u1=getenv("USER");
 us one,u;
 time_t rawtime;
 struct tm *info;
 f1=fopen("/tmp/Slash/.confedential","r+");           //This file stores the user id and passord made by         
 while(i)                                                  
 {    
  printf("Enter the user id : ");
  gets(one.uid);
  printf("Enter the password  :");
  getpasswd(one.passwd);
  while(fread(&u,sizeof(u),1,f1))
  {   
   if(ucmp(u,one)==0  && strcmp(one.uid,u1)==0)        //compares user id and password
   { 
     e=1;
     break;
   }
  } 
   if(e==1)
     break;   
   if(i!=0)                                                //gives 3 chances to user
    {
     printf("\nWrong userid or password.Try again\n");
     rewind(f1);
    }
  i--;
 } 
 if(i==0)
 {
  printf("Access Denied\n");
  fclose(f1);
  exit(0);
 }

 u.mn--;
 time(&rawtime);
 info=localtime(&rawtime);
 if(u.dy==info->tm_mday && u.mn==info->tm_mon)              //prints birthday wishes on bitrthday
  system("banner HAPPY BIRTHDAY \n");

 printf("\n*****Welcome to SLASH*****\n");       
 if(u.log==0)
 {
  strcat3(s,"/tmp/Slash/.",u1,"history");                  //history file is created when user is logging in for the 
  f2=fopen(s,"w");                                         //first time
  if(f2!=NULL)
  {
      chmod(s,0666);
      fclose(f2);
  }
      u.log=1;
 }    
 else   
  printf("LAST LOGGED IN ON : %s ",ctime(&u.logtime));           //This is to print last login
 printf("Quote for the day : ");
 quote();
 time(&(u.logtime));                                        //Stores the logging in time                              
 fseek(f1,-1*sizeof(u),1);
 fwrite(&u,sizeof(u),1,f1);
 fclose(f1);
 } 

//This functions checks if the user is present in database or not
int checkuid(char a[])
{
    FILE *f1;
    us z;
    f1=fopen("/tmp/Slash/.confedential","r");
    while(fread(&z,sizeof(z),1,f1)==1)
    {
        if(strcmp(z.uid,a)==0)
        {                                          //opens the data file and checks for the user
            printf("User already exists\n");
            fclose(f1);
            return 0;
        }
    }
    fclose(f1);
    return 1;
}

//This function gives the error occured in the current process
void error(void)
{
    char *err=strerror(errno);
    printf("Slash : %s",err);
}

//This function checks if the given input is numeric expression or no.
int ne(char s[])
{
    int l=strlen(s);

    while(l!=0)
    {
        l--;
        if(isalpha(s[l])||s[l]=='\n')
            return 0;       
    }
    return 1;
}

//This funcntion is used for On-The_Go Calculator
//This function opens a file .YOUR_INPUT to write the input
//if it is an numeric expression.
void expe(char input[])
{
    FILE *f1=fopen(".YOUR_INPUT","w");
    int i=0;  
    if(ne(input))
    {
        while(input[i])
            {
                fputc(input[i],f1);
                i++;
            }    
        fputc('\n',f1);
    } 

    fclose(f1);   
}

//This function gives the Slash > prompt.
void prompt()
{
    printf("\033[7m");
    printf("Sla");
    printf("\033[00m");
    printf("\033[01m");
    printf("sh");
    printf(" > ");
    printf("\033[00m");
}

//This function checks if any pipes exist in input.
//If yes it return the position of the pipe in the string input
//If non return 0.
int is_pipe(char *input)
{
    int i=0;
         while(input[i]!='\0')
         {
             if(input[i]=='|')
                 return i;
             else
                 i++;
         }
         return 0;
}

//This function checks for any redirection in the given input.
int is_redirect(char *input)
{
    int i=0;
    while(input[i]!='\0')
    {
        if(input[i]=='>'&&input[i+1]=='>')//return 1 if >>
            return 1;
        else if(input[i]=='>')
            return 0;                   //return 0 if >
        else if(input[i]=='<')
            return 2;                   //return 2 if <
        else i++;
    }
    return -1;                             //return -1 if no redirection present.
}


//This function executes the given input.
//This function uses the structure called wordexp_t  -> word expand
//wordexp() functio expands string arg and return it in wrd.
void execute(char* arg)
{
    int i;
    wordexp_t wrd;//Identifier of 
    char* dir=getenv("HOME");
    i=wordexp(arg,&wrd,0);
    if(i!=0)
        error();
    if(!strcmp(wrd.we_wordv[0],"cd"))//If input is cd then use chdir() function to complete the task.
    {
        if(wrd.we_wordv[1]!=NULL)
            i=chdir(wrd.we_wordv[1]);
        else
            i=chdir(dir);
        if(i==-1)
           error();
    }
    else
    {
    execvp(wrd.we_wordv[0],wrd.we_wordv);//Executing the command.
    error();
    }
}

//This function redirects accordingly if any redirection exists.
int  redirect(char *input)
{
    FILE *fp;
    char command[168],file[168];
    int i,j;
    i=is_redirect(input);
    switch(i)
    {
        case -1:
            strcpy(command,input);
            break;
        case 0:
            for(i=0;input[i]!='>';i++)
               command[i]=input[i];
            command[i]='\0'; 
            i++;
            for(j=0;input[i]!='\0';i++,j++)
                file[j]=input[i];
            file[j]='\0';
            fp=fopen(file,"w");
            if(!fp)
                error();
            else
            {
                close(1);
                dup(fileno(fp));
                close(fileno(fp));
            }
               break;
        case 1:
            for(i=0;input[i]!='>';i++)
               command[i]=input[i];
            command[i]='\0';
            i+=2;
            for(j=0;input[i]!='\0';i++,j++)
                file[j]=input[i];
            file[j]='\0';
            fp=fopen(file,"a");
            if(!fp)
                error();
            else
            {
                close(1);
                dup(fileno(fp));
                close(fileno(fp));
            }
            break;
        case 2:
            for(i=0;input[i]!='<';i++)
               command[i]=input[i];
            command[i]='\0';            
            i++;
            for(j=0;input[i]!='\0';i++,j++)
                file[j]=input[i];
            file[j]='\0';
            fp=fopen(file,"r");
            if(!fp)
                error();
            else
            {
                close(0);
                dup(fileno(fp));
                close(fileno(fp));
            }
            break;
    }
    execute(command);
}

