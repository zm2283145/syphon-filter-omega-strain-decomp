/*
 * Libs/SFOLib/Source/GenInfoObject: 1 file, 00439560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00439560 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cMemMan_Deallocate(int, int, char *, int);                         
int NetGetObject(void **, int);                    
unsigned int D_00497578[2] = { 0xFFFFFFFF, 0x0 };
extern char D_004BFD60;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char D_005723C8;
extern signed char D_00583880;
extern int D_00583888;

void cGenInfoObject_GenInfoCreationCallback(int d0, int arg1) {
    char * sp38[2];
    int temp_s1;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (NetGetObject((void **)sp38, arg1) == 0) {
        temp_s1 = D_00583888;
        if (temp_s1 != 0) {
            if (g_ProfileLockEnabled != 0) {
                Alloc_Lock(9);
            }
            g_ProfileLockDepth += 1;
            cMemMan_Deallocate(0, temp_s1, &D_004BFD60, 0x234);
            if (g_ProfileLockEnabled != 0) {
                EnableIntc(9);
            }
            g_ProfileLockDepth -= 1;
        }
        D_00583888 = F_(sp38[0], 0x1C, int);
        D_00583880 = 1;
        (*(int*)D_00497578) = arg1;
    }
    D_005723C8 = 0;
}
static inline void merge_flush_func_00439560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00439560 */
