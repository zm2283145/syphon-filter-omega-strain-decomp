/* GuiAgentModify_UserInterface: step the selected part option (texture / mesh / colour / patch) back or
 * forward and refresh the slider and counter text; same shape as GuiAgentCreate_UserInterface. */
#include "types.h"

typedef struct { __int128 a; __int128 b; } Ent_1330;
typedef struct {
    char pad0[0x40];
    char app[0x40];             /* +0x40 */
    Ent_1330 e[0xF2];           /* +0x80 */
    char x1EC0[0x500];          /* +0x1EC0 */
    unsigned short count;       /* +0x23C0 */
    char pad23C2[0x2C0D - 0x23C2];
    signed char tone;           /* +0x2C0D */
} Skel_1330;
typedef struct { char pad[0x60]; Skel_1330 skel; } Tbl_1330;
typedef struct { char pad[0x14]; unsigned short flags; } W_1330;
typedef struct { short pos; char pad[2]; } Tab_1330;
typedef struct {
    char pad0[0x78];
    W_1330* w78;            /* +0x78 */
    W_1330* w7C;            /* +0x7C */
    char pad80[0x8C - 0x80];
    Tbl_1330* tbl;          /* +0x8C */
    char pad90[0xE4 - 0x90];
    int count;              /* +0xE4 */
    int pos;                /* +0xE8 */
    int fEC;                /* +0xEC */
    char padF0[0xF8 - 0xF0];
    int row;                /* +0xF8 */
    int tone;               /* +0xFC */
    int vE0;                /* +0x100 */
    int vE4;                /* +0x104 */
    char pad108[0x10D - 0x108];
    signed char slot;       /* +0x10D */
    signed char mode;       /* +0x10E */
    signed char cur;        /* +0x10F */
    char pad110[0x158 - 0x110];
    unsigned char b158;     /* +0x158 */
} S_1330;

extern char g_AgentPartCache[];
extern char D_004B9F70[];
extern char D_004B9F78[];
extern __int128* D_0048B460;
extern Tab_1330 D_00492A02[];

extern int sprintf(char* buf, const char* fmt, ...);
extern void* Gui_Canvas(void);
extern void GuiTextWidget_SetText(W_1330* w, char* text, int flags);
extern void GuiWidget_SendMessage(S_1330* o, void* w, int kind, int v, int f);
extern void GuiAgentModify_TattooPatchesLockout(S_1330* self);
extern int Monster_FindNextPart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
extern int Monster_FindNextSamePart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
extern int FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, unsigned int tone, void* app, void* x);
extern int FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, unsigned int tone, void* app, void* x);
extern int AgentPacking_StepTexture(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, int tone, void* app, void* x);
extern int FindTextureNumber__7MonsterF1(void* db, __int128 key);

static inline void Slider_1330(S_1330* o, W_1330* w, int kind, int v, int f)
{
    if (w) GuiWidget_SendMessage(o, w, kind, v, f);
}

void GuiAgentModify_UserInterface(S_1330* self, int back, int fwd)
{
    int dir = 1;
    if ((back || fwd) && self->cur < 16 && self->count) {
        int old;
        int v;
        char buf[0x10];
        self->b158 = 1;
        if (back) dir = -1;
        if (self->mode == 3) {
            Skel_1330* s = &self->tbl->skel;
            int r = AgentPacking_StepTexture(g_AgentPartCache, dir, s->e[self->slot].a, s->e[self->slot].b, self->vE4, self->slot, self->row, self->tone, s->app, s->x1EC0);
            if ((dir == 1 && !(self->vE4 < r)) || (dir == -1 && !(r < self->vE4))) {
                int m;
                s = &self->tbl->skel;
                m = Monster_FindNextPart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, s->tone, s->app, s->x1EC0);
                if (m != -1) {
                    self->vE0 = m;
                    self->vE4 = -1;
                    {
                        Skel_1330* t = &self->tbl->skel;
                        self->vE4 = AgentPacking_StepTexture(g_AgentPartCache, dir, t->e[self->slot].a, t->e[self->slot].b, self->vE4, self->slot, self->row, self->tone, t->app, t->x1EC0);
                    }
                }
            } else {
                self->vE4 = r;
            }
        } else if (self->mode == 0) {
            Skel_1330* s = &self->tbl->skel;
            int r = Monster_FindNextPart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, s->tone, s->app, s->x1EC0);
            if (r != -1) {
                self->vE0 = r;
                self->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].b);
            }
        } else if (self->mode == 4) {
            Skel_1330* s = &self->tbl->skel;
            int r = Monster_FindNextSamePart(g_AgentPartCache, dir, s->e[self->slot].a, self->vE0, self->slot, self->row, s->tone, s->app, s->x1EC0);
            if (r != -1) {
                self->vE0 = r;
                self->vE4 = FindTextureNumber__7MonsterF1(g_AgentPartCache, self->tbl->skel.e[self->slot].b);
            }
        } else if (self->mode == 1) {
            int slot = self->slot;
            int r;
            Skel_1330* s = &self->tbl->skel;
            if (slot < s->count) {
                if (self->count > 1)
                    r = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, s->e[slot].a, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
                else
                    r = -1;
            } else {
                r = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, *D_0048B460, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
            }
            if (r != -1)
                self->vE4 = r;
        } else if (self->mode == 2) {
            int slot = self->slot;
            int r;
            Skel_1330* s = &self->tbl->skel;
            if (slot < s->count) {
                if (self->count > 1)
                    r = FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, s->e[slot].a, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
                else
                    r = -1;
            } else {
                r = FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, *D_0048B460, s->e[slot].b, self->vE4, slot, self->row, s->tone, s->app, s->x1EC0);
            }
            if (r != -1)
                self->vE4 = r;
        } else if (self->mode == 5) {
            Skel_1330* s = &self->tbl->skel;
            int r = AgentPacking_StepTexture(g_AgentPartCache, dir, s->e[self->slot].a, s->e[self->slot].b, self->vE4, self->slot, self->row, self->tone, s->app, s->x1EC0);
            if (r != -1)
                self->vE4 = r;
        }
        old = self->pos;
        self->pos = old + dir;
        if (self->pos < 0) self->pos = self->count - 1;
        if (self->pos < 0) self->pos = 0;
        if (self->pos >= self->count) self->pos = 0;
        if (self->pos != old)
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 6, 0);
        D_00492A02[self->cur].pos = self->pos;
        v = (int)((100.0f / (float)(self->count - 1)) * (float)self->pos);
        Slider_1330(self, self->w78, 10, v, 0);
        if (self->w7C) {
            if (self->count) {
                sprintf(buf, D_004B9F70, self->pos + 1, self->count);
                GuiTextWidget_SetText(self->w7C, buf, 0);
            } else {
                GuiTextWidget_SetText(self->w7C, D_004B9F78, 0);
            }
        }
        if (self->fEC == 2)
            GuiAgentModify_TattooPatchesLockout(self);
    }
}
