.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel func_00100220
    addiu      $v1, $zero, 0x23
    syscall    0 /* handwritten instruction */
endlabel func_00100220
    nop
    nop
