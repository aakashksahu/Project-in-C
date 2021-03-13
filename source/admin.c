//This is code which is run by admin to create and delete users in Slash shell.
//By veerendra 163233,Aakash 163221,Nagateja 163227

# include "slash.h"

void main()
{
 FILE *f1,*f2;   
 us one;
 char name[15],cat[40],temp[40],a1;
 int a,b,i=1,flag=0;
 while(1)
 {    
  printf("\n1.To create new user\n2.To Delete an account\n3.To display all users\n4.TO SEE PASSWORD\n0.To EXIT\n");
  scanf("%d",&b);
  getchar();
  strcpy(cat,"/tmp/Slash/.");
  switch(b)    
  {
   case 1:
     printf("Enter the userid : ");
     gets(one.uid);                             //Creates new user
     strcat(cat,one.uid);
     f1=fopen(cat,"w");
     chmod(cat,0666);
     print(f1);
     fclose(f1);
     strcat(cat,"stat");                         //Creates files which are used in mail program
     f2=fopen(cat,"w");
     print(f2);
     chmod(cat,0666);
     strcpy(cat,"/tmp/Slash/.");
     fclose(f2);
     printf("Enter the password : ");
     getpasswd(one.passwd);
     printf("\nEnter the date of birth DD.MM.YY : ");
     scanf("%d.%d.%d",&one.dy,&one.mn,&one.yr);        //stores birth date
     f1=fopen("/tmp/Slash/.confedential","a");
     print(f1);
     one.log=0;
     fwrite(&one,sizeof(us),1,f1);
     fclose(f1);
     break;

   case 2:
     
     strcat(cat,"confedential");
     f1=fopen(cat,"r");
     print(f1);
     strcpy(temp,cat);
     strcat(temp,"temp");
     f2=fopen(temp,"w");
     print(f2);
     chmod(temp,0666);
     printf("Enter the userid: ");
     gets(name);                                //creates a temp file and copies all users except the one which is to-  
     while(fread(&one,sizeof(us),1,f1)==1)      //-be deleted
     {
      if(strcmp(one.uid,name)!=0)
       fwrite(&one,sizeof(us),1,f2);
      else if(strcmp(one.uid,name)==0)
      {
        strcat2(cat,"/tmp/Slash/.",one.uid);    
        remove(cat);                        //deletes mail files 
        strcat(cat,"stat");
        remove(cat);
        strcat3(cat,"/tmp/Slash/.",one.uid,"history");  //deletes history files
        remove(cat);
        strcpy(cat,"/tmp/Slash/.");
        flag=1;
      }
     } 
      if(flag==1)
      {
          flag=0;
          printf("USER DELETED SUCCESSFULLY.HAVE A NICE DAY\n");
      }
      else
          printf("NO SUCH USER.HAVE A NICE DAY\n");
     
     fclose(f2);
     fclose(f1);
     remove("/tmp/Slash/.confedential");  
     rename(temp,"/tmp/Slash/.confedential");   //renames the temp file
     break;

   case 3:
     
     f1=fopen("/tmp/Slash/.confedential","r");
     print(f1);
     if(a1=fgetc(f1)==EOF)
       printf("\nNO USERS\n");
     else
     {
      i=1;
      rewind(f1);
      while(fread(&one,sizeof(us),1,f1)==1)      //Dislays all the users registered 
      { 
        printf("%d)%s and his date of birth is : %d.%d.%d\n",i,one.uid,one.dy,one.mn,one.yr);
        i++;
      }
      fclose(f1);
     } 
     break; 
   case 4:
     printf("Enter the user name: ");
     gets(name);
     f1=fopen("/tmp/Slash/.confedential","r");
     print(f1);
     while(fread(&one,sizeof(one),1,f1)==1)
     {
      if(strcmp(one.uid,name)==0)
      {                                                    //To see any user's password from a given user name
          puts(one.passwd);
          flag=1;
          break;
      }
     } 
      if(flag==0)
      {
        printf("SORRY.USER NOT FOUND\n");
      }
      else
          flag=0;
      fclose(f1);
      break;
   case 0:
     exit(0);

   default:
     printf("WRONG OPTION.TRY AGAIN\n");
  }
 }
}


