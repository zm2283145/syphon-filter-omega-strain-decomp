/*
 * SFOGame/Source/Generator: 1 file, 0021C9A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021C9A0 */
#pragma push /* merge_units */
#pragma explicit_zero_data on
#include "types.h"
typedef struct { void* vtable; char pad04[0x1C]; char kind; char pad21[7]; char op; char pad29[3]; } Msg0021C9A0;
typedef struct { char pad[0xC0]; int pulse; } Gen0021C9A0;
extern unsigned char g_IsMultiplayer;
unsigned int D_004A4A78[2] = { 0x0, 0x0 };
extern char D_004DB5E0[];
extern void cMessage_ctor_cMessageNameR(Msg0021C9A0* m, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg0021C9A0* m, void* target, int a);
extern void cMessage_dtor(Msg0021C9A0* m, int flags);
int Script_cGenerator_ResetPulse(Gen0021C9A0** args)
{
    Gen0021C9A0* g = *args;
    g->pulse = 0;
    if (g_IsMultiplayer) {
        Msg0021C9A0 m;
        cMessage_ctor_cMessageNameR(&m, ((char*)D_004A4A78));
        m.vtable = D_004DB5E0;
        m.op = 2;
        m.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&m, g, 0);
        m.vtable = D_004DB5E0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
static inline void merge_flush_func_0021C9A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021C9A0 */
