#include "types.h"

typedef struct { char pad[0x14]; unsigned short flags; } W_28D610;
typedef struct { __int128 a; __int128 b; } Ent_28D610;
typedef struct { char pad[0xE0]; Ent_28D610 e[1]; } Tbl_28D610;
typedef struct { unsigned char mode; signed char slot; short pos; } Tab_28D610;
typedef struct {
    char pad0[0x58]; W_28D610* w58; W_28D610* w5C; char pad60[0x10]; Tbl_28D610* items; char pad74[0x4C];
    int dirty; int count; int pos; char padCC[0xC]; int row; char padDC[4]; int vE0; int vE4; char padE8[5];
    signed char slot; unsigned char mode; signed char cur; signed char prev;
} S_28D610;

extern char D_0048B560[11][20];
extern Tab_28D610 D_0048B500[][11];
extern unsigned char D_0048B501[][44];
extern char D_0055DDA0[];
extern char D_004A9A30[];
extern char D_004A9A38[];
extern char D_004A9A40[];
extern int strcmp(const char* a, const char* b);
extern int sprintf(char* buf, const char* fmt, ...);
extern int func_00404690(void* db, __int128 key);
extern int func_00401DE0(void* db, __int128 key);
extern void GuiAgentCreate_UpdateCount(S_28D610* o);
extern void func_0041BEB0(W_28D610* w, char* text, int flags);
extern void func_0041E0F0(S_28D610* o, W_28D610* w, int kind, int v, int f);

static inline void Slider_28D610(S_28D610* o, W_28D610* w, int kind, int v, int f)
{
    if (w) func_0041E0F0(o, w, kind, v, f);
}

void GuiAgentCreate_SelectOption(S_28D610* o, char* name)
{
    char buf[0x10];
    int i;
    for (i = 0; i < 11; i++) {
        if (!strcmp(D_0048B560[i], name)) break;
    }
    if (i != o->cur) {
        o->prev = o->cur;
        o->cur = i;
        o->dirty = 1;
        if (i < 11) {
            o->slot = D_0048B501[o->row][o->cur * 4];
            o->mode = D_0048B500[o->row][o->cur].mode;
            o->vE0 = func_00404690(D_0055DDA0, o->items->e[o->slot].a);
            o->vE4 = func_00401DE0(D_0055DDA0, o->items->e[o->slot].b);
            GuiAgentCreate_UpdateCount(o);
            if (o->w58) o->w58->flags |= 2;
            Slider_28D610(o, o->w58, 10, (int)((100.0f / (float)(o->count - 1)) * (float)o->pos), 0);
            if (o->w5C) {
                if (o->count) {
                    sprintf(buf, D_004A9A30, o->pos + 1, o->count);
                    func_0041BEB0(o->w5C, buf, 0);
                } else {
                    func_0041BEB0(o->w5C, D_004A9A38, 0);
                }
            }
        } else {
            o->count = 0;
            o->pos = 0;
            if (o->w58) o->w58->flags &= ~2;
            if (o->w5C) func_0041BEB0(o->w5C, D_004A9A40, 0);
        }
    }
}
