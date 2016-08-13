/**
  ******************************************************************************
  * @file    main.c
  * @author  Peytom
  * @version V1.0
  * @date    2016-03-06
  * @brief   测试led
  ******************************************************************************
*/
#include "stm32f10x.h"                  // Device header 
#include "bsp.c"   
//#define KEY_ON	0
//#define KEY_OFF	1
void Delay(__IO u32 nCount); 		
//void LED_GPIO_Config(void);
//void Key_GPIO_Config(void);
//uint8_t Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin,uint8_t Down_state);
int main(void)
{
	LED_GPIO_Config();
	Key_GPIO_Config();	
while(1)
    {
			if( Key_Scan(GPIOA,GPIO_Pin_0,1) == KEY_ON  )
		{
			/*LED1反转*/
		 GPIO_ResetBits(GPIOB,GPIO_Pin_0);
     Delay(0x0FFFFF);
     GPIO_SetBits(GPIOB,GPIO_Pin_0);
		 GPIO_ResetBits(GPIOF,GPIO_Pin_7);
     Delay(0x0FFFFF);
		 GPIO_SetBits(GPIOF,GPIO_Pin_7);
		 Delay(0x0FFFFF);
		 GPIO_ResetBits(GPIOF,GPIO_Pin_8);
		 Delay(0x0FFFFF);
		 GPIO_SetBits(GPIOF,GPIO_Pin_8);
		}   
     
    }
}
void Delay(__IO u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
