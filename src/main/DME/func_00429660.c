#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);
int Alloc_Unlock(int);
char * Mem_Alloc(int, int, char *, int);
int PtrVec_PushBack_429770(char *, void **);
int strncpy(char * , int, int);
extern char D_004BF9B0; /* "DME.cc" */
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char D_005723C8;
extern char D_005724A0; /* game address list (NetworkGameList) */

#pragma push
#pragma opt_common_subs off
/* Appends a { char name[16]; int value; } entry to the game address list. */
void DME_AddGameAddress(int name, int value) {
    struct { char pad40[8]; char * f48[2]; } sl;
    char * entry;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    entry = Mem_Alloc(0, 0x14, &D_004BF9B0, 0x72F);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Unlock(9);
    }
    g_ProfileLockDepth -= 1;
    if (entry != NULL) {
        F_(entry, 0x10, int) = 0xE4A;
    }
    sl.f48[0] = entry;
    strncpy(entry, name, 0x10);
    F_(sl.f48[0], 0x10, int) = value;
    PtrVec_PushBack_429770(&D_005724A0, sl.f48);
    D_005723C8 = 0;
}
#pragma pop
