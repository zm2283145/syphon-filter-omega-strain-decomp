#pragma cplusplus on
#include "types.h"
struct Voice_EF50 { char pad[0xC]; int id; };
struct Handle_EF50 {
    Voice_EF50* p; int id;
    inline bool Valid() { return !p || p->id == id; }
    inline Voice_EF50* Get() { return Valid() ? p : 0; }
};
struct Ev_EF50 {
    char hdr[0x30]; int type; int pad34[3]; __int128 name; Handle_EF50 voice;
    char pad58[0x1B0 - 0x58]; int x180; short x184; unsigned char x186;
};
struct Out_EF50 { int pad[2]; int type; int pad0c; __int128 name; int x180; int id; unsigned char x186; };
extern "C" {
extern int D_004F53C0;
void Event_PackHeader(Ev_EF50* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
}
extern "C" int func_0020F620(Ev_EF50* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf) {
    int r = -1;
    if (size >= 0x30 && buf) {
        Out_EF50* o = (Out_EF50*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        o->type = e->type;
        o->name = e->name;
        o->x180 = e->x180;
        o->x186 = e->x186;
        if (e->voice.Get()) o->id = e->voice.Get()->id; else o->id = 0;
        if (type) {
            r = 0x30;
            *type = D_004F53C0;
        }
    }
    return r;
}

