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
void func_0043C810(W_0320* w);
void GuiBitmapWidget_SetImage(W_0320* w, char* name, int x);
void GuiTextWidget_SetText(W_0320* w, char* s, int x);
char* String_Copy(char* d, const char* s);
int String_CompareN(const char* a, const char* b, int n);
char* Libc_Strcat(char* d, const char* s);
void* Agent_GetSelected(void* a, int b);
void AgentData_GetAwardRows(void* ag, unsigned char k, Rel_0320* r);
void AgentData_GetRatings(void* ag, Rel_0320* r);
void func_00296FA0(Rel_0320* r);
void func_00299360(Rel_0320* r, int f);
int Loc_FindKeyThunk(char* k);
char* Loc_GetTextById(int id);
void GuiAgentModify_ShowPatch(Self_0320* self);
}

extern "C" void GuiAgentModify_ShowPatch(Self_0320* self)
{
    char buf[0x20];
    char name[0x20];
    int a;
    int b;
    int c;
    if (self->fF0) {
        if (self->f80) {
            func_0043C810(self->f80);
            self->f80->flags &= ~2;
        }
        if (self->f84) {
            GuiTextWidget_SetText(self->f84, D_004B9F20, 0);
            self->f84->flags &= ~2;
        }
    } else {
        if (self->f80)
            func_0043C810(self->f80);
        a = -1;
        b = a;
        c = a;
        String_Copy(buf, ((char(*)[0x20])((char*)self->f8C + 0xF0))[self->b10D]);
        if (!String_CompareN(&buf[6], D_004B9F28, 3) && buf[10] != 'B') {
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
            }            String_Copy(name, buf);
            Libc_Strcat(name, D_004B9F30);
            if (self->f80)
                GuiBitmapWidget_SetImage(self->f80, name, D_004FFC04->x25C);
        } else {
            String_Copy(name, buf);
            Libc_Strcat(name, D_004B9F30);
            if (self->f80)
                GuiBitmapWidget_SetImage(self->f80, name, 0);
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
                    AgentData_GetAwardRows(Agent_GetSelected(g_Game, -1), b, &r);
                    if (c < r.count)
                        txt = r.data[c].str;
                } else if (b == 3) {
                    AgentData_GetRatings(Agent_GetSelected(g_Game, -1), &r);
                    if (c < r.count)
                        txt = r.data[c].str;
                } else if (b == 6) {
                    txt = Loc_GetTextById(c + Loc_FindKeyThunk(D_004B9F38));
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