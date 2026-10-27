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
extern void cMessage_ctor_cMessageNameR(Msg_12F0D0* m, void* type);
extern void cMessage_dtor(Msg_12F0D0* m, int f);
extern void Stream_ReadByte(signed char* out);
extern void cNetMsg_GetChar(unsigned char* out);
extern char* cGameSystem_GetAgentData(void*, int);
extern void cAgentData_NetUnpackStats(char*);
extern void cAgentData_NetUnpack(char*, int);
extern char* cNetObj_GetPlayer(int);
extern int cGOBJ_GetGobjClientIndex(char*);
extern char* pString_ctor(char*);
extern void Hud_AppendCalloutName(char*, char*, int, int);
extern int func_0012F2C0(void*);
extern char* cSystem_GetObjectID_void(char*);
extern char* pString_CStr(char*);
extern void cHud_SetCallout(int, char*, char*, int, int, int, float, float);
extern float func_0012F290(char*);
extern void func_0012F280(char*, float);

void cNetAgentUpdateMsg_NetReceive(void)
{
    Msg_12F0D0 m;
    char buf[0x90];
    int i;
    cMessage_ctor_cMessageNameR(&m, D_004EA098);
    m.vt = D_004D91A0;
    Stream_ReadByte(&m.id);
    cNetMsg_GetChar(&m.flag);
    cNetMsg_GetChar(&m.b2D);
    m.agent = cGameSystem_GetAgentData(g_Game, m.id);
    if (m.flag) {
        cAgentData_NetUnpackStats(m.agent);
    } else {
        cAgentData_NetUnpack(m.agent, m.b2D);
        for (i = 0; i < 4; i++) {
            char* p = cNetObj_GetPlayer(i);
            if (p && m.id == cGOBJ_GetGobjClientIndex(p)) {
                pString_ctor(buf);
                Hud_AppendCalloutName(buf, p, m.id, 1);
                cHud_SetCallout(func_0012F2C0(g_Game), cSystem_GetObjectID_void(p), pString_CStr(buf), 0, 0, 0, -1.0f, 0.0f);
                break;
            }
        }
        if (!m.id) {
            char* g = cGameSystem_GetAgentData(g_Game, -1);
            func_0012F280(g, func_0012F290(m.agent));
        }
    }
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
