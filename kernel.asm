;Setup Assembly
bits 32
section .text

	align 4
	dd 0x1BADB002
	dd 0x00
	dd - 0x1BADB002 + 0x00
extern DOORS
global start
; INITIALIZE
extern DoorsMain

/*
    GETS CALLED AFTER THE CONSOLE INITIALIZING

    ##SEE libc/doors/dynamic/CONSOLE.ASM
    ##SEE libc/doors/dynamic/DIRECTORY.ASM
*/
extern DoorsConsoleInit

start:
	cli  ; stop interrupts

	call DoorsMain


	call DoorsConsoleInit

	hlt

