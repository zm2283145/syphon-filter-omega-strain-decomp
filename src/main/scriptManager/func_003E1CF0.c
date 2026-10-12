#pragma cplusplus on
#include "types.h"
#pragma push
#pragma bool off
#pragma inline_depth(12)
struct Item { char* name; int x4; unsigned char defined; char pad[7]; int refs; };
struct Func { char* name; char pad[0x30]; unsigned char defined; char pad35[3]; int refs; };
struct It { Item** p; };
struct Ft { Func** p; };
extern "C" {
void Script_PrintWarning(char*,char*);
It func_003E1F20(void*);
It func_003E1EF0(void*);
void func_003E1F10(It*,const It*);
Ft func_003E10C0(void*);
Ft func_003E1090(void*);
void func_003E10B0(Ft*,const Ft*);
extern void* D_00554F18;
extern void* D_00554F20;
}
struct IE:It { IE(const It& i) { func_003E1F10(this,&i); } };
struct FE:Ft { FE(const Ft& i) { func_003E10B0(this,&i); } };
static inline IE beginI() { return IE(func_003E1F20(D_00554F18)); }
static inline IE endI() { return IE(func_003E1EF0(D_00554F18)); }
static inline FE beginF() { return FE(func_003E10C0(D_00554F20)); }
static inline FE endF() { return FE(func_003E1090(D_00554F20)); }
static inline int neqI(const It& a,const It& b) { return (a.p == b.p)^1; }
static inline int neqF(const Ft& a,const Ft& b) { return (a.p == b.p)^1; }
static inline FE beginF0() { return beginF(); }
extern "C" int cScriptInterpreter_CheckAllReferences() {
    unsigned char bad=0;
    It i=beginI();
    while(neqI(i,endI())) {
        Item* p=*i.p;
        if(p->refs>0 && !p->defined) { Script_PrintWarning("var %s not defined",p->name); bad=1; }
        i.p++;
    }
    Ft f=beginF0();
    while(neqF(f,endF())) {
        Func* p=*f.p;
        if(p->refs>0 && !p->defined) { Script_PrintWarning("func %s not defined",p->name); bad=1; }
        f.p++;
    }
    return !bad;
}
#pragma pop
