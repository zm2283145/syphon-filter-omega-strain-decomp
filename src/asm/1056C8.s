.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel _rix_000
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    sll        $t3, $t4, 1
    addiu      $t7, $zero, -0x1
    mtsab      $t5, 0x0
  .L001056EC:
    lq         $t0, 0x0($a1)
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    lq         $t1, 0x0($a2)
    addu       $a1, $a1, $t4
    qfsrv      $t2, $t1, $t0
    pextlb     $t0, $zero, $t2
    pextub     $t1, $zero, $t2
    sq         $t0, 0x0($t6)
    addu       $a2, $a2, $t4
    sq         $t1, 0x10($t6)
    bgtz       $a3, .L001056EC
    addu      $t6, $t6, $t3
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t2, $t7, $a3
    bnez       $t2, .L001056EC
    daddu     $t7, $zero, $zero
    jr         $ra
    nop
endlabel _rix_000
    nop

/* Handwritten function */

glabel _ri0_000
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    sll        $t3, $t4, 1
    mtsab      $t5, 0x0
    addiu      $t8, $zero, -0x1
  .L00105760:
    lw         $a3, 0x8($a0)
    addiu      $t7, $zero, -0x1
  .L00105768:
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    qfsrv      $t1, $t0, $t0
    pextlb     $t0, $zero, $t1
    sq         $t0, 0x0($t6)
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    addu       $a1, $a1, $t4
    addu       $t6, $t6, $t3
    bgtz       $a3, .L00105768
    addu      $a2, $a2, $t4
    addiu      $a1, $a1, 0x140
    addiu      $a2, $a2, 0x140
    lw         $a3, 0xC($a0)
    and        $t2, $t7, $a3
    bnez       $t2, .L00105768
    daddu     $t7, $zero, $zero
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    bnez       $t8, .L00105760
    daddu     $t8, $zero, $zero
    jr         $ra
    nop
endlabel _ri0_000
    nop

/* Handwritten function */

glabel _rix_001
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t8, 0x10($a0)
    lq         $t0, 0x0($a1)
    sll        $t4, $t8, 1
    lq         $t1, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $t2, $t1, $t0
    pextlb     $t0, $zero, $t2
    addiu      $t3, $zero, -0x1
    beqz       $a3, .L0010586C
    pextub    $t1, $zero, $t2
  .L0010581C:
    addu       $a1, $a1, $t8
    addu       $a2, $a2, $t8
    lq         $t2, 0x0($a1)
    lq         $t7, 0x0($a2)
    qfsrv      $v0, $t7, $t2
    pextlb     $t2, $zero, $v0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    pextub     $t7, $zero, $v0
    paddh      $v0, $t0, $t2
    paddh      $v1, $t1, $t7
    por        $t0, $t2, $zero
    por        $t1, $t7, $zero
    paddh      $v0, $v0, $t9
    paddh      $v1, $v1, $t9
    psrlh      $v0, $v0, 1
    psrlh      $v1, $v1, 1
    sq         $v0, 0x0($t6)
    sq         $v1, 0x10($t6)
    bgtz       $a3, .L0010581C
    addu      $t6, $t6, $t4
  .L0010586C:
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t2, $t3, $a3
    bnez       $t2, .L0010581C
    daddu     $t3, $zero, $zero
    jr         $ra
    nop
endlabel _rix_001
    nop

/* Handwritten function */

glabel _ri0_001
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    addiu      $t3, $zero, 0x1
    sll        $t8, $t4, 1
    mtsab      $t5, 0x0
  .L001058B8:
    lw         $a3, 0x8($a0)
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    qfsrv      $t0, $t0, $t0
    ori        $t3, $t3, 0x8000
    beqz       $a3, .L00105914
    pextlb    $t7, $zero, $t0
  .L001058D8:
    addu       $a1, $a1, $t4
    addu       $a2, $a2, $t4
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    qfsrv      $t0, $t0, $t0
    pextlb     $t2, $zero, $t0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    paddh      $t1, $t2, $t7
    por        $t7, $t2, $zero
    paddh      $t2, $t1, $t9
    psrlh      $t2, $t2, 1
    sq         $t2, 0x0($t6)
    bgtz       $a3, .L001058D8
    addu      $t6, $t6, $t8
  .L00105914:
    psrah      $t2, $t3, 15
    addiu      $a1, $a1, 0x140
    lw         $a3, 0xC($a0)
    addiu      $a2, $a2, 0x140
    and        $t2, $t2, $a3
    bnez       $t2, .L001058D8
    andi      $t3, $t3, 0x7FFF
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    andi       $t2, $t3, 0x1
    bnez       $t2, .L001058B8
    andi      $t3, $t3, 0xFFFE
    jr         $ra
    nop
endlabel _ri0_001
    nop

/* Handwritten function */

glabel _rix_010
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    addiu      $t8, $zero, 0x1
    lw         $t1, 0x10($a0)
    sll        $t0, $t1, 1
    addiu      $t3, $zero, -0x1
  .L0010598C:
    lq         $t2, 0x0($a1)
    lq         $t7, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $v0, $t7, $t2
    qfsrv      $v1, $t2, $t7
    pextlb     $t2, $zero, $v0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    pextub     $t7, $zero, $v0
    mtsab      $t8, 0x0
    qfsrv      $v1, $v1, $v0
    pextlb     $v0, $zero, $v1
    pextub     $v1, $zero, $v1
    paddh      $t2, $t2, $v0
    paddh      $t7, $t7, $v1
    paddh      $v0, $t2, $t9
    paddh      $v1, $t7, $t9
    psrlh      $v0, $v0, 1
    psrlh      $v1, $v1, 1
    sq         $v0, 0x0($t6)
    sq         $v1, 0x10($t6)
    addu       $a1, $a1, $t1
    addu       $a2, $a2, $t1
    bgtz       $a3, .L0010598C
    addu      $t6, $t6, $t0
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t4, $t3, $a3
    bnez       $t4, .L0010598C
    daddu     $t3, $zero, $zero
    jr         $ra
    nop
endlabel _rix_010
    nop

/* Handwritten function */

glabel _ri0_010
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    addiu      $t8, $zero, 0x1
    addiu      $t4, $zero, -0x1
    lw         $v1, 0x10($a0)
    sll        $v0, $v1, 1
  .L00105A38:
    lw         $a3, 0x8($a0)
    addiu      $t3, $zero, -0x1
  .L00105A40:
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    mtsab      $t5, 0x0
    qfsrv      $t0, $t0, $t0
    pextlb     $t1, $zero, $t0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    addu       $a1, $a1, $v1
    addu       $a2, $a2, $v1
    mtsab      $t8, 0x0
    qfsrv      $t2, $zero, $t0
    pextlb     $t0, $zero, $t2
    paddh      $t2, $t1, $t0
    paddh      $t2, $t2, $t9
    psrlh      $t2, $t2, 1
    sq         $t2, 0x0($t6)
    bgtz       $a3, .L00105A40
    addu      $t6, $t6, $v0
    addiu      $a1, $a1, 0x140
    addiu      $a2, $a2, 0x140
    lw         $a3, 0xC($a0)
    and        $t2, $t3, $a3
    bnez       $t2, .L00105A40
    daddu     $t3, $zero, $zero
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    bnez       $t4, .L00105A38
    daddu     $t4, $zero, $zero
    jr         $ra
    nop
endlabel _ri0_010

/* Handwritten function */

glabel _rix_011
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    psllh      $t9, $t9, 1
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    addiu      $t8, $zero, 0x1
    lq         $t0, 0x0($a1)
    lq         $t1, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $t2, $t1, $t0
    qfsrv      $t7, $t0, $t1
    pextlb     $t0, $zero, $t2
    pextub     $t1, $zero, $t2
    addiu      $t3, $zero, -0x1
    mtsab      $t8, 0x0
    qfsrv      $t7, $t7, $t2
    pextlb     $t2, $zero, $t7
    pextub     $t7, $zero, $t7
    paddh      $t0, $t0, $t2
    beqz       $a3, .L00105BA0
    paddh     $t1, $t1, $t7
  .L00105B2C:
    addu       $a1, $a1, $t4
    addu       $a2, $a2, $t4
    lq         $t2, 0x0($a1)
    lq         $t7, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $v0, $t7, $t2
    qfsrv      $v1, $t2, $t7
    pextlb     $t2, $zero, $v0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    pextub     $t7, $zero, $v0
    mtsab      $t8, 0x0
    qfsrv      $v1, $v1, $v0
    pextlb     $v0, $zero, $v1
    pextub     $v1, $zero, $v1
    paddh      $t2, $t2, $v0
    paddh      $t7, $t7, $v1
    paddh      $v0, $t0, $t2
    paddh      $v1, $t1, $t7
    por        $t0, $t2, $zero
    por        $t1, $t7, $zero
    paddh      $v0, $v0, $t9
    paddh      $v1, $v1, $t9
    psrlh      $v0, $v0, 2
    psrlh      $v1, $v1, 2
    sq         $v0, 0x0($t6)
    sll        $t2, $t4, 1
    sq         $v1, 0x10($t6)
    bgtz       $a3, .L00105B2C
    addu      $t6, $t6, $t2
  .L00105BA0:
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t2, $t3, $a3
    bnez       $t2, .L00105B2C
    daddu     $t3, $zero, $zero
    jr         $ra
    nop
endlabel _rix_011

/* Handwritten function */

glabel _ri0_011
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    psllh      $t9, $t9, 1
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    addiu      $t8, $zero, 0x1
    addiu      $t3, $zero, 0x1
  .L00105BE8:
    lw         $a3, 0x8($a0)
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    mtsab      $t5, 0x0
    qfsrv      $t0, $t0, $t0
    pextlb     $t1, $zero, $t0
    addu       $a1, $a1, $t4
    ori        $t3, $t3, 0x8000
    mtsab      $t8, 0x0
    qfsrv      $t2, $zero, $t0
    pextlb     $t0, $zero, $t2
    beqz       $a3, .L00105C74
    paddh     $t7, $t1, $t0
  .L00105C20:
    addu       $a2, $a2, $t4
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    mtsab      $t5, 0x0
    qfsrv      $t0, $t0, $t0
    pextlb     $t1, $zero, $t0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    addu       $a1, $a1, $t4
    mtsab      $t8, 0x0
    qfsrv      $t2, $zero, $t0
    pextlb     $t0, $zero, $t2
    paddh      $t2, $t1, $t0
    paddh      $t1, $t2, $t7
    por        $t7, $t2, $zero
    paddh      $t2, $t1, $t9
    sll        $t0, $t4, 1
    psrlh      $t2, $t2, 2
    sq         $t2, 0x0($t6)
    bgtz       $a3, .L00105C20
    addu      $t6, $t6, $t0
  .L00105C74:
    psrah      $t2, $t3, 15
    addiu      $a1, $a1, 0x140
    lw         $a3, 0xC($a0)
    addiu      $a2, $a2, 0x140
    and        $t2, $t2, $a3
    bnez       $t2, .L00105C20
    andi      $t3, $t3, 0x7FFF
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    andi       $t2, $t3, 0x1
    bnez       $t2, .L00105BE8
    andi      $t3, $t3, 0xFFFE
    jr         $ra
    nop
endlabel _ri0_011
    nop

/* Handwritten function */

glabel _rix_100
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t1, 0x10($a0)
    sll        $t0, $t1, 1
    addiu      $t3, $zero, -0x1
    mtsab      $t5, 0x0
  .L00105CE4:
    lq         $t2, 0x0($a1)
    lq         $t7, 0x0($a2)
    qfsrv      $v0, $t7, $t2
    pextlb     $t2, $zero, $v0
    pextub     $t7, $zero, $v0
    lq         $v0, 0x0($t6)
    lq         $v1, 0x10($t6)
    paddh      $v0, $v0, $t2
    paddh      $v1, $v1, $t7
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    paddh      $t2, $v0, $t9
    psrlh      $v0, $t2, 1
    paddh      $t2, $v1, $t9
    psrlh      $v1, $t2, 1
    sq         $v0, 0x0($t6)
    sq         $v1, 0x10($t6)
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    addu       $a1, $a1, $t1
    addu       $t6, $t6, $t0
    bgtz       $a3, .L00105CE4
    addu      $a2, $a2, $t1
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t4, $t3, $a3
    bnez       $t4, .L00105CE4
    daddu     $t3, $zero, $zero
    jr         $ra
    nop
endlabel _rix_100
    nop

/* Handwritten function */

glabel _ri0_100
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    addiu      $t4, $zero, -0x1
    lw         $v1, 0x10($a0)
    sll        $v0, $v1, 1
    mtsab      $t5, 0x0
  .L00105D80:
    lw         $a3, 0x8($a0)
    addiu      $t3, $zero, -0x1
  .L00105D88:
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    qfsrv      $t0, $t0, $t0
    pextlb     $t1, $zero, $t0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    addu       $a1, $a1, $v1
    addu       $a2, $a2, $v1
    lq         $t0, 0x0($t6)
    paddh      $t2, $t1, $t0
    pcgth      $t1, $t2, $zero
    psrlh      $t1, $t1, 15
    paddh      $t2, $t2, $t1
    psrlh      $t2, $t2, 1
    sq         $t2, 0x0($t6)
    bgtz       $a3, .L00105D88
    addu      $t6, $t6, $v0
    addiu      $a1, $a1, 0x140
    addiu      $a2, $a2, 0x140
    lw         $a3, 0xC($a0)
    and        $t2, $t3, $a3
    bnez       $t2, .L00105D88
    daddu     $t3, $zero, $zero
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    bnez       $t4, .L00105D80
    daddu     $t4, $zero, $zero
    jr         $ra
    nop
endlabel _ri0_100
    nop

/* Handwritten function */

glabel _rix_101
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    lq         $t0, 0x0($a1)
    lq         $t1, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $t2, $t1, $t0
    sll        $t8, $t4, 1
    pextlb     $t0, $zero, $t2
    addiu      $t3, $zero, -0x1
    beqz       $a3, .L00105ECC
    pextub    $t1, $zero, $t2
  .L00105E54:
    addu       $a1, $a1, $t4
    addu       $a2, $a2, $t4
    lq         $t2, 0x0($a1)
    lq         $t7, 0x0($a2)
    qfsrv      $v0, $t7, $t2
    pextlb     $t2, $zero, $v0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    pextub     $t7, $zero, $v0
    paddh      $v0, $t0, $t2
    paddh      $v1, $t1, $t7
    por        $t0, $t2, $zero
    por        $t1, $t7, $zero
    paddh      $v0, $v0, $t9
    paddh      $v1, $v1, $t9
    psrlh      $v0, $v0, 1
    psrlh      $v1, $v1, 1
    lq         $t2, 0x0($t6)
    lq         $t7, 0x10($t6)
    paddh      $v0, $v0, $t2
    paddh      $v1, $v1, $t7
    paddh      $t2, $v0, $t9
    psrlh      $v0, $t2, 1
    pcgth      $t2, $v1, $zero
    psrlh      $t2, $t2, 15
    paddh      $t2, $v1, $t2
    psrlh      $v1, $t2, 1
    sq         $v0, 0x0($t6)
    sq         $v1, 0x10($t6)
    bgtz       $a3, .L00105E54
    addu      $t6, $t6, $t8
  .L00105ECC:
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t2, $t3, $a3
    bnez       $t2, .L00105E54
    daddu     $t3, $zero, $zero
    jr         $ra
    nop
endlabel _rix_101
    nop

/* Handwritten function */

glabel _ri0_101
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    addiu      $t3, $zero, 0x1
    sll        $t8, $t4, 1
    mtsab      $t5, 0x0
  .L00105F18:
    lw         $a3, 0x8($a0)
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    qfsrv      $t0, $t0, $t0
    ori        $t3, $t3, 0x8000
    beqz       $a3, .L00105F8C
    pextlb    $t7, $zero, $t0
  .L00105F38:
    addu       $a1, $a1, $t4
    addu       $a2, $a2, $t4
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    qfsrv      $t0, $t0, $t0
    pextlb     $t2, $zero, $t0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    paddh      $t1, $t2, $t7
    por        $t7, $t2, $zero
    paddh      $t2, $t1, $t9
    psrlh      $t2, $t2, 1
    lq         $t0, 0x0($t6)
    paddh      $t2, $t2, $t0
    pcgth      $t1, $t2, $zero
    psrlh      $t1, $t1, 15
    paddh      $t2, $t2, $t1
    psrlh      $t2, $t2, 1
    sq         $t2, 0x0($t6)
    bgtz       $a3, .L00105F38
    addu      $t6, $t6, $t8
  .L00105F8C:
    psrah      $t2, $t3, 15
    addiu      $a1, $a1, 0x140
    lw         $a3, 0xC($a0)
    addiu      $a2, $a2, 0x140
    and        $t2, $t2, $a3
    bnez       $t2, .L00105F38
    andi      $t3, $t3, 0x7FFF
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    andi       $t2, $t3, 0x1
    bnez       $t2, .L00105F18
    andi      $t3, $t3, 0xFFFE
    jr         $ra
    nop
endlabel _ri0_101
    nop

/* Handwritten function */

glabel _rix_110
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    addiu      $t8, $zero, 0x1
    lw         $t1, 0x10($a0)
    sll        $t0, $t1, 1
    addiu      $t3, $zero, -0x1
  .L00106004:
    lq         $t2, 0x0($a1)
    lq         $t7, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $v0, $t7, $t2
    qfsrv      $v1, $t2, $t7
    pextlb     $t2, $zero, $v0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    pextub     $t7, $zero, $v0
    mtsab      $t8, 0x0
    qfsrv      $v1, $v1, $v0
    pextlb     $v0, $zero, $v1
    pextub     $v1, $zero, $v1
    paddh      $t2, $t2, $v0
    paddh      $t7, $t7, $v1
    paddh      $v0, $t2, $t9
    paddh      $v1, $t7, $t9
    psrlh      $v0, $v0, 1
    psrlh      $v1, $v1, 1
    lq         $t2, 0x0($t6)
    lq         $t7, 0x10($t6)
    paddh      $v0, $v0, $t2
    paddh      $v1, $v1, $t7
    paddh      $t2, $v0, $t9
    psrlh      $v0, $t2, 1
    pcgth      $t2, $v1, $zero
    psrlh      $t2, $t2, 15
    paddh      $t2, $v1, $t2
    psrlh      $v1, $t2, 1
    sq         $v0, 0x0($t6)
    sq         $v1, 0x10($t6)
    addu       $a1, $a1, $t1
    addu       $a2, $a2, $t1
    bgtz       $a3, .L00106004
    addu      $t6, $t6, $t0
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t4, $t3, $a3
    bnez       $t4, .L00106004
    daddu     $t3, $zero, $zero
    jr         $ra
    nop
endlabel _rix_110
    nop

/* Handwritten function */

glabel _ri0_110
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    addiu      $t8, $zero, 0x1
    addiu      $t4, $zero, -0x1
    lw         $v1, 0x10($a0)
    sll        $v0, $v1, 1
  .L001060D8:
    lw         $a3, 0x8($a0)
    addiu      $t3, $zero, -0x1
  .L001060E0:
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    mtsab      $t5, 0x0
    qfsrv      $t0, $t0, $t0
    pextlb     $t1, $zero, $t0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    addu       $a1, $a1, $v1
    addu       $a2, $a2, $v1
    mtsab      $t8, 0x0
    qfsrv      $t2, $zero, $t0
    pextlb     $t0, $zero, $t2
    paddh      $t2, $t1, $t0
    paddh      $t2, $t2, $t9
    psrlh      $t2, $t2, 1
    lq         $t0, 0x0($t6)
    paddh      $t2, $t2, $t0
    pcgth      $t1, $t2, $zero
    psrlh      $t1, $t1, 15
    paddh      $t2, $t2, $t1
    psrlh      $t2, $t2, 1
    sq         $t2, 0x0($t6)
    bgtz       $a3, .L001060E0
    addu      $t6, $t6, $v0
    addiu      $a1, $a1, 0x140
    addiu      $a2, $a2, 0x140
    lw         $a3, 0xC($a0)
    and        $t2, $t3, $a3
    bnez       $t2, .L001060E0
    daddu     $t3, $zero, $zero
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    bnez       $t4, .L001060D8
    daddu     $t4, $zero, $zero
    jr         $ra
    nop
endlabel _ri0_110

/* Handwritten function */

glabel _rix_111
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    psllh      $t9, $t9, 1
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $a3, 0x8($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t8, 0x10($a0)
    addiu      $t4, $zero, 0x1
    lq         $t0, 0x0($a1)
    lq         $t1, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $t2, $t1, $t0
    qfsrv      $t7, $t0, $t1
    pextlb     $t0, $zero, $t2
    pextub     $t1, $zero, $t2
    addiu      $t3, $zero, -0x1
    mtsab      $t4, 0x0
    qfsrv      $t7, $t7, $t2
    pextlb     $t2, $zero, $t7
    pextub     $t7, $zero, $t7
    paddh      $t0, $t0, $t2
    beqz       $a3, .L00106280
    paddh     $t1, $t1, $t7
  .L001061E4:
    addu       $a1, $a1, $t8
    addu       $a2, $a2, $t8
    lq         $t2, 0x0($a1)
    lq         $t7, 0x0($a2)
    mtsab      $t5, 0x0
    qfsrv      $v0, $t7, $t2
    qfsrv      $v1, $t2, $t7
    pextlb     $t2, $zero, $v0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    pextub     $t7, $zero, $v0
    mtsab      $t4, 0x0
    qfsrv      $v1, $v1, $v0
    pextlb     $v0, $zero, $v1
    pextub     $v1, $zero, $v1
    paddh      $t2, $t2, $v0
    paddh      $t7, $t7, $v1
    paddh      $v0, $t0, $t2
    paddh      $v1, $t1, $t7
    por        $t0, $t2, $zero
    por        $t1, $t7, $zero
    paddh      $v0, $v0, $t9
    paddh      $v1, $v1, $t9
    psrlh      $v0, $v0, 2
    psrlh      $v1, $v1, 2
    lq         $t2, 0x0($t6)
    lq         $t7, 0x10($t6)
    paddh      $v0, $v0, $t2
    paddh      $v1, $v1, $t7
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    paddh      $t2, $v0, $t9
    psrlh      $v0, $t2, 1
    paddh      $t2, $v1, $t9
    psrlh      $v1, $t2, 1
    sq         $v0, 0x0($t6)
    sll        $t2, $t8, 1
    sq         $v1, 0x10($t6)
    bgtz       $a3, .L001061E4
    addu      $t6, $t6, $t2
  .L00106280:
    addiu      $a1, $a1, 0x80
    addiu      $a2, $a2, 0x80
    lw         $a3, 0xC($a0)
    and        $t2, $t3, $a3
    bnez       $t2, .L001061E4
    daddu     $t3, $zero, $zero
    jr         $ra
    nop
endlabel _rix_111

/* Handwritten function */

glabel _ri0_111
    pnor       $t9, $zero, $zero
    psrlh      $t9, $t9, 15
    psllh      $t9, $t9, 1
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    lw         $t5, 0x4($a0)
    lw         $t4, 0x10($a0)
    addiu      $t8, $zero, 0x1
    addiu      $t3, $zero, 0x1
  .L001062C8:
    lw         $a3, 0x8($a0)
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    mtsab      $t5, 0x0
    qfsrv      $t0, $t0, $t0
    pextlb     $t1, $zero, $t0
    addu       $a1, $a1, $t4
    ori        $t3, $t3, 0x8000
    mtsab      $t8, 0x0
    qfsrv      $t2, $zero, $t0
    pextlb     $t0, $zero, $t2
    beqz       $a3, .L0010636C
    paddh     $t7, $t1, $t0
  .L00106300:
    addu       $a2, $a2, $t4
    ld         $t0, 0x0($a1)
    ld         $t1, 0x0($a2)
    pcpyld     $t0, $t1, $t0
    mtsab      $t5, 0x0
    qfsrv      $t0, $t0, $t0
    pextlb     $t1, $zero, $t0
    addi       $a3, $a3, -0x1 /* handwritten instruction */
    addu       $a1, $a1, $t4
    mtsab      $t8, 0x0
    qfsrv      $t2, $zero, $t0
    pextlb     $t0, $zero, $t2
    paddh      $t2, $t1, $t0
    paddh      $t1, $t2, $t7
    por        $t7, $t2, $zero
    paddh      $t2, $t1, $t9
    psrlh      $t2, $t2, 2
    lq         $t0, 0x0($t6)
    paddh      $t2, $t2, $t0
    pcgth      $t1, $t2, $zero
    psrlh      $t1, $t1, 15
    paddh      $t2, $t2, $t1
    sll        $t0, $t4, 1
    psrlh      $t2, $t2, 1
    sq         $t2, 0x0($t6)
    bgtz       $a3, .L00106300
    addu      $t6, $t6, $t0
  .L0010636C:
    psrah      $t2, $t3, 15
    addiu      $a1, $a1, 0x140
    lw         $a3, 0xC($a0)
    addiu      $a2, $a2, 0x140
    and        $t2, $t2, $a3
    bnez       $t2, .L00106300
    andi      $t3, $t3, 0x7FFF
    lw         $a1, 0x14($a0)
    lw         $a2, 0x18($a0)
    lw         $t6, 0x0($a0)
    addiu      $a1, $a1, 0x40
    addiu      $a2, $a2, 0x40
    addiu      $t6, $t6, 0x80
    andi       $t2, $t3, 0x1
    bnez       $t2, .L001062C8
    andi      $t3, $t3, 0xFFFE
    jr         $ra
    nop
endlabel _ri0_111
    nop

/* Handwritten function */

glabel func_001063B8
    addiu      $t4, $zero, 0x18
    lui        $t2, %hi(D_00106460)
    addiu      $t2, $t2, %lo(D_00106460)
    lq         $t3, 0x0($t2)
  .L001063C8:
    lq         $t0, 0x0($a1)
    addi       $t4, $t4, -0x1 /* handwritten instruction */
    lq         $t5, 0x0($a2)
    addiu      $a0, $a0, 0x10
    lq         $t1, 0x10($a1)
    paddh      $t0, $t0, $t5
    lq         $v0, 0x10($a2)
    pminh      $t0, $t0, $t3
    paddh      $t1, $t1, $v0
    pmaxh      $t0, $t0, $zero
    pminh      $t1, $t1, $t3
    addiu      $a1, $a1, 0x20
    pmaxh      $t1, $t1, $zero
    addiu      $a2, $a2, 0x20
    ppacb      $t2, $t1, $t0
    bnez       $t4, .L001063C8
    sq        $t2, -0x10($a0)
    jr         $ra
    nop
endlabel func_001063B8
    nop


dlabel func_00106418
    .word 0x240C0018
    .word 0x3C0A0010
    .word 0x254A6460
    .word 0x794B0000
    .word 0x78A80000
    .word 0x218CFFFF
    .word 0x710B41E8
    .word 0x78A90010
    .word 0x710041C8
    .word 0x712B49E8
    .word 0x24A50020
    .word 0x712049C8
    .word 0x24840010
    .word 0x712856C8
    .word 0x1580FFF5
    .word 0x7C8AFFF0
    .word 0x00000000
    .word 0x00000000


dlabel D_00106460
    .word 0x00FF00FF /* invalid instruction */
    .word 0x00FF00FF /* invalid instruction */
    .word 0x00FF00FF /* invalid instruction */
    .word 0x00FF00FF /* invalid instruction */
    .word 0x03E00008
    .word 0x00000000
enddlabel func_00106418
