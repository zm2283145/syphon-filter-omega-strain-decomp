typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS32;
typedef struct { union { SS32 s; unsigned int w; } h; unsigned int size; } Str32;
typedef struct { char p[0x48]; Str32 name; } Obj32;
typedef struct { char p[0x4C]; Obj32 *o; } Own32;
static inline unsigned int size32(Str32 *s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }
int func_0032AF10(Own32 *arg0, int c) {
    if ((unsigned char)c == 0x20 && size32(&arg0->o->name) == 0) return 0;
    return 1;
}