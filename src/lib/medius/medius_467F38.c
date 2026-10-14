/*
 * lib/medius: 4 files, 00467F38-00468158
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00467F38 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00467DD0(int);                                 
int func_00467DF0(int );                            

void func_00467F38(int arg0) {
    if (F_(arg0, 0x4, int) != 0) {
        func_00467DD0(2);
        return;
    }
    if (F_(arg0, 0x0, int) == 0) {
        func_00467DD0(2);
        return;
    }
    func_00467DF0(arg0 + 8);
    func_00467DD0(1);
}
/* merge_units: end func_00467F38 */

/* merge_units: begin func_00467F90 */
#include "types.h"
typedef struct { char b[0xC4]; } S_C4;
typedef struct { char b[0xEC]; } S_EC;
extern int D_00497E24;
extern S_C4 D_00587E08;
extern S_EC D_00587ED0;
void func_00467F90(int type, void* data)
{
    D_00497E24 = type;
    switch (type) {
    case 0x2C:
        D_00587E08 = *(S_C4*)data;
        break;
    case 0x12:
        D_00587ED0 = *(S_EC*)data;
        break;
    }
}
/* merge_units: end func_00467F90 */

/* merge_units: begin func_00468148 */
void func_00468148(int *arg0) {
    *arg0 = D_00497E24;
}
/* merge_units: end func_00468148 */

/* merge_units: begin func_00468158 */
typedef struct { char w[0xC4]; } SA;
typedef struct { char w[0xEC]; } SB;
#if 0 /* merge_units */
extern SA D_00587E08;
#endif /* merge_units */
#define D_00587E08 (*(SA*)&D_00587E08) /* merge_units */

#if 0 /* merge_units */
extern SB D_00587ED0;
#endif /* merge_units */
#define D_00587ED0 (*(SB*)&D_00587ED0) /* merge_units */

void func_00468158(void* dst)
{
    switch (D_00497E24) {
    case 44:
        *(SA*)dst = D_00587E08;
        break;
    case 18:
        *(SB*)dst = D_00587ED0;
        break;
    }
}
#undef D_00587E08 /* merge_units */
#undef D_00587ED0 /* merge_units */
/* merge_units: end func_00468158 */
