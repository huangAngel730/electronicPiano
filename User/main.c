#include "stm32f10x.h"                  // Device  header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#define BUZZER_TIM TIM2
#include "LED.h"
#include "Serial.h"
#include "electronic_keyboard.h"

#define STM32_FREQ 72000000

uint8_t i;			//定义for循环的变量
uint8_t KeyNum=0;
uint8_t number =100;
const uint32_t note_frequencies[] = {
    262, // do
    294, // re
    330, // me
    349, // fa
    392, // so
    440, // la
    494,// si
	523
};

int main(void)
{
	//int frequency1;
	/*模块初始化*/
 	//OLED_Init();		//OLED初始化 
	PWM_Init(1);	
//	LED_Init();
	Key_Init();
	Serial_Init();

    while (1) 
	{
		//Buzzer_PlayNote(1, 500);
	//	 SendPWMFrequencyToPC(note_frequencies[1]);
		//OLED_ShowNum(1,1,TIM_GetCounter(TIM2),8);
        	//	 Serial_SendNumber(123, 3);
		Key_GetNum();
//		number = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8);
//		Serial_SendNumber(number, 1);
//		Delay_ms(1000);
		
		KeyNum =Key_GetNum();
		//LED1();	
	
//		switch(KeyNum)
//		{
//		case 1:`
//		
//		
//			Buzzer_PlayNote(0, 500); 
//			 SendPWMFrequencyToPC(note_frequencies[0]);
//			//KeyNum=0;
//			
//			break;
//		case 2:
//		
//		
//			Buzzer_PlayNote(1, 500); 
//			 SendPWMFrequencyToPC(note_frequencies[1]);
//			//KeyNum=0;
//			
//			break;
//		case 3:
//		
//		
//			Buzzer_PlayNote(2, 500); 
//			 SendPWMFrequencyToPC(note_frequencies[2]);
//			//KeyNum=0;
//			
//			break;
//		case 4:
//		
//		
//			Buzzer_PlayNote(3, 500); 
//			 SendPWMFrequencyToPC(note_frequencies[3]);
//			//KeyNum=0;
//			
//			break;
//		
		if (KeyNum==1)
		{
			Buzzer_PlayNote(0, 500); 
			 SendPWMFrequencyToPC(note_frequencies[0]);
		//	Serial_SendNumber(321, 3);
//			KeyNum=0;
//			LED1_Turn();
			
		}
	if (KeyNum==2)
		{
			Buzzer_PlayNote(1, 500); 
			 SendPWMFrequencyToPC(note_frequencies[1]);
//			KeyNum=0;
//			LED1_Turn();
			
		}
		if (KeyNum==3)
		{
			Buzzer_PlayNote(2, 500); 
//			KeyNum=0;
		
		 SendPWMFrequencyToPC(note_frequencies[2]);
		}
		if (KeyNum==4)
		{
			Buzzer_PlayNote(3, 500); 
			 SendPWMFrequencyToPC(note_frequencies[3]);
		}
			
		
		if (KeyNum==5)
		{
			Buzzer_PlayNote(4, 500); 
		 SendPWMFrequencyToPC(note_frequencies[4]);
			//LED1_ON();
		}
		if (KeyNum==6)
		{
			Buzzer_PlayNote(5, 500); 
			SendPWMFrequencyToPC(note_frequencies[5]);
			//LED1_ON();
		}
		if (KeyNum==7)
		{
			Buzzer_PlayNote(6, 500); 
			 SendPWMFrequencyToPC(note_frequencies[6]);
			//LED1_ON();
		}
		if (KeyNum==8)
		{
			Buzzer_PlayNote(7, 500); 
			 SendPWMFrequencyToPC(note_frequencies[7]);
			//LED1_ON();
		}
		
//		if (KeyNum==LED1_ON())
//		{
//			Buzzer_PlayNote(1, 500); 
//			
//		}
//			default:
//			break;
		//}

////		 for (i = 0; i < 8; i++)
////		{
////		Buzzer_PlayNote(i, 500); // 播放每个音符，持续500毫秒
////	
////		frequency1=TIM3_IRQHandler();
////			
////		Printfrequency(frequency1);
////		}
//	// SendPWMFrequencyToPC(void);
//	//	PWM_Frequency = 72000000 / ((TIM_Period + 1) * (TIM_Prescaler + 1))
	}
}



