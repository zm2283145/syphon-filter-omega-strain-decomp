/*
 * SFOGame/Source/backpack: 2 files, 002539B0-00253C60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002539B0 */
#pragma push /* merge_units */
#include "types.h"
extern unsigned char* D_005061D0;
static inline void W8_002539B0(int v) { *D_005061D0++ = v; }
static inline void W16_002539B0(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
typedef struct { int a[4]; int b[4]; int x; int n; } Sub_002539B0;
typedef struct { unsigned char id; char pad[3]; Sub_002539B0 s[5]; int count; unsigned char flag; char pad2[3]; } Ent_002539B0;
typedef struct { char pad[0x64]; Ent_002539B0 e[3]; int count; int b; int c; int d; char pad2f0; unsigned char f; } S_002539B0;
void cBackpack_Pack(S_002539B0* p) {
    int i; Ent_002539B0* e; int j; Sub_002539B0* s; int k;
    W8_002539B0(p->count);
    W8_002539B0(p->b);
    W16_002539B0(p->c);
    W16_002539B0(p->d);
    W8_002539B0(p->f);
    for (i = 0; i < p->count; i++) {
        e = &p->e[i];
        W8_002539B0(e->id);
        W8_002539B0(e->count);
        W8_002539B0(e->flag);
        for (j = 0; j < e->count; j++) {
            s = &e->s[j];
            W8_002539B0(s->x);
            W8_002539B0(s->n);
            for (k = 0; k < s->n; k++) {
                W16_002539B0(s->a[k]);
                W8_002539B0(s->b[k]);
            }
        }
    }
}
static inline void merge_flush_func_002539B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002539B0 */

/* merge_units: begin func_00253C60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack script natives and script type registration.
 */

#include "backpack_types.h"

extern int D_004F7EB8;
extern int D_004F7EF8;
extern int D_004F7F78;
extern int D_004F7F80;
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int cBackpack_StealPlayerWeapons(cBackpack* backpack, int a1, int a2, int a3);
extern int Backpack_RemoveAll_Thunk(void);
extern int cBackpack_RemoveAll(void);
extern int* cGOBJ_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int type, int msgType);
extern void cScriptBase_declareParent(int type, int baseType);

int Script_RemoveAllBackpacks(void) {
    Backpack_RemoveAll_Thunk();
    return 0;
}

int Backpack_RemoveAll_Thunk(void) {
    return cBackpack_RemoveAll();
}

/* Overloads with 3, 2 and 1 explicit arguments; missing ones default to 8. */
int Script_cBackpack_StealPlayerWeapons_3(BackpackScriptArg* args) {
    cBackpack_StealPlayerWeapons(args[0].p, args[1].u8, args[2].u8, args[3].u8);
    return 0;
}

int Script_cBackpack_StealPlayerWeapons_2(BackpackScriptArg* args) {
    cBackpack_StealPlayerWeapons(args[0].p, args[1].u8, args[2].u8, 8);
    return 0;
}

int Script_cBackpack_StealPlayerWeapons(BackpackScriptArg* args) {
    cBackpack_StealPlayerWeapons(args[0].p, args[1].u8, 8, 8);
    return 0;
}

int Script_cBackpack_SetAutoPickup(BackpackScriptArg* args) {
    ((cBackpack*)args[0].p)->autoPickup = (unsigned int)args[1].i != 0;
    return 0;
}

/* Registers cBackpack under its base type and the two message types it handles. */
int cBackpack_SOBJ_init(void) {
    int* base = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7F80, *base);
    cScriptBase_declareMsgUse(D_004F7F80, D_004F7EB8);
    return cScriptBase_declareMsgUse(D_004F7F80, D_004F7EF8);
}

int cBackpack_getSOBJClassId(void) {
    return D_004F7F78;
}

int cBackpack_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
static inline void merge_flush_func_00253C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00253C60 */
