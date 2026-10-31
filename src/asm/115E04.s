.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"



glabel func_00115E04
    nop
endlabel func_00115E04
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop

/* Handwritten function */

glabel func_00115E40
    lui        $k0, %hi(D_004E7480) /* handwritten instruction */
    addiu      $k0, $k0, %lo(D_004E7480) /* handwritten instruction */
    sq         $at, 0x10($k0) /* handwritten instruction */
    sq         $v0, 0x20($k0) /* handwritten instruction */
    sq         $v1, 0x30($k0) /* handwritten instruction */
    sq         $a0, 0x40($k0) /* handwritten instruction */
    sq         $a1, 0x50($k0) /* handwritten instruction */
    sq         $a2, 0x60($k0) /* handwritten instruction */
    sq         $a3, 0x70($k0) /* handwritten instruction */
    sq         $t0, 0x80($k0) /* handwritten instruction */
    sq         $t1, 0x90($k0) /* handwritten instruction */
    sq         $t2, 0xA0($k0) /* handwritten instruction */
    sq         $t3, 0xB0($k0) /* handwritten instruction */
    sq         $t4, 0xC0($k0) /* handwritten instruction */
    sq         $t5, 0xD0($k0) /* handwritten instruction */
    sq         $t6, 0xE0($k0) /* handwritten instruction */
    sq         $t7, 0xF0($k0) /* handwritten instruction */
    sq         $s0, 0x100($k0) /* handwritten instruction */
    sq         $s1, 0x110($k0) /* handwritten instruction */
    sq         $s2, 0x120($k0) /* handwritten instruction */
    sq         $s3, 0x130($k0) /* handwritten instruction */
    sq         $s4, 0x140($k0) /* handwritten instruction */
    sq         $s5, 0x150($k0) /* handwritten instruction */
    sq         $s6, 0x160($k0) /* handwritten instruction */
    sq         $s7, 0x170($k0) /* handwritten instruction */
    sq         $t8, 0x180($k0) /* handwritten instruction */
    sq         $t9, 0x190($k0) /* handwritten instruction */
    sq         $gp, 0x1C0($k0) /* handwritten instruction */
    sq         $sp, 0x1D0($k0) /* handwritten instruction */
    sq         $fp, 0x1E0($k0) /* handwritten instruction */
    sq         $ra, 0x1F0($k0) /* handwritten instruction */
    mfhi       $v0
    lui        $at, %hi(D_004E7680)
    sd         $v0, %lo(D_004E7680)($at)
    mfhi1      $v0
    lui        $at, %hi(D_004E7688)
    sd         $v0, %lo(D_004E7688)($at)
    mflo       $v0
    lui        $at, %hi(D_004E7690)
    sd         $v0, %lo(D_004E7690)($at)
    mflo1      $v0
    lui        $at, %hi(D_004E7698)
    sd         $v0, %lo(D_004E7698)($at)
    mfsa       $v0
    lui        $at, %hi(D_004E76A0)
    sd         $v0, %lo(D_004E76A0)($at)
    mfc0       $a0, $12 /* handwritten instruction */
    mfc0       $a1, $13 /* handwritten instruction */
    mfc0       $a2, $14 /* handwritten instruction */
    mfc0       $a3, $8 /* handwritten instruction */
    lui        $t0, %hi(D_004E7480)
    addiu      $t0, $t0, %lo(D_004E7480)
    lui        $at, %hi(D_004E76A8)
    sw         $a2, %lo(D_004E76A8)($at)
    lui        $at, %hi(D_00115F40)
    addiu      $at, $at, %lo(D_00115F40)
    mtc0       $at, $14 /* handwritten instruction */
    sync.p
    mfc0       $at, $12 /* handwritten instruction */
    addiu      $v0, $zero, -0x2
    and        $at, $at, $v0
    mtc0       $at, $12 /* handwritten instruction */
    sync.p
    eret /* handwritten instruction */
  alabel D_00115F40
    lui        $at, %hi(D_00486598)
    lw         $at, %lo(D_00486598)($at)
    lui        $sp, %hi(D_004E7480)
    jalr       $at
    addiu     $sp, $sp, %lo(D_004E7480)
    addiu      $v1, $zero, -0x54
    syscall    0 /* handwritten instruction */
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    mfc0       $at, $12 /* handwritten instruction */
    addiu      $k0, $zero, -0x1C /* handwritten instruction */
    and        $at, $at, $k0
    mtc0       $at, $12 /* handwritten instruction */
    sync.p
    lui        $v0, %hi(D_004E76A8)
    lw         $v0, %lo(D_004E76A8)($v0)
    mtc0       $v0, $14 /* handwritten instruction */
    sync.p
    lui        $v0, %hi(D_004E7680)
    ld         $v0, %lo(D_004E7680)($v0)
    mthi       $v0
    lui        $v0, %hi(D_004E7688)
    ld         $v0, %lo(D_004E7688)($v0)
    mthi1      $v0
    lui        $v0, %hi(D_004E7690)
    ld         $v0, %lo(D_004E7690)($v0)
    mtlo       $v0
    lui        $v0, %hi(D_004E7698)
    ld         $v0, %lo(D_004E7698)($v0)
    mtlo1      $v0
    lui        $v0, %hi(D_004E76A0)
    ld         $v0, %lo(D_004E76A0)($v0)
    mtsa       $v0
    sync.p
    lui        $k0, %hi(D_004E7480) /* handwritten instruction */
    addiu      $k0, $k0, %lo(D_004E7480) /* handwritten instruction */
    lq         $at, 0x10($k0) /* handwritten instruction */
    lq         $v0, 0x20($k0) /* handwritten instruction */
    lq         $v1, 0x30($k0) /* handwritten instruction */
    lq         $a0, 0x40($k0) /* handwritten instruction */
    lq         $a1, 0x50($k0) /* handwritten instruction */
    lq         $a2, 0x60($k0) /* handwritten instruction */
    lq         $a3, 0x70($k0) /* handwritten instruction */
    lq         $t0, 0x80($k0) /* handwritten instruction */
    lq         $t1, 0x90($k0) /* handwritten instruction */
    lq         $t2, 0xA0($k0) /* handwritten instruction */
    lq         $t3, 0xB0($k0) /* handwritten instruction */
    lq         $t4, 0xC0($k0) /* handwritten instruction */
    lq         $t5, 0xD0($k0) /* handwritten instruction */
    lq         $t6, 0xE0($k0) /* handwritten instruction */
    lq         $t7, 0xF0($k0) /* handwritten instruction */
    lq         $s0, 0x100($k0) /* handwritten instruction */
    lq         $s1, 0x110($k0) /* handwritten instruction */
    lq         $s2, 0x120($k0) /* handwritten instruction */
    lq         $s3, 0x130($k0) /* handwritten instruction */
    lq         $s4, 0x140($k0) /* handwritten instruction */
    lq         $s5, 0x150($k0) /* handwritten instruction */
    lq         $s6, 0x160($k0) /* handwritten instruction */
    lq         $s7, 0x170($k0) /* handwritten instruction */
    lq         $t8, 0x180($k0) /* handwritten instruction */
    lq         $t9, 0x190($k0) /* handwritten instruction */
    lq         $gp, 0x1C0($k0) /* handwritten instruction */
    lq         $sp, 0x1D0($k0) /* handwritten instruction */
    lq         $fp, 0x1E0($k0) /* handwritten instruction */
    lq         $ra, 0x1F0($k0) /* handwritten instruction */
    mfc0       $k0, $12 /* handwritten instruction */
    ori        $k0, $k0, 0x13 /* handwritten instruction */
    mtc0       $k0, $12 /* handwritten instruction */
    sync.p
    eret /* handwritten instruction */
    nop
    nop
    nop
  alabel D_00116080
    lui        $k0, %hi(D_004E7480) /* handwritten instruction */
    addiu      $k0, $k0, %lo(D_004E7480) /* handwritten instruction */
    sq         $at, 0x10($k0) /* handwritten instruction */
    sq         $v0, 0x20($k0) /* handwritten instruction */
    sq         $v1, 0x30($k0) /* handwritten instruction */
    sq         $a0, 0x40($k0) /* handwritten instruction */
    sq         $a1, 0x50($k0) /* handwritten instruction */
    sq         $a2, 0x60($k0) /* handwritten instruction */
    sq         $a3, 0x70($k0) /* handwritten instruction */
    sq         $t0, 0x80($k0) /* handwritten instruction */
    sq         $t1, 0x90($k0) /* handwritten instruction */
    sq         $t2, 0xA0($k0) /* handwritten instruction */
    sq         $t3, 0xB0($k0) /* handwritten instruction */
    sq         $t4, 0xC0($k0) /* handwritten instruction */
    sq         $t5, 0xD0($k0) /* handwritten instruction */
    sq         $t6, 0xE0($k0) /* handwritten instruction */
    sq         $t7, 0xF0($k0) /* handwritten instruction */
    sq         $s0, 0x100($k0) /* handwritten instruction */
    sq         $s1, 0x110($k0) /* handwritten instruction */
    sq         $s2, 0x120($k0) /* handwritten instruction */
    sq         $s3, 0x130($k0) /* handwritten instruction */
    sq         $s4, 0x140($k0) /* handwritten instruction */
    sq         $s5, 0x150($k0) /* handwritten instruction */
    sq         $s6, 0x160($k0) /* handwritten instruction */
    sq         $s7, 0x170($k0) /* handwritten instruction */
    sq         $t8, 0x180($k0) /* handwritten instruction */
    sq         $t9, 0x190($k0) /* handwritten instruction */
    sq         $gp, 0x1C0($k0) /* handwritten instruction */
    sq         $sp, 0x1D0($k0) /* handwritten instruction */
    sq         $fp, 0x1E0($k0) /* handwritten instruction */
    sq         $ra, 0x1F0($k0) /* handwritten instruction */
    mfhi       $v0
    lui        $at, %hi(D_004E7680)
    sd         $v0, %lo(D_004E7680)($at)
    mfhi1      $v0
    lui        $at, %hi(D_004E7688)
    sd         $v0, %lo(D_004E7688)($at)
    mflo       $v0
    lui        $at, %hi(D_004E7690)
    sd         $v0, %lo(D_004E7690)($at)
    mflo1      $v0
    lui        $at, %hi(D_004E7698)
    sd         $v0, %lo(D_004E7698)($at)
    mfsa       $v0
    lui        $at, %hi(D_004E76A0)
    sd         $v0, %lo(D_004E76A0)($at)
    mfc0       $a0, $12 /* handwritten instruction */
    mfc0       $a1, $13 /* handwritten instruction */
    mfc0       $a2, $14 /* handwritten instruction */
    mfc0       $a3, $8 /* handwritten instruction */
    mfc0       $t0, $23 /* handwritten instruction */
    lui        $t1, %hi(D_004E7480)
    addiu      $t1, $t1, %lo(D_004E7480)
    lui        $at, %hi(D_0011617C)
    addiu      $at, $at, %lo(D_0011617C)
    mtc0       $at, $14 /* handwritten instruction */
    sync.p
    mfc0       $at, $12 /* handwritten instruction */
    addiu      $v0, $zero, -0x2
    and        $at, $at, $v0
    mtc0       $at, $12 /* handwritten instruction */
    sync.p
    eret /* handwritten instruction */
  alabel D_0011617C
    andi       $v0, $a1, 0x7C
    lui        $at, %hi(D_004865A0)
    addu       $at, $at, $v0
    lw         $at, %lo(D_004865A0)($at)
    lui        $sp, %hi(D_004E7480)
    jalr       $at
    addiu     $sp, $sp, %lo(D_004E7480)
    break      1023, 1023
endlabel func_00115E40
    nop
