.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"



glabel strcmp
    or         $t0, $a0, $a1
    andi       $v0, $t0, 0x7
    bnel       $v0, $zero, .L00129348
    lb        $v0, 0x0($a0)
    andi       $t1, $t0, 0xF
    lui        $a3, (0x1010101 >> 16)
    ori        $a3, $a3, (0x1010101 & 0xFFFF)
    dsll       $a3, $a3, 16
    ori        $a3, $a3, 0x101
    dsll       $a3, $a3, 16
    ori        $a3, $a3, 0x101
    lui        $a2, (0x80808080 >> 16)
    ori        $a2, $a2, (0x80808080 & 0xFFFF)
    dsll       $a2, $a2, 16
    ori        $a2, $a2, 0x8080
    dsll       $a2, $a2, 16
    ori        $a2, $a2, 0x8080
    bnez       $t1, .L001292DC
    ld        $v0, 0x0($a1)
    lq         $v1, 0x0($a0)
    pcpyld     $t0, $a3, $a3
    lq         $v0, 0x0($a1)
    pcpyld     $t2, $a2, $a2
    psubw      $a3, $v0, $v1
    pcpyud     $a2, $a3, $a0
    or         $v1, $a2, $a3
    bnel       $v1, $zero, .L00129348
    lb        $v0, 0x0($a0)
    lq         $v0, 0x0($a0)
    pnor       $v1, $zero, $v0
  .L00129290:
    psubb      $v0, $v0, $t0
    pand       $v0, $v0, $v1
    pand       $v0, $v0, $t2
    pcpyud     $v1, $v0, $a0
    or         $a2, $v1, $v0
    beqz       $a2, .L001292B4
    addiu     $a0, $a0, 0x10
    jr         $ra
    daddu     $v0, $zero, $zero
  .L001292B4:
    addiu      $a1, $a1, 0x10
    lq         $v0, 0x0($a0)
    lq         $v1, 0x0($a1)
    psubw      $a3, $v0, $v1
    pcpyud     $a2, $a3, $a0
    or         $t1, $a2, $a3
    beql       $t1, $zero, .L00129290
    pnor      $v1, $zero, $v0
    b          .L00129348
    lb        $v0, 0x0($a0)
  .L001292DC:
    ld         $v1, 0x0($a0)
    bnel       $v1, $v0, .L00129348
    lb        $v0, 0x0($a0)
    ld         $v0, 0x0($a0)
    nor        $t0, $zero, $v0
  .L001292F0:
    dsubu      $v0, $v0, $a3
    and        $v0, $v0, $t0
    and        $v0, $v0, $a2
    beqz       $v0, .L0012930C
    addiu     $a0, $a0, 0x8
    jr         $ra
    daddu     $v0, $zero, $zero
  .L0012930C:
    addiu      $a1, $a1, 0x8
    ld         $v0, 0x0($a0)
    ld         $v1, 0x0($a1)
    beql       $v1, $v0, .L001292F0
    nor       $t0, $zero, $v0
    b          .L00129348
    lb        $v0, 0x0($a0)
  .L00129328:
    sll        $v0, $v1, 24
    lb         $v1, 0x0($a1)
    sra        $v0, $v0, 24
    bnel       $v0, $v1, .L00129350
    lbu       $v1, 0x0($a0)
    addiu      $a0, $a0, 0x1
    addiu      $a1, $a1, 0x1
    lb         $v0, 0x0($a0)
  .L00129348:
    bnez       $v0, .L00129328
    lbu       $v1, 0x0($a0)
  .L00129350:
    lbu        $v0, 0x0($a1)
    jr         $ra
    subu      $v0, $v1, $v0
endlabel strcmp
    nop
