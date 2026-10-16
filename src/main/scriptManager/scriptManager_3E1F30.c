/*
 * main/scriptManager: range (2 files, 003E1F30-003E1FD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003E1F30 */
#pragma push /* merge_units */
typedef struct N1F30 { int m0; struct N1F30* next; void* data; } N1F30;
typedef struct { char pad[0xC]; int list; } T1F30;
extern void List_Begin(int* out, void* list);
extern void func_003E13D0(N1F30** out, int* in);
extern void func_003E13C0(int* out, void* list);
extern void func_003E13B0(N1F30** out, int* in);
extern void Script_RunVarInitializers(void* s);
void cScriptInterpreter_ExecuteInitCode(T1F30* self)
{
    N1F30* e;
    N1F30* it;
    int t1;
    int t2;
    N1F30* n;
    List_Begin(&t1, &self->list);
    func_003E13D0(&it, &t1);
    for (n = it; func_003E13C0(&t2, &self->list), func_003E13B0(&e, &t2), n != e; n = n->next)
        Script_RunVarInitializers(n->data);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1F30 */

/* merge_units: begin func_003E1FD0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int ScriptMgr_CallFunction();         
int ScriptMgr_LoadScript();                   
int cScriptInterpreter_CheckAllReferences(int );  
#if 0 /* merge_units */
int cScriptInterpreter_ExecuteInitCode(int );
#endif /* merge_units */
#define cScriptInterpreter_ExecuteInitCode(a0) (cScriptInterpreter_ExecuteInitCode((void *)(a0))) /* merge_units */
       
int Script_PrintWarning();                               
int func_003D7E30();                                  
extern unsigned char D_004938D0;

int ScriptMgr_InitClient(int arg0) {
    int var_s0;

    var_s0 = 0;
    if ((D_004938D0 != 0) && (ScriptMgr_LoadScript(arg0, ((int*)"client"), 1) != 0)) {
        cScriptInterpreter_ExecuteInitCode(arg0);
        var_s0 = ScriptMgr_CallFunction(arg0, ((int*)"client::Init"), 0) != 0;
        if (var_s0 == 0) {
            Script_PrintWarning(((int*)"script client::Init() failed"));
        } else {
            var_s0 = cScriptInterpreter_CheckAllReferences(arg0) & 0xFF;
            if (var_s0 == 0) {
                Script_PrintWarning(((int*)"client init reference check failed..."));
            }
        }
        func_003D7E30();
        F_(arg0, 0x4E60, int) = F_(arg0, 0xC, int);
        F_(arg0, 0x4E64, int) = F_(arg0, 0x28, int);
    }
    return var_s0;
}
#undef cScriptInterpreter_ExecuteInitCode /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1FD0 */
