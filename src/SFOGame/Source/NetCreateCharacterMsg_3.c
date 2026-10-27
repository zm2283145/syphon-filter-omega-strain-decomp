/*
 * SFOGame/Source/NetCreateCharacterMsg: 2 files, 002C72A0-002C7460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C72A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z; } V3;
struct V4 { float x, y, z, w; V4() {} V4(const V4& o) { __int128 t; const V4* s = &o; asm volatile { lq t, 0(s)
 sq t, 0(this) } } } __attribute__((aligned(16)));
typedef struct { V4 r[4]; } M4;
typedef struct {
    char* name;
    int a1;
    V3 rot;
    V3 pos;
    int s1;
    short arr[6];
    char buf[0x400];
} __attribute__((aligned(16))) Msg72A0;
extern "C" {
extern unsigned char D_0055C780[];
extern char D_004DE148[];
extern int D_0051EE70;
extern void cEulerAngle_T_1_2_ctor_cMatrixR(V4* out, M4* m);
extern void* SKL_CompressSKL(void* data, int* len);
extern bool cNetObj_SendMessage_int_int_ucharP_int_etc(int a, int b, void* c, int target, int type);
bool netCreatePlayer_SendCreated(int idx, int a1, int a2, M4* m, void* data, short* sh, int s1);
}

static inline void QCopy(void* dst0, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    void* dst = dst0;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}

static inline void Q1(void* d, const void* s) { __int128 q; asm volatile { lq q, 0(s)
 sq q, 0(d) } }
static inline bool IsConnected(int idx)
{
    bool ok = true;
    unsigned char st = D_0055C780[idx];
    if (st != 1 && st != 2) ok = false;
    return ok;
}

#pragma opt_unroll_loops off
#pragma opt_rotateloops off

bool netCreatePlayer_SendCreated(int idx, int a1, int a2, M4* m, void* data, short* sh, int s1)
{
    int len;
    Msg72A0 msg;
    V4 e;
    V4 p;
    int i;
    bool ret = false;
    if (IsConnected(idx)) {
        msg.name = D_004DE148;
        msg.a1 = a1;
        cEulerAngle_T_1_2_ctor_cMatrixR(&e, m);
        msg.rot.x = e.x; msg.rot.y = e.y; msg.rot.z = e.z;
        Q1(&p, &m->r[3]);
        msg.pos.x = p.x;
        msg.pos.y = p.y;
        msg.pos.z = p.z;
        msg.s1 = s1;
        for (i = 0; i != 6; i++) msg.arr[i] = sh[i];
        void* d = SKL_CompressSKL(data, &len);
        QCopy(msg.buf, d, len);
        Msg72A0* pm = &msg; if (cNetObj_SendMessage_int_int_ucharP_int_etc(D_0051EE70, 0x430, pm, idx, 0x40)) ret = true;
    }
    return ret;
}
static inline void merge_flush_func_002C72A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C72A0 */

/* merge_units: begin func_002C7460 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    int version;
    int ids[6];
    short values[6];
    char name[0x20];
    unsigned char flagA;
    unsigned char flagB;
    short count;
    char pad60[0xC];
} SaveHeader;
extern char D_004DE158[];
extern int D_0051EE78;
extern int NetRegisterMessageStart(void* stream);
extern int NetMessageField(SaveHeader* hdr, void* dst, int size, int count);
extern int NetRegisterApplicationMessage(int* out, void (*cb)(void));
extern void netCreateNPC_netCreateNPCCallback(void);

/* Reads the save header fields in order; returns the first error, or 0. */
int netCreateNPC_InitNet(void* stream)
{
    SaveHeader hdr;
    int handle;
    int err;
    hdr.vtable = D_004DE158;
    err = NetRegisterMessageStart(stream);
    if (err == 0) {
        err = NetMessageField(&hdr, &hdr.version, 4, 1);
        if (err == 0) {
            err = NetMessageField(&hdr, hdr.ids, 4, 6);
            if (err == 0) {
                err = NetMessageField(&hdr, hdr.name, 1, 0x20);
                if (err == 0) {
                    err = NetMessageField(&hdr, &hdr.count, 2, 1);
                    if (err == 0) {
                        err = NetMessageField(&hdr, hdr.values, 2, 6);
                        if (err == 0) {
                            err = NetMessageField(&hdr, &hdr.flagA, 1, 1);
                            if (err == 0) {
                                err = NetMessageField(&hdr, &hdr.flagB, 1, 1);
                                if (err == 0) {
                                    err = NetRegisterApplicationMessage(&handle, netCreateNPC_netCreateNPCCallback);
                                    if (err == 0) {
                                        D_0051EE78 = handle;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return err;
}
static inline void merge_flush_func_002C7460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C7460 */
