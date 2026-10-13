/*
 * main/hog: 2 files, 0036CB90-0036CD80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036CB90 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_0036CB90 */

/* merge_units: begin func_0036CD80 */
#pragma push /* merge_units */
#pragma cplusplus on
struct S36CD80 { char pad[0x80]; char m80[0xC8]; void* p148; unsigned char b14C; char pad14D[0xB]; void* p158; int x15C; int x160; int pool; };
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void Rel36CD80(void* p, int pool, int line)
{
    AllocGuard g;
    Mem_Free(pool, p, D_004BBF88, line);
}
extern "C" int func_0036CD80(S36CD80* s)
{
    if (!s->b14C)
        return 0;
    func_003695C0(s->m80);
    if (s->p158) {
        Rel36CD80(s->p158, s->pool, 0x122);
        s->p158 = 0;
    }
    if (s->b14C == 2) {
        Rel36CD80(s->p148, s->pool, 0x128);
    }
    s->p148 = 0;
    s->x15C = 0;
    s->x160 = 0;
    s->pool = 0;
    s->b14C = 0;
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036CD80 */
