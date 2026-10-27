/*
 * SFOGame/Source/GuiAgentModify: 1 file, 00340320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00340320 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct W_0320 { char pad[0x14]; unsigned short flags; };
struct Npc_0320 { char pad[0xF0]; char names[1][0x20]; };
struct Ent_0320 { char* str; char pad[0x10]; };
struct Rel_0320 { int a0; int count; Ent_0320* data; unsigned char own; char pad[3]; };
struct Opts_0320 { char pad[0x25C]; int x25C; };
struct Self_0320 {
    char pad0[0x80];
    W_0320* f80;
    W_0320* f84;
    char pad88[4];
    Npc_0320* f8C;
    char pad90[0xF0 - 0x90];
    int fF0;
    char padF4[0x10D - 0xF4];
    signed char b10D;
};
extern "C" {
extern char D_004B9F20[];
extern char D_004B9F28[];
extern char D_004B9F30[];
extern char D_004B9F38[];
extern char D_004B9F40[];
extern char g_Game[];
extern Opts_0320* D_004FFC04;
void GuiBitmapWidget_ClearBitmap(W_0320* w);
void GuiBitmapWidget_SetBitmap(W_0320* w, char* name, int x);
void GuiTextWidget_SetText(W_0320* w, char* s, int x);
char* Libc_Strcpy(char* d, const char* s);
int Libc_Strncmp(const char* a, const char* b, int n);
char* Libc_Strcat(char* d, const char* s);
void* cGameSystem_GetAgentData(void* a, int b);
void cAgentData_GetAchievements(void* ag, unsigned char k, Rel_0320* r);
void cAgentData_GetRatings(void* ag, Rel_0320* r);
void func_00296FA0(Rel_0320* r);
void func_00299360(Rel_0320* r, int f);
int nGlobalization_GetStringIndex(char* k);
char* nGlobalization_GetString_int(int id);
void GuiAgentModify_SetBigPatch(Self_0320* self);
}

extern "C" void GuiAgentModify_SetBigPatch(Self_0320* self)
{
    char buf[0x20];
    char name[0x20];
    int a;
    int b;
    int c;
    if (self->fF0) {
        if (self->f80) {
            GuiBitmapWidget_ClearBitmap(self->f80);
            self->f80->flags &= ~2;
        }
        if (self->f84) {
            GuiTextWidget_SetText(self->f84, D_004B9F20, 0);
            self->f84->flags &= ~2;
        }
    } else {
        if (self->f80)
            GuiBitmapWidget_ClearBitmap(self->f80);
        a = -1;
        b = a;
        c = a;
        Libc_Strcpy(buf, ((char(*)[0x20])((char*)self->f8C + 0xF0))[self->b10D]);
        if (!Libc_Strncmp(&buf[6], D_004B9F28, 3) && buf[10] != 'B') {
            a = buf[10] - '0';
            buf[0] = buf[10];
            buf[1] = '_';
            b = buf[11] - '0';
            buf[2] = buf[11];
            buf[3] = '_';
            buf[4] = buf[12];
            if (buf[13] >= '0' && buf[13] <= '9') {
                c = (buf[12] - '0') * 10;
                c += buf[13] - '1';
                buf[5] = buf[13];
                buf[6] = 's';
                buf[7] = 0;
            } else {
                c = buf[12] - '1';
                buf[5] = 's';
                buf[6] = 0;
            }            Libc_Strcpy(name, buf);
            Libc_Strcat(name, D_004B9F30);
            if (self->f80)
                GuiBitmapWidget_SetBitmap(self->f80, name, D_004FFC04->x25C);
        } else {
            Libc_Strcpy(name, buf);
            Libc_Strcat(name, D_004B9F30);
            if (self->f80)
                GuiBitmapWidget_SetBitmap(self->f80, name, 0);
        }
        if (self->f80)
            self->f80->flags |= 2;
        if (self->f84) {
            if (a != -1) {
                Rel_0320 r;
                char* txt;
                func_00296FA0(&r);
                r.own = 1;
                txt = 0;
                if (b == 2 || b == 4 || (b == 3 && c >= 25)) {
                    if (b == 3) {
                        b = 0;
                        c -= 25;
                    } else if (b == 4) {
                        b = 1;
                    }
                    cAgentData_GetAchievements(cGameSystem_GetAgentData(g_Game, -1), b, &r);
                    if (c < r.count)
                        txt = r.data[c].str;
                } else if (b == 3) {
                    cAgentData_GetRatings(cGameSystem_GetAgentData(g_Game, -1), &r);
                    if (c < r.count)
                        txt = r.data[c].str;
                } else if (b == 6) {
                    txt = nGlobalization_GetString_int(c + nGlobalization_GetStringIndex(D_004B9F38));
                }
                if (txt)
                    GuiTextWidget_SetText(self->f84, txt, 0);
                else
                    GuiTextWidget_SetText(self->f84, D_004B9F40, 0);
                self->f84->flags |= 2;
                func_00299360(&r, 0);
            } else {
                GuiTextWidget_SetText(self->f84, D_004B9F20, 0);
                self->f84->flags &= ~2;
            }
        }
    }
}
static inline void merge_flush_func_00340320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00340320 */
