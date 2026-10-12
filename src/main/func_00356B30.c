#pragma cplusplus on
class Obj356B30 {
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void f60(int);
    virtual void f64(int);
    char pad[0x5C];
    int x60;
};
extern "C" int func_0041EF10(Obj356B30 *self, int a1, unsigned short msg, int a3, int param);
extern "C" int func_00356B30(Obj356B30 *self, int a1, unsigned short msg, int a3, int param)
{
    if (msg == 0x14) {
        self->f60(param);
        return 1;
    }
    if (msg == 0x10 && a3 == 1)
        return 1;
    if (msg == 0x13) {
        self->f64(param);
        return 1;
    }
    if (msg == 0x3000) {
        self->x60 = a3;
        return 1;
    }
    return func_0041EF10(self, a1, msg, a3, param);
}