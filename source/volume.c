//This file contains all the volume formulas.
/*
 * Part of Slash.
 *  By veerendra 163233,Aakash 163221,Nagateja 163227
 */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define PI 3.141592

void cyan()//This function sets the settings to cyan color
{
    printf("\033[1;36m");
}

void reset()//This function resets the color settings to normal
{
    printf("\033[00m");
}

void print(char *shape)//This function is used to print a string
{
    cyan();
    printf("%s",shape);
    reset();
}
void main(int c,char *v[])//The main function
{
    char shape[20];//The identifier which stores the name of the shape.
    if(v[1]==NULL)//If command line arguments are not used.
    {
        printf("Enter the shape.\n");
        scanf("%s",shape);
    }
        float i1,i2,i3;
   if(v[1]!=NULL)//If commandline arguments are used then.
        strcpy(shape,v[1]);
    if(!strcmp(shape,"cube"))//Compares whether the entered string(shape) is cube.
    {
       print("EDGE : ");
       scanf("%f",&i1);//Inputs the data
       printf("%.3f\n",i1*i1*i1);//computes its volume and prints the result
    }
    else
    if(!strcmp(shape,"cuboid"))//compares whether the entered string(shape) is cuboid
    {
        print("LENGTH : ");//Inputs the data
        scanf("%f",&i1);
        print("BREADTH : ");
        scanf("%f",&i2);
        print("HEIGHT : ");
        scanf("%f",&i3);
        printf("%.3f\n",i1*i2*i3);//computes its volume and prints the result
    }
    else
    if(!strcmp(shape,"sphere"))//compares whether the entered string(shape) is sphere
    {
        print("RADIUS : ");//Inputs the data
        scanf("%f",&i1);
        i3=4.0/3;
        i2=(i3*PI*i1*i1*i1);
        printf("%.3f\n",i2);//computes its volume and prints the result
    }
    else
    if((!strcmp(shape,"hemisphere"))||(!strcmp(shape,"hsphere")))//compares whether the entered string(shape) is hemisphere
    {
         print("RADIUS : ");//Inputs the data
         scanf("%f",&i1);
         i3=2.0/3;
         i2=(i3*PI*i1*i1*i1);
         printf("%.3f\n",i2);//computes its volume and prints the result
    }
    else
    if(!strcmp(shape,"cone"))//compares whether the entered string(shape) is cone
    {
        print("RADIUS : ");//Inputs the data
        scanf("%f",&i1);
        print("HEIGHT : ");
        scanf("%f",&i2);
        i3=1.0/3;
        printf("%.3f\n",i3*PI*i1*i1*i2);//computes its volume and prints the result
    }
    else
    if(!strcmp(shape,"cylinder"))//compares whether the entered string(shape) is cylinder
    {
        print("RADIUS : ");//Inputs the data
        scanf("%f",&i1);
        print("HEIGHT : ");
        scanf("%f",&i2);
        printf("%.3f\n",PI*i1*i1*i2);//computes its volume and prints the result
    }

}
