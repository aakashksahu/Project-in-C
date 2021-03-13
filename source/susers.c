//This program prints the users who are logged in Slash shell
//By veerendra 163233,Aakash 163221,Nagateja 163227

# include"slash.h"
void main()
{  
    us one; 
    FILE *f1=fopen("/tmp/Slash/.confedential","r");
    char a;                                       //opens file which contains database of users and displays the users.
    print(f1);
     if(a=fgetc(f1)==EOF)
       printf("\nNO USERS\n");
     else
     {
      rewind(f1);
      while(fread(&one,sizeof(us),1,f1)==1)      //Dislays all the users registered in slash shell 
        printf("%s ",one.uid);
     }
   fclose(f1); 
   printf("\n");
}     
