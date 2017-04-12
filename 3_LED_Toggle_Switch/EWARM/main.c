/*
See folders for files included

Version - 1.0
Date - 14/10/2016
Author - Anshuman Tripathi

*/
*/
#include "stm32f4xx.h"

//defining pin number of PORTx that is connected to LED
#define LED_PIN GPIO_Pin_5
#define SWT_PIN GPIO_Pin_13

int main(void)
{
  //activating peripheral clock for Port A
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  //typedef for PIN configurations - GPIO Init structure definition
  GPIO_InitTypeDef  GPIO_Init_LED, GPIO_Init_SWT;
  
  //config for different param at GPIO_InitTypeDef
  GPIO_Init_LED.GPIO_Pin = LED_PIN;
  GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init_LED.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
  GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_Init_LED);
  
  //config for different param at GPIO_InitTypeDef
  GPIO_Init_SWT.GPIO_Pin = SWT_PIN;
  GPIO_Init_SWT.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init_SWT.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init_SWT.GPIO_OType = GPIO_OType_PP;
  GPIO_Init_SWT.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOC, &GPIO_Init_SWT);
  
  
  while(1)
  {
    for(int j=100000; j>1; j=j-1000)
    {
      GPIO_SetBits(GPIOA, LED_PIN); //set GPIOx
      for(int i=0; i<j; i++)
        if(!GPIO_ReadInputDataBit(GPIOC, SWT_PIN))
          GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
      GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
      for(int i=0; i<j; i++)
        if(!GPIO_ReadInputDataBit(GPIOC, SWT_PIN))
          GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
    }
    for(int j=1; j<100000; j=j+10000)
    {
      GPIO_SetBits(GPIOA, LED_PIN); //set GPIOx
      for(int i=0; i<j; i++)
        if(!GPIO_ReadInputDataBit(GPIOC, SWT_PIN))
          GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
      GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
      for(int i=0; i<j; i++)
        if(!GPIO_ReadInputDataBit(GPIOC, SWT_PIN))
          GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
    }
    
  }
}

