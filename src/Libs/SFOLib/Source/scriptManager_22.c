/*
 * Libs/SFOLib/Source/scriptManager: 3 files, 003E0A70-003E0AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E0A70 */
#pragma push /* merge_units */
#include "types.h"

typedef struct LevelInfo {
    char pad[0x8C];
    int level;
} LevelInfo;

typedef struct LevelOwner {
    char pad[0x20];
    LevelInfo* info;
} LevelOwner;

extern int ClassDef_isController(void* arg);

/* Returns ClassDef_isController(arg) as a byte when the owner's level is at least 8, else 0. */
int cScriptInterpreter_UseIdInsteadOfPointer(void* self, LevelOwner* owner, void* arg) {
    int result = 0;
    LevelInfo* info = owner->info;
    if (info && info->level > 7) {
        result = (unsigned char)ClassDef_isController(arg);
    }
    return result;
}
static inline void merge_flush_func_003E0A70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E0A70 */

/* merge_units: begin func_003E0AB0 */
#pragma push /* merge_units */
/* cScriptInterpreter_callFunction */
typedef struct { int type; } Pt2_ArgType;
typedef struct { char* name; char pad4[0xC]; Pt2_ArgType** argTypes; char pad14[4]; int script; int (*native)(int*, int); } Pt2_Handler;
typedef struct { char pad[0x4E68]; int cur; } Pt2_Interp;
extern char D_004BD510[];
extern void cScriptInterpreter_pushInt(Pt2_Interp*, int);
extern int cScriptInterpreter_execute(Pt2_Interp*, Pt2_Handler*);
extern void cScriptInterpreter_error(Pt2_Interp*, char*, int, char*);

#pragma opt_strength_reduction off
int cScriptInterpreter_callFunction(Pt2_Interp* in, Pt2_Handler* h, int* args, int n) {
    int i;
    int* a;
    if (h->script) {
        for (i = 0; i < n; i++) cScriptInterpreter_pushInt(in, args[n - i - 1]);
        in->cur = h->script;
        return cScriptInterpreter_execute(in, h);
    }
    i = 0;
    if (i < n) {
        a = args;
        do {
            if (h->argTypes[i]->type >= 100 && *a < 1000) {
                cScriptInterpreter_error(in, D_004BD510, i, h->name);
                return 0;
            }
            i++;
            a++;
        } while (i < n);
    }
    return h->native(args, n);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E0AB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E0AB0 */

/* merge_units: begin func_003E0BE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; unsigned char m3C; } T0BE0;
extern T0BE0* cScriptInterpreter_findCls(int a);
T0BE0* cScriptInterpreter_findScriptObj(int a)
{
    T0BE0* p = cScriptInterpreter_findCls(a);
    if (p && p->m3C)
        return p;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E0BE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E0BE0 */
