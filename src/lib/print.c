// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// =-=-=-=-=-=-=-=-=-=-=-=-= Code =-=-=-=-=-=-=-=-=-=-=-=-=-=
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//               SoliOS Copyright © 2021-2022
//
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// -=-=-=-=-=-=-=-=-=-=-=-= About file =-=-=-=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//  File name: kernel.c
//  File language: C programming language
//  File extension: .c
//  File usage: Main kernel file
//
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void _print_char(char c) {
    asm volatile (
        "mov %[char] , %al\n\t"
        "movb $0x0e, %ah\n\t" 
        "int  $0x10" : : [charPrint] "g" (c));
    return;
} 

// See any errors in our file? Have we just forgotten to add something? Send Issue to our github repository:
// https://github.com/SolindekDev/SoliKernel