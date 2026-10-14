/*
 * main/NIEvent: range (2 files, 00239DF0-00239FA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00239DF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma optimize_for_size on
struct Key_239DF0 { float a; float t; float c; float d; };
struct Vec_239DF0 {
    int capacity; int count; Key_239DF0* data;
};
struct Track_239DF0 {
    float cur;
    Vec_239DF0 keys;
    int pad10;
    int w14;
    int w18;
    unsigned char b1C;
};
struct Reader_239DF0 { int version; int size; unsigned int base; char* cur; };
static inline float RdF_239DF0(Reader_239DF0* r) { float t = *(float*)r->cur; r->cur += 4; return t; }
static inline int RdI_239DF0(Reader_239DF0* r) { int t = *(int*)r->cur; r->cur += 4; return t; }
static inline Key_239DF0* Zero_239DF0(void* d0, int n0) { void* dst = d0; int n = n0; Key_239DF0* r;
    asm {
        beqz dst, done
        move r, dst
    loop:
        sb $zero, 0(dst)
        addiu n, n, -1
        addiu dst, dst, 1
        bnez n, loop
    done:
    }
    return r;
}
extern "C" void func_00240150(Vec_239DF0* v, unsigned int n, const Key_239DF0* value);
extern "C" void NiEvent_ReadKeyedTrack4(Track_239DF0* self, Reader_239DF0* r)
{
    Key_239DF0 k1;
    Key_239DF0 k0;
    int n = RdI_239DF0(r);
    int i;
    if (n)
        self->w14 = (int)(RdF_239DF0(r) - 1.0f);
    {
        Key_239DF0* p1 = Zero_239DF0(&k1, 16);
        Key_239DF0* p0 = Zero_239DF0(&k0, 16);
        func_00240150(&self->keys, 0, p0);
        func_00240150(&self->keys, n, p1);
    }
    i = 0;
    if (0 < n) do {
        self->keys.data[i].a = RdF_239DF0(r);
        self->keys.data[i].t = RdF_239DF0(r);
        self->keys.data[i].c = *(float*)r->cur;
        r->cur += 4;
        self->keys.data[i].d = *(float*)r->cur;
        r->cur += 4;
    } while (++i < n);
    self->b1C = 0;
    self->w18 = 0;
    if (self->keys.count > 0)
        self->cur = self->keys.data[0].t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239DF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239DF0 */

/* merge_units: begin func_00239FA0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Tgt00239FA0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void apply();
    char pad[0x34];
    int value;
};
struct Ev00239FA0 {
    char pad00[0x38];
    int value;
    char pad3C[0xDC - 0x3C];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt00239FA0* target;
};
extern "C" void cNIEventOBJ_v14(Ev00239FA0* self)
{
    if (self->enabled) {
        self->target->value = self->value;
        self->target->apply();
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239FA0 */
