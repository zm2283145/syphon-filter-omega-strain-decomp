#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Msg2823E0 {
    VPAD4(a) virtual void Write(); virtual short Kind();
};
typedef struct { char pad[8]; short len; short kind; unsigned char data[1]; } Buf2823E0;
extern "C" {
extern unsigned char* D_005061D0;
extern int D_005061C8;
void Event_PackHeader(Msg2823E0* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
void printf(const char* format, ...);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_002823E0(Msg2823E0* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf) {
    int r = -1;
    if (size >= 0x10C && buf) {
        Buf2823E0* b = (Buf2823E0*)buf;
        unsigned char* save;
        int n;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->kind = e->Kind();
        save = D_005061D0;
        D_005061D0 = b->data;
        e->Write();
        n = D_005061D0 - b->data;
        D_005061D0 = save;
b->len = n;
        if (type) {
            r = n + 0xC;
            *type = D_005061C8;
        }
    }
    if ((unsigned int)r > 0x10C) printf("size = %d\n", r);
    return r;
}
#pragma pop
