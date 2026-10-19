/*
 * main/gameSound: range (2 files, 001C6650-001C6700)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001C6650 */
#pragma push /* merge_units */
int Event_Send(void*, void*, int);
int SoundEvent_Ctor(void*, void*, int);
int SoundRequest_Ctor(void*, int, void*, int, int);
int cMessage_dtor(void*, int);
int FileMan_Release(void*, int);
extern char D_004DADF0[];
extern char g_Game[];
extern unsigned char func_001C6700(void);
typedef struct { int w[43]; } A2C4; typedef struct { int w[39]; } A228; typedef struct { int w[18]; } A1E0; typedef struct { int w[47]; } A124; typedef struct { int w[39]; } A88; typedef struct { void* vt; int w[29]; } A10;
/* stop all quips: broadcast a stop sound event; the message objects share one
 * stack block (4-byte aligned layout) */
#pragma push
#pragma opt_common_subs off
void Global_StopAllQuips(void) {
    struct { A10 sp10; A88 sp88; A124 sp124; A1E0 sp1E0; A228 sp228; A2C4 sp2C4; } L;
    if (&func_001C6700 != 0) {
        SoundRequest_Ctor(&L.sp1E0, 4, "", 0, 0);
        SoundEvent_Ctor(&L.sp10, &L.sp1E0, 0);
        Event_Send(&L.sp10, g_Game, 0);
        L.sp10.vt = D_004DADF0;
        FileMan_Release(&L.sp124, -1);
        FileMan_Release(&L.sp88, -1);
        cMessage_dtor(&L.sp10, 0);
        FileMan_Release(&L.sp2C4, -1);
        FileMan_Release(&L.sp228, -1);
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6650(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6650 */

/* merge_units: begin func_001C6700 */
#pragma push /* merge_units */
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
unsigned char func_001C6700(void) { if (g_IsMultiplayer) return D_005721C0; return 1; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6700 */
