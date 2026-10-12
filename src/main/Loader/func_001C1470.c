#pragma cplusplus on
#include "types.h"
struct PopReader_1C1470 { int version; int size; unsigned int base; char* cur; };
struct Vec_1C1470 { float x, y, z; };
struct Buf_1C1470 { char b[0x24]; };
struct Loc_1C1470 { Vec_1C1470 v; int pad; Buf_1C1470 buf; };
struct Col_1C1470 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void Activate(int on);
};
extern "C" {
int Pop_FindTag(PopReader_1C1470* r, int tag);
Col_1C1470* IdMgr_FindCollision(int a, int b);
void ZoneMgr_Associate(Col_1C1470* a, Col_1C1470* b, int c, Col_1C1470* d);
}
static inline void Align_1C1470(PopReader_1C1470* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}
static inline int ReadInt_1C1470(PopReader_1C1470* r)
{
    int v = *(int*)r->cur;
    r->cur += 4;
    return v;
}
static inline float ReadFloat_1C1470(PopReader_1C1470* r)
{
    float v = *(float*)r->cur;
    r->cur += 4;
    return v;
}
static inline void Copy_1C1470(void* d0, void* s0, int n0)
{
    int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi $a0, s, 0xF
        andi $a1, d, 0xF
        or $a0, $a0, $a1
        andi $a1, n, 0xF
        or $a0, $a0, $a1
        nop
        bgtz $a0, bytes
        nop
    quads:
        lq $a1, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq $a1, -0x10(d)
        b done
        nop
    bytes:
        lb $a1, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb $a1, -1(d)
        .set reorder
    done:
    }
}
extern "C" void Loader_LoadPointLights(void* a0, PopReader_1C1470* r)
{
    Align_1C1470(r);
    if ((unsigned char)Pop_FindTag(r, 0x3A544E50)) {
        int n = ReadInt_1C1470(r);
        int i = 0;
        for (; i < n; i++) {
            Loc_1C1470 L;
            int a = ReadInt_1C1470(r);
            int b = ReadInt_1C1470(r);
            int c = ReadInt_1C1470(r);
            int d = ReadInt_1C1470(r);
            if (c != -1 && d != -1) {
                Col_1C1470* o1 = IdMgr_FindCollision(a, b);
                Col_1C1470* o2 = IdMgr_FindCollision(c, d);
                if (o1)
                    o1->Activate(1);
                if (o2 && o1)
                    ZoneMgr_Associate(o2, o1, 1, o2);
            }
            Copy_1C1470((void*)&L.buf, r->cur, 0x24);
            r->cur += 0x24;
            L.v.x = *(float*)r->cur; r->cur += 4;
            L.v.y = *(float*)r->cur; r->cur += 4;
            L.v.z = *(float*)r->cur; r->cur += 4;
            r->cur += 4;
            r->cur += 4;
            r->cur += 1;
            Align_1C1470(r);
            if (r->version >= 0x3B) {
                r->cur += 1;
                Align_1C1470(r);
                r->cur += 1;
                Align_1C1470(r);
            }
            r->cur += 4;
        }
    }
}