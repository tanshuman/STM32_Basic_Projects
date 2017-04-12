/*
See folders for files included

Version - 1.0
Date - 14/10/2016
Author - Anshuman Tripathi

*/
#include "stm32f4xx.h"

//defining pin number of PORTx that is connected to LED
#define LED_PIN GPIO_Pin_5

int main(void)
{
  //activating peripheral clock for Port A
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  //typedef for PIN configurations - GPIO Init structure definition
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  //config for different param at GPIO_InitTypeDef
  GPIO_InitStructure.GPIO_Pin = LED_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  while(1)
  {
    for(int j=900000; j>1; j=j-25000)
    {
      GPIO_SetBits(GPIOA, LED_PIN); //set GPIOx
      for(int i=0; i<j; i++) ;
      GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
      for(int i=0; i<j; i++) ;
    }
    for(int j=1; j<900000; j=j+25000)
    {
      GPIO_SetBits(GPIOA, LED_PIN);
      for(int i=0; i<j; i++) ;
      GPIO_ResetBits(GPIOA, LED_PIN);
      for(int i=0; i<j; i++) ;
    }
    
  }
}

