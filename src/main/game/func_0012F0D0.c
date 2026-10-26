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
extern char g_Game[];
extern void Event_Construct(Msg_12F0D0* m, void* type);
extern void cMessage_dtor(Msg_12F0D0* m, int f);
extern void Stream_ReadByte(signed char* out);
extern void Stream_ReadBool(unsigned char* out);
extern char* Agent_GetSelected(void*, int);
extern void cAgentData_NetUnpackStats(char*);
extern void cAgentData_NetUnpack(char*, int);
extern char* PlayerSlots_Get(int);
extern int cGOBJ_GetGobjClientIndex(char*);
extern char* pString_ctor(char*);
extern void Hud_AppendCalloutName(char*, char*, int, int);
extern int func_0012F2C0(void*);
extern char* cSystem_GetObjectID_void(char*);
extern char* pString_CStr(char*);
extern void Hud_ShowCallout(int, char*, char*, int, int, int, float, float);
extern float func_0012F290(char*);
extern void func_0012F280(char*, float);

void cNetAgentUpdateMsg_NetReceive(void)
{
    Msg_12F0D0 m;
    char buf[0x90];
    int i;
    Event_Construct(&m, D_004EA098);
    m.vt = D_004D91A0;
    Stream_ReadByte(&m.id);
    Stream_ReadBool(&m.flag);
    Stream_ReadBool(&m.b2D);
    m.agent = Agent_GetSelected(g_Game, m.id);
    if (m.flag) {
        cAgentData_NetUnpackStats(m.agent);
    } else {
        cAgentData_NetUnpack(m.agent, m.b2D);
        for (i = 0; i < 4; i++) {
            char* p = PlayerSlots_Get(i);
            if (p && m.id == cGOBJ_GetGobjClientIndex(p)) {
                pString_ctor(buf);
                Hud_AppendCalloutName(buf, p, m.id, 1);
                Hud_ShowCallout(func_0012F2C0(g_Game), cSystem_GetObjectID_void(p), pString_CStr(buf), 0, 0, 0, -1.0f, 0.0f);
                break;
            }
        }
        if (!m.id) {
            char* g = Agent_GetSelected(g_Game, -1);
            func_0012F280(g, func_0012F290(m.agent));
        }
    }
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
