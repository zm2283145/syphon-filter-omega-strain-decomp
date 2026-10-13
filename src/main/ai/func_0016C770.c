#include "types.h"
typedef struct { char pad[0x20]; unsigned char f20; char p21[3]; float f24; char p28[0x10]; unsigned char f38; unsigned char f39; unsigned char f3A; char p3B; unsigned char f3C; } Rec_770;
typedef struct { char pad[8]; Rec_770* val; } Node_770;
typedef struct { char pad[0x30]; char map[1]; } Owner_770;
extern void NpcPerception_FindRecord(Node_770** out, void* map, int key);
extern void func_0016BB80(Node_770** out, void* map);
extern void func_0016BB90(Node_770** out, Node_770** in);
extern void NpcPerception_AddAwareness(Owner_770* p, int key, int kind, float amt);
void NpcPerception_RegisterSighting(Owner_770* p, int key, unsigned char a, unsigned char b)
{
    int both = (a & b) != 0;
    Node_770* it;
    Node_770* end;
    Node_770* tmp;
    NpcPerception_FindRecord(&it, p->map, key);
    func_0016BB80(&tmp, p->map);
    func_0016BB90(&end, &tmp);
    if (it != end) {
        if (both && !it->val->f3C) {
            NpcPerception_AddAwareness(p, key, 6, 0.0f);
        } else {
            it->val->f38 = b;
            it->val->f39 = a;
            if (a) {
                if (b) {
                    it->val->f24 = 0.0f;
                    it->val->f3A = 1;
                    it->val->f20 = 6;
                } else if (it->val->f24 < 10.0f) {
                    it->val->f24 = 0.0f;
                }
            }
        }
    } else if (both) {
        NpcPerception_AddAwareness(p, key, 6, 0.0f);
    }
}
