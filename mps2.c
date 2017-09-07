#ifndef F_CPU
#define F_CPU 14745600
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


unsigned char card[20];
unsigned int i=0,j=0,k;

void uart0_init(uint32_t baud)
{
	
	uint16_t ubrr = F_CPU / 16 / baud -1;
	
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	
	UCSR0C = (3<<UCSZ00);
}

void uart0_tx(uint8_t data)
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

uint8_t uart0_rx()
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void uart1_init(uint32_t baud)
{
	
	uint16_t ubrr = F_CPU / 16 / baud -1;
	
	UBRR1H = (unsigned char)(ubrr>>8);
	UBRR1L = (unsigned char)ubrr;
	
	UCSR1B = (1<<RXEN1)|(1<<TXEN1)|(1<<RXCIE1);
	
	UCSR1C = (3<<UCSZ10);
}

uint8_t uart1_rx()
{
	while(!(UCSR1A & (1<<RXC1)));
	return UDR1;
}

void uart1_tx(uint8_t data)
{
	while(!(UCSR1A & (1 << UDRE1)));
	UDR1 = data;
}

void uart2_init(uint32_t baud)
{
	
	uint16_t ubrr = F_CPU / 16 / baud -1;
	
	UBRR2H = (unsigned char)(ubrr>>8);
	UBRR2L = (unsigned char)ubrr;
	
	UCSR2B = (1<<RXEN2)|(1<<TXEN2)|(1<<RXCIE2);
	
	UCSR2C = (3<<UCSZ20);
}

void uart2_tx(uint8_t data)
{
	while(!(UCSR2A & (1 << UDRE2)));
	UDR2 = data;
}

uint8_t uart2_rx()
{
	while(!(UCSR2A & (1<<RXC2)));
	return UDR2;
}


int main()
{
	// char data;
	// uint8_t b[10];
	// char card[20],a[]="read fghcard";
	// int i=0,j=0;
	DDRA=0xFF;
	uart0_init(9600);
 	uart1_init(9600);
 	uart2_init(9600);
 	//sei();
 	 while(1)
 	{
 	 		//uart2_tx('a');
 	 	for(i=0;i<12;i++)
 	 		 	card[i]=uart0_rx();
		 for(i=0;i<12;i++)
 	 		 	uart2_tx(card[i]);
 	}
 	// uart2_tx('1');
 	//while(1);
 	return 0;
}
