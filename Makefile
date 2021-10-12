# C files
_c-files = src/kernel.c src/lib/std.c
_c-files-kernel = kernel.s std.s
_gcc-compiler = gcc

# Assembly files
_asm-files = src/asm/boot.s
_asm-compiler = as

# Ld
_link-binary-files = builds/boot.o builds/kernel.o 

compile:
	@echo Compile Assembly files..
	@${_asm-compiler} -o ./builds/boot.o ${_asm-files}
	@echo Compile C files to Assembly..
	@${_gcc-compiler} -S ${_c-files}
	@echo Compile Assembly Kernel and Lib files to binary..
	@${_asm-compiler} -o ./builds/kernel.o ${_c-files-kernel}
	@echo Connect binary files to os
	@ld  --oformat binary -o builds/os.bin -e init ${_link-binary-files}
	@echo Start simulate the system

# qemu-system-x86_64 builds/os.bin

	
compile-only-bootloader: 
	@echo Compiling
	@as -o ./builds/boot.o src/asm/boot.s 
	@ld -o builds/boot.bin --oformat binary -e init builds/boot.o
	@qemu-system-x86_64 builds/boot.bin
