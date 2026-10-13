/*
 * main/GobjMan: 5 files, 0040C1E0-0040C460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040C1E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc
 */

#include "types.h"
#include "GobjMan_types.h"

/* Address of the payload at +0x08. */
void* func_0040C1E0(GobjHolder* self) {
    return self->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C1E0 */

/* merge_units: begin Object_ToString */
#pragma push /* merge_units */
extern char D_00571B80[];
extern int sprintf(char* buf, const char* fmt, ...);

/* Formats the id's high byte (bits 16-23) and low half into a static buffer and returns it. */
char* Object_ToString(unsigned int* id)
{
    sprintf(D_00571B80, "(%d %d)", (*id & 0xFF0000) >> 16, *id & 0xFFFF);
    return D_00571B80;
}
#pragma pop /* merge_units */
/* merge_units: end Object_ToString */

/* merge_units: begin IdMgr_Allocate */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int IdMgr_FindCollision(int, int);                  
extern char D_00571780;

void IdMgr_Allocate(int *arg0, int arg1) {
    int temp_v0;
    int *temp_s2;
    int temp_s1;

    temp_s1 = arg1 & 0xFF;
    temp_s2 = &D_00571780 + (temp_s1 * 4);
    do {
        temp_v0 = *temp_s2 + 1;
        *temp_s2 = temp_v0;
        if (temp_v0 > 0xFFFF) {
            *temp_s2 = 0;
        }
    } while (IdMgr_FindCollision(temp_s1, *temp_s2) != 0);
    *arg0 = *temp_s2 | (temp_s1 << 0x10);
}
#pragma pop /* merge_units */
/* merge_units: end IdMgr_Allocate */

/* merge_units: begin IdMgr_Init */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct IdPool_n1 { int unk0; } IdPool_n1;
typedef struct IdSlot_n1 { int id; } IdSlot_n1;
extern "C" {
extern char D_004BECA8[];
extern IdPool_n1* D_00571740;
extern IdPool_n1* D_00571748;
#if 0 /* merge_units */
extern int D_00571780[256];
#endif /* merge_units */
#define D_00571780 ((int*)&D_00571780) /* merge_units */

void* Mem_Alloc(int, int, char*, int);
void func_0040BA10(IdPool_n1* self, int capacity, IdPool_n1* parent);
}
static inline void* AllocL_n1(int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}
extern "C" void IdMgr_Init(void)
{
    int i;
    IdPool_n1* p;
    p = (IdPool_n1*)AllocL_n1(0x24, D_004BECA8, 0xCF);
    if (p) {
        func_0040BA10(p, 0x1194, 0);
    }
    D_00571740 = p;
    p = (IdPool_n1*)AllocL_n1(0x24, D_004BECA8, 0xD0);
    if (p) {
        func_0040BA10(p, 0x9C4, D_00571740);
    }
    D_00571748 = p;
    for (i = 0; i < 256; i++) {
        ((IdSlot_n1*)D_00571780)[i].id = 0;
    }
}
#undef D_00571780 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end IdMgr_Init */

/* merge_units: begin Scope_GetParent */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: scope chain accessors used by the script object lookup.
 */


GobjScope* Scope_GetParent(GobjScope* self) {
    return self->parent;
}

GobjScope* Object_GetScope(GobjEntry* self) {
    return self->scope;
}
#pragma pop /* merge_units */
/* merge_units: end Scope_GetParent */
