#include "types.h"
typedef struct NetSessCfg_r8 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* cb2C;
    int unk30;
    void* cb34;
    int pad[7];
} NetSessCfg_r8;
extern void func_00437F90(void);
extern void func_00438240(void);
static inline void MemClear_r8(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a2, dst, 0xF
        andi $a1, n, 0xF
        or $a2, $a2, $a1
        nop
        bgtz $a2, bytes
        srl $a1, n, 4
        nop
        blez $a1, bytes
        nop
        nop
    quads:
        addi $a1, $a1, -1
        sq $zero, 0(dst)
        bgtz $a1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}
void func_0042B420(NetSessCfg_r8* sess)
{
    MemClear_r8(sess, 0x54);
    sess->unk10 = 1;
    sess->unk04 = 1;
    sess->unk0C = 1;
    sess->cb34 = func_00438240;
    sess->cb2C = func_00437F90;
    sess->unk08 = 2;
    sess->unk14 = 1;
    sess->unk20 = 2;
    sess->unk18 = 0x10;
    sess->unk24 = 0x10;
    sess->unk1C = 0x1F40;
    sess->unk28 = 0x1F40;
}
