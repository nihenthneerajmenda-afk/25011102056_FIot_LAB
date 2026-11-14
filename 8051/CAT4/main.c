#include<stdio.h>
#include<reg51.h>

sbit in = P2^7;
sbit out = P2^3;

sbit led1 = P1^0;
sbit led2 = P1^1;
sbit led3 = P1^2;
sbit led4 = P1^3;


sbit A = P0^0 ;
sbit B1 = P0^1 ;
sbit C = P0^2 ;
sbit D = P0^3 ;
sbit E = P0^4 ;
sbit F = P0^5 ;
sbit G = P0^6 ;
sbit DP = P0^7 ;

int mode = 0;
int counter = 0;

void delay()
{
    int i,j;
    for(i=0;i<120;i++)
        for(j=0;j<120;j++);
}

void display_digit(unsigned char value)
{
	switch(value)
	{
				case 0: A=1;B1=1;C=1;D=1;E=1;F=1;G=0; break;
        case 1: A=0;B1=1;C=1;D=0;E=0;F=0;G=0; break;
        case 2: A=1;B1=1;C=0;D=1;E=1;F=0;G=1; break;
        case 3: A=1;B1=1;C=1;D=1;E=0;F=0;G=1; break;
        case 4: A=0;B1=1;C=1;D=0;E=0;F=1;G=1; break;
        case 5: A=1;B1=0;C=1;D=1;E=0;F=1;G=1; break;
        case 6: A=1;B1=0;C=1;D=1;E=1;F=1;G=1; break;
        case 7: A=1;B1=1;C=1;D=0;E=0;F=0;G=0; break;
        case 8: A=1;B1=1;C=1;D=1;E=1;F=1;G=1; break;
        case 9: A=1;B1=1;C=1;D=1;E=0;F=1;G=1; break;
        default: break;
	}
}

void mode0(){
	display_digit(0);
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
}

void mode1(){
	display_digit(1);
	led1 = 1;
	led2 = 0;
	led3 = 0;
	led4 = 0;
}

void mode2(){
	display_digit(2);
	led1 = 0;
	led2 = 1;
	led3 = 0;
	led4 = 0;
}

void mode3(){
	display_digit(3);
	led1 = 0;
	led2 = 0;
	led3 = 1;
	led4 = 0;
}
	
void mode4(){
	display_digit(4);
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 1;
}

void mode5(){
	display_digit(5);
	  led1 = 1 ;led2 = 0 ;led3 = 0 ; led4 = 0;
	  delay();
	  led1 = 0 ;led2 = 1 ;led3 = 0 ; led4 = 0;
	  delay();
	  led1 = 0 ;led2 = 0 ;led3 = 1 ; led4 = 0;
	  delay();
	  led1 = 0 ;led2 = 0 ;led3 = 0 ; led4 = 1;
	  delay();
}
	
void mode6(){
	display_digit(6);
	led1 = 1 ;led2 = 0 ;led3 = 1 ; led4 = 0;
	  delay();
	led1 = 0 ;led2 = 1 ;led3 = 0 ; led4 = 1;
	  delay();
}

void mode7()
{
	display_digit(7);
    if(counter == 0)  { led1=0; led2=0; led3=0; led4=0; }
    else if(counter == 1)  { led1=1; led2=0; led3=0; led4=0; }
    else if(counter == 2)  { led1=0; led2=1; led3=0; led4=0; }
    else if(counter == 3)  { led1=1; led2=1; led3=0; led4=0; }
    else if(counter == 4)  { led1=0; led2=0; led3=1; led4=0; }
    else if(counter == 5)  { led1=1; led2=0; led3=1; led4=0; }
    else if(counter == 6)  { led1=0; led2=1; led3=1; led4=0; }
    else if(counter == 7)  { led1=1; led2=1; led3=1; led4=0; }
    else if(counter == 8)  { led1=0; led2=0; led3=0; led4=1; }
    else if(counter == 9)  { led1=1; led2=0; led3=0; led4=1; }
    else if(counter == 10) { led1=0; led2=1; led3=0; led4=1; }
    else if(counter == 11) { led1=1; led2=1; led3=0; led4=1; }
    else if(counter == 12) { led1=0; led2=0; led3=1; led4=1; }
    else if(counter == 13) { led1=1; led2=0; led3=1; led4=1; }
    else if(counter == 14) { led1=0; led2=1; led3=1; led4=1; }
    else if(counter == 15) { led1=1; led2=1; led3=1; led4=1; }

    delay();

    counter = counter + 1;
    if(counter > 15)
    {
        counter = 0;
    }
}

void mode8(){
	display_digit(8);
	led1 = 1;
	led2 = 1;
	led3 = 1;
	led4 = 1;
	delay();
	
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
	delay();

}
	
void mode9(){
	display_digit(9);
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
}



void check()
{
    if(in == 0)
    {
        delay();
        if(in == 0)
        {
            mode = (mode+1)%10;
            while(in==0){}
            delay();
        }
    }
}

void run()
{
    if(mode == 0)
    {
        mode0();
    }
    else if(mode == 1)
    {
        mode1();
    }
    else if(mode == 2)
    {
        mode2();
    }
    else if(mode == 3)
    {
        mode3();
    }
    else if(mode == 4)
    {
        mode4();
    }
		else if(mode == 5)
    {
        mode5();
    }
		else if(mode == 6)
    {
        mode6();
    }
		else if(mode == 7)
    {
        mode7();
    }
		else if(mode == 8)
    {
        mode8();
    }
		else if(mode == 9)
    {
        mode9();
    }
}

void main()
{
    out = 0;
    mode = 0;
    counter = 0;

    while(1)
    {
        check();
        run();
    }
}