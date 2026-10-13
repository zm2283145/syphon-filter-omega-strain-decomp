#pragma cplusplus on
#include "types.h"
struct Ui_00465610 { char pad[0x33]; unsigned char f33; char pad34; unsigned char f35; };
extern "C" {
extern Ui_00465610* D_004FFC04;
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;
extern unsigned char D_00587B38;
extern char D_004C2988[];
extern char D_00586AF0[];
extern char D_00586C90[];
extern char D_00586E30[];
extern char D_00586FD0[];
extern char D_00587170[];
char* Loc_LookupText(int key);
int func_002CAE30(void* ui, int a, char* b, char* c, void* d, int e);
int func_0041DF00(void* self, int message, int first, int second);
int func_00465A50(void* self, void* sender, int message, int first, int second);
int func_00465B50(void* sender, char* tbl, int message);
int func_00465C50(void* sender, char* tbl, int message);
}
extern "C" int func_00465610(void* self, void* sender, int message, int first, int second)
{
    unsigned short m = message;
    if (m == 0x1E) {
        if (!func_0041DF00(self, message, first, second)) {
            if ((first != 0) == 1) {
                D_004FFBA1 = D_004FFBA0;
                D_004FFBA0 = 3;
            } else {
                D_004FFC04->f35 = 0;
                D_004FFC04->f33 = 0;
                { Ui_00465610* ui = D_004FFC04; func_002CAE30(ui, 2, D_004C2988, Loc_LookupText(second), 0, 0); }
            }
        }
        return 1;
    }
    if (m == 0x10 || m == 0x11) {
        char* tbl;
        if (D_00587B38)
            return 1;
        tbl = 0;
        switch (first) {
        case 5: tbl = D_00586AF0; break;
        case 6: tbl = D_00586C90; break;
        case 7: tbl = D_00586E30; break;
        case 8: tbl = D_00586FD0; break;
        case 9: tbl = D_00587170; break;
        }
        if (tbl) {
            if (m == 0x10)
                return func_00465C50(sender, tbl, message);
            else
                return func_00465B50(sender, tbl, message);
        }
    }
    return func_00465A50(self, sender, message, first, second);
}

