//This program is to count how old is

# include "slash.h"

void main()
{
 time_t curtime=time(NULL);
 struct tm info;
 int day,mon,year;
 us u;
 FILE *f1;
 char *k;
 info=*localtime(&curtime);
 info.tm_mon++;
 f1=fopen("/tmp/Slash/.confedential","r");
 if(f1==NULL)
 {
     printf("\nSORRY.AN ERROR OCCURRED\n");
     exit(0);
 }
 k=getenv("USER");
 while(fread(&u,sizeof(u),1,f1)==1)
  if(strcmp(k,u.uid)==0)   
  {
   info.tm_year=info.tm_year+1900; 
   year=info.tm_year-u.yr-1;
   day=daysover(info.tm_mday,info.tm_mon,info.tm_year);
   day=day+daysleft(u.dy,u.mn,u.yr);
   //printf("%d %d %d\n",info.tm_mday,info.tm_mon,info.tm_year);
  // printf("%d %d %d\n",u.dy,u.mn,u.yr);
   if(day>=365)
   {
    year++;
    day=day-365;
   }
   printf("you are %d years %d days old\n",year,day);
   break;
  }
 fclose(f1);
} 
