#include "types.h"
typedef struct { char p0[0x1C]; int f1C; } E449770;
typedef struct { char p0[0x70]; char f70[4]; int n74; } S449770;
extern void func_00451AE0(S449770*);
extern int func_00449510(S449770*);
extern E449770* LobbyArray_At(void*, int);
extern void func_00449660(S449770*, int);
extern unsigned char func_00452FF0(S449770*, int);
int func_00449770(S449770* s)
{
    int i;
    func_00451AE0(s);
    func_00449510(s);
    for (i = 0; i < s->n74; i++) {
        func_00449660(s, LobbyArray_At(s->f70, i)->f1C);
    }
    return func_00452FF0(s, 0) == 0;
}
