/**
  ******************************************************************************
  * File   : USART/Printf/main.c 
  * Version: V1.2.4
  * Date   : 2020-08-26
  * Brief  : Main program body
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"
#include "at32_board.h"
#include <stdio.h>

/** @addtogroup AT32F421_StdPeriph_Examples
  * @{
  */
static void Delay(uint32_t delay)
{
  uint32_t i;

  for(i = 0; i < delay; i++)
    ;
}

/** @addtogroup USART_Printf
  * @{
  */ 
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
extern	void ADC_START(void);
extern __IO uint16_t ADCConvertedValue;
int main(void)
{     
	int lastValue=0,maxValue=0,minValue=0;
	int diff =0 ;
  UART_Print_Init(115200);

  /* Output a message on Hyperterminal using printf function */
  printf("start ADC-DMA TEST\n\r");

	ADC_START();
	
  Delay(10000);
	lastValue=ADCConvertedValue;
  maxValue=ADCConvertedValue;
  minValue=ADCConvertedValue;
	
	while (1)
	{
		Delay(900000);
    maxValue = ADCConvertedValue>maxValue?  ADCConvertedValue:maxValue;
    minValue = ADCConvertedValue<minValue?  ADCConvertedValue:minValue;
    diff = ADCConvertedValue - lastValue;
		lastValue=ADCConvertedValue;
		printf("\r\nADCConvertedValue=%d\r\n",ADCConvertedValue);
    printf("diff=%d\r\n",diff);
    printf("maxValue=%d,minValue=%d\r\n",maxValue,minValue);
	}	
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}

#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2018 ArteryTek *****END OF FILE****/ 
