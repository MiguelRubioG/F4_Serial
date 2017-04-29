//usart 2.c
#include <stm32f4xx.h>

/* I/O ports configuration */
void GPIO_Configuration2 (void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	
	//PD5 configuration
	GPIOD->MODER |= 2<<(5*2);
	GPIOD->AFR[0] |= 7<<(5*4);
	
	//PD6 configuration
	GPIOD->MODER |= 2<<(6*2);
	GPIOD->AFR[0] |= 7<<(6*4);
	
}

void USART2_Configuration(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable USART2 clock
 
  USART2->BRR = 42000000/115200;
  
  USART2->CR1  &=  ~USART_CR1_OVER8; // Oversampling mode = 16 
  USART2->CR1  &=  ~USART_CR1_M;     // Word length = 8 bits
  USART2->CR1  &=  ~USART_CR1_PCE;   // No parity
  USART2->CR1  |=   USART_CR1_TE;    // Transmitter enable
  USART2->CR1  |=   USART_CR1_RE;    // Receiver enable
  USART2->CR1  |=   USART_CR1_UE;    // USART enable
  
  USART2->CR2  &= ~(USART_CR2_STOP_1 | USART_CR2_STOP_0); // one stop bit
}

void SendChar2 (uint8_t ch)  
{
  while (!(USART2->SR & USART_SR_TXE));
  USART2->DR = (ch & 0xFF);
}

uint8_t GetChar2 (void)  
{
  while (!(USART2->SR & USART_SR_RXNE));
  return ((uint8_t)(USART2->DR & 0xFF));
}

void SendString2(uint8_t *ptr)
{
  do
  {
    SendChar2(*ptr);
    ptr++;
  } while (*ptr !=0);
}

void GetString2(uint8_t *ptr)
{
  do
  {
    ptr++;
    *ptr = GetChar2();
  } while (*ptr != '\r');
}

void ClearString2(uint8_t *ptr)
{
  uint8_t i;
  for (i=0;i<20;i++)
    *ptr++ = 0;
}
