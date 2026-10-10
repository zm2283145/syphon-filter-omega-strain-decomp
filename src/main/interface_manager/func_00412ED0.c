#include "types.h"

typedef struct { char data[0xA0]; } TextObj;
typedef struct { char pad[0xC]; void* target; void* enabled; int color; } Label412; /* 0x18 bytes */

extern char D_004BEF48[];
extern void* func_001692D0(Label412* label);
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_0036E5D0(TextObj* obj);
extern void Hog_Register(TextObj* obj, char* text, int color, int flags);
extern void func_003E7AD0(void* target, TextObj* obj);
extern void func_0036E220(TextObj* obj, int flags);

/* Builds and attaches a text object for each of the 20 active labels. */
void func_00412ED0(Label412* self)
{
    Label412* p;
    int i;
    i = 0;
    p = self;
    for (; i < 20; i++, p++) {
        if (p->enabled && p->target) {
            TextObj obj;
            char buf[0x20];
            sprintf(buf, D_004BEF48, func_001692D0(p));
            func_0036E5D0(&obj);
            Hog_Register(&obj, buf, p->color, 0);
            func_003E7AD0(p->target, &obj);
            func_0036E220(&obj, -1);
        }
    }
}
