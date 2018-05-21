#include "fsl_gpio.h"
#include "MKL02Z4.h"

#ifndef TM1637_H_
#define TM1637_H_


#endif /* TM1637_H_ */

#define PORT 	PTB
#define	CLK		8
#define	DIO		9


#define NORMAL_MODE 		0x40
#define FIX_ADDRESS_MODE 	0x44
#define DIGIT_1				0xC0
#define	DIGIT_2				0xC1
#define	DIGIT_3				0xC2
#define DIGIT_4				0xC3

//Luminosity
#define PW1				0x88
#define PW2				0x89
#define PW4				0x8A
#define PW10			0x8B
#define PW11			0x8C
#define PW12			0x8D
#define PW13			0x8E
#define PW14			0x8F
#define DISPLAY_OFF		0x88


static int8_t display_table[] = {
		0x3f,0x06,0x5b,0x4f,
		0x66,0x6d,0x7d,0x07,
		0x7f,0x6f,0x77,0x7c,
		0x39,0x5e,0x79,0x71
};

void tm1637_init(void);
void start(void);
void stop(void);
void writeData(unsigned char data);
void write_4digits(unsigned char* tab);
void Cpu_Delay(uint32_t counter);
