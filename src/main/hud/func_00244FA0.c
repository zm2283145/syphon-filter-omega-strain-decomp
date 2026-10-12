#pragma cplusplus on
#include "types.h"
struct Msg_244FA0 { void* vt; char pad04[0x1C]; unsigned char b20; char pad21[3]; int i24; char pad28[8]; };
struct Sub_244FA0 { int x0; virtual void v0(int t); };
struct Svc_244FA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(float dt);
};
struct Tgt_244FA0 { char pad[0x30]; void* x30; };
struct Obj_244FA0 {
    char pad00[0x54];
    int i54;
    char pad58[0x38];
    char hud[0x40];
    Sub_244FA0 sub;
    char padD8[0x28];
    char x100[0x5A0];
    int i6A0;
    char pad6A4[8];
    float f6AC;
    unsigned char b6B0;
    char pad6B1[3];
    float f6B4;
    char pad6B8[0xC];
    char t6C4[0x18];
    float f6DC;
    char pad6E0[8];
    int i6E8;
};
extern "C" {
extern unsigned char D_004FFBB7;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern unsigned char D_004FFC29;
extern unsigned char D_004FFBA0;
extern float D_004F7DD8;
extern char D_004FFC90[];
extern char D_004F7DB8[];
extern char D_004F7A08[];
extern char D_004DBA00[];
extern char D_004DCF10[];
extern Tgt_244FA0* D_004FFC0C;
float func_00245890();
int func_00330C30(void* p, unsigned char b);
int ObjMan_GetService();
int ObjMan_GetTotalCount(int s);
int func_002270C0(int s, int* buf, int n, int k);
void Objective_QueueThresholdVoice(int a, int b);
void func_003F9E60(void* p, float dt);
void func_00242330(Obj_244FA0* o, float dt);
int Object_LookupById(void* id);
void HudTargets_Update(void* h, int t);
void Hud_UpdateAmmoText(Obj_244FA0* o, int t);
void func_003E79C0(int h, float dt);
void func_0026D620(int h, float dt);
bool func_00244D10(void* t, float now);
float func_00245810(Obj_244FA0* o);
void Event_Construct(Msg_244FA0* m, void* p);
void Event_Send(Msg_244FA0* m, void* target, int flags);
void cMessage_dtor(Msg_244FA0* m, int flags);
int func_00414790();
Svc_244FA0* func_004147A0();
void func_00415870(Svc_244FA0* s);
void func_00419260(int h, float dt);
}
extern "C" void func_00244FA0(Obj_244FA0* o, float dt)
{
    if (!D_004FFBB7) {
        o->f6DC += dt;
        unsigned char flag = D_005721C8;
        float cur = func_00245890();
        float max = (float)func_00330C30(D_004FFC90, flag);
        float q = max / 4.0f;
        float h = max / 2.0f;
        float t = 0.75f * max;
        int total = ObjMan_GetTotalCount(ObjMan_GetService());
        int buf[20];
        if (D_004F7DD8 < q && !(cur < q)) {
            int n = func_002270C0(ObjMan_GetService(), buf, 20, 1);
            if (flag && !n)
                Objective_QueueThresholdVoice(0x15, 2);
        } else if (D_004F7DD8 < h && !(cur < h)) {
            int n = func_002270C0(ObjMan_GetService(), buf, 20, 1);
            if (n < total / 2)
                Objective_QueueThresholdVoice(0x15, 3);
            else if (flag)
                Objective_QueueThresholdVoice(0x15, 2);
        } else if (D_004F7DD8 < t && !(cur < t)) {
            if ((float)func_002270C0(ObjMan_GetService(), buf, 20, 1) < 0.75f * (float)total)
                Objective_QueueThresholdVoice(0x15, 4);
        }
        D_004F7DD8 = cur;
    }
    func_003F9E60(o->x100, dt);
    if (o->i6E8)
        func_00242330(o, dt);
    int tgt = Object_LookupById(D_004F7DB8);
    o->sub.v0(tgt);
    HudTargets_Update(o->hud, tgt);
    Hud_UpdateAmmoText(o, tgt);
    func_003E79C0(o->i54, dt);
    if (o->i6A0)
        func_0026D620(o->i6A0, dt);
    if (func_00244D10(&o->f6AC, o->f6DC)) {
        Msg_244FA0 m;
        Event_Construct(&m, D_004F7A08);
        m.vt = D_004DBA00;
        m.i24 = 1;
        m.b20 = 2;
        Event_Send(&m, D_004FFC0C->x30, 0);
        m.vt = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    int busy = o->b6B0 != 0;
    if (!busy) {
        busy = 1;
        if (o->f6B4 <= o->f6AC)
            busy = 0;
    }
    if (!busy && func_00244D10(o->t6C4, func_00245810(o))) {
        if (!D_005721C8 || (D_005721C8 ? D_005721C0 : 1)) {
            Msg_244FA0 m;
            Event_Construct(&m, D_004F7A08);
            m.vt = D_004DBA00;
            m.i24 = 0;
            m.b20 = 1;
            Event_Send(&m, D_004FFC0C->x30, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
    }
    if (!D_004FFC29 || D_005721C8) {
        func_00419260(func_00414790(), dt);
        if (D_004FFBA0 != 0x13)
            func_00415870(func_004147A0());
        func_004147A0()->v22(dt);
    }
}

