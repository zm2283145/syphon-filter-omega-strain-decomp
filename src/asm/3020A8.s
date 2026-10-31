.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel ScrambleSeed
    mfc0       $at, $9 /* handwritten instruction */
    sync.p
    sw         $at, 0x0($a0)
    mfc0       $v0, $1 /* handwritten instruction */
    addu       $at, $at, $a0
    xor        $at, $at, $v0
    sw         $at, 0x4($a0)
    addu       $at, $at, $a1
    sw         $at, 0x8($a0)
    addu       $at, $at, $a2
    sw         $at, 0xC($a0)
    addu       $at, $at, $a3
    sw         $at, 0x10($a0)
    addu       $at, $at, $t0
    sw         $at, 0x14($a0)
    addu       $at, $at, $t1
    sw         $at, 0x18($a0)
    addu       $at, $at, $t2
    sw         $at, 0x1C($a0)
    addu       $at, $at, $t3
    sw         $at, 0x20($a0)
    addu       $at, $at, $t4
    sw         $at, 0x24($a0)
    addu       $at, $at, $t5
    sw         $at, 0x28($a0)
    addu       $at, $at, $t6
    sw         $at, 0x2C($a0)
    addu       $at, $at, $t7
    sw         $at, 0x30($a0)
    mfc0       $t0, $9 /* handwritten instruction */
    sync.p
    addu       $at, $at, $t0
    jr         $ra
    sw        $at, 0x34($a0)
endlabel ScrambleSeed
