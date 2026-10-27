#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int EnableIntc();                                  
int nGobjManager_GetNextId();                           
char * cMemMan_Allocate(int, int, char *, int);                      
int nGobjManager_AddGOBJ();                          
int cGOBJ_ctor();                
int std_list_cNodeListPtr_push_back();                      
extern char D_004A82B8;
extern char D_004DCA80;
extern char D_004F83C0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

#pragma push
#pragma opt_common_subs off
char * cNodeList_ctor(int arg0) {
    struct { int f30; int f34[2]; char * f3C; } sl;
    char * temp_s1;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s1 = (char *)(cMemMan_Allocate(0, 0x64, &D_004A82B8, 0x70));
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s1 != NULL) {
        sl.f30 = 0;
        nGobjManager_GetNextId(sl.f34, 0xF5);
        cGOBJ_ctor(temp_s1, sl.f34, 0, &sl.f30);
        F_(temp_s1, 0x0, int) = (int)(&D_004DCA80);
        F_(temp_s1, 0x60, int) = arg0;
        nGobjManager_AddGOBJ(temp_s1);
    }
    sl.f3C = temp_s1;
    std_list_cNodeListPtr_push_back(&D_004F83C0, &sl.f3C);
    return sl.f3C;
}
#pragma pop
