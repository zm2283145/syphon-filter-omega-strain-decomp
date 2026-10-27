#pragma cplusplus on
#include "types.h"
#include "human_types.h"
#include "vslot_pad.h"
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Net { char pad[0x24]; int w24; };
class Act {
public:
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void Fn60(int);
    char pad4[0xC - 0x4];
    unsigned int wC;
    char pad10[0x14 - 0x10];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Vis* p58;
    char pad5C[0x3584 - 0x5C];
    Net* p3584;
};
struct Agent { char pad[0xB70]; unsigned char bB70; };
struct Color { float r, g, b, a; };
extern "C" {
extern unsigned char D_00572418[];
extern unsigned char D_0055C780[];
extern char D_0055C7A0[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_0049E8B0[];
extern char g_Game[];
extern char* g_Hud;
extern void* g_ActorList;
char* nGlobalization_GetString_charP(char*);
char* cGameSystem_GetClientPlayerName(char*, int);
int sprintf(char*, const char*, ...);
void cInfoBar_AddMessage(char*, char*, Color*, int, int);
void cHuman_PlayQuip(Act*, int);
Agent* cGameSystem_GetAgentData(char*, int);
void cNetObj_RemovePlayer_int(int);
void cAssocArray_int_netSystemField_End(Iter*, char*);
void cAssocArray_int_netSystemField_Find(Iter*, char*, int*);
int cAssocArray_int_netSystemField_Iterator_opNe(Iter*, Iter*);
int cAssocArray_int_netSystemField_Erase(char*, Iter*);
void cBaseObjList_Remove(void*, Act*);
void cSystem_ActualScheduleDelete(Act*, float);
void NetFreeObject(int);
void func_00257040(int);
}
static inline bool IsOn(Act* a)
{
    bool on = 0;
    if (a->p58 && a->p58->IsOn()) on = 1;
    return on;
}
static inline int PIdx(Act* a)
{
    return ((a->wC & 0x7F000000) >> 24) - 1;
}
static inline int NetIdx(Act* a)
{
    if (g_IsMultiplayer) {
        if (IsOn(a)) return PIdx(a);
        return -1;
    }
    return 0;
}
static inline unsigned char Mp()
{
    if (g_IsMultiplayer) return D_005721C0;
    return 1;
}
extern "C" bool cHuman_CheckForDisconnectedNetworkedPlayer(Act* a)
{
    bool ret = 0;
    int idx;
    if (IsOn(a) && !a->b14) {
        idx = PIdx(a);
        if (D_00572418[idx]) {
            char buf[0x100];
            Color c;
            int key;
            int pl = NetIdx(a);
            char* fmt = nGlobalization_GetString_charP(D_0049E8B0);
            sprintf(buf, fmt, cGameSystem_GetClientPlayerName(g_Game, pl));
            c.r = 1.0f;
            c.g = 0.0f;
            c.b = 0.0f;
            c.a = 1.0f;
            cInfoBar_AddMessage(g_Hud + 0x100, buf, &c, 1, 0);
            cHuman_PlayQuip(a, 3);
            D_0055C780[idx] = 0;
            cGameSystem_GetAgentData(g_Game, idx)->bB70 = 0;
            cNetObj_RemovePlayer_int(idx);
            key = a->wC;
            {
                Iter e, f;
                cAssocArray_int_netSystemField_End(&e, D_0055C7A0);
                cAssocArray_int_netSystemField_Find(&f, D_0055C7A0, &key);
                if (cAssocArray_int_netSystemField_Iterator_opNe(&e, &f)) {
                    Iter g;
                    cAssocArray_int_netSystemField_Find(&g, D_0055C7A0, &key);
                    cAssocArray_int_netSystemField_Erase(D_0055C7A0, &g);
                }
            }
            cBaseObjList_Remove(g_ActorList, a);
            cSystem_ActualScheduleDelete(a, 0.1f);
            a->Fn60(1);
            ret = 1;
            {
                unsigned char mp = Mp();
                if (mp && a->p3584) NetFreeObject(a->p3584->w24);
            }
            func_00257040(idx);
        }
    }
    return ret;
}






