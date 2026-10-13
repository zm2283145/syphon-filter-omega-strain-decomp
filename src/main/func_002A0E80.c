#include "types.h"
extern void* D_004FFC04;
extern char D_004AAFF0[];
extern char* D_005064B8;
extern int D_005064B0;
extern unsigned char D_005064A8;
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
