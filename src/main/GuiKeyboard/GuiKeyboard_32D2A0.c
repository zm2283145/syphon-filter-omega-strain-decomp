/*
 * main/GuiKeyboard: 2 files, 0032D2A0-0032D5E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032D2A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; char padD[3]; } List0032D2A0;
typedef struct {
    void* vtable;
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x32];
    int unk48, unk4C, unk50, unk54, unk58, unk5C;
    List0032D2A0 list60;
    List0032D2A0 list70;
    List0032D2A0 list80;
    void* unk90;
    int unk94;
    int unk98;
    unsigned char unk9C;
    char pad9D[3];
    List0032D2A0 listA0;
    List0032D2A0 listB0;
    List0032D2A0 listC0;
    List0032D2A0 listD0;
    char padE0;
    unsigned char unkE1;
    char padE2[2];
    int unkE4;
} Widget0032D2A0;
extern char D_004DE790[];
extern void GuiWidget_ctor(Widget0032D2A0* w);
extern void func_0032D730(List0032D2A0* list);
extern void func_001C10A0(List0032D2A0* list);
extern unsigned char D_004926B8;
extern char D_00491580[], D_004917D0[], D_00491A20[], D_004925A0[], D_00491C70[], D_00491C90[];
extern char D_00491CC0[], D_00491CF0[], D_00491D20[], D_004925D0[], D_00491F70[], D_00491FB0[];
extern char D_00491FE0[], D_00492010[], D_00492260[], D_00492600[], D_004924B0[], D_004924D0[];
extern char D_00492500[], D_00492530[], D_00492570[];
extern void* D_0052AF60; extern int D_0052AF64;
extern void* D_0052AF70; extern int D_0052AF74;
extern void* D_0052AF80; extern int D_0052AF84; extern void* D_0052AF88; extern int D_0052AF8C;
extern void* D_0052AF90; extern int D_0052AF94;
extern void* D_0052AFA0; extern int D_0052AFA4; extern void* D_0052AFA8; extern int D_0052AFAC;
extern void* D_0052AFB0; extern int D_0052AFB4; extern void* D_0052AFB8; extern int D_0052AFBC;
extern void* D_004925A4; extern int D_004925A8;
extern void* D_004925B0; extern int D_004925B4;
extern void* D_004925BC; extern int D_004925C0;
extern void* D_004925C8; extern int D_004925CC;
extern void* D_004925D4; extern int D_004925D8;
extern void* D_004925E0; extern int D_004925E4;
extern void* D_004925EC; extern int D_004925F0;
extern void* D_00492604; extern int D_00492608;
extern void* D_00492610; extern int D_00492614;
extern void* D_0049261C; extern int D_00492620;
extern void* D_00492628; extern int D_0049262C;
extern void* D_00492634; extern int D_00492638;

Widget0032D2A0* GuiKeyboard_ctor(Widget0032D2A0* w)
{
    List0032D2A0 *l, *l2, *l3, *l4, *l5, *l6, *l7;
    GuiWidget_ctor(w);
    w->vtable = D_004DE790;
    l = &w->list60; func_0032D730(l); l->flag = 1;
    l2 = &w->list70; func_001C10A0(l2); l2->flag = 1;
    l3 = &w->list80; func_001C10A0(l3); l3->flag = 1;
    l4 = &w->listA0; func_001C10A0(l4); l4->flag = 1;
    l5 = &w->listB0; func_001C10A0(l5); l5->flag = 1;
    l6 = &w->listC0; func_001C10A0(l6); l6->flag = 1;
    l7 = &w->listD0; func_001C10A0(l7); l7->flag = 1;
    w->unk5C = 0;
    w->unkE4 = 0;
    w->unkE1 = 0;
    w->unk98 = 0;
    w->unk9C = 0;
    w->flags &= ~0x20;
    w->unk48 = 0;
    w->unk4C = 0;
    w->unk54 = 0;
    w->unk58 = 0;
    w->unk50 = 0;
    if (D_004926B8) {
        D_004926B8 = 0;
        D_0052AF60 = D_00491580; D_0052AF64 = 0x31;
        D_0052AF70 = D_004917D0; D_0052AF74 = 0x31;
        D_0052AF80 = D_00491A20; D_0052AF84 = 0x31;
        D_0052AF88 = D_004925A0; D_0052AF8C = 4;
        D_004925A4 = D_00491C70; D_004925A8 = 7;
        D_004925B0 = D_00491C90; D_004925B4 = 0xB;
        D_004925BC = D_00491CC0; D_004925C0 = 0xB;
        D_004925C8 = D_00491CF0; D_004925CC = 0xC;
        D_0052AFA0 = D_00491D20; D_0052AFA4 = 0x31;
        D_0052AFA8 = D_004925D0; D_0052AFAC = 3;
        D_004925D4 = D_00491F70; D_004925D8 = 0xD;
        D_004925E0 = D_00491FB0; D_004925E4 = 0xB;
        D_004925EC = D_00491FE0; D_004925F0 = 0xB;
        D_0052AF90 = D_00492010; D_0052AF94 = 0x31;
        D_0052AFB0 = D_00492260; D_0052AFB4 = 0x31;
        D_0052AFB8 = D_00492600; D_0052AFBC = 5;
        D_00492604 = D_004924B0; D_00492608 = 7;
        D_00492610 = D_004924D0; D_00492614 = 0xB;
        D_0049261C = D_00492500; D_00492620 = 0xB;
        D_00492628 = D_00492530; D_0049262C = 0xD;
        D_00492634 = D_00492570; D_00492638 = 0xC;
    }
    w->unk90 = 0;
    return w;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032D2A0 */

/* merge_units: begin func_0032D5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR2(func_0032D5E0, func_0032D640)
#pragma pop /* merge_units */
/* merge_units: end func_0032D5E0 */
