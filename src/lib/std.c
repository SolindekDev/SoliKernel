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
//  File name: std.h
//  File language: C programming language
//  File extension: .s
//  File usage: Std lib file
//
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#pragma once

void printf_char(char c) {
    // asm volatile (
    //     "mov $0, %al"
    //     "movb $0x0e, %ah\n\t"
    //     "int  $0x10\n\t"
    // )
    __asm (
        "mov  $'H' , %al\n\t"
        "movb $0x0e, %ah\n\t"
        "int  $0x10\n\t");
    // Inline assembly is shit
} 

// See any errors in our file? Have we just forgotten to add something? Send Issue to our github repository:
// https://github.com/SolindekDev/SoliKernel