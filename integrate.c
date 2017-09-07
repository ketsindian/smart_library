#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

/*******************UART FUNCTIONS AND DEFINITIONS************************************/
#define RX  (1<<4)
#define TX  (1<<3)
#define TE  (1<<5)
#define RE  (1<<7)
/*******************uart0****************/





void uart0_init()
{
	UCSR0B = 0x00;							//disable while setting baud rate

	UBRR0L = 95; 					// for the clock frequency 14745600 and the baud rate 9600, value of UBRR is 95
	UBRR0H = 0x00;

	UCSR0C = 3<<1;       //setting 8-bit character and 1 stop bit
 	UCSR0B = RX | TX;      //enabling receiver and transmit
}

void uart_tx0(char data)
{
	while(!(UCSR0A & TE));						//waiting to transmit
	UDR0 = data;
}

char uart_rx0()
{
	while(!(UCSR0A & RE));						//waiting to receive
	return UDR0;
}

void uart_tx0_array(const char *array,int arr_length)
{
	int i=0;
	while(i < arr_length)
	{
		uart_tx0(array[i++]);
	}
}
void uart_tx0_string(char *data)
{
	while(*data != '\0')
	{
		uart_tx0(*data);
		data++;
	}
}

/*******************uart1****************/
void uart1_init()
{
	UCSR1B = 0x00;							//disable while setting baud rate

	UBRR1L = 95; 							// for the clock frequency 14745600 and the baud rate 9600, value of UBRR is 95
	UBRR1H = 0x00;

	UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);							//setting 8-bit character and 1 stop bit
	UCSR1B = RX | TX | RE;						//enabling receiver and transmit
}

void uart_tx1(char data)
{
	while(!(UCSR1A & TE));						//waiting to transmit
	UDR1 = data;
}

char uart_rx1()
{
	while(!(UCSR1A & RE));						//waiting to receive
	return UDR1;
}

void uart_tx1_array(const char *array,int arr_length)
{
	int i=0;
	while(i < arr_length)
	{
		uart_tx1(array[i++]);
	}
}
void uart_tx1_string(char *data)
{
	while(*data != '\0')
	{
		uart_tx1(*data);
		data++;
	}
}

/*******************uart2****************/
void uart2_init()
{
	UCSR2B = 0x00;							//disable while setting baud rate

	UBRR2L = 95; 							// for the clock frequency 14745600 and the baud rate 9600, value of UBRR is 95
	UBRR2H = 0x00;

	UCSR2C = (1<<UCSZ21)|(1<<UCSZ20);							//setting 8-bit character and 1 stop bit
	UCSR2B = RX | TX | RE;						//enabling receiver and transmit
						//enabling receiver and transmit
}

void uart_tx2(char data)
{
	while(!(UCSR2A & TE));						//waiting to transmit
	UDR2 = data;
}

char uart_rx2()
{
	while(!(UCSR2A & RE));						//waiting to receive
	return UDR2;
}

void uart_tx2_array(const char *array,int arr_length)
{
	int i=0;
	while(i < arr_length)
	{
		uart_tx2(array[i++]);
	}
}
void uart_tx2_string(char *data)
{
	while(*data != '\0')
	{
		uart_tx2(*data);
		data++;
	}
}
/*********uart3*****************/
void uart3_init()
{
	UCSR3B = 0x00;							//disable while setting baud rate

	UBRR3L = 95; 							// for the clock frequency 14745600 and the baud rate 9600, value of UBRR is 95
	UBRR3H = 0x00;

	UCSR3C = 3<<1;       //setting 8-bit character and 1 stop bit
 	UCSR3B = RX | TX;						//enabling receiver and transmit
						//enabling receiver and transmit
}

void uart_tx3(char data)
{
	while(!(UCSR3A & TE));						//waiting to transmit
	UDR3 = data;
}

char uart_rx3()
{
	while(!(UCSR3A & RE));						//waiting to receive
	return UDR3;
}

void uart_tx3_array(const char *array,int arr_length)
{
	int i=0;
	while(i < arr_length)
	{
		uart_tx3(array[i++]);
	}
}
void uart_tx3_string(char *data)
{
	while(*data != '\0')
	{
		uart_tx3(*data);
		data++;
	}
}





/*********LCD_4**************/

#define rs PB0
#define rw PB1
#define en PB2
//#define rs PA0 
//#define rw PA1
//#define en PA2
 
//void lcd_init();
//void dis_cmd(char);
//void dis_data(char);
//void lcdcmd(char);
//void lcddata(char);


//out=11110000 
void lcdcmd(char cmdout)
{
PORTB=cmdout;
PORTB&=~(1<<rs);
PORTB&=~(1<<rw);
PORTB|=(1<<en);
_delay_ms(1);
PORTB&=~(1<<en);
}
 
void lcddata(char dataout)
{
PORTB=dataout;
PORTB|=(1<<rs);
PORTB&=~(1<<rw);
PORTB|=(1<<en);
_delay_ms(1);
PORTB&=~(1<<en);
}

void dis_cmd(char cmd_value)
{
char cmd_value1;
 
cmd_value1 = cmd_value & 0xF0; //mask lower nibble because PA4-PA7 pins are used. 
lcdcmd(cmd_value1); // send to LCD
 
cmd_value1 = ((cmd_value<<4) & 0xF0); //shift 4-bit and mask
lcdcmd(cmd_value1); // send to LCD
} 
 
 
void dis_data(char data_value)
{
char data_value1;
 
data_value1=data_value&0xF0;
lcddata(data_value1);
 
data_value1=((data_value<<4)&0xF0);
lcddata(data_value1);
}
 
 
void lcd_init() // fuction for intialize 
{
dis_cmd(0x02); // to initialize LCD in 4-bit mode.
dis_cmd(0x28); //to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
dis_cmd(0x0C);
dis_cmd(0x06);
dis_cmd(0x80);
}
 


/*********LCD_ends***********/








/******______**
void clk(unsigned int t)
{
	unsigned int i;
	for(i=0;i<t;i++)
	{
		PORTD=0b00010000;
		_delay_us(20);
		PORTD=0b01000000;
		_delay_us(20);
		PORTD=0b00100000;
		_delay_us(20);
		PORTD=0b10000000;
		_delay_us(20);
	}
}
void aclk(unsigned int t)
{
	unsigned int i;
	for(i=0;i<t;i++)
	{
		PORTD=0b10000000;
		_delay_us(20);
		PORTD=0b00100000;
		_delay_us(20);
		PORTD=0b01000000;
		_delay_us(20);
		PORTD=0b00010000;
		_delay_us(20);
	}
}

/********Stepper Motor NEds*******/
char entry0[]={"Welcome"}; 
char entry1[]={"No_Entry"};
char number[20];
char name[20];
char b_name[20];
char doi[100];
char dor[100];
char roll[20];
char status;
int j=0;
unsigned int k=0,l=0,m=0,n=0,o=0,p=0;

int mj=0,pj=0;
ISR(USART1_RX_vect)
{

	if((mj%12)==0)
	uart_tx0('X');
	uart_tx0(UDR1);
	mj++;
}

ISR(USART2_RX_vect)
{

	if((pj%12)==0)
	uart_tx0('Y');
	uart_tx0(UDR2);
	pj++;
}

int main(void)
{
	int i=0;
	unsigned char temp;
	
	char s1[]={"AT+CMGS="};
	char s2[]={"\""};
	char s3[]={"\r"};
	char s4[]={"+91"};
	


	DDRB=0xFF;
	lcd_init();
	sei();
	uart0_init();//connected to PC
	uart1_init();//connected to GSM
	uart2_init();
	uart3_init();
	dis_data('A');
/*****Assumption that server will transmit iff there is change*****/

	while(1)
	{
	temp=uart_rx0();
	
	if(temp=='a')
	{
		dis_cmd(0x80);
		while(entry0[i]!='\0')
		{
			
			dis_data(entry0[i]);
			_delay_ms(200);
			i++;
		}
		i=0;
		temp='q';
		//break;
	}
	else if(temp=='b')
	{
		dis_cmd(0x80);
		while(entry1[i]!='\0')
		{
			
			dis_data(entry1[i]);
			_delay_ms(200);
			i++;
			
		}
		i=0;
		temp='q';
		//break;
	}
	else if(isalpha(temp))
	{
		// while(temp!='m')
		// {
		// uart_tx0(temp);
		// status=temp;
		// temp=uart_rx0();
		// //p++;
		// }
		// //p=0;
	//temp=uart_rx0();
		while(temp!='m')
		{
		uart_tx0(temp);
		name[j]=temp;
		temp=uart_rx0();
		j++;
		}
		j=0;
	temp=uart_rx0();
	uart_tx0('q');
	while(temp!='m')
		{
		uart_tx0(temp);
		number[k]=temp;
		temp=uart_rx0();
		k++;
		}
		k=0;
	temp=uart_rx0();
		while(temp!='m')
		{
		uart_tx0(temp);
		roll[l]=temp;
		temp=uart_rx0();
		l++;
		}
		l=0;
temp=uart_rx0();
		while(temp!='m')
		{
		uart_tx0(temp);
		b_name[m]=temp;
		temp=uart_rx0();
		m++;
		}
		m=0;
temp=uart_rx0();
		while(temp!='m')
		{
		uart_tx0(temp);
		doi[n]=temp;
		temp=uart_rx0();
		n++;
		}
		n=0;
temp=uart_rx0();
		while(temp!='m')
		{
		uart_tx0(temp);
		dor[o]=temp;
		temp=uart_rx0();
		o++;
		}
		o=0;
temp=uart_rx0();
		




		uart_tx3_string("AT+CMGF=1\r");
		_delay_ms(1000);
		uart_tx3_string(s1);
		uart_tx3_string(s2);
		
		
		uart_tx3_string("+917588505049");
		uart_tx3_string(s2);
		
		uart_tx3_string(s3);
		
			uart_tx0('u');
			_delay_ms(1000);
		uart_tx3_string(name);
		_delay_ms(1000);
		uart_tx3_string("you have issued the book from smart library");
		_delay_ms(1000);

		//uart_tx3(26);
		uart_tx3_string("\n roll no :");
		_delay_ms(1000);
		uart_tx3_string(roll);
		_delay_ms(1000);
		//uart_tx3(26);
		uart_tx3_string("\n book name is :");
		_delay_ms(1000);
		uart_tx3_string(b_name);
		_delay_ms(1000);
		//uart_tx3(26);
		uart_tx3_string("\n date of issue is :");
		_delay_ms(1000);
		uart_tx3_string(doi);
		_delay_ms(1000);
		//uart_tx3(26);
		uart_tx3_string("\n date of return is :");
		uart_tx3_string(dor);
		_delay_ms(1000);
		uart_tx3(26);
		_delay_ms(1000);
		
			}
		//temp is an alphabet
		
	// 	else if(status=='j')
	// 	{
	// 		uart_tx0('n');
	// 		//_delay_ms(1000);
	// 	uart_tx3_string(name);
	// 	//_delay_ms(1000);
	// 	uart_tx3_string("you have returned the book to smart library");
	// 	//_delay_ms(1000);

	// 	//uart_tx3(26);
	// 	uart_tx3_string("\n roll no :");
	// 	//_delay_ms(1000);
	// 	uart_tx3_string(roll);
	// 	//_delay_ms(1000);
	// 	//uart_tx3(26);
	// 	uart_tx3_string("\n book name is :");
	// 	//_delay_ms(1000);
	// 	uart_tx3_string(b_name);
	// 	//_delay_ms(1000);
	// 	//uart_tx3(26);
	// 	uart_tx3_string("\n date of issue was :");
	// 	//_delay_ms(1000);
	// 	uart_tx3_string(doi);
	// 	//_delay_ms(1000);
	// 	//uart_tx3(26);
	// 	uart_tx3_string("\n date of return is :");
	// 	uart_tx3_string(dor);
	// 	_delay_ms(1000);
	// 	uart_tx3(26);
	// 	_delay_ms(1000);
		
	// 	}


	// //uart_tx0('a');
	
	
	
	// //uart_tx1(13);
	
}
	
	
}


