#pragma cplusplus on
#include "types.h"
struct M_455E10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(void* o);
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_455E10;
typedef struct { char pad[0x48]; void* f48; } O_455E10;
extern "C" {
extern void* D_004FFC2C;
extern char D_004FFB50[];
void func_0043D820(void* p, int v);
void func_0043D760(void* p, int v);
M_455E10* func_004147A0(void);
void func_00456160(O_455E10* o);
void func_00242900(void* p);
void func_00131470(void* p, int v);
int func_00455E10(O_455E10* o, Ev_455E10* ev);
}
static inline unsigned char Down_455E10(Ev_455E10* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_455E10(Ev_455E10* e, int b) { unsigned char r = 0; if (Down_455E10(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_455E10(Ev_455E10* e, int b) { unsigned char r = 0; if (Btn_455E10(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_455E10(Ev_455E10* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_455E10(Ev_455E10* e, int b) { return Down2_455E10(e) && e->btn == b; }
static inline bool Plain2_455E10(Ev_455E10* e, int b) { return Btn2_455E10(e, b) && e->b6 == 0; }

int func_00455E10(O_455E10* o, Ev_455E10* ev)
{
    if (Plain_455E10(ev, 0x1000) && o->f48) {
        func_0043D820(o->f48, 0);
        return 1;
    }
    if (Plain2_455E10(ev, 0x4000) && o->f48) {
        func_0043D760(o->f48, 0);
        return 1;
    }
    if (Plain2_455E10(ev, 0x10)) {
        func_00456160(o);
        return 1;
    }
    if (Plain2_455E10(ev, 0x800)) {
        func_004147A0()->v24(o);
        func_00242900(D_004FFC2C);
        func_00131470(D_004FFB50, 0);
        return 1;
    }
    return 0;
}
