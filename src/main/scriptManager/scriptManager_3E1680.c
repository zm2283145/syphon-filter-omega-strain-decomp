/*
 * main/scriptManager: range (3 files, 003E1680-003E18A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003E1680 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_Load(int, int, int);                       
int Script_PrintWarning(char *, int);                          
int ScriptMgr_BuildScriptPath(char *, int, char *, int);                          
int cScriptInterpreter_findContext(char * , int);                     

int ScriptMgr_ReloadScript(char * arg0, int arg1) {
    int temp_v0;
    int temp_v0_2;
    int var_s0;

    temp_v0 = ScriptMgr_BuildScriptPath(arg0, arg1, "so", 0);
    Script_PrintWarning("reloading %s...", temp_v0);
    var_s0 = 0;
    temp_v0_2 = cScriptInterpreter_findContext(arg0, temp_v0);
    if (temp_v0_2 != 0) {
        var_s0 = Script_Load(temp_v0_2, F_(arg0, 0x4E90, int), 0) & 0xFF;
    }
    if (var_s0 != 0) {
        F_(arg0, 0x4EA0, int) = (int) (F_(arg0, 0x4EA0, int) + 1);
    }
    return var_s0 & 0xFF;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1680 */

/* merge_units: begin func_003E1720 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                      
#if 0 /* merge_units */
int Script_Load(char * , int, int);
#endif /* merge_units */
#define Script_Load(a0, a1, a2) (Script_Load((int)(a0), (a1), (a2))) /* merge_units */
                  
int cArray_charPtr_ctor(char * );                            
int cArray_intPtr_ctor(char * );                          
int cArray_int_ctor(char * );               
int cScriptInterpreter_findContext();                                
int std_list_SymbolTablePtr_push_back(char * , void **);                   
int cArray_SubScriptPtr_ctor(char * );                            
int cArray_FuncDefPtr_ctor(char * );                            
int cArray_VarDefPtr_ctor(char * );                            
extern char D_004BD4C0;
extern char D_004BD890;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

int ScriptMgr_LoadScript(char * arg0, int arg1, int arg2) {
    char * sp5C;
    int temp_s0;
    unsigned char var_s2;
    char * temp_s2;

    var_s2 = 1;
    if (cScriptInterpreter_findContext() == 0) {
        temp_s0 = ScriptMgr_BuildScriptPath(arg0, arg1, &D_004BD890, arg2);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s2 = Mem_Alloc(0, 0x90, &D_004BD4C0, 0x144);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s2 != NULL) {
            cArray_VarDefPtr_ctor(temp_s2);
            cArray_FuncDefPtr_ctor(temp_s2 + 0x10);
            cArray_intPtr_ctor(temp_s2 + 0x20);
            cArray_int_ctor(temp_s2 + 0x30);
            cArray_int_ctor(temp_s2 + 0x40);
            cArray_SubScriptPtr_ctor(temp_s2 + 0x50);
            cArray_charPtr_ctor(temp_s2 + 0x60);
            cArray_charPtr_ctor(temp_s2 + 0x70);
            F_(temp_s2, 0x88, int) = 0;
            F_(temp_s2, 0x84, int) = 0;
        }
        sp5C = temp_s2;
        var_s2 = Script_Load(temp_s2, F_(arg0, 0x4E90, int), temp_s0);
        std_list_SymbolTablePtr_push_back(arg0 + 0xC, &sp5C);
        if (var_s2) Script_PrintWarning("loaded %s...", temp_s0); else Script_PrintWarning("couldn't load script %s...", temp_s0);
    }
    return var_s2;
}
#undef Script_Load /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1720(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1720 */

/* merge_units: begin func_003E18A0 */
#pragma push /* merge_units */
extern void std_vector_imp_FuncDefPtr_1_dtor(void* self, short del);
extern void operator_delete(void* p);
void* cArray_FuncDefPtr_dtor(void* self, short del)
{
    if (self) {
        if (self)
            std_vector_imp_FuncDefPtr_1_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E18A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E18A0 */
