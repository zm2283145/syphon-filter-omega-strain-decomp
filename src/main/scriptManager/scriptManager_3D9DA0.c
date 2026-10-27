/*
 * main/scriptManager: range (3 files, 003D9DA0-003DA010)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_003D9DA0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004BD4C0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
}

static inline void MemClear_3D9(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v1, n, 0xF
        or $a0, $a0, $v1
        nop
        bgtz $a0, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}

struct Arr_3D9DA0 { int* data; int count; };

#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void cScriptVars_extend(Arr_3D9DA0* a, int n)
{
    int* old = a->data;
    if (old) {
        AllocGuard g;
        cMemMan_Deallocate(0, old, D_004BD4C0, 0xD54);
    }
    a->count = n;
    if (n) {
        int* p;
        {
            AllocGuard g;
            p = (int*)cMemMan_Allocate(0, n * 4, D_004BD4C0, 0xD58);
        }
        a->data = p;
        MemClear_3D9(a->data, n * 4);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D9DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D9DA0 */

/* merge_units: begin func_003D9F40 */
#pragma push /* merge_units */
typedef struct { char pad[0x58]; void* m58; } O9F40;
typedef struct { char pad[0x4E50]; int count; void** groups; } T9F40;
extern int cGroup_Find_cSystemP(void* g, void* o);
extern void cGroup_Remove(void* g, void* o);
#pragma opt_strength_reduction off
void cScriptInterpreter_RemoveFromAllGroups(T9F40* self, O9F40* o)
{
    void* sub = o->m58;
    int i;
    for (i = 0; i < self->count; i++) {
        void* g = self->groups[i];
        if (cGroup_Find_cSystemP(g, o) != -1)
            cGroup_Remove(g, o);
        if (sub && cGroup_Find_cSystemP(g, sub) != -1)
            cGroup_Remove(g, sub);
    }
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D9F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D9F40 */

/* merge_units: begin func_003DA010 */
#pragma push /* merge_units */
typedef struct { int x0; int* args; char pad[0x44]; } SrvCtx;
typedef struct { char pad[0x14]; void* init; unsigned char pending; char pad19[3]; void* owner; } SrvVar;
typedef struct { int x0; int count; SrvVar** vars; } SrvScript;
extern char D_00555070[];
extern void FuncDef_ctor_charP_voidP_intP(SrvCtx*, void*, SrvScript*, void*);
extern void cScriptInterpreter_setInstructionPtr(void*, void*);
extern void cScriptInterpreter_execute(void*, SrvCtx*);
extern void FuncDef_dtor(SrvCtx*, int);
#pragma opt_strength_reduction off
void cScriptInterpreter_SymbolTable_executeInitCode(SrvScript* s)
{
    int n = s->count;
    int i;
    for (i = 0; i < n; i++) {
        SrvVar* v = s->vars[i];
        if (v && v->pending && v->owner == s) {
            void* init;
            init = v->init;
            v->pending = 0;
            if (init) {
                SrvCtx ctx;
                int arg[1];
                FuncDef_ctor_charP_voidP_intP(&ctx, "bogusfoobar", s, init);
                arg[0] = 4;
                ctx.args = arg;
                cScriptInterpreter_setInstructionPtr(D_00555070, init);
                cScriptInterpreter_execute(D_00555070, &ctx);
                FuncDef_dtor(&ctx, -1);
            }
        }
    }
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DA010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DA010 */
