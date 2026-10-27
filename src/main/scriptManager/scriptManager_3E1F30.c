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
extern void std_list_deleter_voidPtr_begin_void(int* out, void* list);
extern void std_list_SymbolTablePtr_generic_iterator_ctor(N1F30** out, int* in);
extern void std_list_SymbolTablePtr_end(int* out, void* list);
extern void cLListIterator_SymbolTablePtr_ctor(N1F30** out, int* in);
extern void cScriptInterpreter_SymbolTable_executeInitCode(void* s);
void cScriptInterpreter_ExecuteInitCode(T1F30* self)
{
    N1F30* e;
    N1F30* it;
    int t1;
    int t2;
    N1F30* n;
    std_list_deleter_voidPtr_begin_void(&t1, &self->list);
    std_list_SymbolTablePtr_generic_iterator_ctor(&it, &t1);
    for (n = it; std_list_SymbolTablePtr_end(&t2, &self->list), cLListIterator_SymbolTablePtr_ctor(&e, &t2), n != e; n = n->next)
        cScriptInterpreter_SymbolTable_executeInitCode(n->data);
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
int cScriptInterpreter_CallFunction();         
int cScriptInterpreter_LoadScript();                   
int cScriptInterpreter_CheckAllReferences(int );  
#if 0 /* merge_units */
int cScriptInterpreter_ExecuteInitCode(int );
#endif /* merge_units */
#define cScriptInterpreter_ExecuteInitCode(a0) (cScriptInterpreter_ExecuteInitCode((void *)(a0))) /* merge_units */
       
int cScriptBase_sm_printf();                               
int cScriptBase_SetGameSymsAdded();                                  
extern unsigned char D_004938D0;

int cScriptInterpreter_ExecClientScripts(int arg0) {
    int var_s0;

    var_s0 = 0;
    if ((D_004938D0 != 0) && (cScriptInterpreter_LoadScript(arg0, ((int*)"client"), 1) != 0)) {
        cScriptInterpreter_ExecuteInitCode(arg0);
        var_s0 = cScriptInterpreter_CallFunction(arg0, ((int*)"client::Init"), 0) != 0;
        if (var_s0 == 0) {
            cScriptBase_sm_printf(((int*)"script client::Init() failed"));
        } else {
            var_s0 = cScriptInterpreter_CheckAllReferences(arg0) & 0xFF;
            if (var_s0 == 0) {
                cScriptBase_sm_printf(((int*)"client init reference check failed..."));
            }
        }
        cScriptBase_SetGameSymsAdded();
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
