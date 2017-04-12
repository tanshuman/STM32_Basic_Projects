#include "stm32l1xx.h"

int main()
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIO_InitTypeDef Std_Periph_Struct;
  
  Std_Periph_Struct.GPIO_Pin = GPIO_Pin_5;
  Std_Periph_Struct.GPIO_Mode = GPIO_Mode_OUT;
  Std_Periph_Struct.GPIO_Speed = GPIO_Speed_10MHz;
  Std_Periph_Struct.GPIO_OType = GPIO_OType_PP;
  Std_Periph_Struct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &Std_Periph_Struct);
  
  while(1)
  {
  GPIO_SetBits(GPIOA, GPIO_Pin_5);
  for(int i=0; i<=500000; i++) ;
  GPIO_ResetBits(GPIOA, GPIO_Pin_5);
  for(int i=0; i<=500000; i++) ;
  }
  
}