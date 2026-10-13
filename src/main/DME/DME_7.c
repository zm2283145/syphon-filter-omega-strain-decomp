/*
 * main/DME: 4 files, 0042A960-0042ACD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00572470[];
extern char D_00572478[];
extern int Net_StartSession(int);

int func_0042A960(int a0) {
    *(int*)D_00572470 = 0;
    *(int*)D_00572478 = 1;
    return Net_StartSession(a0);
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A960 */

/* merge_units: begin func_0042A980 */
#pragma push /* merge_units */
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
unsigned int D_00494180[2] = { 0x4, 0x0 };
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
    cfg.port = (*(int*)D_00494180);
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
#pragma pop /* merge_units */
/* merge_units: end func_0042A980 */

/* merge_units: begin func_0042AB00 */
#pragma push /* merge_units */
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
extern char D_004BF9B8[];
extern void func_00429A60(void);
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
#pragma pop /* merge_units */
/* merge_units: end func_0042AB00 */

/* merge_units: begin func_0042ACD0 */
#pragma push /* merge_units */
typedef struct NetJoinCfg_n1_0042ACD0 {
    int unk00;
    int mode;
    int unk08;
    int unk0C;
    char name[0x10];
    int unk20;
    char addr[0x80];
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
} NetJoinCfg_n1_0042ACD0;
#if 0 /* merge_units */
extern int func_002EA5B0(NetJoinCfg_n1_0042ACD0* cfg);
#endif /* merge_units */
#define func_002EA5B0(a0) (func_002EA5B0((NetJoinCfg_n1 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_002EA648(NetJoinCfg_n1_0042ACD0* cfg, NetGameOut_n1* out);
#endif /* merge_units */
#define func_002EA648(a0, a1) (func_002EA648((NetJoinCfg_n1 *)(a0), (a1))) /* merge_units */

extern char* strncpy(char* d, const char* s, unsigned int n);
typedef struct NetHost_n1 { char name[0x10]; int unk10; } NetHost_n1;
static inline void MemClear_n1_0042ACD0(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $v1, dst, 0xF
        andi $v0, n, 0xF
        or $v1, $v1, $v0
        nop
        bgtz $v1, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
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
int func_0042ACD0(NetHost_n1* host)
{
    NetGameOut_n1 out;
    NetJoinCfg_n1_0042ACD0 cfg;
    int err;
    if (D_00494198 == 0x10) {
        func_002E98C0(0, 0x5A, 0x5A);
    } else {
        func_002E98C0(0, 0x3C, 0x3C);
    }
    func_002EA5B0(&cfg);
    cfg.mode = 4;
    cfg.unk08 = 2;
    cfg.unk0C = 1;
    strncpy(cfg.name, host->name, 0x10);
    cfg.unk20 = host->unk10;
    cfg.onConnect = func_00429790;
    cfg.onLost = func_00429A90;
    cfg.onMsg = func_00429920;
    cfg.onFail = func_00429A60;
    MemClear_n1_0042ACD0(&cfg.sess, 0x54);
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
#undef func_002EA5B0 /* merge_units */
#undef func_002EA648 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042ACD0 */
