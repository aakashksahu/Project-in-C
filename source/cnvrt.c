/*
 
   This is the source code for conversions file.

   By veerendra 163233,Aakash 163221,Nagateja 163227

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PI 3.141592

 void cyan()//Changes the color setting of font to cyan
{
     printf("\033[1;36m");
}

void red ()//Changes the color setting of font to red 
{
    printf("\033[1;31m");
}

void green ()//Changes the color setting of font to green
{
    printf("\033[1;32m");
}

void yellow ()//Changes the color setting of font to yellow
{
    printf("\033[1;33m");
}

void blue ()//Changes the color setting of font to blue
{
    printf("\033[1;34m");
}

void pink ()//Changes the color setting of font to pink
{
    printf("\033[1;35m");
}

void white ()//Changes the color setting of font to white
{
    printf("\033[1;37m");
}

 void reset()//Resets the color settings to default.
{
    printf("\033[00m");
}

 void print(char c ,char *s)//print function which takes color, string and print the string in the corresponding color.
{
    switch(c)//Setting the color
    {
        case 'r':
                red();
                break;
        case 'g':
                green();
                break;
        case 'y':
                yellow();
                break;
        case 'b':
                blue();
                break;
        case 'p':
                pink();
                break;
        case 'c':
                cyan();
                break;
        case 'w':
                white();
                break;
    }
    printf("%s",s);//printing the string
    reset();//Resetting the settings
}
void print_num(char c,char *s,float f)//print number in the given color.
{
    switch(c)//Setting the color
    {
        case 'r':
                red();
                break;
        case 'g':
                green();
                break;
        case 'y':
                yellow();
                break;
        case 'b':
                blue();
                break;
        case 'p':
                pink();
                break;
        case 'c':
                cyan();
                break;
        case 'w':
                white();
                break;
    }
    printf(s,f);//printing the number
    reset();  //Resetting hte settings
}

void clrscr()//Function which clears the screen.
{
    printf("\033[2J\033[0;0f");
}

void menu1()//Function to print menu 1.
{
     print('c',"ENTER\n\n");
     print('c',"\t1.LENGTH.\t\t\t   6.VELOCITY.\n");
     print('c',"\t2.VOLUME.\t\t\t   7.PRESSURE.\n");
     print('c',"\t3.AREA.\t\t\t\t   8.ENERGY.\n");
     print('c',"\t4.MASS.\t\t\t\t   9.POWER.\n");
     print('c',"\t5.TEMPERATURE.\t\t0.EXIT.\n");
}

void length()//Function to print options in length
{
    print('y',"LENGTH.\n\n");
    print('c',"\t1. in->cm \t\t\t6. yd->m \n");
    print('c',"\t2. cm->in \t\t\t7. m->yd \n");
    print('c',"\t3. ft->m \t\t\t8. mile->km \n");
    print('c',"\t4. m->ft \t\t\t9. km->mile \n");
    print('c',"\t5. in->ft \t\t\t \n");
}

void volume()//Function to print options in volume
{
    print('y',"VOLUME.\n\n");
    print('c',"\t1. gal->L \t\t\t2. L->gal \n");
}

void area()//Function to print options in area
{
    print('y',"AREA.\n\n");
    print('c',"\t1. acre->m.sq. \t\t\t3. sq.ft->acre \n");
    print('c',"\t2. m.sq.->acre \t\t\t4. acre->sq.ft \n");
}

void mass()//Function to print options in mass
{
    print('y',"MASS.\n\n");
    print('c',"\t1. oz->g \t\t\t3. lb->kg \n");
    print('c',"\t2. g->oz \t\t\t4. kg->lb \n");
}
void temperature()//Function to print options in temperature
{
    print('y',"TEMPERATURE.\n\n");
    print('c',"\t1. deg.F->deg.C \t\t\t4. deg.C->deg.F \n");
    print('c',"\t2. deg.F->K \t\t\t\t5. deg.C->K \n");
    print('c',"\t3. K->deg.F \t\t\t\t6. K->deg.C \n");
}

void velocity()//Function to print options in velocity
{
    print('y',"VELOCITY.\n\n");
    print('c',"\t1. km/h->m/s \t\t\t2. m/s->km/h \n");
}
void pressure()//Function to print options in pressure
{
    print('y',"PRESSURE.\n\n");
    print('c',"\t1. atm->Pa \t\t\t 3. mmHg->Pa \n");
    print('c',"\t2. Pa->atm \t\t\t 4. Pa->mmHg \n");
}
void energy()//Function to print options in energy
{
    print('y',"ENERGY.\n\n");
    print('c',"\t1. J->cal \t\t\t2. cal->J \n");

}
void power()//Function to print options in power
{
    print('y',"POWER.\n\n");
    print('c',"\t1. hp->kW \t\t\t2. kW->hp \n");
}

void menu2(int o)//Function to print menu 2.
{
    print('c',"\nENTER\t\t\t0.BACK\n");
    switch(o)
    {
        case 1:
            length();
            break;
        case 2:
            volume();
            break;
        case 3:
            area();
            break;
        case 4:
            mass();
            break;
        case 5:
            temperature();
            break;
        case 6:
            velocity();
            break;
        case 7:
            pressure();
            break;
        case 8:
            energy();
            break;
        case 9:
            power();
            break;
    }
}

int checko2(int o1,int o2)//Checking the given option2 is correct or no 
{
    switch(o1)
    {
        case 1:
            if(o2>=0&&o2<=9)
                return 1;
            else
                return 0;
            break;
        case 2:
            if(o2>=0&&o2<=2)
                return 1;
            else
                return 0;
            break;
        case 3:
            if(o2>=0&&o2<=4)
                return 1;
            else
                return 0;
            break;
        case 4:
            if(o2>=0&&o2<=4)
                return 1;
            else
                return 0;
            break;
        case 5:
            if(o2>=0&&o2<=6)
                return 1;
            else
                return 0;
            break;
        case 6:
            if(o2>=0&&o2<=2)
                return 1;
            else
                return 0;
            break;
        case 7:
            if(o2>=0&&o2<=4)
                return 1;
            else
                return 0;
            break;
        case 8:
            if(o2>=0&&o2<=2)
                return 1;
            else
                return 0;
            break;
        case 9:
            if(o2>=0&&o2<=2)
                return 1;
            else
                return 0;
            break;
    }
}

void evaluate(int o1,int o2)//The function which computes the conversion.
{
    float f1;//input is stored in this identifier.
    switch(o1)//Choosing from option 1
    {
        case 1:
            switch(o2)//Choosing form option 2
            {
                case 1:
                    print('c',"in->cm:");//Printing in cyan color the string "in->cm:"
                    scanf("%f",&f1);//Taking input
                    print_num('g',"%.2f",f1);//Printing in green "format",number
                    print('c',"in->cm");//Printing "in->cm" in color cyan
                    print_num('g',"%.2f",f1*2.54);//Printing in green "format", result after computation.
                    break;
                case 2://All the other cases are dealt in the same way.
                    print('c',"cm->in:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"cm->in");
                    print_num('g',"%.2f",f1*50.0/127.0);
                    break;
                case 3:
                    print('c',"ft->m:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"ft->m");
                    print_num('g',"%.2f",f1*.3048);
                    break;
                case 4:
                    print('c',"m->ft:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"m->ft");
                    print_num('g',"%.2f",f1*1250.0/381.0);
                    break;
                case 5:
                    print('c',"in->ft:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"in->ft");
                    print_num('g',"%.2f",f1*635.0/7620.0);
                    break;
                case 6:
                    print('c',"yd->m:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"yd->m");
                    print_num('g',"%.2f",f1*.9144);
                    break;
                case 7:
                    print('c',"m->yd:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"m->yd");
                    print_num('g',"%.2f",f1*1250.0/1143.0);
                    break;
                case 8:
                    print('c',"mile->km:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"mile->km");
                    print_num('g',"%.2f",f1*1.609344);
                    break;
                case 9:
                    print('c',"km->mile:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"km->mile");
                    print_num('g',"%.2f",f1*.621371);
                    break;
            }
            break;
        case 2:
            switch(o2)
            {
                case 0:
                    break;
                case 1:
                    print('c',"gal->L:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"gal->L");
                    print_num('g',"%.2f",f1*3.785412);
                    break;
                case 2:
                    print('c',"L->gal:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"L->gal");
                    print_num('g',"%.2f",f1*1.0/3.785412);
                    break;
            }
            break;
        case 3:
            switch(o2)
            {

                case 1:
                    print('c',"acre->m.sq.:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"acre->m.sq.");
                    print_num('g',"%.2f",f1*4046.856);
                    break;
                case 2:
                    print('c',"m.sq.->acre:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"m.sq.->acre");
                    print_num('g',"%.2f",f1*125.0/505857.0);
                    break;
                case 3:
                    print('c',"sq.ft->acre:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"sq.ft->acre");
                    print_num('g',"%.2f",f1/43560.0);
                    break;
                case 4:
                    print('c',"acre->sq.ft:");
                    scanf("%f",&f1);
                    print_num('g',"%.2f",f1);
                    print('c',"acre->sq.ft");
                    print_num('g',"%.2f",f1*43560);
                    break;
            }
            break;
        case 4:
            {
                switch(o2)
                {
                    case 1:
                        print('c',"oz->g:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"oz->g");
                        print_num('g',"%.2f",f1*28.34952);
                        break;
                    case 2:
                        print('c',"g->oz:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"g->oz");
                        print_num('g',"%.2f",f1*1.0/28.34952);
                        break;
                    case 3:
                        print('c',"lb->kg:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"lb->kg");
                        print_num('g',"%.2f",f1*.4535924);
                        break;
                    case 4:
                        print('c',"kg->lb:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"kg->lb");
                        print_num('g',"%.2f",f1*1.0/.4535924);
                        break;
                }
                break;
            case 5:
                switch(o2)
                {
                    case 1:
                        print('c',"deg.F->deg.C:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"deg.F->deg.C");
                        print_num('g',"%.2f",(f1-32.0)*(5.0/9));
                        break;
                    case 2:
                        print('c',"deg.F->K:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"deg.F->K");
                        print_num('g',"%.2f",(f1+459.67)*(5.0/9.0));
                        break;
                    case 3:
                        print('c',"K->deg.F:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"K->deg.F");
                        print_num('g',"%.2f",(f1*9.0/5)-459.67);
                        break;
                    case 4:
                        print('c',"deg.C->deg.F:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"deg.C->deg.F");
                        print_num('g',"%.2f",(f1*9.0/5)+32.0);
                        break;
                    case 5:
                        print('c',"deg.C->K:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"deg.C->K");
                        print_num('g',"%.2f",f1+273.15);
                        break;
                    case 6:
                        print('c',"K->deg.C:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"K->deg.C");
                        print_num('g',"%.2f",f1-273.15);
                        break;
                }
                break;
            case 6:
                switch(o2)
                {
                    case 1:
                        print('c',"km/h->m/s:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"km/h->m/s");
                        print_num('g',"%.2f",f1*5.0/18);
                        break;
                    case 2:
                        print('c',"m/s->km/h:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"m/s->km/h");
                        print_num('g',"%.2f",f1*18.0/5);
                        break;
                }
                break;
            case 7:
                {
                    switch(o2)
                    {

                    case 1:
                        print('c',"atm->Pa:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"atm->Pa");
                        print_num('g',"%.2f",f1*101325);
                        break;
                    case 2:
                        print('c',"Pa->atm:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"Pa->atm");
                        print_num('g',"%.2f",f1*1.0/101325);
                        break;
                    case 3:
                        print('c',"mmHg->Pa:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"mmHg->Pa");
                        print_num('g',"%.2f",f1*133.3224);
                        break;
                    case 4:
                        print('c',"Pa->mmHg:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"Pa->mmHg");
                        print_num('g',"%.2f",f1*1.0/133.3224);
                        break;
                    }
                    break;
                case 8:
                    switch(o2)
                    {

                    case 1:
                        print('c',"J->cal:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"J-cal>");
                        print_num('g',"%.2f",f1*5000.0/20929);
                        break;
                    case 2:
                        print('c',"cal->J:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"cal->J");
                        print_num('g',"%.2f",f1*20929.0/5000);
                        break;
                    }
                    break;
                case 9:
                    switch(o2)
                    {
                    
                    case 1:
                        print('c',"hp->kW:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"hp->kW");
                        print_num('g',"%.2f",f1*.7457);
                        break;
                    case 2:
                        print('c',"kW->hp:");
                        scanf("%f",&f1);
                        print_num('g',"%.2f",f1);
                        print('c',"kW->hp");
                        print_num('g',"%.2f",f1*1.0/.7457);
                        break;
                    }
                }
            }
    }
}
void main(int c,char*v[])//The main function.
{
    int o1,o2;//These identifiers store the details of option 1,2.

    while(1)
    {
    clrscr();//To clear the screen
    menu1();//To print menu 1
    scanf("%d",&o1);//Taking option 1
    while(!(o1>=0&&o1<=9))//Checking option 1 is correct or no.
    {
        clrscr();//To clear screen
        print('r',"Enter correct input");//Print red the string "Enter correct input".
        menu1();//To print menu 1
        getchar();//to clear buffer
        scanf("%d",&o1);//Taking option 1
    }
    if(!o1)//If option 1 is 0
        exit(0);//Exit the program
    clrscr();
    menu2(o1);
    scanf("%d",&o2);
    while(!checko2(o1,o2))//Enter the correct number in option 2
    {
        clrscr();
        print('r',"Enter correct input");
        menu2(o1);
        getchar();
        scanf("%d",&o2);
    }
    if(o2)//We have correct option 2 therfore evaluate
    {
    evaluate(o1,o2);
    getchar();
    getchar();//Clear Buffer.
    }
    }
}
