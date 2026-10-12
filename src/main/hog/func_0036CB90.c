#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct H36CB90 { int pad0; unsigned int count; char pad8[8]; int base; };
struct T36CB90 { H36CB90* hdr; unsigned char state; char pad5[0xB]; void* buf; int x; int* offs; int pool;
    int EntrySize(int i) { if (!state) return 0; return offs[i + 1] - offs[i]; } };
struct S36CB90 { char pad[0x80]; char m80[0xC8]; T36CB90 t; };
extern "C" {
extern char D_004BBF88[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_003695C0(void* p);
void func_003696B0(void* p, void* o, int mode);
void func_00369270(void* p, void* buf, int size, int off);
}
static inline void* Alloc36CB90(int pool, int size)
{
    AllocGuard g;
    return Mem_Alloc(pool, size, D_004BBF88, 0x16C);
}
extern "C" int func_0036CB90(S36CB90* s, int idx, int flag)
{
    if (*(volatile unsigned char*)&s->t.state != 2) return 4;
    if (!s->t.buf) {
        int max = 0;
        int i;
        for (i = 0; i < s->t.hdr->count; i++) {
            int n = s->t.EntrySize(i);
            max = max < n ? n : max;
        }
        s->t.buf = Alloc36CB90(s->t.pool, max);
        if (!s->t.buf) {
            func_003695C0(s->m80);
            return 3;
        }
    }
    if (flag)
        func_003696B0(s->m80, s, 0x8000);
    else
        func_003696B0(s->m80, s, 1);
    {
        int off = s->t.offs[idx];
        func_00369270(s->m80, s->t.buf, s->t.state ? s->t.offs[idx + 1] - off : 0, s->t.hdr->base + off);
    }
    return 0;
}

