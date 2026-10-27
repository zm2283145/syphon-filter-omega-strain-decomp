/*
 * SFOGame/Source/Checkpoint: 1 file, 0022E080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022E080 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cMessage_ctor_cMessageNameR(char **, char *);                       
int QueueMessage_cMessageR_cSystemP_int(char **, int, int);                         
int cMemMan_Allocate(int, int, char *, int);                      
int Libc_Strcpy(int, int);                              
int cMessage_dtor(char **, int);                           
int strlen(int);                                      
extern char D_004A6698;
extern char D_004DB8D0;
extern char D_004F7930;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void Global_SetCheckpoint(char * arg0, int arg1, int arg2) {
    struct { char * f50[9]; int f74; int f78[2]; } sl;
    int temp_s0;
    int temp_s0_2;

    temp_s0 = strlen(arg2) + 1;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s0_2 = cMemMan_Allocate(0, temp_s0, &D_004A6698, 0x1D6);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    Libc_Strcpy(temp_s0_2, arg2);
    cMessage_ctor_cMessageNameR(sl.f50, &D_004F7930);
    sl.f74 = arg1;
    sl.f78[0] = temp_s0_2;
    sl.f50[0] = &D_004DB8D0;
    QueueMessage_cMessageR_cSystemP_int(sl.f50, F_(arg0, 0x30, int), 0);
    sl.f50[0] = &D_004DB8D0;
    cMessage_dtor(sl.f50, 0);
}
static inline void merge_flush_func_0022E080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022E080 */
