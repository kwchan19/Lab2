#include <linux/fb.h>
#include <fcntl.h>
#include <cstdio>
#include <unistd.h>

#ifndef BUF_SIZE 
#define BUF_SIZE 1024
#endif

int main(){
	fb_fix_screeninfo fb;
	fb_var_screeninfo fb_var;
	int inputFd = 0;
	int select = 3;
	inputFd = open("/dev/fb0", O_RDONLY, O_NONBLOCK);
	ssize_t numRead;
	char buf[1024];
	
	if (inputFd == -1) {
		printf("%d", inputFd);
		printf("File not found\n");
	}
	else {
		while(select!=0) {
		
			char menu;
			printf("Menu");
			printf("\n 1. Fixed Screen Info");
			printf("\n 2. Variable Screen Info");
			printf("\n 0. Exit");
			printf("\n Select Option: ");
			scanf("%c", &menu);
			select = menu - '0';
			getchar(); // wait the user type something to continue
			
			switch(select) {
			    	case 0:
					printf("\nExiting");
					select = 0;
					break;
			    	case 1: 
					printf("\nFixed Screen Info:\n\n");
					if(fb.visual == 0) {
						printf("Visual: (0) White\n");
					}
					else if(fb.visual == 1){
						printf("Visual: (1) Black\n");
					}
					
					printf("Accelerator: %d\n", fb.accel);
					printf("Capabilities: %d\n", fb.capabilities);
					
					select = 0;
					break;
			    	case 2: 
					printf("\nVariable Screen Info:\n\n");
					printf("xres: %d\n", fb_var.xres);
					printf("yres: %d\n", fb_var.yres);
					printf("Bits per Pixel: %d\n", fb_var.bits_per_pixel);
					select = 0;
					break;
			    	default:
					printf("\nInvalid Option. Please try again.\n");
					break;
			    	}
	
		
		}
	}	
}
