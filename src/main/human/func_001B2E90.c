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
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_0049E8B0[];
extern char D_004FFB50[];
extern char* D_004FFC2C;
extern void* D_004FFD44;
char* Loc_LookupText(char*);
char* func_0012F5D0(char*, int);
int sprintf(char*, const char*, ...);
void Notify_Insert(char*, char*, Color*, int, int);
void Actor_BuildVoiceKey(Act*, int);
Agent* Agent_GetSelected(char*, int);
void func_003FB750(int);
void func_001B31A0(Iter*, char*);
void func_001B3170(Iter*, char*, int*);
int func_001B3150(Iter*, Iter*);
int ReceiverMap_Erase(char*, Iter*);
void func_0040B720(void*, Act*);
void Object_DeleteLater(Act*, float);
void func_002EC2A8(int);
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
    if (D_005721C8) {
        if (IsOn(a)) return PIdx(a);
        return -1;
    }
    return 0;
}
static inline unsigned char Mp()
{
    if (D_005721C8) return D_005721C0;
    return 1;
}
extern "C" bool func_001B2E90(Act* a)
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
            char* fmt = Loc_LookupText(D_0049E8B0);
            sprintf(buf, fmt, func_0012F5D0(D_004FFB50, pl));
            c.r = 1.0f;
            c.g = 0.0f;
            c.b = 0.0f;
            c.a = 1.0f;
            Notify_Insert(D_004FFC2C + 0x100, buf, &c, 1, 0);
            Actor_BuildVoiceKey(a, 3);
            D_0055C780[idx] = 0;
            Agent_GetSelected(D_004FFB50, idx)->bB70 = 0;
            func_003FB750(idx);
            key = a->wC;
            {
                Iter e, f;
                func_001B31A0(&e, D_0055C7A0);
                func_001B3170(&f, D_0055C7A0, &key);
                if (func_001B3150(&e, &f)) {
                    Iter g;
                    func_001B3170(&g, D_0055C7A0, &key);
                    ReceiverMap_Erase(D_0055C7A0, &g);
                }
            }
            func_0040B720(D_004FFD44, a);
            Object_DeleteLater(a, 0.1f);
            a->Fn60(1);
            ret = 1;
            {
                unsigned char mp = Mp();
                if (mp && a->p3584) func_002EC2A8(a->p3584->w24);
            }
            func_00257040(idx);
        }
    }
    return ret;
}






