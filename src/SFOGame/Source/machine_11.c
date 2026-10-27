/*
 * SFOGame/Source/machine: 3 files, 00169780-00169920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00169780 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Allocate(...);                        
int cFont_ctor(...);                             
int cSystemContainer_ctor_void(...);                                  
int cConsole_ctor(...);                     
int cDME_ctor(...);                            
extern char D_0049C390;
extern char D_004D97B0;
extern unsigned char g_ProfileLockEnabled;
extern char D_0055A700;
extern int g_FrameCounter;
}
extern "C" char * cMachine_ctor(char * arg0) {
    int var_s2;
    int var_s1;
    int var_s0;

    cSystemContainer_ctor_void();
    F_(arg0, 0x0, int) = (int)(&D_004D97B0);
    cConsole_ctor(arg0 + 0x2C, "1.0", &D_0055A700);
    cDME_ctor(arg0 + 0x279);
    F_(arg0, 0x268, int) = 0;
    F_(arg0, 0x264, int) = 0;
    var_s2 = 0;
    g_FrameCounter = 0;
    var_s0 = 0;
    F_(arg0, 0x270, int) = 0;
    F_(arg0, 0x274, int) = 0;
    F_(arg0, 0x27C, int) = 0;
    F_(arg0, 0x278, signed char) = 0;
    do {
        {
            AllocGuard g;
        var_s1 = cMemMan_Allocate(0, 0x8A80, &D_0049C390, 0x97);
        }
        if (var_s1 != 0) {
            var_s1 = cFont_ctor(var_s1);
        }
        F_((arg0 + var_s0), 0x280, int) = var_s1;
        var_s2 += 1;
        var_s0 += 4;
    } while (var_s2 < 3);
    return arg0;
}
static inline void merge_flush_func_00169780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169780 */

/* merge_units: begin func_001698C0 */
#pragma push /* merge_units */
extern signed char D_004EE1C0;
extern char D_004EE1C8[];
extern char D_004EE1E0[];
#if 0 /* merge_units */
void cMachine_ctor(void* p);
#endif /* merge_units */
#define cMachine_ctor(a0) ((void)cMachine_ctor((char *)(a0))) /* merge_units */

void cMachine_dtor(void* p, int flags);
void __register_global_object(void* obj, void* dtor, void* link);
void* GetMachine(void)
{
    if (!D_004EE1C0) {
        cMachine_ctor(D_004EE1E0);
        __register_global_object(D_004EE1E0, cMachine_dtor, D_004EE1C8);
        D_004EE1C0 = 1;
    }
    return D_004EE1E0;
}
#undef cMachine_ctor /* merge_units */
static inline void merge_flush_func_001698C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001698C0 */

/* merge_units: begin func_00169920 */
#pragma push /* merge_units */
typedef struct { char pad[0x250]; unsigned char state; } S_9920;
#if 0 /* merge_units */
extern S_9920* GetMachine(void);
#endif /* merge_units */
#define GetMachine() ((S_9920 *)GetMachine()) /* merge_units */

unsigned char func_00169920(void)
{
    unsigned char s = GetMachine()->state;
    unsigned char r = 1;
    if (s != 0 && s != 4)
        r = 0;
    return r;
}
#undef GetMachine /* merge_units */
static inline void merge_flush_func_00169920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169920 */
