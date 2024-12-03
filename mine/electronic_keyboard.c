#include "stm32f10x.h" // Device header
#include "Serial.h"
#include "PWM.h"
#include"electronic_keyboard.h"

// 假设使用TIM3和通道1进行输入捕获
int TIM3_IRQHandler(void)
	{
    if (TIM_GetITStatus(TIM3, TIM_IT_CC1) != RESET) {
        // 清除中断标志位
        TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);
        
        // 读取捕获值
        uint16_t capture_value = TIM_GetCapture1(TIM3);
        
        // 计算频率，假设系统时钟为72MHz
        uint32_t frequency = 72000000 / (capture_value + 1);
        
        // 打印频率值
        //printf("PWM Frequency: %lu Hz\n", frequency);
		return frequency;
    }
}

void TIM3_Init(void) 
	{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_ICInitTypeDef TIM_ICInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    
    // 使能TIM3时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    
    // 配置TIM3
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    
    // 配置输入捕获
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    TIM_ICInit(TIM3, &TIM_ICInitStructure);
    
    // 配置NVIC
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // 使能TIM3中断
    TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
    
    // 使能TIM3
    TIM_Cmd(TIM3, ENABLE);
}

void Printfrequency(int frequency)
{	
	OLED_Init();
		//OLED_Clear();
		OLED_ShowString(1,1,"frequency:");
		OLED_ShowNum(2, 1, frequency, 3);
	
}	

int Getfrequency()
{
	
	
	return GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0);
}


void Buzzer_Setperiod(float frequency){

	int period=100000/frequency;
	PWM_Init(period);

}

void Buzzer_SetFrequency(float frequency) {

	int pulse=100000/frequency/2;
    TIM_SetCompare1(TIM2, pulse); // 设置占空比
}

// 播放一个音符
void Buzzer_PlayNote(uint8_t note_index, uint16_t duration_ms) {
	const uint16_t note_frequencies[] = {
    262, // do
    294, // re
    330, // me
    349, // fa
    392, // so
    440, // la
    494,
	523
};
    Buzzer_Setperiod(note_frequencies[note_index]);
//    TIM_SetCounter(BUZZER_TIM, 0); // 重置定时器计数器
	//  Delay_ms(duration_ms); // 延时，根据需要实现Delay函数
//    TIM_SetCompare2(BUZZER_TIM, 0); // 停止发声
//	return  note_frequencies[note_index];
}

//void Buzzer_PlayNotes(float frequency) {
//    Buzzer_SetFrequency(frequency);
//}
//void LED1(void)
//{
//	if (KeyNum==3)		//获取输出寄存器的状态，如果当前引脚输出低电平
//	{                                                  
//		GPIO_SetBits(GPIOA, GPIO_Pin_1);               		//则设置PA2引脚为高电平
//	}                                                  
//	else                                               		//否则，即当前引脚输出高电平
//	{                                                  
//		GPIO_ResetBits(GPIOA, GPIO_Pin_1);             		//则设置PA2引脚为低电平
//	}
//	
//}

void SendPWMFrequencyToPC(uint32_t pwmFrequency)
{
   // int pwmFrequency ;
	//pwmFrequency =  Getfrequency();
  //  char frequencyString[20];

   //sprintf(frequencyString, "PWM Frequency: %.2f Hz\n", pwmFrequency);

   // Serial_SendString(frequencyString);
	Serial_SendNumber(pwmFrequency, 3);
}


