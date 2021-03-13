//This program shows history of commands used by the user
//By veerendra 163233,Aakash 163221,Nagateja 163227

# include "slash.h"
void main(int argc,char *argv[])
{
    char s[40],*u=getenv("USER");
    strcat3(s,"/tmp/Slash/.",u,"history");           //opens the history file and prints all the commands
    FILE *f1;
    if(argv[1]==NULL)
    {   
    
        f1=fopen(s,"r");
        print(f1);
        hist h;
        while(fread(&h,sizeof(h),1,f1)==1)          //reads history using hist structure and prints the-
         printf("%s\n",h.word);                     //-command  
        fclose(f1);
    }
    else if(strcmp(argv[1],"clear")==0)
    {
        f1=fopen(s,"w");                           //opens history file in write mode which deletes the- 
        print(f1);                                 //previous contents 
        printf("history cleared successfully!!!\n");
        fclose(f1);
    }
}
