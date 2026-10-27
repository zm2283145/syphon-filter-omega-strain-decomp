/*
 * SFOGame/Source/hud: 2 files, 00241AC0-00241B70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00241AC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct S20 { char pad[0x14]; unsigned short f14; };
struct Mgr { char pad[0x20]; S20* p20; };
extern "C" {
extern void* D_004FFC04;
int cGameFrontEnd_IsMessageBoxAwake_void_2(void*);
Mgr* Gui_Canvas(void);
}
/* Going through an inline wrapper keeps the bool locals from being folded. */
static inline Mgr* M() { return Gui_Canvas(); }
extern "C" bool Hud_IsGuiFocused(void)
{
    bool r = 1;
    if (!cGameFrontEnd_IsMessageBoxAwake_void_2(D_004FFC04)) {
        bool b = 0;
        bool a = 0;
        if (M() && M()->p20) a = 1;
        if (a) { if (M()->p20->f14 & 0x80) b = 1; }
        if (!b) r = 0;
    }
    return r;
}
static inline void merge_flush_func_00241AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00241AC0 */

/* merge_units: begin func_00241B70 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cFileMan_EncodeFilename_charP_cHogFileR_bool(char *, char *, int, int);                     
int cMemMan_Allocate(int, int, char *, int);                        
int cFileMan_dtor(char *, int);                            
int cFileMan_ctor_void(char *);                               
int cInterface_ctor(int, char *);                        
int sprintf(char *, char *, int);                           
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

int LoadInterface_charP_cHogFileR(int arg0, int arg1) {
    int spD0[12];
    int sp30[40];
    int var_s0;

    cFileMan_ctor_void(sp30);
    sprintf(spD0, "%s.IE", arg0);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(sp30, spD0, arg1, 0);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    var_s0 = cMemMan_Allocate(0, 8, "hud.cc", 0x704);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (var_s0 != 0) {
        var_s0 = cInterface_ctor(var_s0, sp30);
    }
    cFileMan_dtor(sp30, -1);
    return var_s0;
}
static inline void merge_flush_func_00241B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00241B70 */
