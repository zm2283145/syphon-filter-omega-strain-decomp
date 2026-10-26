/*
 * main/gobj: 3 files, 003D1770-003D18F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D1770 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned char m0; unsigned char m1; unsigned char m2; char pad3; char f4[4]; char info[8]; unsigned char m10; } T1770;
extern int sceUsbKbInit(void* p);
extern int sceUsbKbGetInfo(void* info);
extern int sceUsbKbSetLEDStatus(int no, int s);
extern int sceUsbKbSetLEDMode(int no, int m);
extern int sceUsbKbSync(int mode, int* result);
extern int sceUsbKbSetRepeat(int i, int a, int b);
extern int sceUsbKbClearRbuf(int i);
extern int sceUsbKbSetCodeType(int i, unsigned int v);
extern int sceUsbKbSetArrangement(int a, int b);
extern int sceUsbKbSetReadMode(int a, int b);
void cUSBKeybd_Init(T1770* kb)
{
    int r;
    int i = kb->m0 ? 49999 : 0;
    if (!kb->m0) {
        r = sceUsbKbInit(kb->f4);
        if (r == 0)
            kb->m0 = 1;
        else
            kb->m0 = 0;
    }
    do {
        r = sceUsbKbGetInfo(kb->info);
        sceUsbKbSync(0, &r);
    } while (!kb->m10 && ++i < 50000);
    if (kb->m10 && i < 50000) {
        r = sceUsbKbSetLEDStatus(0, 1);
        sceUsbKbSync(0, &r);
        r = sceUsbKbSetLEDMode(0, 1);
        sceUsbKbSync(0, &r);
        sceUsbKbSetRepeat(0, 30, 2);
        sceUsbKbClearRbuf(0);
        if (kb->m2 == 1)
            sceUsbKbSetCodeType(0, 0);
        else
            sceUsbKbSetCodeType(0, 1);
        sceUsbKbSetArrangement(0, 0);
        sceUsbKbSetReadMode(0, 0);
        kb->m1 = 1;
    } else {
        kb->m1 = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1770 */

/* merge_units: begin func_003D18D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

L4Bytes3* cUSBKeybd_ctor(L4Bytes3* self) {
    self->unk00 = 0;
    self->unk01 = 0;
    self->unk02 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D18D0 */

/* merge_units: begin func_003D18F0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
extern "C" void cCellAnimTexture_Reset();
extern "C" void TexFrameAnim_Update();
extern void * const D_004E0060[];
extern const unsigned int D_004E0080[];
struct VC_003D18F0 { char pad[0x10]; void* vtable; };
extern "C" VC_003D18F0* TexFrameAnim_dtor(VC_003D18F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0060);
        if (self)
            self->vtable = ((char*)D_004E0080);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0060[8] = { (void*)0x0, (void*)0x0, (void*)TexFrameAnim_Update, (void*)cCellAnimTexture_Reset, (void*)TexFrameAnim_dtor, (void*)0x0, (void*)0x0, (void*)0x0 };
const unsigned int D_004E0080[4] = { 0x0, 0x0, 0x0, 0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_003D18F0 */
