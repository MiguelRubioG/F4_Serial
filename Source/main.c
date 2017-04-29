#include <stm32f4xx.h>
#include "delay.h"
#include "USART2.h"
#include <stdio.h>


uint32_t i,j;
uint8_t character;
uint8_t message1[50]= "\r\nWrite a sentende terminated by Enter\r\n";
uint8_t message2[50];
uint8_t message3[50]="The sentence written is:\r\n";
uint8_t message4[4]="\r\n";
char message5[4];
double reading= 3.71;

int main( )
{
	//Initialization stage
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	
	GPIOD->MODER |= 1<<(2*12);
	GPIO_Configuration2();
	USART2_Configuration();
	
	while(1)
	{
		for(i=0x30;i<0x80;i++)
    {
      SendChar2(i); 
			_delay_ms(500);
      //character=GetChar2(); 
    }
	}
}
