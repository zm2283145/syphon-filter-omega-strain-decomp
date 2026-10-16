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
} Msg_12F0D0;
extern char D_004EA098[];
extern char D_004D91A0[];
extern char D_004DCF10[];
extern char D_004FFB50[];
extern void Event_Construct(Msg_12F0D0* m, void* type);
extern void cMessage_dtor(Msg_12F0D0* m, int f);
extern void Stream_ReadByte(signed char* out);
extern void Stream_ReadBool(unsigned char* out);
extern char* Agent_GetSelected(void*, int);
extern void func_00330E40(char*);
extern void func_003314F0(char*, int);
extern char* PlayerSlots_Get(int);
extern int func_0012F2E0(char*);
extern char* func_0012F2D0(char*);
extern void func_002C9270(char*, char*, int, int);
extern int func_0012F2C0(void*);
extern char* func_0012F2B0(char*);
extern char* func_0012F2A0(char*);
extern void Hud_ShowCallout(int, char*, char*, int, int, int, float, float);
extern float func_0012F290(char*);
extern void func_0012F280(char*, float);

void func_0012F0D0(void)
{
    Msg_12F0D0 m;
    char buf[0x90];
    int i;
    Event_Construct(&m, D_004EA098);
    m.vt = D_004D91A0;
    Stream_ReadByte(&m.id);
    Stream_ReadBool(&m.flag);
    Stream_ReadBool(&m.b2D);
    m.agent = Agent_GetSelected(D_004FFB50, m.id);
    if (m.flag) {
        func_00330E40(m.agent);
    } else {
        func_003314F0(m.agent, m.b2D);
        for (i = 0; i < 4; i++) {
            char* p = PlayerSlots_Get(i);
            if (p && m.id == func_0012F2E0(p)) {
                func_0012F2D0(buf);
                func_002C9270(buf, p, m.id, 1);
                Hud_ShowCallout(func_0012F2C0(D_004FFB50), func_0012F2B0(p), func_0012F2A0(buf), 0, 0, 0, -1.0f, 0.0f);
                break;
            }
        }
        if (!m.id) {
            char* g = Agent_GetSelected(D_004FFB50, -1);
            func_0012F280(g, func_0012F290(m.agent));
        }
    }
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
