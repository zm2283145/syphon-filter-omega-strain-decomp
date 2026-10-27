/*
 * main/scriptManager: range (2 files, 003E1A20-003E1AA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003E1A20 */
#pragma push /* merge_units */
extern unsigned char D_004938D0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cScriptInterpreter_CallFunction(void*, char*, int);
static inline int ok3E1(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
void cScriptInterpreter_StartLevel(void* s) {
    if (D_004938D0) {
        cScriptInterpreter_CallFunction(s, "init::ClientStartLevel", 0);
        if (!g_IsMultiplayer || ok3E1()) cScriptInterpreter_CallFunction(s, "init::StartLevel", 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1A20 */

/* merge_units: begin func_003E1AA0 */
#pragma push /* merge_units */
#pragma cplusplus on

class FiltObjE6 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int GetType();
};

typedef struct FiltScratchE6 { int w[16]; } FiltScratchE6;

#if 0 /* merge_units */
extern "C" unsigned char D_004938D0;
#endif /* merge_units */
#define D_004938D0 (*(unsigned char*)&D_004938D0) /* merge_units */

extern "C" unsigned char cScriptInterpreter_callEvent_cSystemP_cMessageP_charP_int_etc(void* filter, int type, int arg, FiltScratchE6* scratch, int mode, int pass);

/* Runs both filter passes for an object; true if either accepted it. */
extern "C" unsigned char cScriptInterpreter_CallEvent(void* filter, FiltObjE6* obj, int arg)
{
    unsigned char result = 0;
    if (D_004938D0) {
        FiltScratchE6 scratch;
        result = cScriptInterpreter_callEvent_cSystemP_cMessageP_charP_int_etc(filter, obj->GetType(), arg, &scratch, 2, 0);
        if (cScriptInterpreter_callEvent_cSystemP_cMessageP_charP_int_etc(filter, obj->GetType(), arg, &scratch, 2, 1)) {
            result = 1;
        }
    }
    return result;
}
#undef D_004938D0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1AA0 */
