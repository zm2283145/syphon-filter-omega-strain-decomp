#pragma cplusplus on
#include "types.h"

typedef struct { char pad[0xC]; int serial; } Tracked;
typedef struct { Tracked* obj; int serial; } WeakRef;

extern "C" {
Tracked* func_0014D350(WeakRef* self);
int func_00273210(void*, int*, void*, char*);
int Event_Construct(void*, char*);
int Event_Send(void*, void*, int);
int cMessage_dtor(void*, int);
char* strncpy(char*, const char*, unsigned int);
extern char D_004DE4F0[];
extern char D_0051F0B0;
extern unsigned char D_005721C8;
}

struct ObjMap228 {
    void Add(int* key, void* o, char* n) { func_00273210(this, key, o, n); }
};
struct Mgr228 { char pad[0x90]; ObjMap228 map; };
extern "C" Mgr228* D_004FFC2C;

struct Ev228 {
    char* vt; char p4[0x18]; int f1C; signed char f20; char p21[0xB]; signed char f2C; char p2D[7]; int f34; char name[0x10];
};

typedef struct { char pad[0x34]; WeakRef ref; } Obj228;

static inline Tracked* Get(WeakRef* r)
{
    Tracked* obj = r->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != r->serial)
        valid = 0;
    return valid ? obj : 0;
}
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
    return ((!obj) != 0 || obj->serial == r->serial) ? obj : 0;
}
static inline const int& IdOf(Tracked* p) { if (p) return p->serial; int m = -1; return m; }



extern "C" void cObjective_SetMapObject(Obj228* self, Tracked* obj, char* name, int quiet)
{
    if (Get1(&self->ref) || !obj)
        return;
    self->ref.obj = obj;
    self->ref.serial = IdOf(obj);
    if (Get(&self->ref)) {
        Mgr228* g = D_004FFC2C;
        g->map.Add(&Get2(&self->ref)->serial, self, name);
    }
    if (!quiet && D_005721C8 && Get1(&self->ref)) {
        int id = func_0014D350(&self->ref)->serial;
        Ev228 ev;
        Ev228* e = &ev;
        Event_Construct(e, &D_0051F0B0);
        ev.f34 = id;
        ev.vt = D_004DE4F0;
        ev.f2C = 6;
        if (name)
            strncpy(e->name, name, 0x10);
        e->f1C = 0x40;
        ev.f20 = 4;
        Event_Send(&ev, self, 0);
        ev.vt = D_004DE4F0;
        cMessage_dtor(&ev, 0);
    }
}