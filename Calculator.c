/*****************************************************
Project : Simple Calculator
Version : 
Date    : 5/22/2014
Author  : Niloofar Zendehdel
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <stdio.h>
// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include<math.h>
#include <stdlib.h>
// Declare your global variables here
void calculation (void);
void num(int  x);
int m=0;
int n=0;
long int temp[2];
int operator[1];
bit flag=0;
bit nflag=0,mflag=0;
long int ans=0;
int f2=0;
float fans=0;
void main()
{
// Declare your local variables here
char lcd_buffer[16];

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTB Bit 0
// RD - PORTB Bit 1
// EN - PORTB Bit 2
// D4 - PORTB Bit 4
// D5 - PORTB Bit 5
// D6 - PORTB Bit 6
// D7 - PORTB Bit 7
// Characters/line: 16
lcd_init(16);
DDRD=0x0f;
while (1)
      {
      
      PORTD=0x01;
      delay_us(100);
      /********************/   
      /*77777777777777777777*/
      if(PIND.4==1) 
       {
        if(flag==1)
        {
          lcd_clear();
          flag=0;
        }
      lcd_putchar('7');
      temp[n]=temp[n]*10+7; 
      nflag=1;
      delay_us(100);
      } 
      /*888888888888888888888*/
      else if(PIND.5==1)
      {
       if(flag==1)
       {
         lcd_clear();
         flag=0;
       }
      lcd_putchar('8');
      temp[n]=temp[n]*10+8;
      nflag=1;
      delay_us(100);
      } 
      /*9999999999999999999999*/
      else if(PIND.6==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('9');
      temp[n]=temp[n]*10+9; 
      nflag=1; 
      delay_us(100);
      }
      ///////////////////////
      else if(PIND.7==1)
      {
        if (flag==1)
        {
         lcd_clear();
         lcd_putsf("ans/");
         temp[n]=ans;
         flag=0;
         delay_us(100);
        }
      else 
       {
        lcd_putchar('/');
        delay_us(100);
       }
      operator[n]=4;
      n++;
      } 
      /*********************/
      PORTD=0x02;
      delay_us(100);
      /********************/ 
      /*44444444444444444444*/ 
      if(PIND.4==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('4');
      temp[n]=temp[n]*10+4;
      nflag=1;
      delay_us(100);
      } 
      /*55555555555555555555*/
      else if(PIND.5==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('5'); 
      temp[n]=temp[n]*10+5;
      nflag=1; 
      delay_us(100);
      }
      /*666666666666666666666*/
      else if(PIND.6==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('6');
      temp[n]=temp[n]*10+6; 
      nflag=1;
      delay_us(100);
      }
      /*********************/
      else if(PIND.7==1)
      {
       if (flag==1)
        {
         lcd_clear();
         lcd_putsf("ans*");
         temp[n]=ans;
         flag=0;
         delay_us(100);
        }
       else 
        {
         lcd_putchar('*');
         delay_us(100);
        }
      operator[n]=3;
      n++;
      }
      /********************/
      PORTD=0x04;  
      delay_us(100);
      /*111111111111111111111*/
      if(PIND.4==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('1');
      temp[n]=temp[n]*10+1; 
      nflag=1;
      delay_us(100);
      }  
      /*22222222222222222222222*/
      else if(PIND.5==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('2');
      temp[n]=temp[n]*10+2;
      nflag=1; 
      delay_us(100);
      }  
      /*33333333333333333333333*/
      else if(PIND.6==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('3');
      temp[n]=temp[n]*10+3;
      nflag=1; 
      delay_us(100);
      }  
      /*------------------------*/
      else if(PIND.7==1)
      {
       if (flag==1)
        {
         lcd_clear();
         lcd_putsf("ans-");
         temp[n]=ans;
         flag=0;
         delay_us(100);
         operator[n]=2;
         n++;
       }
       else 
       { 
        lcd_putchar('-');
        delay_us(100);
        if(nflag==0)
         mflag=1;
        else
        {
         operator[n]=2;
         n++;
        }
       }

      } 
      /*************************/
      PORTD=0x08;
      delay_us(100);
      /*************************/
      /*on on on on on on on on */
      if(PIND.4==1)
      {
       lcd_clear();
       delay_us(100);
       flag=0;
       nflag=0;
       mflag=0;
       ans=0;
       f2=0;
      }  
      /*0000000000000000000000000*/
      else if(PIND.5==1)
      {
       if(flag==1)
        {
         lcd_clear();
         flag=0;
        }
      lcd_putchar('0');
      temp[n]=temp[n]*10+0;
      nflag=1;
      delay_us(100);
      }
      /*=========================*/
      else if(PIND.6==1)
      { 
       if(flag==1)
        delay_ms(25);
        
       calculation();  
       if(f2!=0)
       { 

        if(f2<0 && ans!=0)
        {
         lcd_gotoxy(0,1);
         sprintf(lcd_buffer,"=%d.%d",ans,abs(f2));
         lcd_puts(lcd_buffer); 
        } 
        else if(f2<0 && ans==0) 
        {
         lcd_gotoxy(0,1);
         sprintf(lcd_buffer,"=-%d.%d",ans,abs(f2)); 
         lcd_puts(lcd_buffer);
        } 
        else
        {
         lcd_gotoxy(0,1);
         sprintf(lcd_buffer,"=%d.%d",ans,f2); 
         lcd_puts(lcd_buffer);
        }
        
       
       }
       else
        { 
         lcd_gotoxy(0,1);
         sprintf(lcd_buffer,"=%d",ans); 
         lcd_puts(lcd_buffer);
        }
       
       temp[0]=0;
       temp[1]=0;
       flag=1;
       n=0;
      }
      /*++++++++++++++++++*/
      else if(PIND.7==1)
      {
       if (flag==1)
        {
         lcd_clear();
         lcd_putsf("ans+"); 
         delay_us(100);
         temp[n]=ans;
         flag=0;
         operator[n]=1;
         n++;
        } 
       else 
        {
         lcd_putchar('+');
         delay_us(100);
         if(nflag!=0)
         {
          operator[n]=1;
          n++;
         }
        }
      } 
      //////////////////////////
      delay_ms(30);
      }
}

void calculation(void)
{ 
  ans=0; 
  if(mflag==1)
  {
   temp[0]*=-1;
   mflag=0;
  }
  if(operator[0]==1)
  {
   ans=temp[0]+temp[1]; 
   if(f2<0 && temp[0]<0)
   { 
    if(temp[0]==0)
    {
     ans=(temp[1]-1);
     f2=100+f2;
    }
    else if(abs(temp[0])<temp[1])
    {
    ans=(temp[0]+temp[1])-1;
    f2=100+f2; 

    }
    
   }

  }
  else if(operator[0]==2)
  {
   ans=temp[0]-temp[1];  
   if(f2>0) 
    { 
     if( temp[0]==0)
     {
      ans=(temp[1]-1)*(-1);
      f2=(100-f2)*(-1);
     }
     else if(temp[1]>temp[0])
     {
     ans=temp[0]-temp[1]+1;
     f2=(100-f2)*(-1);
     }
    }
  }
  else if(operator[0]==3)
  {
   ans=temp[0]*temp[1];
   f2*=temp[1];
   if((f2/100)!=0)
   {
   ans+=(f2/100);
   f2=(f2%100);
   }

  }
  else if(operator[0]==4) 
  {
   ans=temp[0]/temp[1]; 
   if(f2==0)
   {
    if((temp[0]%temp[1])!=0)
    f2=((temp[0]%temp[1])*100)/temp[1];
   }
   else
   { 
    f2=f2/temp[1];
    if((temp[0]%temp[1])!=0)
    f2+=((temp[0]%temp[1])*100)/temp[1];
    if((f2/100)!=0)
    {
     ans+=(f2/100);
     f2=(f2%100);
    }
   }
   

   
  }
}

void num(int x)
{
 
 lcd_putchar(48+(x/1000000)/100000);
 lcd_putchar(48+(x%100000)/10000); 
 lcd_putchar(48+(x%10000)/1000); 
 lcd_putchar(48+(x%1000)/100);
 lcd_putchar(48+(x%100)/10);
 lcd_putchar(48+x%10);
 lcd_putchar(' ');  

 }