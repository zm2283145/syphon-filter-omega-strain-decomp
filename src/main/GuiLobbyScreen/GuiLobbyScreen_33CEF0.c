/*
 * main/GuiLobbyScreen: range (2 files, 0033CEF0-0033CF90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0033CEF0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0033C320(int, int);                                 
extern int D_00532FD0;

int GuiScreen_HandleInput(int arg0, int arg1) {
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
            func_0033C320(arg0, 9);
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
extern char D_004B99D8[];
extern void *DME_GetLobby(void);
extern int func_0033D0C0(O *o, void *snd, unsigned short msg, int param, int extra);
extern char *func_0033CE30(O *o, unsigned char a, char *b, char *c, int d, int e);
extern int FrontEnd_OpenPopup(void *ui, int a, char *b, char *c, void *d, int e);
extern int func_00449770(void *p);
extern void FrontEnd_ClosePopup(void *ui, int id);
extern int func_00441CA0(O *o, void *snd, unsigned short msg, int param, int extra);

int GuiScreen_HandleEvent(O *o, void *snd, unsigned short msg, int param, int extra)
{
    if (msg == 0x2000) {
        func_0033D0C0(o, snd, msg, param, extra);
        return 1;
    }
    if (param == 0x13) {
        void *owner = DME_GetLobby();
        if (owner) {
            void *ui = D_004FFC04;
            int id = FrontEnd_OpenPopup(ui, 0, D_004B99D8, func_0033CE30(o, 0x56, 0, 0, 0, 0), 0, 0);
            if (!func_00449770(owner)) {
                ui = D_004FFC04;
                FrontEnd_OpenPopup(ui, 2, D_004B99D8, func_0033CE30(o, 0x57, 0, 0, 0, 0), 0, 0);
            }
            FrontEnd_ClosePopup(D_004FFC04, id);
        }
        return 1;
    }
    return func_00441CA0(o, snd, msg, param, extra);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033CF90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0033CF90 */
