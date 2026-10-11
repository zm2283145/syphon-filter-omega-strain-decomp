#pragma cplusplus on
class V_0012F2E0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int f();
};
struct O_0012F2E0 { char pad[0xC]; unsigned int xC; char pad2[0x58-0x10]; V_0012F2E0* x58; };
extern "C" { extern unsigned char D_005721C8; }
extern "C" int func_0012F2E0(O_0012F2E0* o)
{
    int r;
    if (D_005721C8) {
        bool ok = false;
        if (o->x58 && o->x58->f()) ok = true;
        r = ok ? (int)((o->xC & 0x7F000000) >> 24) - 1 : -1;
    } else {
        r = 0;
    }
    return r;
}
