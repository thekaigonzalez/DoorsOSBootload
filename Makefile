

# KERNEL


#INIT



#------------------------------------------------------


# Default Compilations
all:
	nasm -f elf32 kernel.asm -o dbd.o
	nasm -f elf32 def.asm -o def.o
	gcc -m32 -c kernel.c -o base.o
	gcc -m32 -c secure/security.c -o crypto.o
	ld -m elf_i386 -T link.ld -o kernel dbd.o base.o def.o crypto.o
	qemu-system-i386 -kernel kernel


# ADV. Compiling

assembly:
	nasm kernel.asm
	nasm def.asm

code:
	echo WARNING: Compiling this code will result in _starting Errors. Be Reminded that this KERNEL is meant to run on a x64 BIT architecture with about at least 2GB RAM Attached for performance.
	gcc kernel.c -o binaries/kernel_binary.mfe
# Compile Doors with normal Output from DoorsC
dev:
	echo WARNING: Compiling this code Initializes the Developer System. Be Reminded that this KERNEL is meant to run on a x64 BIT architecture with about at least 2GB RAM Attached for performance.
	nasm -f elf32 libc/doors/dynamic/NORMAL_OUTPUT.asm -o libDoorsGcc/libdoors.dsdyst
	nasm -f elf32 libc/doors/dynamic/PARSERS.asm -o libDoorsGcc/libgcc.dsdyst
	# Compile Something Random Because.  . .
	nasm -f elf32 libc/doors/dynamic/SHARED.ASM -o libDoorsGcc/dynlib.dsdyst # I guess that's our new extension xd
	gcc -m32 -c kernel.c -o default_kernelbase.dsdyst
