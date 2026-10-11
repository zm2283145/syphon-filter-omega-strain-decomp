#include "types.h"
typedef struct NetSessCfg_h5 {
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
} NetSessCfg_h5;
typedef struct NetGameCfg_h5 {
    int unk00;
    void* onConnect;
    int unk08;
    void* onLost;
    int unk10;
    void* onMsg;
    int unk18;
    int port;
    NetSessCfg_h5 sess;
} NetGameCfg_h5;
typedef struct NetGameOut_h5 {
    int unk0;
    int unk4;
    int handle;
    int unkC;
} NetGameOut_h5;
extern int D_00494180;
extern int D_00494198;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005724B0;
extern void func_00429790(void);
extern void func_00429A90(void);
extern void func_00429920(void);
extern void func_00437F90(void);
extern void func_00438240(void);
extern void func_002E98C0(int a, int b, int c);
extern int func_002EA6F0(NetGameCfg_h5* cfg);
extern int NetGame_Create(NetGameCfg_h5* cfg, NetGameOut_h5* out);
static inline void MemClear_h5(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a1, dst, 0xF
        andi $a0, n, 0xF
        or $a1, $a1, $a0
        nop
        bgtz $a1, bytes
        srl $a0, n, 4
        nop
        blez $a0, bytes
        nop
        nop
    quads:
        addi $a0, $a0, -1
        sq $zero, 0(dst)
        bgtz $a0, quads
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
void Net_CreateGame(void)
{
    NetGameOut_h5 out;
    NetGameCfg_h5 cfg;
    int err;
    if (D_00494198 == 0x10) {
        func_002E98C0(0, 0x5A, 0x5A);
    } else {
        func_002E98C0(0, 0x3C, 0x3C);
    }
    err = func_002EA6F0(&cfg);
    cfg.onConnect = func_00429790;
    cfg.port = D_00494180;
    cfg.onLost = func_00429A90;
    cfg.onMsg = func_00429920;
    MemClear_h5(&cfg.sess, 0x54);
    cfg.sess.cb34 = func_00438240;
    cfg.sess.unk10 = 1;
    cfg.sess.unk04 = 1;
    cfg.sess.cb2C = func_00437F90;
    cfg.sess.unk0C = 1;
    cfg.sess.unk14 = 1;
    cfg.sess.unk08 = 2;
    cfg.sess.unk20 = 2;
    cfg.sess.unk18 = 0x10;
    cfg.sess.unk24 = 0x10;
    cfg.sess.unk1C = 0x1F40;
    cfg.sess.unk28 = 0x1F40;
    if (err == 0) {
        if (NetGame_Create(&cfg, &out) == 0) {
            D_005721C0 = 1;
        } else {
            D_005721A8 = out.handle;
            D_005724B0 = 7;
        }
    }
}