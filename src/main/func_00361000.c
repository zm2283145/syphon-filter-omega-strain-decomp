/* GuiAgentInfo_SetupWidgets: fill the agent score sheet (name, team, rank, ratings and award columns, stats
 * table, rank badge, online buttons). */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct W_1000 { char p0[0x14]; unsigned short flags; };
class Wid_1000 {
public:
    VPAD16(a) VPAD4(b) virtual int IsA(void* type); virtual void SetCols(int n, int h);
};
struct Rec_1000 { int x0; int key; char p8[0xC]; };
struct Vec_1000 { int x0; int count; Rec_1000* data; unsigned char own; char pD[3]; };
struct Fe_1000 { char p0[0x25C]; int img; };
struct Self_1000 {
    char p0[0x88];
    int vals[12];               /* +0x88 */
    char strB8[0xC];            /* +0xB8 */
    char strC4[0xC];            /* +0xC4 */
    int rank;                   /* +0xD0 */
    unsigned char flags[6][4];  /* +0xD4 */
    unsigned char award[8];     /* +0xEC */
    unsigned char bF4;          /* +0xF4 */
    char pF5[3];
    int xF8;                    /* +0xF8 */
    int team;                   /* +0xFC */
    W_1000* w100;               /* +0x100 */
    W_1000* w104;               /* +0x104 */
    W_1000* w108;               /* +0x108 */
    Wid_1000* w10C;             /* +0x10C */
    Wid_1000* w110;             /* +0x110 */
    W_1000* w114;               /* +0x114 */
    W_1000* w118;               /* +0x118 */
    void* w11C;                 /* +0x11C */
};

extern "C" {
extern char g_Game[];
extern Fe_1000* D_004FFC04;
extern char D_004BB868[], D_004BB8B0[], D_004BB8C0[], D_004BB8D0[], D_004BB8E0[], D_004BB8F0[], D_004BB8F8[];
extern char D_004BB908[], D_004BB910[], D_004BB920[], D_004BB928[], D_004BB930[], D_004BB940[], D_004BB948[];
extern char D_004A7520[];
extern char D_00587BE0[], D_00587BD0[];
void* cGameSystem_GetAgentData(void* a, int b);
char* std_basic_string_char_char_traits_char_c_str(void* str);
void GuiTextWidget_SetText(void* w, char* text, int flags);
char* nGlobalization_GetString_charP(char* key);
char* nGlobalization_GetStringTag(int key);
int sprintf(char* buf, const char* fmt, ...);
Wid_1000* GuiWidget_FindChild_charP(void* self, char* name);
void GuiTextArrayWidget_SetTextFormat(Wid_1000* w, int a);
void GuiArrayWidget_SetColumnWidth(Wid_1000* w, int col, int width);
void GuiTextArrayWidget_SetText(Wid_1000* w, int col, int row, char* text);
void GuiTextArrayWidget_SetElementTextColor(Wid_1000* w, int col, int row, char* colour);
void GuiTextArrayWidget_SetElementTextFormat(Wid_1000* w, int col, int row, int align);
void func_00296FA0(Vec_1000* v);
void func_00299360(Vec_1000* v, int f);
void cAgentData_GetRatings(void* ag, Vec_1000* v);
void cAgentData_GetAchievements(void* ag, int a, Vec_1000* v);
void GuiBitmapWidget_SetBitmap(void* w, char* name, int img);
void* cDME_GetLobby(void);
int SFOLobby_CellContainsAgent(void* lb, int id, int f);
int SFOLobby_ContactListContainsAgent(void* lb, int id, int f);
void GuiAgentInfo_SetupWidgets(Self_1000* self);
}

extern "C" void GuiAgentInfo_SetupWidgets(Self_1000* self)
{
    void* ag = cGameSystem_GetAgentData(g_Game, -1);
    char buf[0x10];
    char* t;
    GuiTextWidget_SetText(self->w100, std_basic_string_char_char_traits_char_c_str(self->strB8), 0);
    t = std_basic_string_char_char_traits_char_c_str(self->strC4);
    if (!t || !*t)
        t = nGlobalization_GetString_charP(D_004BB8B0);
    GuiTextWidget_SetText(self->w108, t ? t : D_004BB868, 0);
    sprintf(buf, D_004BB8C0, self->rank + 1);
    t = nGlobalization_GetString_charP(buf);
    GuiTextWidget_SetText(self->w104, t ? t : D_004BB868, 0);
    {
        Wid_1000* c = GuiWidget_FindChild_charP(self, D_004BB8D0);
        c = (c && c->IsA(D_004A7520)) ? c : 0;
        if (c)
            GuiTextWidget_SetText(c, nGlobalization_GetString_charP(self->team == 1 ? D_004BB8E0 : D_004BB8F0), 0);
    }
    self->w10C->SetCols(2, 8);
    GuiTextArrayWidget_SetTextFormat(self->w10C, 2);
    GuiArrayWidget_SetColumnWidth(self->w10C, 0, 0x70);
    GuiArrayWidget_SetColumnWidth(self->w10C, 1, 10);
    {
        Vec_1000 r;
        int j;
        int i;
        func_00296FA0(&r);
        r.own = 1;
        cAgentData_GetRatings(cGameSystem_GetAgentData(g_Game, -1), &r);
        j = 0;
        for (i = 0; i < 6; i++) {
            char line[0x20];
            int idx = -1;
            int k;
            char* s;
            for (k = 0; k < 4; k++, j++) {
                if (self->flags[i][k]) idx = j;
            }
            if (idx == -1) {
                s = nGlobalization_GetString_charP(D_004BB8F8);
            } else {
                sprintf(line, D_004BB908, nGlobalization_GetStringTag(r.data[idx].key));
                s = nGlobalization_GetString_charP(line);
            }
            GuiTextArrayWidget_SetText(self->w10C, 0, i, s);
        }
        {
            Vec_1000 a;
            func_00296FA0(&a);
            a.own = 1;
            cAgentData_GetAchievements(ag, 0, &a);
            int n;
            for (n = 0; n < a.count && n < 8; n++) {
                if (self->award[n]) {
                    char line[0x20];
                    sprintf(line, D_004BB908, nGlobalization_GetStringTag(((Rec_1000*)((char*)a.data + n * sizeof(Rec_1000)))->key));
                    GuiTextArrayWidget_SetText(self->w10C, 1, n, nGlobalization_GetString_charP(line));
                }
            }
            func_00299360(&a, 0);
        }
        func_00299360(&r, 0);
    }
    self->w110->SetCols(2, 0xC);
    GuiArrayWidget_SetColumnWidth(self->w110, 0, 0xA0);
    GuiArrayWidget_SetColumnWidth(self->w110, 1, 10);
    {
        int i;
        for (i = 0; i < 12; i++) {
            char line[0x20];
            sprintf(line, D_004BB910, i);
            GuiTextArrayWidget_SetText(self->w110, 0, i, nGlobalization_GetString_charP(line));
            if (i == 6 || i == 7)
                sprintf(line, D_004BB920, self->vals[i]);
            else
                sprintf(line, D_004BB928, self->vals[i]);
            GuiTextArrayWidget_SetText(self->w110, 1, i, line);
            GuiTextArrayWidget_SetElementTextColor(self->w110, 0, i, D_00587BE0);
            GuiTextArrayWidget_SetElementTextFormat(self->w110, 0, i, 2);
            GuiTextArrayWidget_SetElementTextColor(self->w110, 1, i, D_00587BD0);
            GuiTextArrayWidget_SetElementTextFormat(self->w110, 1, i, 1);
        }
    }
    {
        char line[0x20];
        W_1000* b1;
        W_1000* b2;
        sprintf(line, D_004BB930, self->rank + 1);
        GuiBitmapWidget_SetBitmap(self->w11C, line, D_004FFC04->img);
        b1 = (W_1000*)GuiWidget_FindChild_charP(self, D_004BB940);
        b2 = (W_1000*)GuiWidget_FindChild_charP(self, D_004BB948);
        if (b1) {
            if (self->team == 1) b1->flags |= 2;
            else b1->flags &= ~2;
        }
        if (b2) {
            if (self->team == 1) b2->flags |= 2;
            else b2->flags &= ~2;
        }
    }
    if (self->team == 1) {
        void* lb;
        self->w114->flags |= 2;
        self->w118->flags |= 2;
        lb = cDME_GetLobby();
        if (!lb || self->xF8 == -1) {
            self->w118->flags &= ~4;
            self->w114->flags &= ~4;
        } else {
            unsigned char ok;
            if (self->bF4) {
                ok = !SFOLobby_CellContainsAgent(lb, self->xF8, 1);
                {
                    W_1000* w = self->w118;
                    if (ok) w->flags |= 4;
                    else w->flags &= ~4;
                }
            } else {
                self->w118->flags &= ~4;
            }
            ok = !SFOLobby_ContactListContainsAgent(lb, self->xF8, 1);
            {
                W_1000* w = self->w114;
                if (ok) w->flags |= 4;
                else w->flags &= ~4;
            }
        }
    } else {
        self->w114->flags &= ~2;
        self->w118->flags &= ~2;
    }
}
