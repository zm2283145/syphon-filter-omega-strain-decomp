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
    short arr[6];
    char str[0x20];
    unsigned char b1;
    unsigned char b2;
    short s;
} __attribute__((aligned(16))) Msg7110;
extern "C" {
extern unsigned char D_0055C780[];
extern char D_004DE158[];
extern int D_0051EE78;
extern void Mtx_ToEuler(V4* out, M4* m);
extern bool NetObj_SendMessage(int a, int b, void* c, int target, int type);
bool netCreateNPC_SendCreated(int idx, int a1, int a2, M4* m, const char* str, short* sh, unsigned char b1, unsigned char b2, int sv);
void* memset(void* d, int c, unsigned int n);
unsigned int strlen(const char* s);
char* strncpy(char* d, const char* s, unsigned int n);
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

bool netCreateNPC_SendCreated(int idx, int a1, int a2, M4* m, const char* str, short* sh, unsigned char b1, unsigned char b2, int sv)
{
    Msg7110 msg;
    V4 e;
    V4 p;
    int i;
    bool ret = false;
    if (IsConnected(idx)) {
        msg.name = D_004DE158;
        msg.a1 = a1;
        Mtx_ToEuler(&e, m);
        msg.rot.x = e.x; msg.rot.y = e.y; msg.rot.z = e.z;
        Q1(&p, &m->r[3]);
        msg.pos.x = p.x;
        msg.pos.y = p.y;
        msg.pos.z = p.z;
        memset(msg.str, 0, 0x20);
        strncpy(msg.str, str, strlen(str));
        msg.s = sv;
        for (i = 0; i != 6; i++) msg.arr[i] = sh[i];
        msg.b1 = b1;
        msg.b2 = b2;
        Msg7110* pm = &msg; if (NetObj_SendMessage(D_0051EE78, 0x50, pm, idx, 0x40)) ret = true;
    }
    return ret;
}
