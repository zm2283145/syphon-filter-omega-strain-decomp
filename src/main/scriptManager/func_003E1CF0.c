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
It std_vector_VarDefPtr_begin(void*);
It std_vector_VarDefPtr_end(void*);
void cArray_VarDefPtr_Iterator_ctor(It*,const It*);
Ft std_vector_FuncDefPtr_begin(void*);
Ft std_vector_FuncDefPtr_end(void*);
void cArray_FuncDefPtr_Iterator_ctor(Ft*,const Ft*);
extern void* D_00554F18;
extern void* D_00554F20;
}
struct IE:It { IE(const It& i) { cArray_VarDefPtr_Iterator_ctor(this,&i); } };
struct FE:Ft { FE(const Ft& i) { cArray_FuncDefPtr_Iterator_ctor(this,&i); } };
static inline IE beginI() { return IE(std_vector_VarDefPtr_begin(D_00554F18)); }
static inline IE endI() { return IE(std_vector_VarDefPtr_end(D_00554F18)); }
static inline FE beginF() { return FE(std_vector_FuncDefPtr_begin(D_00554F20)); }
static inline FE endF() { return FE(std_vector_FuncDefPtr_end(D_00554F20)); }
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
