#include "types.h"
typedef struct {
    void* vt;
    char pad04[0x18];
    int f1C;
    signed char kind;
    char pad21[3];
    signed char id;
    char pad25[3];
    char* agent;
    unsigned char flag;
    unsigned char b2D;
} Msg_12EEE0;
char* Agent_GetSelected(int, int);
int func_002EBAF8(int*, int);
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern char D_004EA098[];
extern char D_004D91A0[];
extern char D_004DCF10[];
extern void Event_Construct(Msg_12EEE0* m, void* type);
extern void Transport_Send(int a, Msg_12EEE0* m, int b, int c);
extern void cMessage_dtor(Msg_12EEE0* m, int f);

void Game_NetSendPauseState(int arg0, unsigned char arg1, unsigned char arg2)
{
    Msg_12EEE0 m;
    Msg_12EEE0* p;
    if (D_005721C8) {
        int id;
        int a = D_005721A8;
        if (D_005721C8) {
            if (D_00494178 == -1) func_002EBAF8(&D_00494178, a);
            id = D_00494178;
        } else id = 0;
        {
            char* agent = Agent_GetSelected(arg0, -1);
            p = &m;
            Event_Construct(p, D_004EA098);
            m.agent = agent;
            m.vt = D_004D91A0;
            m.id = id;
            m.kind = 4;
            {
                unsigned char* f = &m.flag;
                *f = arg1;
                if (!*f) p->f1C = 0x40;
            }
            p->b2D = arg2;
            Transport_Send(0, &m, -1, -1);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
    }
}
