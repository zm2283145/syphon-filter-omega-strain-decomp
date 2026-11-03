.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* Handwritten syscall stub. Both prototypes confirm this 16-byte boundary;
 * the following sceGsSetDefDispEnv is compiled code in a separate unit. */
glabel _GetGsDxDyOffset
    addiu      $v1, $zero, 0x80
    syscall    0
    jr         $ra
     nop
endlabel _GetGsDxDyOffset
