/*
 * main/GuiGameScreen: range (3 files, 0045D420-0045D7F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0045D420 */
#pragma push /* merge_units */
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_45D420;
typedef struct { char pad[0x90]; int f90; int f94; int f98; unsigned char b9C; char pad9D[0xD4 - 0x9D]; int fD4; } O_45D420;
int func_0045BD00(O_45D420* o);
void func_0045BF80(O_45D420* o);
unsigned long long func_003698B0(void);
void func_0045C540(O_45D420* o, int v);
void func_0045C480(O_45D420* o);
void func_0045CA20(O_45D420* o, int on);
static inline unsigned char Down_45D420(Ev_45D420* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_45D420(Ev_45D420* e, int b) { unsigned char r = 0; if (Down_45D420(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Shift_45D420(Ev_45D420* e, int b) { unsigned char r = 0; if (Btn_45D420(e, b) && e->b6 == 1) r = 1; return r; }
static inline int Down2_45D420(Ev_45D420* e) { return e->type == 1 && e->b2 == 0; }
static inline int Btn2_45D420(Ev_45D420* e, int b) { return Down2_45D420(e) && e->btn == b; }
static inline int Plain2_45D420(Ev_45D420* e, int b) { return Btn2_45D420(e, b) && e->b6 == 0; }

int func_0045D420(O_45D420* o, Ev_45D420* ev)
{
    if (Plain2_45D420(ev, 0x10) && func_0045BD00(o)) {
        func_0045BF80(o);
        return 1;
    }
    if (o->fD4 == 1) {
    if (Shift_45D420(ev, 0x100)) {
        if (!o->b9C && o->f94 == o->f90 && func_003698B0() - o->f98 < 100) func_0045C540(o, 1);
        func_0045C480(o);
        func_0045CA20(o, 0);
        return 1;
    }
    if (Plain2_45D420(ev, 8) || Plain2_45D420(ev, 2)) {
        func_0045C540(o, 0);
        return 1;
    }
    if (Plain2_45D420(ev, 4) || Plain2_45D420(ev, 1)) {
        func_0045C540(o, 1);
        return 1;
    }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045D420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045D420 */

/* merge_units: begin func_0045D710 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { char pad[0x416]; signed char v; } T_45D710;
typedef struct {
    char pad0[0xF0];
    unsigned char type;
    char padF1[0x11C - 0xF1];
    T_45D710* alt;
    char pad120[0x13C - 0x120];
    T_45D710* main;
} W_45D710;
typedef struct {
    char pad0[0x74];
    int n;
    int* ids;
    char pad7C[0x88 - 0x7C];
    int* vals;
    char pad8C[0xD8 - 0x8C];
    T_45D710* def;
} O_45D710;
extern void* D_004FFD30;
W_45D710* WeaponDb_Get(void* db, int id);

static inline T_45D710* W_Get(W_45D710* w)
{
    if (w->type == 7 && w->alt != 0) return w->alt;
    return w->main;
}

void func_0045D710(O_45D710* o)
{
    int i;
    for (i = 0; i < o->n; i++) {
        if (o->ids[i] == -2) {
            o->def->v = -1;
        } else {
            W_45D710* w = WeaponDb_Get(D_004FFD30, o->ids[i]);
            if (w) {
                T_45D710* t = W_Get(w);
                if (t) t->v = o->vals[i];
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045D710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045D710 */

/* merge_units: begin func_0045D7F0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct {
    char pad0[0x74];
    int n;
    int* ids;
    char pad7C[0x80 - 0x7C];
    char vec80[8];
    int* vals;
    char pad8C[0xD8 - 0x8C];
    T_45D710* def;
} O_45D710_0045D7F0;
extern int D_00497B08;
void PtrVector_Resize(void* v, unsigned int n, int* fill);

void func_0045D7F0(O_45D710_0045D7F0* o)
{
    int i;
    PtrVector_Resize(o->vec80, o->n, &D_00497B08);
    for (i = 0; i < o->n; i++) {
        if (o->ids[i] != -2) {
            W_45D710* w = WeaponDb_Get(D_004FFD30, o->ids[i]);
            if (w) {
                T_45D710* t = W_Get(w);
                if (t) o->vals[i] = t->v;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045D7F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045D7F0 */
