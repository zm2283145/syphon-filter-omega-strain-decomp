#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);                       
int cNetObj_SendMessage_int_cMessageR_int_int(int, char **, int, int);                  
int cMessage_dtor(char **, int);                           
int cGameCamera_RemoveCamera(int);                
extern void cMessage_getSOBJClassId();
extern void cNICameraMsg_dtor();
extern void cNICameraMsg_Pack();
extern void cNICameraMsg_Clone();
void * const D_004DC2D0[8] = { (void*)0x0, (void*)0x0, (void*)cNICameraMsg_dtor, (void*)cNICameraMsg_Clone, (void*)cNICameraMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern char D_004F7C38;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;

int Script_cNIEventOBJ_DeactivateCamera(void **arg0) {
    struct { char * f20[9]; signed char f44[12]; } sl;
    int temp_a0;
    int var_v0;
    char * temp_s0;

    temp_s0 = *arg0;
    if (F_(temp_s0, 0x60, int) == 5) {
        temp_a0 = F_(temp_s0, 0x140, int);
        if (temp_a0 != 0) {
            cGameCamera_RemoveCamera(temp_a0);
            if (g_IsMultiplayer != 0) {
                if (g_IsMultiplayer != 0) {
                    var_v0 = D_005721C0;
                } else {
                    var_v0 = 1;
                }
                if (var_v0 != 0) {
                    cMessage_ctor_cMessageNameR(sl.f20, &D_004F7C38);
                    sl.f20[0] = &(*(char*)D_004DC2D0);
                    sl.f44[0] = 1;
                    cNetObj_SendMessage_int_cMessageR_int_int(F_(temp_s0, 0xC, int), sl.f20, -1, -1);
                    sl.f20[0] = &(*(char*)D_004DC2D0);
                    cMessage_dtor(sl.f20, 0);
                }
            }
        }
    }
    return 0;
}
