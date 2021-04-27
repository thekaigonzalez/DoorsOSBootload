/*
 *
 * kernel.c - version 0.0.1
 * 
 */

#include "libc/doors.h"
#define WHITE_TXT 0x07 /* light gray on black text */
#define BLUE_T 0x01
#define GRN_T 0x10
#define CY_T 0x11
void k_clear_screen();
unsigned int doorPrintf(char *message, unsigned int line);
unsigned int DSLog(char* message);
void ColorLog();
unsigned int Store();
unsigned int IDoorsPrintln(char* message, unsigned int);
void setLine();
void DoorsMain()
{

	k_clear_screen();
	doorPrintf("Welcome to DoorsOS DOS!", 0);
    doorPrintf("Before we begin, Please Make sure that you have allocated enough VRAM / Have finished setting up doorsOS Correctly.\n\n", 1);
    setLine(3);
    ColorLog("I would like to thank the following users for being with DoorsOS through it's journey.\n", WHITE_TXT);
    Store();
    //thank you to
    /*
     * - Mafia
     * - Micah Gonzalez
     * - Chayce Josiah
     * - Jaden
     * - Master_Coder
     * - literally anybody else
     */

    setLine(5);
    Store();
    setLine(6);
    DSLog("- Mafia");
    setLine(7);
    DSLog(" ");
    setLine(8);
};

/* k_clear_screen : to clear the entire text screen */
void k_clear_screen()
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]=WHITE_TXT;
		i++;
	};
};

/* k_printf : the message and the line # */
unsigned int doorPrintf(char *message, unsigned int line)
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;

	i=(line*80*2);

	while(*message!=0)
	{
		if(*message=='\n') // check for a new line
		{
			line++;
			i=(line*80*2);
			*message++;
		} else {
			vidmem[i]=*message;
			*message++;
			i++;
			vidmem[i]=WHITE_TXT;
			i++;
		};
	};

	return(1);
}
//
int line = 0;

void setLine(int new) {
    line = new;
}
unsigned int IDoorsPrintln(char* message, unsigned int currentLine)
{
    DSLog(message);

    setLine(currentLine+1);

   return(1);
}
unsigned int Store() {
    DSLog(" ");
    return(1);
}
unsigned int DSLog(char* message)
{
    char *vidmem = (char *) 0xb8000;
    unsigned int i=0;

    i=(line*80*2);

    while(*message!=0)
    {
        if(*message=='\n') // check for a new line
        {
            line++;
            i=(line*80*2);
            *message++;
        } else {
            vidmem[i]=*message;
            *message++;
            i++;
            vidmem[i]=WHITE_TXT;
            i++;
        }; 
    };
    return(1);
}
void ColorLog(char* message, unsigned int color)
{
    char *vidmem = (char *) 0xb8000;
    unsigned int i=0;

    i=(line*80*2);

    while(*message!=0)
    {
        if(*message=='\n')
        {
            line++;
            i=(line*80*2);
            *message++;
        } else {
            vidmem[i]=*message;
            *message++;
            i++;
            vidmem[i]=color;
            i++;
        };
    };

}
void DoorsConsoleInit() {
    DSLog("The Console Is starting.");
}
