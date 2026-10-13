#include "types.h"
typedef struct NetSessCfg_n1 {
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
} NetSessCfg_n1;
typedef struct NetJoinCfg_n1 {
    int unk00;
    int mode;
    char addr[0x9C];
    void* onConnect;
    int unkA8;
    int unkAC;
    int unkB0;
    void* onLost;
    int unkB8;
    void* onMsg;
    int unkC0;
    void* onFail;
    int unkC8;
    NetSessCfg_n1 sess;
    int tail[4];
} NetJoinCfg_n1;
typedef struct NetGameOut_n1 {
    int unk0;
    int unk4;
    int handle;
    int unkC;
} NetGameOut_n1;
extern int D_00494198;
extern int D_005721A8;
extern unsigned char D_005724B0;
extern char D_004BF9B8[];
extern void func_00429790(void);
extern void func_00429A90(void);
extern void func_00429A60(void);
extern void func_00429920(void);
extern void func_00437F90(void);
extern void func_00438240(void);
extern void func_002E98C0(int a, int b, int c);
extern int func_002EA5B0(NetJoinCfg_n1* cfg);
extern int func_002EA648(NetJoinCfg_n1* cfg, NetGameOut_n1* out);
extern void* memcpy(void* d, const void* s, unsigned int n);
extern int Gui_GetScreenStack(void);
extern void func_0041E0F0(int a, int b, int c, int d, int e);
static inline void MemClear_n1(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v1, n, 0xF
        or $a0, $a0, $v1
        nop
        bgtz $a0, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
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
int Net_ConnectGame(void* addr)
{
    NetGameOut_n1 out;
    NetJoinCfg_n1 cfg;
    int err;
    if (D_00494198 == 0x10) {
        func_002E98C0(0, 0x5A, 0x5A);
    } else {
        func_002E98C0(0, 0x3C, 0x3C);
    }
    func_002EA5B0(&cfg);
    cfg.mode = 4;
    memcpy(cfg.addr, addr, 0x9C);
    cfg.onConnect = func_00429790;
    cfg.onLost = func_00429A90;
    cfg.onMsg = func_00429920;
    cfg.onFail = func_00429A60;
    MemClear_n1(&cfg.sess, 0x54);
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
    err = func_002EA648(&cfg, &out);
    if (err) {
        D_005721A8 = out.handle;
        D_005724B0 = 7;
        if (Gui_GetScreenStack()) {
            func_0041E0F0(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, (int)D_004BF9B8);
        }
    }
    return err;
}