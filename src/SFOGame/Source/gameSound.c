/*
 * SFOGame/Source/gameSound: 5 files, 001C61A0-001C63B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C61A0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vt8_chain_dtor.h"
#pragma pop

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
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_1C6200* m, void* type);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern int nGlobalization_GetStringIndex(char* s);
#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int a, Msg_1C6200* m, int b, int c);
#endif /* merge_units */
void cNetObj_SendMessage_int_cMessageR_int_int(int, void*, int, int); /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) (cNetObj_SendMessage_int_cMessageR_int_int((a0), (void *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_1C6200* m, int f);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

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
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C6200 */

/* merge_units: begin func_001C6350 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"
DEFINE_VTABLE_BASE_DTOR(cNetLabelMsg_dtor, D_004DE280, cMessage_dtor)
static inline void merge_flush_func_001C6350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C6350 */

/* merge_units: begin func_001C63B0 */
#pragma push /* merge_units */
typedef union { int i; char* s; } ScriptArg_1C63B0;
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; } Msg_1C63B0;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_1C63B0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int a, Msg_1C63B0* m, int b, int c);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) (cNetObj_SendMessage_int_cMessageR_int_int((a0), (void *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_1C63B0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

/* script: add a PDA quip (name, text) and broadcast it when networked */
int Script_AddPDAQuip_2(ScriptArg_1C63B0* args)
{
    char* b[1];
    char* a[1];
    char* text;
    char* name;
    b[0] = args[1].s;
    a[0] = args[0].s;
    name = *(char**)a;
    text = *(char**)b;
    if (name) {
        text = (!text || !*text) ? D_0049F490 : text;
        cHud_AddPDAQuip(g_Hud, name, text);
        {
            void* hud = g_Hud;
            cHud_Message(hud, nGlobalization_GetString_charP(D_0049F490));
        }
        if (g_IsMultiplayer) {
            Msg_1C63B0 m;
            Msg_1C63B0* p = &m;
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
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C63B0(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C63B0 */

/* merge_units: begin func_001C6500 */
#pragma push /* merge_units */
/* retail keeps the dead skeleton of (t && *t) ? t : D with t propagated to $zero: opt_dead_code off */

/* script: add a PDA quip (name, text) and broadcast it when networked */
#pragma opt_dead_code off
int Script_AddPDAQuip(ScriptArg_1C63B0* args)
{
    char* a[1];
    char* text;
    char* name;
    a[0] = args[0].s;
    name = *(char**)a;
    if (name) {
        { char* t0 = 0; text = (t0 && *t0) ? t0 : D_0049F490; }
        cHud_AddPDAQuip(g_Hud, name, text);
        {
            void* hud = g_Hud;
            cHud_Message(hud, nGlobalization_GetString_charP(D_0049F490));
        }
        if (g_IsMultiplayer) {
            Msg_1C63B0 m;
            Msg_1C63B0* p = &m;
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
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6500 */
