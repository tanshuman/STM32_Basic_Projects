#define LED_PIN GPIO_Pin_5
#define SWT_PIN GPIO_Pin_13


/*Config Clock for ADC and GPIO***************************/



void initialize_hwd(void)
{
  GPIO_InitTypeDef  GPIO_Init_Config;
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    
  GPIO_Init_Config.GPIO_Pin = LED_PIN;
  GPIO_Init_Config.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init_Config.GPIO_Speed = GPIO_Fast_Speed;
  GPIO_Init_Config.GPIO_OType = GPIO_OType_PP;
  GPIO_Init_Config.GPIO_PuPd = GPIO_PuPd_DOWN;
  
  GPIO_Init(GPIOA, &GPIO_Init_Config);
}