#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Event_Construct(char **, char *);                       
int Event_Send(char **, int, int);                         
int Mem_Alloc(int, int, char *, int);                      
int String_Copy(int, int);                              
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
    temp_s0_2 = Mem_Alloc(0, temp_s0, &D_004A6698, 0x1D6);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Unlock(9);
    }
    g_ProfileLockDepth -= 1;
    String_Copy(temp_s0_2, arg2);
    Event_Construct(sl.f50, &D_004F7930);
    sl.f74 = arg1;
    sl.f78[0] = temp_s0_2;
    sl.f50[0] = &D_004DB8D0;
    Event_Send(sl.f50, F_(arg0, 0x30, int), 0);
    sl.f50[0] = &D_004DB8D0;
    cMessage_dtor(sl.f50, 0);
}
