/*
 * main/guiMLTextWidget: 4 files, 0043FF70-00440160
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043FF70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004E1160[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* func_0043FF70(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)Mem_Alloc(0, 0x28, "NetTransferRecvMsg.hh", 0x14);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w4 = self->w4;
        p->w8 = self->w8;
        p->wC = self->wC;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004E1160;
        p->w24 = self->w24;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043FF70 */

/* merge_units: begin func_00440070 */
#pragma push /* merge_units */
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_00583988;
extern int func_00440100();
unsigned char func_00440070(void) {
    int a[2];
    int buf[2];
    int busy;
    unsigned char r = 0;
    busy = func_002E9A10();
    if (!busy && func_003C9C30(buf) && !busy && func_002E9A98(buf, a, 4, 1) == 0 && NetMsg_RegisterType(&D_00583988, 2, func_00440100) == 0) {
        r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00440070 */

/* merge_units: begin func_00440100 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0042D300(int *);                             
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;

int func_00440100(int d0, int d1, int d2, char * arg3) {
    int sp18[2];

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (D_005721D0 != 0) {
        sp18[0] = F_(arg3, 0x8, int);
        func_0042D300(sp18);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop /* merge_units */
/* merge_units: end func_00440100 */

/* merge_units: begin func_00440160 */
#pragma push /* merge_units */
#include "message_pack.h"

#define PACK_PRE(e)
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24);

DEFINE_MESSAGE_PACK_PRE(func_00440160, 12, D_00583988, PACK_PRE, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00440160 */
