#include "types.h"
typedef struct {
    void* vt; char pad04[0x18]; int w1C; signed char kind; char pad21[3]; float f; char key[16];
} Msg_245560;
typedef struct {
    void* vtable;
    char pad04[0x1C];
    char b20;
    char pad21[0x57];
    char memberA[0x9C];
    char memberB[0xAC];
} EMsg_245560;
typedef struct { void* owner; } Net_245560;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004F7DC0[];
extern char D_004DC310[];
extern char D_004DCF10[];
extern char D_004DAE30[];
extern char D_004F0F90[];
extern char D_004FFB50[];
extern char* D_004FFC0C;
extern float func_00245810(char* o);
extern int Loc_LookupText(char* key);
extern void func_00244EE0(void* t, int text, float time);
extern void EffectMsg_WrapRequest(EMsg_245560* m, void* a);
extern void Event_Send(void* m, void* target, int a);
extern void func_0036E220(void* member, int flags);
extern void Event_Construct(Msg_245560* m, void* type);
extern char* strncpy(char*, const char*, int);
extern void cMessage_dtor(void* m, int f);

void func_00245560(char* o, char* key, float f)
{
    EMsg_245560 em;
    float t = f + func_00245810(o);
    func_00244EE0(o + 0x6C4, key ? Loc_LookupText(key) : 0, t);
    EffectMsg_WrapRequest(&em, D_004F0F90);
    em.b20 = 1;
    Event_Send(&em, D_004FFB50, 0);
    if (D_005721C8 && (D_005721C8 ? D_005721C0 : 1)) {
        Msg_245560 m;
        Msg_245560* p = &m;
        Event_Construct(p, D_004F7DC0);
        m.vt = D_004DC310;
        m.f = t;
        m.kind = 4;
        m.w1C = 0x40;
        if (key) {
            strncpy(p->key, key, 16);
        } else {
            p->key[0] = 0;
        }
        Event_Send(&m, *(void**)(D_004FFC0C + 0x30), 0);
        m.vt = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    em.vtable = D_004DAE30;
    func_0036E220(em.memberB, -1);
    func_0036E220(em.memberA, -1);
    cMessage_dtor(&em, 0);
}
