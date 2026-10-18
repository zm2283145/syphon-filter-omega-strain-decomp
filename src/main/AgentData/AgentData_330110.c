/*
 * main/AgentData: range (2 files, 00330110-00330180)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00330110 */
#pragma push /* merge_units */
typedef struct { void* buffer; int unk4; int index; int unkC; char pad[4]; int unk14; } Obj330;

extern void* D_004FFD30;
extern char* WeaponDb_Get(void* p);
extern void* Loc_FindKeyThunk(char* p);

/* Constructor: allocates the buffer and initializes the fields; returns self. */
Obj330* Awards_RegisterName(Obj330* self, int a, int b)
{
    self->buffer = Loc_FindKeyThunk(WeaponDb_Get(D_004FFD30) + 0x80);
    self->unk14 = a;
    self->unk4 = b;
    self->index = -1;
    self->unkC = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330110 */

/* merge_units: begin func_00330180 */
#pragma push /* merge_units */
typedef struct { int text; int unk4; int unk8; int unkC; int unk10; int unk14; } ObjectiveRow;
#if 0 /* merge_units */
extern int Loc_FindKeyThunk(const char* key);
#endif /* merge_units */
#define Loc_FindKeyThunk(a0) ((int)Loc_FindKeyThunk((void *)(a0))) /* merge_units */


/* Initialises an objective row: looks up the text key and stores the parameters. */
ObjectiveRow* ObjectiveRow_Construct(ObjectiveRow* row, const char* key, int a, int b)
{
    row->text = Loc_FindKeyThunk(key);
    row->unk14 = a;
    row->unk4 = b;
    row->unk8 = -1;
    row->unkC = 0;
    return row;
}
#undef Loc_FindKeyThunk /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330180 */
