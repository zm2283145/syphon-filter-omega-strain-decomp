#include "types.h"
typedef struct CxRouteSearch { char pad[0x10]; unsigned char state; } CxRouteSearch;
extern char D_004ED9F0[];
extern unsigned char D_004ED9FD;
extern int D_004EDE68;
extern unsigned int D_004EE010;
extern int D_004EE014[];
extern void func_00161DB0(void*, unsigned char*);
extern void func_00163410(CxRouteSearch*, int);

void func_00163580(CxRouteSearch* self, unsigned char* blocked) {
    unsigned char state = self->state;
    if (state == 2) {
        D_004ED9FD = 0;
        D_004EDE68 = (unsigned char)!*blocked;
    } else if (state == 0) {
        func_00161DB0(D_004ED9F0, blocked);
        if (D_004EDE68 >= 0) {
            func_00163410(self, D_004EDE68);
            D_004EDE68 = -1;
        }
    } else if (state == 1) {
        func_00161DB0(D_004ED9F0, blocked);
        if (D_004EDE68 >= 0) {
            if (D_004EE010 < 64) {
                D_004EE014[D_004EE010] = D_004EDE68;
                D_004EE010++;
            }
            D_004EDE68 = -1;
        }
    }
}
