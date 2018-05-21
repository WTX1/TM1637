## Library for 4-digit display with TM1637 written in C for NXP Kinetis microcontroller

Developed on FRDM-KL02z, change `#include "MKL02Z4.h"` according to your microcontroller  
Default pins PTB8 as Clock and PTB9 as Data both are set as GPIO so you need to initialize the pins before  
Change `PORT`, `CLK` and `DIO` definitions according to your needs 

## Functions

### `tm1637_init()`
Turn OFF the display and clears all digits
 
### `start()`  
Start data transfer 

### `stop()`
Stop data transfer

### `writeData(unsigned char data)`
Write 8 bits data to `DIO` with `CLK` handling, you need to use `start()` function before and `stop()` after.

### `write_4digits(unsigned char* tab)`
With this function you can write data to the whole screen 

## Example

`tm1637_init();`  

`start();`  
`writeData(NORMAL_MODE);`  
`stop();`  

`start();`  
`writeData(PW14); //Set maximum luminosity`  
`stop();`

`unsigned char screen[] = {0x3f,0x86,0x5b,0x4f}; //0,1,2,3`

`start();`  
`write_4digits(screen); //displays 0,1,2,3`  
`stop();`

`start();`  
`writeData(DIGIT_1); //set address to first digit`  
`stop();`