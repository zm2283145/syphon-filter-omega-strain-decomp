/*
 * main/gobj: 8 files, 003D1400-003D1700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D1400 */
#pragma push /* merge_units */
#include "types.h"
extern char D_004BD328[];
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int del);
extern void Mem_Free(int heap, void* p, const char* file, int line);
void func_003D1400(void* self, void* p)
{
    if (p) {
        int g[1];
        func_00136DA0(g);
        Mem_Free(0, p, D_004BD328, 100);
        func_0012F530(g, -1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1400 */

/* merge_units: begin func_003D1460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_003D1460(void) {
    return 1;
}

int func_003D1470(Word* self) {
    return self[0].value;
}

int func_003D1480(Word* self) {
    return self[1].value;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1460 */

/* merge_units: begin func_003D1490 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_int_pair_copy_ctor.h"
struct SF6_3D1490 { ShortStr first; int second; float a, b, c, d, e, f; };
extern "C" SF6_3D1490* func_003D1490(SF6_3D1490* self, const SF6_3D1490* src)
{
    if (!ShortStr_IsLong(&src->first)) {
        self->first = src->first;
    } else {
        self->first.u.l.word = 0;
        self->first.u.l.length = 0;
        self->first.u.l.data = 0;
        String_Reserve(&self->first, src->first.u.l.length);
        ShortStrIterTag tag;
        String_Replace(&self->first, 0, 0, src->first.u.l.data,
                       src->first.u.l.data + src->first.u.l.length, tag);
    }
    self->second = src->second;
    self->a = src->a;
    self->b = src->b;
    self->c = src->c;
    self->d = src->d;
    self->e = src->e;
    self->f = src->f;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1490 */

/* merge_units: begin func_003D1560 */
#pragma push /* merge_units */
List* List_InitEmpty(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1560 */

/* merge_units: begin func_003D1580 */
#pragma push /* merge_units */
static unsigned char D_00493800[] = "abcdefghijklmnopqrstuvwxyz1234567890\nE\b\t -=[]?\\;'?,./";
static unsigned char D_00493840[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()\nE\b\t _+{}?|:\"?<>?";
unsigned char UsbKbd_TranslateKey(unsigned char c, int flags)
{
    int v = c;
    if (v >= 0x42 || v < 4) return 0;
    if (v >= 0x3A && v < 0x42) return v + 0x46;
    return ((flags & 2) || (flags & 0x20)) ? D_00493840[v - 4] : D_00493800[v - 4];
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1580 */

/* merge_units: begin func_003D1610 */
#pragma push /* merge_units */
typedef struct { char pad[0x98]; int m98; unsigned short m9C; } T1610;
unsigned char UsbKbd_GetCode(T1610* p)
{
    unsigned char r = 0;
    if (p->m98) {
        unsigned short f = p->m9C;
        if (f & 0x8000) {
            r = 0;
        } else if (f & 0x4000) {
            r = f & ~0x4000;
        } else {
            r = f;
        }
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1610 */

/* merge_units: begin func_003D1660 */
#pragma push /* merge_units */
typedef struct { unsigned char m0; unsigned char m1; char pad[0x8E]; char data[8]; int m98; } T1660;
extern int sceUsbKbRead(unsigned int no, void* data);
extern int func_00223360(int mode, int* result);
extern void func_003D1770(T1660* kb);
int UsbKbd_Poll(T1660* kb, int flag)
{
    int v;
    if (kb->m1) {
        int r = sceUsbKbRead(0, kb->data);
        func_00223360(0, &r);
        if (r) {
            kb->m1 = 0;
            if (flag)
                func_003D1770(kb);
        }
    } else if (flag) {
        func_003D1770(kb);
    }
    v = kb->m1 ? kb->m98 : 0;
    return v != 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1660 */

/* merge_units: begin func_003D1700 */
#pragma push /* merge_units */
#include "loose04_types.h"

extern int func_002232C0(int, int);

int func_003D1700(Unk3D1700* self) {
    int ret = func_002232C0(0, 1);

    self->unk02 = 0;
    return ret;
}

int func_003D1730(Unk3D1700* self) {
    int ret = func_002232C0(0, 0);

    self->unk02 = 1;
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1700 */
