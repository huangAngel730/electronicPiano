#ifndef __ELECTRONIC_KEYBOARD_H
#define __ELECTRONIC_KEYBOARD_H

int TIM3_IRQHandler();
void TIM3_Init(void);
void Printfrequency(int frequency);
int Getfrequency();
void Buzzer_Setperiod(float frequency);
void Buzzer_SetFrequency(float frequency);
void Buzzer_PlayNote(uint8_t note_index, uint16_t duration_ms);
void Buzzer_PlayNotes(float frequency);
void SendPWMFrequencyToPC(uint32_t pwmFrequenc);

#endif
