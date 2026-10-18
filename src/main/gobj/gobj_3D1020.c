/*
 * main/gobj: 2 files, 003D1020-003D10B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D1020 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int f0; char f4[0xC]; char f10[0xC]; unsigned char b1C; } M3D1020;
extern signed char D_00543740;
extern M3D1020 D_00543760;
extern char D_00543764[];
extern char D_00543770[];
extern char D_00543748[];
extern char TextManager_Destroy[];
extern void List_InitEmpty(void* p);
extern void ScalarCollection_Init(void* p);
extern void __register_global_object(void* o, void* d, void* l);
#pragma push
#pragma opt_propagation off
M3D1020* TextManager_Get(void)
{
    if (!D_00543740) {
        M3D1020* m = &D_00543760;
        D_00543760.f0 = 0;
        List_InitEmpty(D_00543764);
        ScalarCollection_Init(D_00543770);
        m->b1C = 1;
        __register_global_object(m, TextManager_Destroy, D_00543748);
        D_00543740 = 1;
    }
    return &D_00543760;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003D1020 */

/* merge_units: begin func_003D10B0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_003D0DE0();                            
int func_003D11A0(void **, int, int, char *, int);                

void func_003D10B0(void ***arg0, int *arg1, void ***arg2, void ***arg3) {
    void **temp_a0;
    void **temp_a2;
    void **temp_v1;
    char * temp_a1;

    temp_a2 = *arg2;
    temp_v1 = *arg3;
    if (temp_a2 == temp_v1) {
        *arg0 = temp_v1;
        return;
    }
    temp_a1 = *temp_v1;
    F_((*temp_a2), 0x4, int) = (int)(F_(temp_a1, 0x4, int));
    *(int *)F_(temp_a1, 0x4, int) = (int)(*temp_a2);
    if (*arg2 != *arg3) {
        do {
            func_003D0DE0((char *)*arg2 + 0x10, -1);
            temp_a0 = *arg2;
            *arg2 = (void **)(F_(temp_a0, 0x4, int));
            if (temp_a0 != NULL) {
                func_003D11A0(temp_a0, 0, 0, "allocator.hh", 100);
            }
            *arg1 -= 1;
        } while (*arg2 != *arg3);
    }
    *arg0 = *arg3;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D10B0 */
