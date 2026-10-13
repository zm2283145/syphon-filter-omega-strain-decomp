#pragma cplusplus on
#include "types.h"
#pragma push
#pragma bool off
#pragma inline_depth(12)
struct Func { char* name; char pad4[8]; int type; char pad10[0x24]; unsigned char defined; char pad35[3]; int body; };
struct Ft { Func** p; };
extern "C" {
int String_CompareNoCase(char*, char*);
Ft func_003E10C0(void*);
Ft func_003E1090(void*);
void func_003E10B0(Ft*,const Ft*);
extern void* D_00554F20;
}
struct FE:Ft { FE(const Ft& i) { func_003E10B0(this,&i); } };
static inline FE beginF() { return FE(func_003E10C0(D_00554F20)); }
static inline FE endF() { return FE(func_003E1090(D_00554F20)); }
static inline int neqF(const Ft& a,const Ft& b) { return (a.p == b.p)^1; }
extern "C" Func* func_003E0F50(void* self, char* name, int type) {
    Ft f=beginF();
    while(neqF(f,endF())) {
        Func* p=*f.p;
        if(p->defined && p->body && type == p->type && !String_CompareNoCase(p->name, name)) return *f.p;
        f.p++;
    }
    return 0;
}
#pragma pop
