#include "types.h"
typedef struct { char pad[0x24]; float f24; } B7_6A0Val;
typedef struct { char pad[8]; B7_6A0Val* val; } B7_6A0Node;
typedef struct { char pad[0x30]; char map[1]; } B7_6A0Owner;
extern void func_0016DB40(B7_6A0Node** out, void* map, int key);
extern void func_0016BB80(B7_6A0Node** out, void* map);
extern void func_0016BB90(B7_6A0Node** out, B7_6A0Node** in);
B7_6A0Val* func_0016C6A0(B7_6A0Owner* p, int key)
{
    B7_6A0Val* r = 0;
    B7_6A0Node* it;
    B7_6A0Node* end;
    B7_6A0Node* tmp;
    B7_6A0Node* n;
    func_0016DB40(&it, p->map, key);
    n = it;
    func_0016BB80(&tmp, p->map);
    func_0016BB90(&end, &tmp);
    if (n != end) {
        B7_6A0Val* v = n->val;
        if (!(v->f24 < 0.0f)) {
            r = v;
        }
    }
    return r;
}