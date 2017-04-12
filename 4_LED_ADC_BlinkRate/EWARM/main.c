/*
Version - 1.0
Date - 14/10/2016
Author - Anshuman Tripathi

*/


#include "main.h"

/*User Definitions*****************************************/
#define LED_PIN GPIO_Pin_5
#define SWT_PIN GPIO_Pin_13
#define ADC_PIN GPIO_Pin_1

/*Function Definitions*************************************/
void initialize_hwd(void);
int readADC1();

/* Private variables ---------------------------------------------------------*/
int uhADCxConvertedValue = 0;
int uwADCxConvertedVoltage = 0;

int main()
{
  initialize_hwd();
  while(1)
  {
    uhADCxConvertedValue = readADC1();
    uwADCxConvertedVoltage = uhADCxConvertedValue*150;
    
    GPIO_ResetBits(GPIOA, LED_PIN); //reset GPIOx
    for(int i=0; i<=uwADCxConvertedVoltage; i++) ; 
    for(int j=0; j<75000; j++);
    GPIO_SetBits(GPIOA, LED_PIN); //set GPIOx
    for(int i=0; i<=uwADCxConvertedVoltage; i++) ;
    for(int j=0; j<75000; j++);
  }
  
}


int readADC1()
{
  ADC_SoftwareStartConv(ADC1);
  // Wait until conversion completion
  while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
  // Get the conversion value
  return ADC_GetConversionValue(ADC1);
}



/* HARDWARE CONFIGURATIONS*********************************/
void initialize_hwd()
{
  GPIO_InitTypeDef      GPIO_Init_Config;
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  
  /*Default Configurations********************************/
  GPIO_Init_Config.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init_Config.GPIO_Speed = GPIO_Fast_Speed;
  GPIO_Init_Config.GPIO_OType = GPIO_OType_PP;
  GPIO_Init_Config.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  /*Configuration for onboard LED Pin***********************/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  GPIO_Init_Config.GPIO_Pin = LED_PIN;
  GPIO_Init(GPIOA, &GPIO_Init_Config);
  
  /*Configuration for onboard toggle switch******************/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_Init_Config.GPIO_Pin = SWT_PIN;
  GPIO_Init_Config.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_Init_Config);
  
  /*Configuration for ADC Pin********************************/  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); 
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  GPIO_Init_Config.GPIO_Pin = ADC_PIN;
  GPIO_Init_Config.GPIO_Mode = GPIO_Mode_AN;
  GPIO_Init(GPIOA, &GPIO_Init_Config);
  
  /*ADC Common Init******************************************/
  ADC_CommonInitStructure.ADC_Mode = ADC_DualMode_RegSimult;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
  ADC_CommonInit(&ADC_CommonInitStructure);
  
  /* ADC3 Init ****************************************************************/
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 1;
  ADC_Init(ADC1, &ADC_InitStructure);
  
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_3Cycles);
  /* Enable ADC1 */
  ADC_Cmd(ADC1, ENABLE);
  
  
}