#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_6150;
typedef struct { char* data; unsigned int len; } Src_6150;
typedef struct { Src_6150* s; unsigned int pos; unsigned char empty; } Tok_6150;
extern void String_CtorCStr_13B480(Str_6150* s, char* c);
extern void func_0013D680(Str_6150* d, Str_6150* s);
extern void func_00138B70(Str_6150* s, int f);
extern void String_PushBack(Str_6150* s, char c);
extern char D_004BD008[];
extern char D_00499C70[];
#define isspace_(c) ((D_00499C70 + 1)[c] & 8)

Tok_6150* func_003B6150(Tok_6150* self, Str_6150* out)
{
    int started;
    {
        Str_6150 t;
        String_CtorCStr_13B480(&t, D_004BD008);
        func_0013D680(out, &t);
        func_00138B70(&t, 0);
    }
    started = 0;
    if (self->s) {
        for (; self->pos < self->s->len; self->pos++) {
            char c = self->s->data[self->pos];
            int sp = isspace_(c) != 0;
            if (!(unsigned char)started && !sp) started = 1;
            if ((unsigned char)started == 1) {
                if (sp) break;
                String_PushBack(out, c);
            }
        }
    }
    self->empty = (unsigned char)started == 0;
    return self;
}

