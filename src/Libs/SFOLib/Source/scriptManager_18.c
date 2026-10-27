/*
 * Libs/SFOLib/Source/scriptManager: 4 files, 003DFDA0-003E0040
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003DFDA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(12)
#pragma opt_strength_reduction off
struct Param { int kind; };
struct Desc { char pad[0x10];Param**p; };
struct Ev { int x0,x4;void*vtable;char*args;int count;Desc*desc; };
extern "C" {
extern char D_004BD4C0[],D_004D9DE0[],D_004E00C0[];
void cMemMan_Deallocate(int,void*,char*,int);void operator_delete(void*);
}
static inline void Free(void*p,int line){AllocGuard g;cMemMan_Deallocate(0,p,D_004BD4C0,line);}
extern "C" Ev* SchedCallback_dtor(Ev*self,short flag){
 if(self){
 self->vtable=D_004E00C0;
 int i=0,off;
 if(0<self->count){off=0;do {
 if(self->desc->p[i]->kind==3){void*p=*(void**)(self->args+off);Free(p,0x6df);}
 ++i;off+=4;
 }while(i<self->count);}
 void*p=self->args;if(p)Free(p,0x6e3);
 if(self)self->vtable=D_004D9DE0;
 if(flag>0)operator_delete(self);
 }
 return self;
}
static inline void merge_flush_func_003DFDA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DFDA0 */

/* merge_units: begin func_003DFF80 */
#pragma push /* merge_units */
#include "scriptManager_types.h"

/* Script native placeholder for invalid argument lists; does nothing. */
void cScriptInterpreter_error(int a, int b, ...)
{
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFF80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFF80 */

/* merge_units: begin func_003DFFB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script evaluation stack (ScriptManager+0x4E70, grows downwards).
 */


extern void cScriptInterpreter_pushInt(ScriptManager* self, int value);
extern int cScriptInterpreter_popInt(ScriptManager* self);

/* Pops a float. volatile mirrors the original stack temporary. */
float cScriptInterpreter_popFloat(ScriptManager* self) {
    volatile int bits = cScriptInterpreter_popInt(self);
    return *(float*)&bits;
}

/* Pops an int word. */
int cScriptInterpreter_popInt(ScriptManager* self) {
    return *self->sp++;
}

/* Pushes a float. volatile mirrors the original stack temporary. */
void cScriptInterpreter_pushFloat(ScriptManager* self, float value) {
    volatile float bits = value;
    cScriptInterpreter_pushInt(self, *(int*)&bits);
}

void cScriptInterpreter_pushInt(ScriptManager* self, int value) {
    self->sp = self->sp - 1;
    *self->sp = value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFFB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFFB0 */

/* merge_units: begin func_003E0040 */
#pragma push /* merge_units */
typedef struct EnumMember3E0 { int value; char* name; int unk8; } EnumMember3E0;
typedef struct Enum3E0 { char pad00[0x8]; int count; EnumMember3E0* members; } Enum3E0;
typedef struct Vec3E0 { int pad0; int count; Enum3E0** data; } Vec3E0;
extern Vec3E0* D_00554F30;
#pragma opt_strength_reduction off
char* cScriptInterpreter_getEnumValString(void* script, int id, int value)
{
    Enum3E0* e;
    int i;
    int n;
    if (id < 10) return "ERROR: invalid enum Id";
    i = id - 10;
    e = D_00554F30->data[i];
    n = e->count;
    i = 0;
    if (i < n) do {
        if (value == e->members[i].value) return (*(EnumMember3E0* volatile*)&e->members)[i].name;
        i++;
    } while (i < n);
    return "ERROR: invalid value";
}
static inline void merge_flush_func_003E0040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E0040 */
