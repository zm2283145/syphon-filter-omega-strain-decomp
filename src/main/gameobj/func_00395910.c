#pragma cplusplus on
#pragma exceptions off
#include "types.h"
struct S00395910 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual int Set(void* a, int b); /* +0x90 */
    char p04[0x64];
    int f68;
    int p6C;
    int f70;
    char p74[0x1E0 - 0x74];
    int f1E0;
    int f1E4;
    int f1E8;
    int f1EC;
    char p1F0[2];
    unsigned char f1F2;
    unsigned char f1F3;
};
extern "C" char D_0055C9F0[];
extern "C" int func_00395910(S00395910* p) {
    p->f68 = 0;
    p->f70 = 0;
    p->f1E0 = 0;
    p->f1E8 = 0;
    p->f1E4 = 0;
    p->f1EC = 0;
    p->f1F2 = 0;
    p->f1F3 = 0;
    return p->Set(D_0055C9F0, 0);
}