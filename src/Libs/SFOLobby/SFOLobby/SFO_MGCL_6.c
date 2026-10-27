/*
 * Libs/SFOLobby/SFOLobby/SFO_MGCL: 1 file, 00445260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00445260 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(char *, char *);                            
extern char D_00584220;
extern signed char D_00584235;
extern signed char D_00584236;
extern char D_00584378;

void Callback_MGCLServerSessionBegin(int d0, int d1, int d2, char * arg3) {
    D_00584235 = 1;
    if (F_(arg3, 0x15, signed char) == 0) {
        Libc_Strcpy(&D_00584220, arg3 + 0x90);
        Libc_Strcpy(&D_00584378, &D_00584220);
        D_00584236 = 1;
        return;
    }
    D_00584236 = 0;
}
static inline void merge_flush_func_00445260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00445260 */
