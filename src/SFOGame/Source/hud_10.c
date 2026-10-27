/*
 * SFOGame/Source/hud: 1 file, 00242E40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00242E40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    void* vt; char pad04[0x18]; int w1C; signed char kind; char pad21[3]; signed char b24; char pad25[3];
    int id; float f0; float f1; char key[16]; int a3; signed char c0; signed char c1;
} Msg_242E40;
extern unsigned char g_IsMultiplayer;
extern char D_0051EE48[];
extern char D_004DE0F0[];
extern int nGlobalization_GetString_charP(char* key);
extern void cHud_SetCallout(int a0, int* a1, float f0, float f1, int text, int a3, signed char c0, signed char c1);
extern void cMessage_ctor_cMessageNameR(Msg_242E40* m, void* type);
extern char* strncpy(char*, const char*, int);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int a, Msg_242E40* m, int b, int c);
extern void cMessage_dtor(Msg_242E40* m, int f);

void cHud_SetCalloutLabel(int a0, int* a1, float f0, float f1, char* key, int a3, signed char c0, signed char c1, int send)
{
    int text = nGlobalization_GetString_charP(key);
    if (text) {
        cHud_SetCallout(a0, a1, f0, f1, text, a3, c0, c1);
        if (g_IsMultiplayer && send) {
            Msg_242E40 m;
            Msg_242E40* p = &m;
            cMessage_ctor_cMessageNameR(p, D_0051EE48);
            m.b24 = 0;
            m.vt = D_004DE0F0;
            m.id = *a1;
            m.f0 = f0;
            m.f1 = f1;
            m.a3 = a3;
            m.c0 = c0;
            m.c1 = c1;
            if (key) {
                strncpy(p->key, key, 16);
            }
            m.w1C = 0x40;
            m.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            m.vt = D_004DE0F0;
            cMessage_dtor(&m, 0);
        }
    }
}
static inline void merge_flush_func_00242E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00242E40 */
