/* Slash file */
//This is the main file for Slash shell
//by -Rajkumar
//   -Aakash
//   -Nagateja

//Including header file.
#include"slash.h"

int main ()//The main function
{
    char input[168],*path;//Input contains the input entered by user.
    //path is a charater pointer
    pid_t child_pid;//Identifier which represents Child process
    int status,i;
    char *calc="bc -q .YOUR_INPUT /usr/bin/.end";//This string contains input for the On-The-Go Calculator.

    path=getenv("PATH");//Get the path environment variable
    i=setenv("PATH",strcat(path,":/tmp/Slash/bin"),1);//Setting the path to Slash
    if(i<0)//Error in setting the path
    {
        error();
    }
    clrscr();//Clear the screen
    login();//Call login function
    while(1)
    {
       prompt();        //gives the slash prompt.
        
       gets(input);     //Takes input from the user.
       shistory(input);
       if(is_pipe(input))       //Checks if the input contains any pipes.
       {
        
           int pipefd[2],_i,_j;
           pid_t left_pid, right_pid, ret;
           char _arg[168];

           if(pipe(pipefd) < 0)//Checking for error in pipes
           {
               perror("Error in pipe.");
               continue;
           }

           if((left_pid = fork())<0)//Checking for error  in fork 
           {
               perror("Error in fork.");
               continue;
           }
           else if(left_pid == 0)//If left child
           {
               
               for(_i=0;input[_i]!='|';_i++)//Taking command before '|'
                  _arg[_i]=input[_i];
               _arg[_i]='\0';

               close(pipefd[0]);//Closing pipe's read end and stdout
               close(1);
               dup(pipefd[1]);// Duplicating pipe's write end to stdout and closing it
               close(pipefd[1]);

               redirect(_arg);//Check for redirection and execute
           }
           else
           {
            waitpid(left_pid, &status,WUNTRACED);//Waiting for child to finish
           }
           
           if((right_pid = fork())<0)//Forking right child
           {
               perror("Error in fork.");
               continue;
           }
           else if(right_pid == 0)//If right child
           {
               _i=is_pipe(input)+1;
               for(_j=0;input[_i]!='\0';_i++)//Taking command after '|'
                   _arg[_j++]=input[_i];
               _arg[_j]='\0';

               close(pipefd[1]);//Closing pipe's write end and stdin
               close(0);
               dup(pipefd[0]);// Duplicating pipe's read end to stdin and closing it
               close(pipefd[0]);

               redirect(_arg);//Check for redirection and execute
           }
           else
           {
               sleep(1);//Waiting for child to finish

           }
       }
       else
       if(ne(input))        //Checks if the input is a numeric expression or not.     
       {
          expe(input);//Writing to YOUR_INPUT

         child_pid =fork();
        if(child_pid == 0)
        {
            redirect(calc);//Check for redirection and execute
        }

        else
        {  
            waitpid(child_pid, &status,WUNTRACED);//Waiting for child to finish
        }     
      }

      else if((!strcmp(input,"slashout"))||(!strcmp(input,"Slashout"))||(!strcmp(input,"sout")))//If command is to exit
      {
          i=setenv("PATH",path,1);//Set environment back and exit
          exit(0);
      }
      else
      {    
        child_pid =fork();//If no pipes, forking a child
        if(child_pid == 0)
            redirect(input);//Check redirection and execute
        else
            waitpid(child_pid, &status,WUNTRACED);//Waiting for child to finish
      }
    
    }

}
