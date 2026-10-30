/*
 * SFOGame/Source/Rumble: 4 files, 0026BC20-0026BDE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026BC20 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
struct E26BC20 { unsigned char b0; int i4; float f8; int iC; float f10; int i14; unsigned char b18; };
struct C26BC20 { char pad[0x1C0]; };
extern int D_004FF020;
extern unsigned char D_004FF028;
extern char D_004FEED0[];
extern C26BC20 D_0055A300[2];
extern "C" int cJoyPad_SetVibration(void* p, int f, int n);
extern "C" void nRumbleManager_NextFrame(float dt) {
    int k;
    D_004FF020++;
    for (k = 0; k < 2; k++) {
        unsigned char flag = 0;
        int sum = 0;
        if (D_004FF028) {
            int j;
            for (j = 0; j < 6; j++) {
                E26BC20* e = &((E26BC20 (*)[6])D_004FEED0)[k][j];
                if (e->b18) {
                    e->f10 += dt;
                    if (D_004FF020 % e->iC == 0) {
                        flag = (flag | e->b0) != 0;
                        sum += e->i4;
                    }
                    if (!(e->f8 < 0.0f) && e->f10 > e->f8) {
                        e->b18 = 0;
                    }
                }
            }
        }
        cJoyPad_SetVibration((char*)&D_0055A300[k] + 0x40, flag, sum);
    }
}
static inline void merge_flush_func_0026BC20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BC20 */

/* merge_units: begin func_0026BD60 */
#pragma push /* merge_units */
extern char D_0055A340[];
extern char D_0055A500[];
#if 0 /* merge_units */
extern int cJoyPad_SetVibration(void*, int, int);
#endif /* merge_units */
#define cJoyPad_SetVibration(a0, a1, a2) (cJoyPad_SetVibration((a0), (a1), (a2))) /* merge_units */


int nRumbleManager_StopAll(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    a0 = 0;
    v1 = (int)D_004FEED0;
L0026BD78:;
    *(char*)((char*)v1 + 24) = 0;
    *(char*)((char*)v1 + 52) = 0;
    a0 = a0 + 1;
    *(char*)((char*)v1 + 80) = 0;
    v0 = a0 < 2;
    *(char*)((char*)v1 + 108) = 0;
    *(char*)((char*)v1 + 136) = 0;
    *(char*)((char*)v1 + 164) = 0;
    cond = v0 != 0;
    v1 = v1 + 168;
    if (cond) goto L0026BD78;
    a1 = 0;
    a0 = (int)D_0055A340;
    a2 = 0;
    v0 = cJoyPad_SetVibration((void*)a0, a1, a2);
    a1 = 0;
    a0 = (int)D_0055A500;
    a2 = 0;
    v0 = cJoyPad_SetVibration((void*)a0, a1, a2);
    goto ret;
ret:
    return v0;
}
#undef cJoyPad_SetVibration /* merge_units */
static inline void merge_flush_func_0026BD60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BD60 */

/* merge_units: begin func_0026BDE0 */
#pragma push /* merge_units */
typedef struct { unsigned char type; int a; float f; int b; int c; int id; unsigned char used; } C4Slot26B;
static unsigned int dat_0048B270[2] = { 0x1, 0x0 };
int nRumbleManager_Start(int idx, unsigned char type, int a, int b, float f) {
    int i;
    for (i = 0; i < 6; i++) {
        C4Slot26B* s = &((C4Slot26B (*)[6])D_004FEED0)[idx][i];
        if (!s->used) {
            int id;
            s->used = 1;
            s->type = type;
            s->a = a;
            s->f = f;
            s->b = b;
            s->c = 0;
            id = (*(int*)dat_0048B270)++;
            s->id = id;
            return s->id;
        }
    }
    return 0;
}
static inline void merge_flush_func_0026BDE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BDE0 */

/* merge_units: begin func_0026BE70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern char D_004FF028;
#endif /* merge_units */
#define D_004FF028 (*(char*)&D_004FF028) /* merge_units */


void nRumbleManager_SetEnabled(int value) {
    D_004FF028 = value;
}
#undef D_004FF028 /* merge_units */
static inline void merge_flush_func_0026BE70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BE70 */
