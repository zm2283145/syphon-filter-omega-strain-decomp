#include "types.h"

typedef struct { char pad[0x14]; unsigned short flags; } W_341C50;
typedef struct { __int128 a; __int128 b; } Ent_341C50;
typedef struct { char pad[0xE0]; Ent_341C50 e[1]; } Tbl_341C50;
typedef struct { unsigned char mode; signed char slot; short pos; } Tab_341C50;
typedef struct {
    char pad0[0x78]; W_341C50* w78; W_341C50* w7C; char pad80[0xC]; Tbl_341C50* items; char pad90[0x50];
    int dirty; int count; int pos; char padEC[0x14]; int v100; int v104; char pad108[5];
    signed char slot; unsigned char mode; signed char cur; signed char prev;
} S_341C50;

extern char D_00492A40[16][16];
extern Tab_341C50 D_00492A00[16];
extern signed char D_00492A01[];
extern short D_00492A02[];
extern char D_0055DDA0[];
extern char D_004B9F20[];
extern char D_004B9F70[];
extern char D_004B9F78[];
extern int strcmp(const char* a, const char* b);
extern int sprintf(char* buf, const char* fmt, ...);
extern int func_00404690(void* db, __int128 key);
extern int func_00401DE0(void* db, __int128 key);
extern void func_00343940(S_341C50* o);
extern void func_0041BEB0(W_341C50* w, char* text, int flags);
extern void func_0041E0F0(S_341C50* o, W_341C50* w, int kind, int v, int f);

static inline void Slider_341C50(S_341C50* o, W_341C50* w, int kind, int v, int f)
{
    if (w) func_0041E0F0(o, w, kind, v, f);
}

void func_00341C50(S_341C50* o, char* name)
{
    char buf[0x10];
    int i;
    for (i = 0; i < 16; i++) {
        if (!strcmp(D_00492A40[i], name)) break;
    }
    if (i != o->cur) {
        o->prev = o->cur;
        o->cur = i;
        o->dirty = 1;
        if (i < 16) {
            o->slot = D_00492A01[o->cur * 4];
            if (o->slot == -1) {
                if (o->w78) o->w78->flags &= ~2;
                o->mode = 6;
                return;
            }
            o->mode = D_00492A00[o->cur].mode;
            o->v100 = func_00404690(D_0055DDA0, o->items->e[o->slot].a);
            o->v104 = func_00401DE0(D_0055DDA0, o->items->e[o->slot].b);
            func_00343940(o);
            if (o->count) o->pos = o->pos % o->count;
            else o->pos = 0;
            *(short*)((char*)D_00492A02 + o->cur * 4) = o->pos;
            if (o->w78) o->w78->flags |= 2;
            Slider_341C50(o, o->w78, 10, (int)((100.0f / (float)(o->count - 1)) * (float)o->pos), 0);
            if (o->w7C) {
                if (o->count) {
                    sprintf(buf, D_004B9F70, o->pos + 1, o->count);
                    func_0041BEB0(o->w7C, buf, 0);
                } else {
                    func_0041BEB0(o->w7C, D_004B9F78, 0);
                }
            }
        } else {
            o->count = 0;
            o->pos = 0;
            if (o->w78) o->w78->flags &= ~2;
            if (o->w7C) func_0041BEB0(o->w7C, D_004B9F20, 0);
        }
    }
}