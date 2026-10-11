#include "types.h"
typedef struct { void* vt; char pad[0x20]; signed char f24; char pad2[0x30 - 0x25]; } Msg_7780;
int Event_Construct(Msg_7780 *, char *);
int Transport_Send(int, Msg_7780 *, int, int);
int cMessage_dtor(Msg_7780 *, int);
int cNIEventOBJ_ActivateCamera(int);
extern char D_004DC2D0;
extern char D_004F7C38;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
int Script_cNIEventOBJ_ActivateCamera(void **arg0) {
    Msg_7780 m;
    char * o = *arg0;
    if (*(int*)(o + 0x60) == 5) {
        int c = *(int*)(o + 0x140);
        if (c != 0) {
            cNIEventOBJ_ActivateCamera(c);
            if (D_005721C8 != 0) {
                int v;
                if (D_005721C8 != 0) v = D_005721C0; else v = 1;
                if (v != 0) {
                    Event_Construct(&m, &D_004F7C38);
                    m.f24 = 0;
                    m.vt = &D_004DC2D0;
                    Transport_Send(*(int*)(o + 0xC), &m, -1, -1);
                    m.vt = &D_004DC2D0;
                    cMessage_dtor(&m, 0);
                }
            }
        }
    }
    return 0;
}