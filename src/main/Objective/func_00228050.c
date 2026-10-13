#pragma cplusplus on
#include "types.h"

typedef struct { char pad[0xC]; int serial; } Tracked;
typedef struct { Tracked* obj; int serial; } WeakRef;

extern "C" {
int ObjMarkerMgr_RemoveDefault(void*, int*);
int Event_Construct(void*, char*);
int Event_Send(void*, void*, int);
int cMessage_dtor(void*, int);
extern char D_004DE4F0[];
extern char D_0051F0B0;
extern unsigned char D_005721C8;
}

struct ObjMap228 {
    void Remove(int* key) { ObjMarkerMgr_RemoveDefault(this, key); }
};
struct Mgr228 { char pad[0x90]; ObjMap228 map; };
extern "C" Mgr228* D_004FFC2C;

struct Ev228 {
    char* vt; char p4[0x18]; int f1C; signed char f20; char p21[0xB]; signed char f2C; char p2D[3]; int f30; int f34; char name[0x10];
};

typedef struct { char pad[0x34]; WeakRef ref; } Obj228;

static inline Tracked* Get1(WeakRef* r)
{
    unsigned char valid = 1;
    Tracked* obj = r->obj;
    bool n = !obj;
    if (!n && obj->serial != r->serial)
        valid = 0;
    return valid ? obj : 0;
}
static inline Tracked* Get2(WeakRef* r)
{
    Tracked* obj = r->obj;
    bool n = !obj;
    return (n || obj->serial == r->serial) ? obj : 0;
}
static inline const int& IdOf(Tracked* p) { if (p) return p->serial; int m = -1; return m; }

extern "C" void cObjective_ClearMapObject(Obj228* self, int quiet)
{
    if (Get1(&self->ref)) {
        Mgr228* g = D_004FFC2C;
        g->map.Remove(&Get2(&self->ref)->serial);
    }
    self->ref.obj = 0;
    self->ref.serial = IdOf(0);
    if (!quiet && D_005721C8) {
        Ev228 ev;
        Event_Construct(&ev, &D_0051F0B0);
        ev.vt = D_004DE4F0;
        ev.f30 = -1;
        ev.f2C = 7;
        ev.f1C = 0x40;
        ev.f20 = 4;
        Event_Send(&ev, self, 0);
        ev.vt = D_004DE4F0;
        cMessage_dtor(&ev, 0);
    }
}

