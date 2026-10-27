/*
 * SFOGame/Source/hud_netlobby: 6 files, 0027A740-0027AA80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027A740 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x3C]; int mode; char pad2[0x16]; unsigned char busy; } Menu27A7;
typedef struct { char pad[0x14C]; unsigned int pressed; char pad2[8]; unsigned int held; } Pad27A7;
#if 0 /* merge_units */
extern void cHudNetLobby_NextButton(Menu27A7* s, int dir);
#endif /* merge_units */
void cHudNetLobby_NextButton(); /* merge_units */

#if 0 /* merge_units */
extern void cHudNetLobby_ButtonPressed(Menu27A7* s);
#endif /* merge_units */
void cHudNetLobby_ButtonPressed(); /* merge_units */


extern void cHudNetLobby_InitCurrentScreen(Menu27A7* s);
void cHudNetLobby_HandleInput(Menu27A7* s, Pad27A7* p) {
    unsigned int bits;
    if (s->busy) return;
    bits = p->pressed & ~p->held;
    if (bits & 0x1000) cHudNetLobby_NextButton(s, 0);
    if (bits & 0x4000) cHudNetLobby_NextButton(s, 1);
    if (bits & 0x40) cHudNetLobby_ButtonPressed(s);
    if (s->mode == 1 && (bits & 0x10)) {
        s->mode = 0;
        cHudNetLobby_InitCurrentScreen(s);
    }
}
static inline void merge_flush_func_0027A740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A740 */

/* merge_units: begin func_0027A7F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern char g_Video[];
extern int D_00538C60;
extern int cInterface_Render(int*);

/* Resets the current slot record (index D_00538C60) and calls cInterface_Render on the handle. */
int cHudNetLobby_Render(HandleHolder* self) {
    Slot110View* slot = (Slot110View*)(g_Video + D_00538C60 * 272);

    slot->unk2E0 = 0;
    slot->unk2E8 = 100.0f;
    slot->unk2F6 = 1;
    slot->unk2F4 = 1;
    return cInterface_Render(self->handle);
}
static inline void merge_flush_func_0027A7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A7F0 */

/* merge_units: begin func_0027A830 */
#pragma push /* merge_units */
typedef struct { int a; char pad[0x52]; unsigned char b56; } B8S_27A830;
extern void cInterface_NextFrame(int);
extern void cHudNetLobby_UpdateGameInfo(B8S_27A830*);
extern float D_00504048;
void cHudNetLobby_NextFrame(B8S_27A830* p, float dt) {
    cInterface_NextFrame(p->a);
    if (p->b56 == 0) {
        D_00504048 += dt;
        if (D_00504048 > 5.0f) {
            cHudNetLobby_UpdateGameInfo(p);
            D_00504048 = 0.0f;
        }
    }
}
static inline void merge_flush_func_0027A830(void) {} /* merge_units */
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
extern void std_list_deleter_voidPtr_begin_void(It27A8 *r, void *l);
#if 0 /* merge_units */
extern void std_list_GameInfoPtr_generic_iterator_ctor(It27A8 *r, It27A8 *s);
#endif /* merge_units */
Word * std_list_GameInfoPtr_generic_iterator_ctor(); /* merge_units */

#if 0 /* merge_units */
extern char *std_list_GameInfoPtr_front(void *l);
#endif /* merge_units */
char * std_list_GameInfoPtr_front(); /* merge_units */

#if 0 /* merge_units */
extern void cHudNetLobby_InitCurrentScreen(Menu27A8 *s);
#endif /* merge_units */
#define cHudNetLobby_InitCurrentScreen(a0) (cHudNetLobby_InitCurrentScreen((Menu27A7 *)(a0))) /* merge_units */



void cHudNetLobby_ButtonPressed(Menu27A8 *s)
{
    if (s->mode == 0) {
        if (s->sel == 1) {
            if (D_00504040 == 0) {
                s->mode = 1;
                cHudNetLobby_InitCurrentScreen(s);
            } else if (s->count != 0) {
                Entry27A8 *e;
                s->b54 = 1;
                s->b55 = 0;
                e = *(Entry27A8 **)std_list_GameInfoPtr_front(&s->count);
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
            std_list_deleter_voidPtr_begin_void(&t, &s->count);
            std_list_GameInfoPtr_generic_iterator_ctor(&it, &t);
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
#undef cHudNetLobby_InitCurrentScreen /* merge_units */
static inline void merge_flush_func_0027A8B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A8B0 */

/* merge_units: begin func_0027AA80 */
#pragma push /* merge_units */
Word* std_list_GameInfoPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Address 8 bytes past the node stored at +8. */
char* std_list_GameInfoPtr_front(PtrVec* self) {
    return (char*)self->data + 8;
}
static inline void merge_flush_func_0027AA80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027AA80 */

/* merge_units: begin func_0027AAA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; int count; char pad2[8]; int sel; int mode; } Menu27AA;
extern void cHudNetLobby_SetActive(Menu27AA* s);
void cHudNetLobby_NextButton(Menu27AA* s, int dir) {
    int n = 0;
    if (s->mode == 0) {
        if (D_00504040 || !s->count) return;
        n = 2;
    } else if (s->mode == 1) {
        n = s->count;
    }
    if (n) {
        if (dir) {
            s->sel++;
            if (s->sel >= n) s->sel = 0;
        } else {
            s->sel--;
            if (s->sel < 0) s->sel = n - 1;
        }
    }
    cHudNetLobby_SetActive(s);
}
static inline void merge_flush_func_0027AAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027AAA0 */
