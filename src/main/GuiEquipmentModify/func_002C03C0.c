#pragma cplusplus on
#include "types.h"
extern "C" {
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0xF];
    char payload[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundMsg;
}

struct Ent { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual unsigned char f78(); char pad04[0x10]; unsigned char b14; char pad15[0x4B]; char x60[0x40]; char xA0[4]; };
extern "C" {
typedef struct Hud { char pad[0x14]; unsigned short flags; } Hud;
typedef struct Self { char pad[0x80]; int x80; char pad84[0x8D4]; Hud* hud; char* fmt; } Self;
typedef struct Tbl { char pad[0xF8]; int t[1][4]; } Tbl;
extern unsigned char D_005721C8, D_005721C0, D_005723F8;
extern unsigned char D_00506518[];
extern int D_00506508;
extern float D_00506510;
extern char D_0048BAA0[][8];
extern Tbl D_0055DDA0;
extern char D_004FFB50[];
extern char D_004DAE10[];
extern void func_0041E3B0(Self*, float);
extern Ent* func_003FB8D0(int);
extern void func_001B2E90(Ent*);
extern void func_001B2D20(Ent*);
extern int func_004067E0(void*);
extern void func_00391020(void*, int);
extern void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
extern void func_0020F190(SoundMsg* msg, SoundRequest* req, Ent* e);
extern void Event_Send(SoundMsg* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);
extern void func_0012EEE0(void*, int, int);
extern int sprintf(char*, const char*, ...);
extern void func_0041BEB0(Hud*, char*, int);
extern void func_00429B30(void);
}
/* Per-frame update: polls the four player slots, tracks the slot-0 state-3 countdown and plays each slot's join sound once. */
extern "C" void func_002C03C0(Self* self, float dt) {
    SoundRequest req;
    SoundMsg msg;
    char buf[0x40];
    Ent* e;
    int i;
    func_0041E3B0(self, dt);
    if (!D_005721C8) return;
    for (i = 0; i < 4; i++) {
        e = func_003FB8D0(i);
        if (!e) continue;
        if (!e->b14) func_001B2E90(e);
        func_001B2D20(e);
        if (e->f78() == 3) {
            D_00506508++;
            self->hud->flags |= 2;
        } else if (i == 0 && (self->hud->flags & 2)) {
            D_00506508 = 0;
            D_00506510 = 0;
            self->hud->flags &= ~2;
            if (D_005723F8) D_005723F8 = 0;
        }
        if (D_00506518[i]) continue;
        D_00506518[i] = 1;
        if (self->x80) {
            int a = D_0055DDA0.t[func_004067E0(e->xA0)][i];
            if (a) func_00391020(e->x60, a);
        }
        if (i != 0) {
            SoundRequest_Ctor(&req, 4, D_0048BAA0[i], 0, 0);
            func_0020F190(&msg, &req, e);
            msg.flag = 1;
            Event_Send(&msg, D_004FFB50, 0);
            msg.vtbl = D_004DAE10;
            SoundMsg* m = &msg;
            if (m->payload) {
                func_0036E220(msg.partB, -1);
                func_0036E220(msg.partA, -1);
            }
            cMessage_dtor(&msg, 0);
            func_0036E220(req.partB, -1);
            func_0036E220(req.partA, -1);
        }
        func_0012EEE0(D_004FFB50, 0, 0);
    }
    if (D_00506508) {
        D_00506510 += dt;
        sprintf(buf, self->fmt, 10 - (int)(D_00506510 / 30.0f));
        if (self->hud) func_0041BEB0(self->hud, buf, 0);
        if ((D_005721C8 ? D_005721C0 : 1) && !(D_00506510 <= 300.0f)) func_00429B30();
    }
}



