/*
 * main/GuiOnlineOfflineSelect: 2 files, 002A0DC0-002A0E80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A0DC0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Agent_GetSelected(char *, int, int, signed char);               
int func_00332A10(int, int, int, int);                    
const unsigned int D_004ACB30[12] = { 0x0, 0x1, 0x2, 0x4, 0x5, 0x8, 0xC, 0xD, 0x10, 0x0, 0x0, 0x0 };
extern char D_004FFB50;
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;
extern char * D_004FFC04;
extern signed char D_005064A8;
extern int D_005064B0;
extern int D_005064B8;

void func_002A0DC0(void) {
    int temp_s0;
    signed char temp_a3;

    temp_a3 = D_004FFBA0;
    D_004FFBA1 = temp_a3;
    D_004FFBA0 = 3;
    F_(D_004FFC04, 0x35, signed char) = 1;
    F_(D_004FFC04, 0x33, signed char) = 1;
    temp_s0 = F_(D_004FFC04, 0x248, int);
    if (temp_s0 != -1) {
        func_00332A10(Agent_GetSelected(&D_004FFB50, -1, 3, temp_a3), F_(&(*(char*)D_004ACB30), (temp_s0 * 4), int) + 1, 6, 1);
    }
    D_005064A8 = 0;
    D_005064B0 = 0;
    D_005064B8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0DC0 */

/* merge_units: begin func_002A0E80 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */

extern char D_004AAFF0[];
#if 0 /* merge_units */
extern char* D_005064B8;
#endif /* merge_units */
#define D_005064B8 (*(char **)&D_005064B8) /* merge_units */

#if 0 /* merge_units */
extern unsigned char D_005064A8;
#endif /* merge_units */
#define D_005064A8 (*(unsigned char*)&D_005064A8) /* merge_units */

extern char* func_0033CE30(void* self, int id, int a, int b, int c, int d);
extern char* Loc_LookupText(char* key);
extern void FrontEnd_OpenPopup(void* gui, int kind, char* title, char* text, int a, int b);
extern void func_0042B1F0(void);

static inline unsigned char Nz2A0E80(int v) { return v != 0; }
/* Shows the pending message box (built-in text or a looked-up key) and clears the request. */
void func_002A0E80(void* self, int builtin)
{
    void* g;
    if (builtin) {
        g = D_004FFC04;
        FrontEnd_OpenPopup(g, 2, D_004AAFF0, func_0033CE30(self, 0x59, 0, 0, 0, 0), 0, 0);
    } else {
        g = D_004FFC04;
        FrontEnd_OpenPopup(g, 2, D_004AAFF0, Loc_LookupText(D_005064B8), 0, 0);
    }
    if (Nz2A0E80(D_005064B0) == 1) func_0042B1F0();
    D_005064A8 = 0;
    D_005064B0 = 0;
    D_005064B8 = 0;
}
#undef D_004FFC04 /* merge_units */
#undef D_005064B8 /* merge_units */
#undef D_005064A8 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A0E80 */
