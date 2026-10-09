/*
 * Matched functions (byte-identical with the retail executable).
 * cAI script-type registration.
 */

#include "types.h"

extern char D_004EE5D8[];
extern char D_004EE5E0[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int* func_0022F170(void);
extern int* func_0026ED30(void);
extern int* func_0026ED70(void);
extern int* func_0026EDF0(void);
extern int* func_0026EE30(void);
extern int* func_0026EEC0(void);
extern int* func_0026EF10(void);
extern int* func_0026EF50(void);
extern int* func_0026EF90(void);
extern int* func_0026F030(void);
extern int* func_0026F080(void);
extern int* func_0026F0B0(void);
extern int* func_0026F0F0(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);

/*
 * Registers the cAI script type under its parent, then registers each of the
 * message script types cAI accepts (one key getter per message type).
 */
int ScriptType_cAI_Init(void) {
    int* key;

    key = func_0022F170();
    func_003D9440(*(int*)D_004EE5E0, *key);
    key = func_0026F0F0();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026F0B0();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026F080();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026F030();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026EF90();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026EF50();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026EF10();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026EEC0();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026EE30();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026EDF0();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026ED70();
    func_003D9400(*(int*)D_004EE5E0, *key);
    key = func_0026ED30();
    return func_003D9400(*(int*)D_004EE5E0, *key);
}

/* Address of the cAI script-type key. */
int func_0016AD70(void) {
    return (int)D_004EE5D8;
}

int cAI_v0B(void) {
    return *(int*)D_004EE5D8;
}

int cAI_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
