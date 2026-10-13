#pragma cplusplus on
struct PsObj { char pad[0xC]; int serial; };
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
void func_003FB750(int);
}
extern "C" PsObj* PlayerSlots_Get(int key)
{
    PsIt e2;
    PsIt it;
    PsIt e;
    PsNode* n;
    PsObj* o;
    bool isnull;
    unsigned char valid;
    PsRef* r;
    PsObj* got;
    func_003FC000(&it, D_0055C770, &key);
    n = it.p;
    func_003FB8C0(&e, D_0055C770);
    func_003FB8B0(&e2, &e);
    if ((n == e2.p) ^ 1) {
        r = &n->ref;
        valid = 1;
        o = r->obj;
        isnull = !o;
        if (!isnull && o->serial != r->serial) valid = 0;
        got = valid ? o : 0;
        if (got) return r->Get();
        func_003FB750(key);
    }
    return 0;
}
