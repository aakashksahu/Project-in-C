//This program is to change the password by the user
//By veerendra 163233,Aakash 163221,Nagateja 163227


# include "slash.h"

void main()
{
 char z[MAXLEN],pswd1[MAXLEN],pswd2[MAXLEN],*u1=getenv("USER");
 FILE *f1;
 us u,one;
 int e=0;
 printf("Enter the userid : ");   
 gets(u.uid);
 printf("Enter the current password : ");
 getpasswd(u.passwd);                                   
 f1=fopen("/tmp/Slash/.confedential","r+");                               //reads from the data file 
 if(f1==NULL)
 {
  printf("SORRY.AN ERROR OCCURRED\n");
  exit(0);
 } 
 while(fread(&one,sizeof(us),1,f1)==1)
 {   
  if(ucmp(u,one)==0 && strcmp(u1,one.uid)==0)           //checks if the user is logged in slash and checks if user in-
  {                                                     //-his bash or not
   e=1;   
   printf("\nEnter the new password : ");
   getpasswd(pswd1);                                    //asks new password for first time
   printf("\nplease re-enter the new password : ");  
   getpasswd(pswd2);                                    //asks new password for second time
   if(strcmp(pswd1,pswd2)==0)                           
   {
    printf("\npassword changed succussfully\n");   
    strcpy(one.passwd,pswd1);                           //if both the passwords are same then password is changed
    fseek(f1,-1*sizeof(us),1);
    fwrite(&one,sizeof(us),1,f1);
   } 
   else
   {
    printf("\nWrong password.\n");   
    exit(0);                                            //if password doesn't match,program ends
   } 
  }
 }
 if(e==0)
  printf("\nWrong userid or password\n");
fclose(f1);
}

