typedef struct { char b[8]; } Name8;
typedef struct { int id; float x; float y; } Ent;
typedef struct { Name8 name; Ent e[4]; } Info;

extern int func_002F64A0(Info *out);
extern int func_003010C8(int r);

int func_002FD718(int a, Info *out)
{
    Info t;
    int r;
    if (out == 0) return 2;
    if (a == 0) {
    r = func_003010C8(func_002F64A0(&t));
    if (r) { __asm__ __volatile__(""); return r; }
    out->name = t.name;
    out->e[0].id = t.e[0].id;
    out->e[0].x = t.e[0].x;
    out->e[0].y = t.e[0].y;
    out->e[1].id = t.e[1].id;
    out->e[1].x = t.e[1].x;
    out->e[1].y = t.e[1].y;
    out->e[2].id = t.e[2].id;
    out->e[2].x = t.e[2].x;
    out->e[2].y = t.e[2].y;
    out->e[3].id = t.e[3].id;
    out->e[3].x = t.e[3].x;
    out->e[3].y = t.e[3].y;
    return r;
    }
    return 3;
}

