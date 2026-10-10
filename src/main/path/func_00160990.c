#include "types.h"
typedef struct { float x, y, z, w; } D2_Vec4;
typedef struct { char pad[0x4C]; void* target; } D2_Obj990;
extern void* func_0015DDB0(void* t);
extern void Node_GetTranslation(D2_Vec4* out, void* node);
extern unsigned char func_00160720(D2_Obj990* o, D2_Vec4* pos, void* t);
unsigned char func_00160990(D2_Obj990* o, void* t) {
    unsigned char r = 0;
    D2_Vec4 pos;
    if (t != o->target) {
        Node_GetTranslation(&pos, func_0015DDB0(t));
        r = func_00160720(o, &pos, t);
    }
    return r;
}