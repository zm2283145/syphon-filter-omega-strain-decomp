.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel GetEntryAddress_void_2
    addiu      $v1, $zero, 0x5B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetEntryAddress_void_2
