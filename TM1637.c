#include "TM1637.h"

void tm1637_init(void){
	PORT->PDDR |= (1<<CLK); //Set CLK pin as output
	PORT->PDDR |= (1<<DIO); //Set DIO pin as output
	PORT->PSOR = 1<<CLK;	//Set CLK pin to 1
	PORT->PSOR = 1<<DIO;	//Set DIO pin to 1

	start();
	writeData(0x80); //Turn screen OFF
	stop();

    start();
	writeData(0x40); //Set automatic address adding
	stop();

	//Clear screen
	start();
	writeData(0xC0); //Go to first address
	Cpu_Delay(5);
	writeData(0x00); //Clear digit 0
	Cpu_Delay(5);
	writeData(0x00); //Clear digit 1
	Cpu_Delay(5);
	writeData(0x00); //Clear digit 2
	Cpu_Delay(5);
	writeData(0x00); //Clear digit 3
	Cpu_Delay(5);
	stop();

	start();
	writeData(0xC0); //Go to first address
	stop();
}

void start(void){
	//Start transfer
	PORT->PCOR = 1<<DIO; //DIO Low
	Cpu_Delay(10);
	PORT->PCOR = 1<<CLK; //CLK Low
}
void stop(void){
	//End transfer
	PORT->PSOR = 1<<CLK; //CLK High
	Cpu_Delay(40);
	PORT->PSOR = 1<<DIO; //DIO High
	Cpu_Delay(40);
}

void writeData(unsigned char data){

	//Transfer loop
	for(uint8_t cpt = 0; cpt < 8; cpt++){
		Cpu_Delay(40);
		GPIO_WritePinOutput(PORT, DIO, (bool)(data & 0x01));
		PORT->PTOR = 1<<CLK;	//CLK High
		Cpu_Delay(40);

		PORT->PTOR = 1<<CLK;	//CLK Low
		data = data >> 1;
	}
	PORT->PCOR = 1<<DIO; //DIO Low
	Cpu_Delay(40);

	PORT->PTOR = 1<<CLK;	//CLK High
	Cpu_Delay(40);
	PORT->PTOR = 1<<CLK;	//CLK Low
	Cpu_Delay(40);
}

void write_4digits(unsigned char* tab){
    //start();
	//writeData(0x40); //Set automatic address adding
	//stop();

	//Clear screen
	start();
	writeData(0xC0); //Go to first address
	Cpu_Delay(5);

	for(char i=0;i<4;i++){
		writeData(tab[i]);
		Cpu_Delay(5);
	}
	stop();
}

void Cpu_Delay(uint32_t counter){
	uint16_t i;
	for(i=0; i<counter; i++){
		__asm("nop");
	}
}
