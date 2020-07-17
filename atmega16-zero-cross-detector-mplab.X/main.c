#include "atmel_start.h"

#define RETURN 100

#define INT_0 External_int_get_level(1)
#define PIN_ON Zerocross_pulse_set_level(true)
#define PIN_OFF Zerocross_pulse_set_level(false)

/****************************************************************************
    Function : char setup(void)
    AVR setup routine
****************************************************************************/
void setup(void)
{
	GIFR = GIFR;           // Clear interrupt flags
	GICR |= (1 << INT0);   // Enable external int0
	MCUCR |= (1 << ISC01); // Set to falling edge interrupt
}

/****************************************************************************
    Function : void C_task main (void)
    Main function for the Zero cross detector
    Calls the setup function, enable global interrupts and loops eternal
    while waiting for external interrupt 0
****************************************************************************/
int main(void)
{
	system_init();

	setup(); // Setup ports and Interrupt
	sei();   // Enable global interrupt and
	       // wait for a zero cross

	for (;;)
		; // Eternal loop
}

/****************************************************************************
ISR(INT0_vect)
External interrupt 0 handling routine. This is where the zero cross action is
placed. When a zero cross detection is needed the main program init a rising
edge external interrupt 0.
On the first falling edge this routine will be executed.
To make sure the falling edge sensing was correct and not caused by noise
it will do five pin samples where it has to sense low pin level on
all before it validate the level. If it don't get five in a row it will return
to the main program and wait for the next falling edge interrupt.
After five in a row the AVR start a zero cross handling action.
The zero cross handling here is only a example and will only apply a short
pulse on PORTB.0.
After the pulse is finished it will enable falling edge interrupt again to init
the next zero cross, then return to the main program and wait for the next
interrupt.
****************************************************************************/
ISR(INT0_vect)
{
	char i, temp;

	/*Filter it to makes sure it was not only noise*/
	for (temp = 0; temp < 5;) // Five samples noise filter
	{
		if (!(INT_0))
			temp++;
		else
			temp = RETURN;
	}
	if (temp != RETURN) {
		/*Place your zero cross action here*/

		PIN_ON; // At each zero cross from pos to neg
		for (i = 0x2F; i > 0; i--)
			;    // PORTB.0 will be set high for a
		PIN_OFF; // short period of time

		/*As this is a example code for zero cross detection it is set to
		  give a PORTB.0 pulse on every pos to neg zero cross. To make a
		  one-shot uncomment the line under which disables the ext int 0
		  interrupt. When you want a zero cross detection again you enable
		  external interrupt 0 on rising edge again*/
		// GIMSK = GIMSK & ~(1<<INT0); //Disable external int 0
	}
}
