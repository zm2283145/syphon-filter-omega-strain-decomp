/*
 * main/game: 3 files, 00275550-00275670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00275550 */
#pragma push /* merge_units */
#include "types.h"

extern char D_004FFE60[];
extern char D_004FFEDC[];
extern char D_004FFF75[];

void func_00275550(void) {
    int a0, a1, a2, v1;
    int cond;

    a1 = 0;
    a0 = (int)D_004FFE60;
L00275560:;
    *(char*)((char*)a0 + 277) = 0;
    *(int*)((char*)a0 + 124) = 0;
    a1 = a1 + 8;
    *(char*)((char*)a0 + 613) = 0;
    v1 = a1 < 42;
    *(int*)((char*)a0 + 460) = 0;
    *(char*)((char*)a0 + 949) = 0;
    *(int*)((char*)a0 + 796) = 0;
    *(char*)((char*)a0 + 1285) = 0;
    *(int*)((char*)a0 + 1132) = 0;
    *(char*)((char*)a0 + 1621) = 0;
    *(int*)((char*)a0 + 1468) = 0;
    *(char*)((char*)a0 + 1957) = 0;
    *(int*)((char*)a0 + 1804) = 0;
    *(char*)((char*)a0 + 2293) = 0;
    *(int*)((char*)a0 + 2140) = 0;
    *(char*)((char*)a0 + 2629) = 0;
    *(int*)((char*)a0 + 2476) = 0;
    cond = v1 != 0;
    a0 = a0 + 2688;
    if (cond) goto L00275560;
    v1 = a1 << 3;
    a2 = v1 - a1;
    a0 = (int)D_004FFF75;
    a1 = a2 << 2;
    a1 = a1 - a2;
    v1 = (int)D_004FFEDC;
    a1 = a1 << 4;
    a0 = a0 + a1;
    v1 = v1 + a1;
    *(char*)(char*)a0 = 0;
    *(int*)(char*)v1 = 0;
    *(char*)((char*)a0 + 336) = 0;
    *(int*)((char*)v1 + 336) = 0;
    goto ret;
ret:;
}
#pragma pop /* merge_units */
/* merge_units: end func_00275550 */

/* merge_units: begin func_002755F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x110]; int w110; char pad2; unsigned char b115; char pad3; unsigned char b117; char pad4[0x150 - 0x118]; } E2755;
#if 0 /* merge_units */
extern E2755 D_004FFE60[50];
#endif /* merge_units */
#define D_004FFE60 ((E2755*)&D_004FFE60) /* merge_units */

extern void func_002757A0(E2755* e);
static inline int ok_2755(E2755* p) { return p->b117 != 0 || p->w110 != 0; }
void func_002755F0(void)
{
    int i;
    for (i = 0; i < 50; i++) {
        if (D_004FFE60[i].b115) {
            if (ok_2755(&D_004FFE60[i]))
                func_002757A0(&D_004FFE60[i]);
        }
    }
}
#undef D_004FFE60 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002755F0 */

/* merge_units: begin func_00275670 */
#pragma push /* merge_units */
typedef struct { char pad[0x115]; unsigned char active; char pad2[0x150 - 0x116]; } G7_E275;
#if 0 /* merge_units */
extern G7_E275 D_004FFE60[];
#endif /* merge_units */
#define D_004FFE60 ((G7_E275*)&D_004FFE60) /* merge_units */

extern void BulletPool_UpdateAll(G7_E275* e, float f);
void BulletPool_Update(float f)
{
    int i;
    G7_E275* e = D_004FFE60;
    for (i = 0; i < 50; i++, e++) {
        if (e->active) {
            BulletPool_UpdateAll(e, f);
        }
    }
}
#undef D_004FFE60 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00275670 */
