#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*******************UART FUNCTIONS AND DEFINITIONS************************************/
#define RX  (1<<4)
#define TX  (1<<3)
#define TE  (1<<5)
#define RE  (1<<7)
/*******************uart0****************/


char entry0[]={"No_Entry"};
char entry1[]={"Welcome "};
char number[15],name[50];
int j=0;
unsigned int k=0;
int mj=0,pj=0;

#define rs PB0
#define rw PB1
#define en PB2


void uart0_init()
{
	UCSR0B = 0x00;							//disable while setting baud rate

	UBRR0L = 95; 							// for the clock frequency 14745600 and the baud rate 9600, value of UBRR is 95
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

	UCSR3C = (1<<UCSZ31)|(1<<UCSZ30);							//setting 8-bit character and 1 stop bit
	UCSR3B = RX | TX | RE;						//enabling receiver and transmit
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
		PORTA=0b00000001;
		_delay_us(20);
		PORTA=0b00000100;
		_delay_us(20);
		PORTA=0b00000010;
		_delay_us(20);
		PORTA=0b00001000;
		_delay_us(20);
	}
}
void aclk(unsigned int t)
{
	unsigned int i;
	for(i=0;i<t;i++)
	{
		PORTA=0b00001000;
		_delay_us(20);
		PORTA=0b00000010;
		_delay_us(20);
		PORTA=0b00000100;
		_delay_us(20);
		PORTA=0b00000001;
		_delay_us(20);
	}
}

/********Stepper Motor NEds*******/



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
	int i=0,flag=0;
	unsigned char temp;
	char a[]={"asdfg"};


	DDRB=0xFF;
	lcd_init();
	sei();
	uart0_init();//connected to PC
	uart1_init();//connected to GSM
	uart2_init();
	//uart3_init();

/*****Assumption that server will transmit iff there is change*****/
	for(i=0;i<5;i++)
	dis_data(a[i]);

	_delay_ms(1000);
	i=0;
 
	while(1)
	{
	temp=uart_rx0();
	if((temp=='b')&&(flag==0))
	{
		dis_cmd(0x80);
		while(entry0[i]!='\0')
		{
			
			dis_data(entry0[i]);
			_delay_ms(200);
			i++;
		}
		flag==1;
		i=0;
		break;
	}
	else if((temp=='a')&&(flag==0))
	{
		dis_cmd(0x80);
		while(entry1[i]!='\0')
		{
			
			dis_data(entry1[i]);
			_delay_ms(200);
			i++;
			
		}
		flag==1;
		i=0;
		break;
	}
	else if(isalpha(temp))
	{
		while(temp!='\0')
		{
		name[j]=uart_rx0();
		j++;
		}
	j=0;
	
		//temp is an alphabet
		
	}
	//uart_tx0(temp);
	else if(isdigit(temp))
	{	
		while(temp!='\0')
		{
		number[k]=uart_rx0();
		k++;
		}
		k=0;
		flag=0;
	}
	}



	

	// uart_tx3_string("AT+CMGF=1\r");
	// _delay_ms(1000);
	// uart_tx3_string("AT+CMGS=\"+919822236188\"\r");
	// _delay_ms(1000);
	// uart_tx3_string("hi");
	// _delay_ms(1000);
	// uart_tx3(26);
	// _delay_ms(1000);

	//uart_tx1(13);
	
	
	
}


