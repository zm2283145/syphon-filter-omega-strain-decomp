#pragma cplusplus on
#include "types.h"

struct Event3FB020 {
    virtual int Dummy0();
    virtual int Dummy1();
    virtual int Serialize(int target, int* handle, int time, int a4, int size, char* buf);
    char pad04[0x18];
    int f1C;
    unsigned char flags;
    char pad21[3];
    int kind;
    unsigned char sub;
};

extern "C" {
extern int D_0055C7B8;
extern int D_0055D480;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char D_005721D0;
int func_0042B1A0(int);
int* Event_GetType(Event3FB020*);
unsigned char NetObj_SendMessage(int a, int b, void* c, int target, int type);
void func_002EBBA0(int, int*);
}

extern "C" int Transport_Send(int target, Event3FB020* e, int a2, int a3)
{
    char buf[0x400];
    int handle;
    int peer;
    int r;
    unsigned char send;

    r = e->Serialize(target, &handle, func_0042B1A0(0), D_0055C7B8, 0x400, buf);
    if (D_005721D0 && target > -1 && r > -1) {
        send = 1;
        int* ty = Event_GetType(e);
        if (*ty == D_0055D480) {
            if (e->sub == 1 || e->sub == 0xC || e->kind == 1 || e->kind == 2 || e->kind == 0x43 ||
                e->kind == 0x3E || e->kind == 0x3F || e->kind == 0x39 || e->kind == 0x3A || e->kind == 0xD)
                send = 0;
        }
        if (send && e->flags != 1) {
            if ((e->flags & 0x15) || (e->flags & 5) || (e->flags & 4)) {
                if (!NetObj_SendMessage(handle, r, buf, a3, e->f1C))
                    r = -1;
            }
            if (e->flags & 8) {
                if (!NetObj_SendMessage(handle, r, buf, a2, e->f1C))
                    r = -1;
            }
            if (e->flags & 2) {
                if (!(D_005721C8 ? D_005721C0 : 1)) {
                    int type = e->f1C;
                    func_002EBBA0(D_005721A8, &peer);
                    if (!NetObj_SendMessage(handle, r, buf, peer, type))
                        r = -1;
                }
            }
        }
    }
    return r != 0;
}




