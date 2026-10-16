#include "types.h"
#pragma mpwc_relax on
int Alloc_Lock(int);
int Alloc_Unlock(int);
int Event_Construct(char **, char *);
int Event_Send(char **, int, int);
int Mem_Alloc(int, int, char *, int);
int String_Copy(int, int);
int cMessage_dtor(char **, int);
int strlen(int);
int PlayerSlots_Get(int);
extern char D_004A6698;
extern char D_004DB8D0;
extern char D_004F7930;
extern unsigned char D_00533880;
extern int D_00533888;

void Global_SetPlayersCheckpoint(int arg1, int arg2) {
    struct { char * f50[9]; int f74; int f78[2]; } sl;
    int i;
    int p;
    int len;
    int buf;

    for (i = 0; i < 4; i++) {
        p = PlayerSlots_Get(i);
        if (p != 0) {
            len = strlen(arg2) + 1;
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            buf = Mem_Alloc(0, len, &D_004A6698, 0x1E6);
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
            String_Copy(buf, arg2);
            Event_Construct(sl.f50, &D_004F7930);
            sl.f50[0] = &D_004DB8D0;
            sl.f74 = arg1;
            sl.f78[0] = buf;
            Event_Send(sl.f50, p, 0);
            sl.f50[0] = &D_004DB8D0;
            cMessage_dtor(sl.f50, 0);
        }
    }
}
