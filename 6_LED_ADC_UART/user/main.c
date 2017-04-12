#include "stm32f4xx.h"
#include "user_config.h"

int main()
{
  RCC->AHB1ENR |= ((uint32_t)0x00000010);
  return 1;
}