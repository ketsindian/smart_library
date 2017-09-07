	
//I have found that a piece of code is missing for the original code to work as expected. The code below is working on Linux compiled with gcc. The added line of code is the one marked with /**<<<<<<------This line made it work.**/
//One line was also commented out : //baudRate = B115200;.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <errno.h>
#include <termios.h>



void signal_handler_IO (int status);   /* definition of signal handler */

int n,n1;
int fd;
int connected;
struct termios termAttr;
struct sigaction saio;
int c, res;
char buf[12];
int i=0;
char ch;
FILE *fp,*fp1,*fp2;
char s[]={"Z"};
char s1[]={"Y"};
char s2[]={"X"};
char s3[]={"Pinak"};
char name[50];
int main(int argc, char *argv[])
{
     
     fd = open("/dev/ttyUSB2", O_RDWR | O_NOCTTY | O_NDELAY);
     if (fd == -1)
     {
        perror("open_port: Unable to open /dev/ttyUSB\n");
        exit(1);
     }

     saio.sa_handler = signal_handler_IO;
     saio.sa_flags = 0;
     saio.sa_restorer = NULL; 
     sigaction(SIGIO,&saio,NULL);

     fcntl(fd, F_SETFL, FNDELAY);
     fcntl(fd, F_SETOWN, getpid());
     fcntl(fd, F_SETFL,  O_ASYNC ); /**<<<<<<------This line made it work.**/

     tcgetattr(fd,&termAttr);
     //baudRate = B115200;          /* Not needed */
     cfsetispeed(&termAttr,B9600);
     cfsetospeed(&termAttr,B9600);
     termAttr.c_cflag &= ~PARENB;
     termAttr.c_cflag &= ~CSTOPB;
     termAttr.c_cflag &= ~CSIZE;
     termAttr.c_cflag |= CS8;
     termAttr.c_cflag |= (CLOCAL | CREAD);
     termAttr.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
     termAttr.c_iflag &= ~(IXON | IXOFF | IXANY);
     termAttr.c_oflag &= ~OPOST;
     tcsetattr(fd,TCSANOW,&termAttr);

     printf("UART1 configured....\n");
	
     res=0;
     connected = 1;


	//fp1=fopen("GSM.txt","r");

	fp2=fopen("/home/pinakwadikar/MPS/LCD.txt","r");
	
	//LCD
	do
	{
	ch=fgetc(fp2);
	//printf("%c",ch);
	n1=write(fd,&ch,1);
	if(n1<0)
	{
	printf("write not succesful");
	}
	
	
	}while(fgetc(fp2)!=EOF);



	
	/*********Case to check updating is required   iff re executed**********/
	//GSM
	
	/*while(fgetc(fp1)!=EOF)
	{
	fscanf(fp1,"%s",s4);
	write(fd,s4,strlen(s4));//name transmitted
	fscanf(fp1,"%s",s4);
	write(fd,s4,strlen(s4));//Number transmitted
	}*/




     while(connected == 1){
     }

     close(fd);
     exit(0);             
}

void signal_handler_IO (int status)
{
     //res=0;
    // printf("received data from UART.\n");
     //while (res!=12) /*STOP==FALSE*/
     //{       
               //printf("received data from UART.\n");
        res = read(fd,&buf[i],1);//#change 255		//as an extra charachter is transmitted
	//printf("from ISR %s \n",buf);
                  //buf[res]=0; /* so we can printf... */
              //printf(":%s", buf, res);
               
               if(i!=12)
                    i++;
               else
               {
                    i=0;
                    fp=fopen("/home/pinakwadikar/MPS/RFID.txt","w");
                    //printf("%d\n",fp);
                    if(fp==NULL)
                         printf("\nfile not created\n");
                    //fprintf(fp,"%s",s1); 
                    printf("%s\n ", buf);
                    fprintf(fp,"%s",buf);
                   fprintf(fp,"%s \n",s);
                    fclose(fp);
                    //system("/home/katty/a.sh");
               }
                   
                   //fprintf(fp,"%s \n",s);
                //if (buf[0]=='z') STOP=TRUE;
     //}
}
// void signal_handler_IO (int status)
// {
//      res=0;
//     // printf("received data from UART.\n");
//      while (res!=12) /*STOP==FALSE*/
//      {       
//                printf("received data from UART.\n");
//              res = read(fd,buf,12);//#change 255
//                   //buf[res]=0; /* so we can printf... */
//               printf(":%s", buf, res); 
               //printf(":%s:%d\n", buf, res); 
//                    //fprintf(fp,"%s \n",s);
//                 //if (buf[0]=='z') STOP=TRUE;
//      }
//}