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
//  File usage: Power lib file
//
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#pragma once

// Void that will be shutdown operating system
void shutdown() {
    asm volatile (
        "mov %ax, 0x1000"
        "mov %ax, ss"
        "mov %sp, 0xf000"
        "mov %ax, 0x5307"
        "mov %bx, 0x0001"
        "mov %cx, 0x0003"
        "int $0x15"
    );
    return;
}

// Void that will be rebooting our operating system
void reboot() {
    // This works
    // Code under is from linux source code
    // https://github.com/torvalds/linux/blob/v4.2/arch/x86/realmode/rm/reboot.S#L114
    asm volatile (
        "movw $0x1000, %ax\n"
        "movw	%ax, %ss\n"
        "movw	$0xf000, %sp\n"
        "movw	$0x5307, %ax\n"
        "movw	$0x0001, %bx\n"
        "movw	$0x0003, %cx\n"
        "int	$0x15"
    );
    return;
}

// See any errors in our file? Have we just forgotten to add something? Send Issue to our github repository:
// https://github.com/SolindekDev/SoliKernel