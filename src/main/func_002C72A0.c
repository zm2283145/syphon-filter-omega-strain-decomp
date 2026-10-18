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
extern void Mtx_ToEuler(V4* out, M4* m);
extern void* AgentPacking_Compact(void* data, int* len);
extern bool NetObj_SendMessage(int a, int b, void* c, int target, int type);
bool func_002C72A0(int idx, int a1, int a2, M4* m, void* data, short* sh, int s1);
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

bool func_002C72A0(int idx, int a1, int a2, M4* m, void* data, short* sh, int s1)
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
        Mtx_ToEuler(&e, m);
        msg.rot.x = e.x; msg.rot.y = e.y; msg.rot.z = e.z;
        Q1(&p, &m->r[3]);
        msg.pos.x = p.x;
        msg.pos.y = p.y;
        msg.pos.z = p.z;
        msg.s1 = s1;
        for (i = 0; i != 6; i++) msg.arr[i] = sh[i];
        void* d = AgentPacking_Compact(data, &len);
        QCopy(msg.buf, d, len);
        Msg72A0* pm = &msg; if (NetObj_SendMessage(D_0051EE70, 0x430, pm, idx, 0x40)) ret = true;
    }
    return ret;
}














