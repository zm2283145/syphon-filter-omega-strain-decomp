/*
 * SFOGame/Source/GuiGameScreen: 6 files, 0045E8C0-0045EBC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045E8C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

DEFINE_VTABLE2_BASE_DTOR(cClearClientInteractMsg_dtor, D_004E16A0, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_0045E8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045E8C0 */

/* merge_units: begin func_0045E930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
struct Ctl_E930 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int isNet(); };
struct Ent_E930 { char pad[0xC]; unsigned int h; char pad10[0x48]; Ctl_E930* ctl; };
typedef struct { char* vt; char pad[0x18]; int f1C; signed char f20; char pad21[3]; int key; int flag; char pad2C[4]; } Msg_E930;
extern "C" {
extern char D_00586158[];
extern char D_004E1680[];
int nGlobalization_GetStringIndex(char* s);
extern char D_004DCF10[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Msg_E930* m, void* type);
#endif /* merge_units */
int cMessage_ctor_cMessageNameR(char**, char*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((char * *)(a0), (char *)(a1))) /* merge_units */

void cNetObj_SendMessage_int_cMessageR_int_int(int to, Msg_E930* m, int a, int b);
#if 0 /* merge_units */
void cMessage_dtor(Msg_E930* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
void DisplayInteractLabel(char* text, unsigned char flag);
#endif /* merge_units */
int DisplayInteractLabel(int, unsigned char); /* merge_units */
#define DisplayInteractLabel(a0, a1) ((void)DisplayInteractLabel((int)(a0), (a1))) /* merge_units */

}
static inline int OwnerOf_E930(Ent_E930* e)
{
    if (g_IsMultiplayer) {
        unsigned char ok = 0;
        Ctl_E930* c = e->ctl;
        if (c && c->isNet()) ok = 1;
        if (ok) return ((e->h & 0x7F000000) >> 24) - 1;
        return -1;
    }
    return 0;
}
static inline void Msg_Init_E930(Msg_E930* p, char* text, unsigned char flag)
{
    p->key = nGlobalization_GetStringIndex(text);
    p->flag = flag;
}
#pragma opt_propagation off
extern "C" void DisplayInteract_cGOBJP_charP_eJoystickButton(Ent_E930* e, char* text, unsigned char flag)
{
    Msg_E930 m;
    if (g_IsMultiplayer) {
        Msg_E930* p = &m;
        cMessage_ctor_cMessageNameR(p, D_00586158);
        m.vt = D_004E1680;
        Msg_Init_E930(p, text, flag);
        m.f1C = 0x40;
        if (!e) {
            m.f20 = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            DisplayInteractLabel(text, flag);
        } else {
            int own = OwnerOf_E930(e);
            if (own != NetLocalId()) cNetObj_SendMessage_int_cMessageR_int_int(0, &m, 0, own);
            else DisplayInteractLabel(text, flag);
        }
        m.vt = D_004DCF10;
        cMessage_dtor(&m, 0);
    } else {
        DisplayInteractLabel(text, flag);
    }
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef DisplayInteractLabel /* merge_units */
static inline void merge_flush_func_0045E930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045E930 */

/* merge_units: begin func_0045EB00 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cDisplayClientInteractMsg_dtor, D_004E1680, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_0045EB00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045EB00 */

/* merge_units: begin func_0045EB70 */
#pragma push /* merge_units */
typedef struct EventMsg {
    void* vtbl;
    char pad[0x2C];
} EventMsg;

extern char D_00586170[];
extern char D_004E16A0[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(EventMsg* msg, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((char * *)(a0), (char *)(a1))) /* merge_units */

extern void ClearInteract_void(void);
#if 0 /* merge_units */
extern void cMessage_dtor(EventMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


/* Constructs a temporary event message around a call to ClearInteract_void. */
void func_0045EB70(void) {
    EventMsg msg;
    cMessage_ctor_cMessageNameR(&msg, D_00586170);
    msg.vtbl = D_004E16A0;
    ClearInteract_void();
    msg.vtbl = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0045EB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045EB70 */

/* merge_units: begin func_0045EBC0 */
#pragma push /* merge_units */
#include "GuiGameScreen_types.h"

#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);                       
int cNetMsg_GetInt(int *);                            
#if 0 /* merge_units */
int cMessage_dtor(char **, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */
                           
int nGlobalization_GetStringTag(int);                             
int DisplayInteractLabel(int, unsigned char);                           
#if 0 /* merge_units */
extern char D_004DCF10;
#endif /* merge_units */
#define D_004DCF10 (*(char*)&D_004DCF10) /* merge_units */

#if 0 /* merge_units */
extern char D_004E1680;
#endif /* merge_units */
#define D_004E1680 (*(char*)&D_004E1680) /* merge_units */

#if 0 /* merge_units */
extern char D_00586158;
#endif /* merge_units */
#define D_00586158 (*(char*)&D_00586158) /* merge_units */


void func_0045EBC0(void) {
    struct { char * f30[9]; int f54; int f58[2]; } sl;
    int temp_a0;

    cMessage_ctor_cMessageNameR(sl.f30, &D_00586158);
    sl.f30[0] = &D_004E1680;
    cNetMsg_GetInt(&sl.f54);
    cNetMsg_GetInt(sl.f58);
    temp_a0 = sl.f54;
    if (temp_a0 != -1) {
        DisplayInteractLabel(nGlobalization_GetStringTag(temp_a0), sl.f58[0]);
    }
    sl.f30[0] = &D_004DCF10;
    cMessage_dtor(sl.f30, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045EBC0(void) {}
#undef cMessage_dtor /* merge_units */
#undef D_004DCF10 /* merge_units */
#undef D_004E1680 /* merge_units */
#undef D_00586158 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045EBC0 */

/* merge_units: begin func_0045EC60 */
#pragma push /* merge_units */
extern GameHudOwner* g_Hud;
extern void GuiGameScreen_ClearInteract(void* hud, int enable);

/* Enable the interaction prompt when both the owner and its HUD are present. */
void ClearInteract_void(void)
{
    if (g_Hud && g_Hud->hud)
        GuiGameScreen_ClearInteract(g_Hud->hud, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045EC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045EC60 */
