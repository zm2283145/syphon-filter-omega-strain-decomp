/*
 * main/hud_netlobby: 3 files, 0027A7F0-0027A8B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027A7F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char g_Video[];
extern int D_00538C60;
extern int IeScreen_Draw(int*);

/* Resets the current slot record (index D_00538C60) and calls IeScreen_Draw on the handle. */
int func_0027A7F0(HandleHolder* self) {
    Slot110View* slot = (Slot110View*)(g_Video + D_00538C60 * 272);

    slot->unk2E0 = 0;
    slot->unk2E8 = 100.0f;
    slot->unk2F6 = 1;
    slot->unk2F4 = 1;
    return IeScreen_Draw(self->handle);
}
#pragma pop /* merge_units */
/* merge_units: end func_0027A7F0 */

/* merge_units: begin func_0027A830 */
#pragma push /* merge_units */
typedef struct { int a; char pad[0x52]; unsigned char b56; } B8S_27A830;
extern void IeScreen_Update(int);
extern void func_0027AEA0(B8S_27A830*);
extern float D_00504048;
void func_0027A830(B8S_27A830* p, float dt) {
    IeScreen_Update(p->a);
    if (p->b56 == 0) {
        D_00504048 += dt;
        if (D_00504048 > 5.0f) {
            func_0027AEA0(p);
            D_00504048 = 0.0f;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0027A830 */

/* merge_units: begin func_0027A8B0 */
#pragma push /* merge_units */
typedef struct { char c[16]; } Name27A8;
typedef struct { Name27A8 name; int x10; } Entry27A8;
typedef struct Node27A8 { int prev; struct Node27A8 *next; Entry27A8 *e; } Node27A8;
typedef struct { Node27A8 *p; } It27A8;
typedef struct {
    char pad[0x2C]; int count; char pad30[8]; int sel; int mode;
    Name27A8 name; int x50; unsigned char b54; unsigned char b55;
} Menu27A8;
extern unsigned char D_00504040;
extern void List_Begin(It27A8 *r, void *l);
extern void func_0027AA80(It27A8 *r, It27A8 *s);
extern char *func_0027AA90(void *l);
extern void func_0027AB60(Menu27A8 *s);

void func_0027A8B0(Menu27A8 *s)
{
    if (s->mode == 0) {
        if (s->sel == 1) {
            if (D_00504040 == 0) {
                s->mode = 1;
                func_0027AB60(s);
            } else if (s->count != 0) {
                Entry27A8 *e;
                s->b54 = 1;
                s->b55 = 0;
                e = *(Entry27A8 **)func_0027AA90(&s->count);
                s->name = e->name;
                s->x50 = e->x10;
            }
        } else if (s->sel == 0) {
            s->b54 = 1;
            s->b55 = 1;
        }
    } else if (s->mode == 1) {
        if (s->count > s->sel) {
            It27A8 it, t;
            Node27A8 *n;
            Entry27A8 *e;
            int i;
            List_Begin(&t, &s->count);
            func_0027AA80(&it, &t);
            n = it.p;
            for (i = 0; i < s->sel; i++) n = n->next;
            s->b54 = 1;
            s->b55 = 0;
            e = n->e;
            s->name = e->name;
            s->x50 = e->x10;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0027A8B0 */
