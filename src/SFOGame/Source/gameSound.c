/*
 * main/gameSound: range (2 files, 001C61A0-001C6200)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vt8_chain_dtor.h"
#pragma pop

/* merge_units: begin func_001C61A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern "C" void cCBData_IsReferencing();
extern "C" void cPauseMusicCB_Call();
extern void * const D_004DAC30[];
extern char D_004D9DE0[];
}
extern "C" Vt8Object* func_001C61A0(Vt8Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAC30);
        if (self)
            self->vtable = D_004D9DE0;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAC30[8] = { (void*)0x0, (void*)0x0, (void*)func_001C61A0, (void*)cCBData_IsReferencing, (void*)cPauseMusicCB_Call, (void*)0x0, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C61A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C61A0 */

/* merge_units: begin func_001C6200 */
#pragma push /* merge_units */
#define AND &&
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; } Msg_1C6200;
extern unsigned char g_IsMultiplayer;
extern void* g_Hud;
extern char D_0049F490[];
extern char D_0051F098[];
extern char D_004DE280[];
extern void cHud_AddPDAQuip(void* hud, char* a, char* b);
extern void* nGlobalization_GetString_charP(char* key);
extern void cHud_Message(void* hud, void* text);
extern void cMessage_ctor_cMessageNameR(Msg_1C6200* m, void* type);
extern int nGlobalization_GetStringIndex(char* s);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int a, Msg_1C6200* m, int b, int c);
extern void cMessage_dtor(Msg_1C6200* m, int f);
/* add a PDA quip (name, text); broadcast it unless silent */

#pragma opt_propagation off
void nGameSound_AddPDAQuip(char* name, char* text0, int silent)
{
    
    if (name) {
        char* text = (!text0 || !*text0) ? D_0049F490 : text0;
        cHud_AddPDAQuip(g_Hud, name, text);
        {
            void* hud = g_Hud;
            cHud_Message(hud, nGlobalization_GetString_charP(D_0049F490));
        }
        if (!silent AND g_IsMultiplayer) {
            Msg_1C6200 m;
            Msg_1C6200* p = &m;
            cMessage_ctor_cMessageNameR(p, D_0051F098);
            m.w24 = 0;
            m.vt = D_004DE280;
            m.b28 = 2;
            p->key0 = name ? nGlobalization_GetStringIndex(name) : -1;
            p->key1 = text ? nGlobalization_GetStringIndex(text) : -1;
            m.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6200 */
