#pragma cplusplus on

class Mgr {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Release(void* p);
};

struct Node {
    int pad0;
    Node* next;
    int id;
};

struct Ent {
    int id;
    int a4;
    char s8[0xC];
    char s14[0xC];
    int a20;
    int a24;
};

struct Head {
    int pad[2];
    Ent e;
};

struct Obj258 {
    char pad[0x10];
    int id;
};

struct SelfCAC80 {
    char pad[0x258];
    Obj258* obj;
    char pad2[0x2FC - 0x25C];
    int list;
    int list300;
    Head* head;
};

extern "C" {
Mgr* func_004147A0(void);
Node* func_002CAC70(void* p);
Node* func_002CAC60(void* p);
void func_002CAC50(Node** it, Node* n);
void func_002CE070(void* ret, void* list, Node** it);
int func_001692D0(void* p);
void func_002A7E90(Obj258* o, int a, int b, int c, int d, int e);
}

extern "C" bool func_002CAC80(SelfCAC80* self, int id)
{
    Obj258* o = self->obj;
    if (!o)
        return 0;
    if (!self->list) {
        func_004147A0()->Release(o);
        return 0;
    }
    {
        bool first = 1;
        bool found = 0;
        Node* n = func_002CAC70(&self->list300)->next;
        char ret[4];
        Node* tmp;
        Node* end;
        while (func_002CAC50(&end, func_002CAC60(&self->list)), n != end) {
            if (id == -1 || id == n->id) {
                tmp = n;
                func_002CE070(ret, &self->list, &tmp);
                found = 1;
                break;
            }
            n = n->next;
            first = 0;
        }
        if (self->list) {
            if (first) {
                Ent* e = &self->head->e;
                int c = func_001692D0(e->s14);
                func_002A7E90(self->obj, e->a4, func_001692D0(e->s8), c, e->a20, e->a24);
                self->obj->id = e->id;
            }
        } else {
            self->obj->id = -1;
            func_004147A0()->Release(self->obj);
        }
        return found;
    }
}
