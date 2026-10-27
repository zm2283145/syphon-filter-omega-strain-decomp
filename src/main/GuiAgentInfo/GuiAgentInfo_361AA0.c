/*
 * main/GuiAgentInfo: 2 files, 00361AA0-00361D90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00361AA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct W_361AA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x5C - 0x16];
    int f5C;
};
typedef struct {
    char pad[0x100]; W_361AA0* f100; W_361AA0* f104; W_361AA0* f108; W_361AA0* f10C; W_361AA0* f110;
    W_361AA0* f114; W_361AA0* f118; W_361AA0* f11C; W_361AA0* f120;
} O_361AA0;
extern "C" {
extern char D_004BB978[]; extern char D_004BB988[]; extern char D_004BB998[]; extern char D_004BB9A8[];
extern char D_004BB9B8[]; extern char D_004BB9C8[];extern char D_004A7520[]; extern char D_004ABAB0[]; extern char D_004A9870[]; extern char D_004B88F0[]; extern char D_004BBBB0[];
extern void* D_004FFC04;
void GuiLobbyScreen_onAdd(O_361AA0* o);
W_361AA0* GuiWidget_FindChild_charP(void* o, char* name);
void func_0041C0D0(W_361AA0* w, int v);
void GuiArrayWidget_SetRowHeight(W_361AA0* w, int v);
void FrontEnd_GetCharacterData(void* p);
void GuiAgentInfo_onAdd(O_361AA0* o);
}
static inline W_361AA0* Cast_361AA0(W_361AA0* w, void* t) { return w && w->IsA(t) ? w : 0; }

void GuiAgentInfo_onAdd(O_361AA0* o)
{
    GuiLobbyScreen_onAdd(o);
    o->f100 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB978), D_004A7520);
    o->f104 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB988), D_004A7520);
    o->f108 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB998), D_004A7520);
    if (o->f108) func_0041C0D0(o->f108, 1);
    o->f10C = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB9A8), D_004ABAB0);
    o->f110 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB9B8), D_004ABAB0);
    o->f114 = Cast_361AA0(GuiWidget_FindChild_charP(o, D_004BB9C8), D_004A9870);
    o->f118 = Cast_361AA0(GuiWidget_FindChild_charP(o, "02"), D_004A9870);
    o->f11C = Cast_361AA0(GuiWidget_FindChild_charP(o, "thumbnail"), D_004B88F0);
    o->f120 = Cast_361AA0(GuiWidget_FindChild_charP(o, "playercharacter"), D_004BBBB0);
    o->f10C->flags &= ~0x80;
    o->f110->flags &= ~0x80;
    GuiArrayWidget_SetRowHeight(o->f110, o->f110->f5C - 2);
    GuiArrayWidget_SetRowHeight(o->f10C, o->f10C->f5C - 4);
    FrontEnd_GetCharacterData(D_004FFC04);
}
#pragma pop /* merge_units */
/* merge_units: end func_00361AA0 */

/* merge_units: begin func_00361D90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo constructor (vtable GuiAgentInfo_vtable); derives from the screen base
 * built by GuiLobbyScreen_ctor (GuiLobbyScreen.cc range).
 */

#include "loose03_types.h"

extern char GuiAgentInfo_vtable[];       /* GuiAgentInfo vtable */
extern int cString_ctor_void(void*);
extern int GuiLobbyScreen_ctor(GuiAgentInfo*);

/* GuiAgentInfo constructor. */
GuiAgentInfo* GuiAgentInfo_ctor(GuiAgentInfo* self) {
    GuiAgentInfoMember88* member;

    GuiLobbyScreen_ctor(self);
    member = &self->unk88;
    self->base.vtable = GuiAgentInfo_vtable;
    cString_ctor_void(member->unk30);
    cString_ctor_void(member->unk3C);
    self->base.screenId = 8;
    self->unkFC = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00361D90 */
