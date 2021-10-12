# Compile Assembly GNU files:
as -o boot.o bootloader.asm

# Binary file to ld:
ld -o boot.bin --oformat binary -e init boot.o




