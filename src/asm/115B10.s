.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel PutTLBEntry
    addiu      $v1, $zero, 0x55
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel PutTLBEntry

/* Handwritten function */

glabel iPutTLBEntry
    addiu      $v1, $zero, -0x55
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iPutTLBEntry

/* Handwritten function */

glabel _SetTLBEntry
    addiu      $v1, $zero, 0x56
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _SetTLBEntry
