#pragma cplusplus on
#include "types.h"
struct MsgQC {
    virtual void v00();
    virtual MsgQC* Clone();
    int pad4;
    int magic;
};
struct EntryQC { int mode; MsgQC* msg; MsgQC* orig; EntryQC(int md, MsgQC* m, MsgQC* o) { mode = md; msg = m; orig = o; } };
struct ObjQC { virtual void v00(); virtual void Handle(MsgQC* m); };
extern "C" char D_004BD130[];
extern "C" char D_005435C0[];
extern "C" char D_005435C4[];
extern "C" void func_00127358(char* msg);
extern "C" void MsgQueue_Insert(void* res, void* map, void* key, EntryQC* e);
extern "C" int MsgQueue_QueueClone(MsgQC* m, ObjQC* target, int mode)
{
    if (target) {
        if (mode != 1) {
            MsgQC* c = m->Clone();
            if (!c) {
                func_00127358(D_004BD130);
                return 0;
            }
            {
                int res;
                char* key;
                c->magic = 0xBEBAAFDE;
                EntryQC e(mode, c, (MsgQC*)target);
                key = D_005435C4;
                MsgQueue_Insert(&res, D_005435C0, &key, &e);
            }
        } else {
            target->Handle(m);
        }
    }
    return 1;
}