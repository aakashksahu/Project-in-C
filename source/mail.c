//This program is mail program
//By veerendra 163233,Aakash 163221,Nagateja 163227

# include "slash.h"

void main(int argc,char* argv[])
{ 
 char i='a',*u,*u1,a,s[30],less[40],s1[30],s2[30],temp[20],temp1[20],cat[20],cat1[20];    
 FILE *f1,*f2,*f3,*tmp;
 int in=1,k,flag=0;
 status st;
 list l=calloc(1,sizeof(list));
 u1=u=getenv("USER");
 strcpy(s,"/tmp/Slash/.");
 strcat3(temp,s,u,"temp");                                
 strcat2(temp1,temp,"1");
 
 //code for seeing mails  
 
 if(argv[1]!=NULL)
 {
  if(strcmp(argv[1],"open")==0)
  {   
   strcat3(less,"less ",s,u);
   system(less);
    exit(0);
  }
  if(strcmp(argv[1],"clear")==0)
  {
   strcat2(s,"/tmp/Slash/.",u);
   f1=fopen(s,"w");
   fclose(f1);
   strcat(s,"stat");
   f1=fopen(s,"w");
   fclose(f1);
   exit(0);
  }
 } 
  if (argv[1]==NULL)     //When user wants to see the mails received,he types the command "smail"
 { 
  strcat3(s,s,u,"stat");   
     displ(f1,s);        //This function displays the status of received mails
  getchar();
  strcat2(s1,s,"1");
  strcat3(less,"less ","/tmp/Slash/.",u);
  system(less);          //less command opens the mail file
  printf("Enter the serial no. of mails that you have read [To stop enter'0']\n");
  while(in)               //after the user reads his mails,he can delete the mails which he read from status      
  {
     i= getchar();
      in=i-'0';
     if(in!=0)
     {
       insatend(l,in);    //This takes serial no. of mails which are read from user and deletes those from status and 
       flag=1;           //inserts in a linked list.
  
     } 
  }  
     if(flag==1)
     {
      f1=fopen(s,"r");   //opens status file
      f2=fopen(s1,"w");  //opens a temporary file 
      if(f1==NULL || f2==NULL)
      {
          printf("SORRY.AN ERROR OCCURRED.\n");
          exit(0);
      }    
      chmod(s,0666);
      chmod(s1,0666);
      i=1;
      while(fread(&st,sizeof(st),1,f1)==1) 
      {
       k=find(l,i);
       if(k!=1)
        fwrite(&st,sizeof(st),1,f2);      //Writes the status of the file which are not read by the user in a temporary-
       i++;                               //-file. 
      }
      fclose(f1);
      fclose(f2);
      remove(s);                         //actual file is removed
      rename(s1,s);                      //temporary file is renamed to actual file name
     }
  exit(0);
 } 
 
 //ends here
 strcat2(s,"/tmp/Slash/.",argv[1]);   
 f1=fopen(s,"r");                       //checks if user is registered or not
 if(f1==NULL)
 {
     printf("USER NOT REGISTERED\n");
     exit(0);
 }   
 fclose(f1);
 tmp=fopen(temp,"w");
 chmod(temp,0666);
 fprintf(tmp,"%s","\n\tsubject : ");  //user writes the mail which is to be sent in temp file
 fclose(tmp);
 strcat2(cat,"cat ",temp);
 system(cat);
 strcat2(cat1,"cat >> ",temp);
 system(cat1);                                          // cat is "cat " and cat1 is "cat >> " 
 time_t senttime;
 time(&senttime);
 time(&(st.senttime));
 f2=fopen(temp1,"w");                                 
 chmod(temp1,0666);                                     
 if(strcmp(argv[0],"flashmail")==0)             //from,to and date are written in temp1 file by the program and 
     fprintf(f2,"%s","FLASH_MAIL\t\tFLASH_MAIL\t\tFLASH_MAIL\n"); //whatever user writes in the temp file- 
 fprintf(f2,"%s","\n\n");                                         //-gets copied to the temp1 file
 fprintf(f2,"FROM : %s\n",u);
 fprintf(f2,"TO   : %s\n",argv[1]);
 fprintf(f2,"ON   : %s\n",ctime(&senttime));
 fclose(f2);
 f2=fopen(temp1,"a");
 f1=fopen(temp,"r");
 while((a=fgetc(f1))!=EOF)
     fputc(a,f2);
 fclose(f1);
 fclose(f2);
 printeof(f2,temp1);
 remove(temp);
 f1=fopen(s,"a");
 tmp=fopen(temp1,"r");
 rewind(tmp);
 while((a=fgetc(tmp))!=EOF)                           //the mail in the temp1 file gets appended to the  mail file-  
  fputc(a,f1);                                        //-which belongs to the receiver. 
 fclose(tmp);
 fclose(f1);
 remove(temp);
 remove(temp1);
 
 //flash mail code
 
 if(strcmp(argv[0],"flashmail")==0)
 {
  
  strcat3(s,"/tmp/Slash/.",argv[1],"stat");
  strcat2(s1,s,"fls");                                //when user wants to send flashmail status of this mails-  
  f1=fopen(s1,"w");                                   //-are shown at the top.    
  if(f1==NULL)
  {
   printf("SORRY.FLASHMAIL FAILED.\n");
   exit(0);
  }
  chmod(s1,0666);
   
  strcpy(st.who,u);
      st.flash=1;
      fwrite(&st,sizeof(st),1,f1);
  fclose(f1);
  f1=fopen(s1,"a");
  f2=fopen(s,"r");
  if(f1==NULL || f2==NULL)
  {
   printf("SORRY.FLASHMAIL FAILED.\n");
   exit(0);
  }
  while(fread(&st,sizeof(st),1,f2)==1)
   fwrite(&st,sizeof(st),1,f1);
  fclose(f1);
  fclose(f2);
  remove(s);
  rename(s1,s);
  exit(0);
 }    

 //ends here
 strcat3(s,"/tmp/Slash/.",argv[1],"stat"); 
 f1=fopen(s,"a"); 
 if(f1==NULL)
 {
     printf("SORRY.SMAIL FAILED\n");
     exit(0);
 }
 chmod(s,0666);
 strcpy(st.who,u1);
 st.flash=0;
 fwrite(&st,sizeof(st),1,f1);            //This is to append in the status file
 fclose(f1);
}    


