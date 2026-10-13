/*
 * main/DME: 4 files, 0042A640-0042A780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A640 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0042A640(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_0042A660(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0042A670(Iter* out, PtrVec* v) {
    out->p = v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A640 */

/* merge_units: begin func_0042A680 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "network_session_types.h"

extern "C" {
extern int D_00572510;
extern int D_00572520;
extern unsigned char D_00572530;
extern unsigned char D_00572500;
extern unsigned char D_00572528;
extern int D_00572508;
extern unsigned char D_00533880;
void func_0010D060(int thread, NetworkThreadStatus* status);
void func_0010CFF0(int thread, int priority);
int func_0010E010(int thread);
void func_0010E1C0(int delay);
}

/* Stop the worker and clear its coordination and allocator-locking flags. */
extern "C" void func_0042A680(void)
{
    NetworkThreadStatus worker;
    NetworkThreadStatus current;
    func_0010D060(D_00572510, &worker);
    func_0010D060(D_00572520, &current);
    if (worker.priority <= current.priority)
        func_0010CFF0(D_00572510, 0);
    D_00572530 = 1;
    int thread = func_0010E010(D_00572510);
    func_0010E1C0(10);
    if (thread == D_00572510) {
        while ((D_00572500 != 0) ^ 1)
            func_0010E1C0(10);
    }
    D_00572530 = 0;
    D_00572528 = 0;
    D_00572508 = 0;
    D_00572500 = 0;
    D_00533880 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A680 */

/* merge_units: begin func_0042A770 */
#pragma push /* merge_units */
extern int func_00429380(int);
extern int func_004295E0(void);

int func_0042A770(void) {
    return func_00429380((int)func_004295E0);
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A770 */

/* merge_units: begin func_0042A780 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_002EBCE0(char *);                               
int Gui_GetScreenStack();                             
int func_0041E0F0(int, int, int, int, int);                    
int func_0042ACD0();                                
extern signed char D_005721E0;
extern signed char D_005721F0;
extern signed char D_005723B0;
extern signed char D_00572468;
extern int D_00572470;
extern int D_00572478;
extern signed char D_005724B0;

extern char D_004BF9B8;
void func_0042A780(void) {
    int sp2C;
    int temp_a0;
    int temp_s0;

    D_005723B0 = 0;
    D_005721E0 = 0;
    D_005724B0 = 5;
    D_005721F0 = 0;
    if (func_0042ACD0() == 0) {
        func_002EBCE0(&sp2C);
        return;
    }
    temp_a0 = D_00572470 + 1;
    D_00572470 = temp_a0;
    if (temp_a0 < D_00572478) {
        D_00572468 = 1;
        return;
    }
    if (Gui_GetScreenStack(temp_a0) != 0) {
        temp_s0 = Gui_GetScreenStack();
        func_0041E0F0(temp_s0, Gui_GetScreenStack(), 0x1E, 0, (int)&D_004BF9B8);
    }
    D_00572470 = 0;
    D_00572478 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A780 */
