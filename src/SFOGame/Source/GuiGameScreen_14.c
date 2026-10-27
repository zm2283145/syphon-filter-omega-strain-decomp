/*
 * SFOGame/Source/GuiGameScreen: 1 file, 0045E930
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

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
void cMessage_ctor_cMessageNameR(Msg_E930* m, void* type);
void cNetObj_SendMessage_int_cMessageR_int_int(int to, Msg_E930* m, int a, int b);
void cMessage_dtor(Msg_E930* m, int flags);
void DisplayInteractLabel(char* text, unsigned char flag);
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
static inline void merge_flush_func_0045E930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045E930 */
