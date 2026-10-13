typedef struct Sub12FF80 {
    char pad0[0xC4];
    int id;
} Sub12FF80;

typedef struct Ent12FF80 {
    char x0;
    char name[0x1F];
} Ent12FF80;

typedef struct Info12FF80 {
    char pad0[0x38];
    Ent12FF80 ents[1];
    char pad58[0xE4];
    int count;
    char pad140[0x48];
    Sub12FF80 sub;
} Info12FF80;

typedef struct Obj12FF80 {
    char pad0[0x50];
    unsigned char state;
    signed char prev;
    char pad52[0xF];
    unsigned char x61;
    char pad62[0x52];
    Info12FF80 * volatile info;
    char padB8[0x88];
    char name[0x20];
} Obj12FF80;

extern int sprintf(char *, const char *, ...);
extern void *Agent_GetSelected(void *, int);
extern int String_CompareNoCase(const char *, const char *);
extern int func_001301D0(Obj12FF80 *, char *);
extern void func_00130520(Obj12FF80 *, char *, int);
extern void func_001303F0(Obj12FF80 *, char *);
extern void func_002C9420(void *);
extern void func_00332A10(void *, int, int, int);
extern void func_003328D0(void *, int, int, int, int);
extern void *D_004FFC04;
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;

void func_0012FF80(Obj12FF80 *o)
{
    char out[0x80];
    char sel[0x90];
    char buf[0x100];
    const char *a;
    const char *b;
    int i;

    if (o->x61 == 0)
        return;
    if (o->state != 8) {
        sel[0] = 0;
        switch (o->state) {
        case 7:
            a = "";
            b = "INTRO";
            if (func_001301D0(o, sel) != 0)
                b = &sel[1];
            break;
        case 9:
            a = "";
            b = "INTRO";
            break;
        case 11:
            a = o->name;
            b = "_SOL";
            break;
        case 12: {
            int id;
            Sub12FF80 *sub;
            Info12FF80 *in;
            a = o->name;
            in = o->info;
            id = in->sub.id;
            sub = &in->sub;
            if (id != -1 && id != 0x11) {
                func_00332A10(Agent_GetSelected(o, -1), id + 1, 6, 2);
                func_003328D0(Agent_GetSelected(o, -1), sub->id + 1, 5, 1, 1);
            }
            if (String_CompareNoCase(a, "UKRAINE") == 0) {
                func_002C9420(o->info);
                o->prev = *(signed char *)&o->state;
                o->state = 8;
                func_0012FF80(o);
                return;
            }
            func_002C9420(D_004FFC04);
            b = "_EOL";
            D_004FFBA1 = D_004FFBA0;
            D_004FFBA0 = 8;
            break;
        }
        default:
            return;
        }
        sprintf(out, "%s%s.PSS", a, b);
        func_00130520(o, out, 1);
    } else {
        for (i = 0; i < o->info->count; i++) {
            sprintf(buf, "%s.PSS", o->info->ents[i].name);
            func_001303F0(o, buf);
        }
    }
}




