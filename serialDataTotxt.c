      #include <sys/types.h>
      #include <sys/stat.h>
      #include <fcntl.h>
      #include <termios.h>
      #include <stdio.h>
      #include <stdlib.h>
      #include <errno.h>
        
      #define BAUDRATE B9600
      #define MODEMDEVICE "/dev/ttyUSB5"
      #define _POSIX_SOURCE 1 /* POSIX compliant source */
      #define FALSE 0
      #define TRUE 1
        
      volatile int STOP=FALSE; 
       
      int main()
      {
         int fd,c, res;
	       FILE *fp;
        struct termios oldtio,newtio;
        char buf[12];	//#change	255
	       char s[]={"HELLO"};
	     fp=fopen("abc.txt","w");
                  if(fp==NULL)
                      printf("\nfile not created\n");
//	fprintf(fp,"%s \n",s);        
        fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY ); 
        if (fd <0) {perror(MODEMDEVICE); exit(-1); }  
        tcgetattr(fd,&oldtio);
        bzero(&newtio, sizeof(newtio));
        newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
        newtio.c_iflag = IGNPAR;
        newtio.c_oflag = 0;
        newtio.c_lflag = 0; 
        newtio.c_cc[VTIME]    = 0;   /* inter-character timer unused */
        newtio.c_cc[VMIN]     = 12;   /* blocking read until 12 chars received */
	       tcflush(fd, TCIFLUSH);
        tcsetattr(fd,TCSANOW,&newtio);

	       res=0;

        while (res!=12) /*STOP==FALSE*/
	     {       
             res = read(fd,buf,12);//#change 255
                  //buf[res]=0; /* so we can printf... */
              printf(":%s:%d\n", buf, res);  
	              //fprintf(fp,"%s \n",s);
	           //if (buf[0]=='z') STOP=TRUE;
        }
	       printf("Out of while loop");
	       fprintf(fp,"%s \n",buf);
        tcsetattr(fd,TCSANOW,&oldtio);
	       fclose(fp);
        return 0;
      }
    