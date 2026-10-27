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

char D_00492A40[16][16] = {
    "hairstyle",
    "haircolor",
    "hat",
    "eyewear",
    "beard",
    "makeup",
    "shirt",
    "vest",
    "pants",
    "boots",
    "leftarm",
    "rightarm",
    "back",
    "leftarm2",
    "rightarm2",
    "hat2"
};
extern Tab_341C50 D_00492A00[16];
extern signed char D_00492A01[];
extern short D_00492A02[];
extern char g_AgentPartCache[];
extern char D_004B9F20[];
extern char D_004B9F70[];
extern char D_004B9F78[];
extern int strcmp(const char* a, const char* b);
extern int sprintf(char* buf, const char* fmt, ...);
extern int FindPartNumber__7MonsterF1(void* db, __int128 key);
extern int FindTextureNumber__7MonsterF1(void* db, __int128 key);
extern void GuiAgentModify_CountSelections(S_341C50* o);
extern void GuiTextWidget_SetText(W_341C50* w, char* text, int flags);
extern void GuiWidget_SendMessage(S_341C50* o, W_341C50* w, int kind, int v, int f);

static inline void Slider_341C50(S_341C50* o, W_341C50* w, int kind, int v, int f)
{
    if (w) GuiWidget_SendMessage(o, w, kind, v, f);
}

void GuiAgentModify_UserInterfaceNextButton(S_341C50* o, char* name)
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
            o->v100 = FindPartNumber__7MonsterF1(g_AgentPartCache, o->items->e[o->slot].a);
            o->v104 = FindTextureNumber__7MonsterF1(g_AgentPartCache, o->items->e[o->slot].b);
            GuiAgentModify_CountSelections(o);
            if (o->count) o->pos = o->pos % o->count;
            else o->pos = 0;
            *(short*)((char*)D_00492A02 + o->cur * 4) = o->pos;
            if (o->w78) o->w78->flags |= 2;
            Slider_341C50(o, o->w78, 10, (int)((100.0f / (float)(o->count - 1)) * (float)o->pos), 0);
            if (o->w7C) {
                if (o->count) {
                    sprintf(buf, D_004B9F70, o->pos + 1, o->count);
                    GuiTextWidget_SetText(o->w7C, buf, 0);
                } else {
                    GuiTextWidget_SetText(o->w7C, D_004B9F78, 0);
                }
            }
        } else {
            o->count = 0;
            o->pos = 0;
            if (o->w78) o->w78->flags &= ~2;
            if (o->w7C) GuiTextWidget_SetText(o->w7C, D_004B9F20, 0);
        }
    }
}