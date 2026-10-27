/*
 * main/SpecFxDefs: range (5 files, 00232810-00232B50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00232810 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad4[0x1C]; unsigned char type; char pad21[0xF]; } Msg00232730;
typedef struct { char pad[0x30]; void* target; } Net00232730;
extern char D_0053B5C0[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern Net00232730* g_LocalPlayer;
extern char D_004DCF10[];
extern void cWind_Set(void* a, float b, float c, float d, float e, float f);
extern void World_StartAtmosphereEffect_Thunk(int a, int b, float c, float d, float e, float f);
extern void cAtmosphericEffectMsg_ctor(Msg00232730* ev, int kind);
extern void QueueMessage_cMessageR_cSystemP_int(Msg00232730* ev, void* target, int flags);
extern void cMessage_dtor(Msg00232730* ev, int flags);
/* Script global: Lorelei rain effect. */
void Global_RainLorelei(void)
{
    cWind_Set(D_0053B5C0, 0.0f, 0.0f, 20.0f, 40.0f, 1.0f);
    World_StartAtmosphereEffect_Thunk(0x18, 0x1F4, 0.0f, 25.0f, 45.0f, 1.0f);
    if (g_IsMultiplayer && (g_IsMultiplayer ? D_005721C0 : 1)) {
        Msg00232730 ev;
        Net00232730* net = g_LocalPlayer;
        cAtmosphericEffectMsg_ctor(&ev, 2);
        ev.type = 4;
        QueueMessage_cMessageR_cSystemP_int(&ev, net->target, 0);
        ev.vtable = D_004DCF10;
        cMessage_dtor(&ev, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232810 */

/* merge_units: begin func_002328F0 */
#pragma push /* merge_units */
/* Script global: Tokyo rain effect. */
void Global_RainTokyo(void)
{
    cWind_Set(D_0053B5C0, 0.0f, 0.0f, 10.0f, 20.0f, 0.5f);
    World_StartAtmosphereEffect_Thunk(0x17, 0x12C, 0.0f, 25.0f, 45.0f, 1.0f);
    if (g_IsMultiplayer && (g_IsMultiplayer ? D_005721C0 : 1)) {
        Msg00232730 ev;
        Net00232730* net = g_LocalPlayer;
        cAtmosphericEffectMsg_ctor(&ev, 1);
        ev.type = 4;
        QueueMessage_cMessageR_cSystemP_int(&ev, net->target, 0);
        ev.vtable = D_004DCF10;
        cMessage_dtor(&ev, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002328F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002328F0 */

/* merge_units: begin func_002329D0 */
#pragma push /* merge_units */
/* Script global: Toronto smoke effect. */
void Global_SmokeToronto3(void)
{
    World_StartAtmosphereEffect_Thunk(0x15, -1, 20.0f, 0.0f, 40.0f, 0.4f);
    if (g_IsMultiplayer && (g_IsMultiplayer ? D_005721C0 : 1)) {
        Msg00232730 ev;
        Net00232730* net = g_LocalPlayer;
        cAtmosphericEffectMsg_ctor(&ev, 0);
        ev.type = 4;
        QueueMessage_cMessageR_cSystemP_int(&ev, net->target, 0);
        ev.vtable = D_004DCF10;
        cMessage_dtor(&ev, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002329D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002329D0 */

/* merge_units: begin func_00232A90 */
#pragma push /* merge_units */
/* Script global: Myanmar fog effect. */
void Global_FogMyanmar(void)
{
    World_StartAtmosphereEffect_Thunk(0x14, -1, 20.0f, 0.0f, 40.0f, 0.4f);
    if (g_IsMultiplayer && (g_IsMultiplayer ? D_005721C0 : 1)) {
        Msg00232730 ev;
        Net00232730* net = g_LocalPlayer;
        cAtmosphericEffectMsg_ctor(&ev, 4);
        ev.type = 4;
        QueueMessage_cMessageR_cSystemP_int(&ev, net->target, 0);
        ev.vtable = D_004DCF10;
        cMessage_dtor(&ev, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232A90 */

/* merge_units: begin func_00232B50 */
#pragma push /* merge_units */
extern void Global_SmokeToronto3(void);
extern void Global_RainTokyo(void);
extern void Global_RainLorelei(void);
extern void Global_SnowBelarus2(void);
extern void Global_FogMyanmar(void);
void SfxAtmosphericParticleEffect_eAtmosphericEffect(unsigned char weather)
{
    switch (weather) {
    case 0:
        Global_SmokeToronto3();
        break;
    case 1:
        Global_RainTokyo();
        break;
    case 2:
        Global_RainLorelei();
        break;
    case 3:
        Global_SnowBelarus2();
        break;
    case 4:
        Global_FogMyanmar();
        break;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232B50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232B50 */
