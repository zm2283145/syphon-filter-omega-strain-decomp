/*
 * main/MemCard: 2 files, 0040EFA0-0040F190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040EFA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int h; char p0[0x10]; int size; char p1[4]; char name[0x1C]; } E40E5D0;
typedef struct {
    E40E5D0 ent[1]; char p0[0x3F4 - 0x38]; int t0; int t1; int t2; char path[0x140];
    int busy; int state; int sub; int saveState; int saveSub; int p554; int arg; int p55C; int p560;
    int idx; int retries; int cnt; int x570; int res; int r; char p57C[0x20]; unsigned char flag;
    unsigned char f59D; unsigned char f59E; unsigned char f59F; unsigned char f5A0; char p5A1[3];
    int x5A4; int x5A8;
} S40E5D0;
extern char* D_00494010;
extern char D_004BED60[];
extern char D_00571C50[];
extern int sprintf(char*, const char*, ...);
extern void func_002B51E0(int, int*);
extern void func_002B56E0(int, char*, int, int, void*, int*);
extern int atoi(char*);

void MemCard_InfoCycle(S40E5D0* s) {
    int i;
    if (s->busy) {
        s->state = s->busy;
        s->busy = 0;
        s->sub = 0;
        return;
    }
    switch (s->sub) {
    case 0:
        func_002B51E0(s->ent[0].h, &s->t0);
        s->sub = 1;
        break;
    case 1:
        s->f59D = s->t0 == 2;
        s->f59E = s->t1 == 1;
        if (s->res < 0) {
            s->x5A8 = -1;
            s->p560 = 0;
            s->x5A4 = 0;
            s->f59F = 0;
            s->f59E = 0;
            if (++s->retries > 6) {
                s->f5A0 = 1;
                s->retries = 0;
            }
            if (*(unsigned short*)&s->res != 0x2F)
                s->f59D = 0;
            s->sub = 0;
        } else {
            s->x5A4 = s->t2;
            sprintf(D_00571C50, D_004BED60, D_00494010, "*");
            func_002B56E0(s->ent[0].h, D_00571C50, 0, 0x12, s->ent[0].p0, &s->p560);
            s->sub = 2;
        }
        break;
    case 2:
        s->x5A8 = -1;
        if (s->res < 0) {
            s->p560 = 0;
            s->f59F = 0;
        } else {
            s->f59F = 1;
            for (i = 0; i < s->p560; i++) {
                if (s->ent[i].name[0] == '#')
                    s->x5A8 = atoi(s->ent[i].name + 1);
            }
        }
        s->retries = 0;
        s->f5A0 = 1;
        s->sub = 0;
        break;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040EFA0 */

/* merge_units: begin func_0040F190 */
#pragma push /* merge_units */
typedef struct MemCard {
    int iconSys;
    char pad[0x10];
    int unk14;
    char pad2[0x400 - 0x18];
    int iconParams[3];
    char pad3[0x440 - 0x40C];
    char iconData[0x100];
    int unk540, unk544, unk548, unk54C, unk550;
    int pad554;
    int unk558;
    int pad55C;
    int unk560, unk564, unk568, unk56C;
    char pad4[0x2C];
    unsigned char flag59C, flag59D, flag59E, flag59F, flag5A0;
    char pad5[3];
    int unk5A4;
} MemCard;

extern int func_002B4F10(int* params, char* data);
extern void String_Copy(char* dst, const char* src); /* String_Copy */
extern void strncpy(void* dst, const void* src, int size); /* strncpy-style copy */
extern void MemCard_TitleToSjis(void* dst, const void* src, int size);
extern char* D_00494008;
extern char D_00493D84[];
extern char D_00493D44[];
extern char D_00493DC4[];
extern char D_00493C40[];
extern char D_00493D00[];

/* Resets the memory card state and builds the icon.sys header strings. */
MemCard* MemCard_SetupIconSys(MemCard* self) {
    self->iconParams[0] = 2;
    self->iconParams[1] = 2;
    self->iconParams[2] = 0;
    self->iconSys = func_002B4F10(self->iconParams, self->iconData);
    self->unk540 = 0;
    self->unk544 = 0;
    self->unk548 = 0;
    self->unk54C = 0;
    self->unk550 = 0;
    self->unk560 = 0;
    self->unk564 = 0;
    self->unk568 = 0;
    self->unk14 = 0x10;
    self->unk558 = 0;
    self->unk56C = 0;
    self->flag59D = 0;
    self->flag59E = 0;
    self->flag59F = 0;
    self->flag5A0 = 0;
    self->flag59C = 0;
    self->unk5A4 = 0;
    String_Copy(D_00493D84, D_00494008);
    String_Copy(D_00493D44, D_00494008);
    String_Copy(D_00493DC4, D_00494008);
    strncpy(D_00493C40, "PS2D", 4);
    MemCard_TitleToSjis(D_00493D00, "Syphon Filter:The Omega Strain", 0x20);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040F190 */
