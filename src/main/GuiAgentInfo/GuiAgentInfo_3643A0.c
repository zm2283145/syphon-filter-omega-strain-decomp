/*
 * main/GuiAgentInfo: range (3 files, 003643A0-00364590)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "vc_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
void *memset(void *, int, int);

/* merge_units: begin func_003643A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
char * Mem_Alloc(...);                      
int Object_AttachTransform(...);           
int cGOBJ_ctor(...);              
char * DisplayActor_Construct(...);                 
int GuiWidget_Init(...);                                  
extern char D_004BBA20;
extern char D_004DA470;
extern unsigned char D_00533880;
extern char D_0055C9F0;
}
#pragma push
#pragma opt_common_subs off
extern "C" void GuiAgentDisplay_Init(char * arg0) {
        int x4C[1];
    char * temp_s1;
    char * var_s1;

    GuiWidget_Init();
    {
        AllocGuard g;
    temp_s1 = (char *)(Mem_Alloc(0, 0x68, &D_004BBA20, 0x49));
    }
    if (temp_s1 != NULL) {
        int x44[1]; int x40[1]; x40[0] = 0;
        x44[0] = 0;
        cGOBJ_ctor(temp_s1, x44, 9, x40);
        F_(temp_s1, 0x0, int) = (int)(&D_004DA470);
        F_(temp_s1, 0x60, int) = 0;
        F_(temp_s1, 0x64, int) = 0;
        Object_AttachTransform(temp_s1, &D_0055C9F0, 0);
        F_(temp_s1, 0x30, int) = 0;
    }
    F_(arg0, 0x90, int) = (int)(temp_s1);
    {
        AllocGuard g;
    var_s1 = (char *)(Mem_Alloc(0, 0x3030, &D_004BBA20, 0x4C));
    }
    if (var_s1 != NULL) {
        x4C[0] = 0;
        var_s1 = (char *)(DisplayActor_Construct(var_s1, x4C));
    }
    F_(arg0, 0x48, int) = (int)(var_s1);
    memset(arg0 + 0xA0, 0, 0x440);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003643A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003643A0 */

/* merge_units: begin func_00364540 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00364540)
#pragma pop /* merge_units */
/* merge_units: end func_00364540 */

/* merge_units: begin func_00364590 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V3 { float x, y, z; V3() {} V3(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
struct S364590 { void* vtable; char pad4[0x44]; int unk48; char pad4C[0x34]; V3 v80; char pad90[0x4E0 - 0x90]; float f4E0; };
extern "C" char D_004DF530[];
extern "C" void GuiWidget_ctor(S364590* self);
extern "C" S364590* GuiAgentDisplay_ctor(S364590* self) {
    V3 t;
    float z;
    GuiWidget_ctor(self);
    self->vtable = D_004DF530;
    t.x = 0.0f; t.y = 0.0f; t.z = 3.1415927f;
    VCopyF(&self->v80, &t);
    z = 0.0f;
    self->unk48 = 0;
    self->f4E0 = z;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364590 */
