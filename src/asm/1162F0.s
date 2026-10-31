.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel FindAddress
    addiu      $v1, $zero, 0x83
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel FindAddress
