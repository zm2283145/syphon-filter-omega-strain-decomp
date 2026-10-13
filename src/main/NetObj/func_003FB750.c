#pragma cplusplus on
class VObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual bool Busy();
};
struct PsObj { char pad[0xC]; int serial; char pad10[0x48]; VObj* v;
    bool IsBusy() { bool r = false; if (v) { if (v->Busy()) r = true; } return r; } };
struct PsRef {
    PsObj* obj;
    int serial;
    PsObj* Get()
    {
        PsObj* o = obj;
        return (o == 0 || o->serial == serial) ? o : 0;
    }
};
struct PsNode { char pad[0x10]; PsRef ref; };
struct PsIt { PsNode* p; };
extern "C" {
extern char D_0055C770[];
void func_003FC000(PsIt*, void*, int*);
void func_003FB8C0(PsIt*, void*);
PsIt* func_003FB8B0(PsIt*, PsIt*);
void func_003FC0C0(void* map, PsIt* it);
}
extern "C" int func_003FB750(int key)
{
    if (key < 4 && key >= 0) {
        PsIt e2;
        PsIt it;
        PsIt er;
        PsIt e;
        PsNode* n;
        bool isnull;
        unsigned char valid;
        PsObj* o;
        PsRef* r;
        PsObj* got;
        func_003FC000(&it, D_0055C770, &key);
        n = it.p;
        func_003FB8C0(&e, D_0055C770);
        func_003FB8B0(&e2, &e);
        if ((n == e2.p) ^ 1) {
            o = n->ref.obj;
            r = &n->ref;
            valid = 1;
            isnull = !o;
            if (!isnull && o->serial != r->serial) valid = 0;
            got = valid ? o : 0;
            if (got) {
                if (!((o == 0 || o->serial == r->serial) ? o : 0)->IsBusy()) return 0;
            }
            er.p = n;
            func_003FC0C0(D_0055C770, &er);
            return 1;
        }
    }
    return 0;
}

