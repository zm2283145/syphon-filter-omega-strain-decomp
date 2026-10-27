/*
 * main/GuiLobbyScreen: 3 files, 0033CE30-0033CEF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiLobbyScreen_33CE30 */
#pragma push /* merge_units */
#include "types.h"
extern void* D_00532FE0;
extern char D_004B99D8[];
extern int sprintf(char*, const char*, ...);
extern char* nGlobalization_GetString_charP(char*);
extern void FormatString(void*, char*, char*, char*, int, int);
extern char* std_basic_string_char_char_traits_char_c_str(void*);
char* GuiLobbyScreen_GetLobbyString(void* self, unsigned char id, char* a, char* b, int c, int d) {
    char buf[16];
    char* t;
    if (!D_00532FE0) return D_004B99D8;
    sprintf(buf, "LOBBY_STR%d", id);
    t = nGlobalization_GetString_charP(buf);
    if (!t) return D_004B99D8;
    FormatString(D_00532FE0, t, a, b, c, d);
    return std_basic_string_char_char_traits_char_c_str(D_00532FE0);
}
#pragma pop /* merge_units */
/* merge_units: end GuiLobbyScreen_33CE30 */

/* merge_units: begin func_0033CEF0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int GuiLobbyScreen_PushLobbyScreen(int, int);                                 
extern int D_00532FD0;

int GuiLobbyScreen_onInput(int arg0, int arg1) {
    int var_v0;

    if (F_(arg0, 0x78, unsigned char) != 0) {
        var_v0 = F_(arg1, 0x0, unsigned short) == 1;
        var_v0 = var_v0 ? F_(arg1, 0x2, unsigned short) == 0 : var_v0;
        if (var_v0 != 0) {
            var_v0 = F_(arg1, 0x8, unsigned short) == 0x800;
        }
        var_v0 = var_v0 ? F_(arg1, 0x6, unsigned short) == 0 : var_v0;
        if (var_v0 != 0) {
            D_00532FD0 = F_(arg0, 0x84, int);
            GuiLobbyScreen_PushLobbyScreen(arg0, 9);
            return 1;
        }
        goto block_9;
    }
block_9:
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033CEF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0033CEF0 */

/* merge_units: begin func_0033CF90 */
#pragma push /* merge_units */
typedef struct O O;
extern void *D_004FFC04;
extern void *cDME_GetLobby(void);
extern int func_0033D0C0(O *o, void *snd, unsigned short msg, int param, int extra);
#if 0 /* merge_units */
extern char *GuiLobbyScreen_GetLobbyString(O *o, unsigned char a, char *b, char *c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((void *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

extern int cGameFrontEnd_PushMessageBox(void *ui, int a, char *b, char *c, void *d, int e);
extern int SFOLobby_CellRevokeAllInvites(void *p);
extern void cGameFrontEnd_PopMessageBox(void *ui, int id);
extern int GuiSaveAgentWidget_OnEvent(O *o, void *snd, unsigned short msg, int param, int extra);

int GuiLobbyScreen_onMessage(O *o, void *snd, unsigned short msg, int param, int extra)
{
    if (msg == 0x2000) {
        func_0033D0C0(o, snd, msg, param, extra);
        return 1;
    }
    if (param == 0x13) {
        void *owner = cDME_GetLobby();
        if (owner) {
            void *ui = D_004FFC04;
            int id = cGameFrontEnd_PushMessageBox(ui, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(o, 0x56, 0, 0, 0, 0), 0, 0);
            if (!SFOLobby_CellRevokeAllInvites(owner)) {
                ui = D_004FFC04;
                cGameFrontEnd_PushMessageBox(ui, 2, D_004B99D8, GuiLobbyScreen_GetLobbyString(o, 0x57, 0, 0, 0, 0), 0, 0);
            }
            cGameFrontEnd_PopMessageBox(D_004FFC04, id);
        }
        return 1;
    }
    return GuiSaveAgentWidget_OnEvent(o, snd, msg, param, extra);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033CF90(void) {}
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033CF90 */
