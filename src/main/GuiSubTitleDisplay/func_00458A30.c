#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct SubVal {
    float a;
    float b __attribute__((aligned(16)));
    float c;
    float d;
    float e;
    int f;
    int g;
    int h;
    int i;
};

struct SubNode;
struct SubList {
    int count;
    SubNode *first;
    SubNode *last;
};

struct SubDisp {
    char pad0[0x3C];
    float maxWidth;
    char pad40[0x4C - 0x40];
    int font;
    char *text;
    char pad54[0x58 - 0x54];
    int lines[2];
};

extern "C" {
void *cMemMan_Allocate(int, unsigned int, char *, int);
void cMemMan_Deallocate(int, void *, char *, int);
int Libc_Sscanf(char *, char *, ...);
void cTimerDisable_ctor(int *);
void cTimerDisable_dtor(int *, int);
int cFont_GetCharH(int);
int cFont_GetStringWidth(int, char *, int);
void GuiSubTitleDisplay_CalcLineTimes(SubDisp *);
void cLList_TextAtom_dtor(SubList *, int);
int std_vector_cLList_TextAtomPtr_push_back(int *, SubList **);
void GuiSubTitleDisplay_DestroyTextLines(SubDisp *);
int std_list_deleter_TextAtom_insert(SubNode **, SubList *, SubNode **, SubVal *);
SubList *std_list_deleter_TextAtom_ctor(SubList *);
extern char D_004C1EB0[];
extern char D_004C1ED0[];
extern char D_004C1ED8[];
extern float D_00587D70;
extern float D_00587D74;
extern float D_00587D78;
extern float D_00587D7C;
int GuiSubTitleDisplay_Atomize(SubDisp *self);
}

static inline void Push(SubList *l, SubVal *v)
{
    SubNode *res;
    SubNode *pos = (SubNode *)&l->first;
    std_list_deleter_TextAtom_insert(&res, l, &pos, v);
}

static inline void FreeList(SubList *l)
{
    int guard;
    cTimerDisable_ctor(&guard);
    cLList_TextAtom_dtor(l, -1);
    cMemMan_Deallocate(0, l, D_004C1EB0, 0x124);
    cTimerDisable_dtor(&guard, -1);
}

int GuiSubTitleDisplay_Atomize(SubDisp *self)
{
    SubList *list;
    float pf;
    int r;
    int g;
    int b;
    float nf;
    char *p;
    int width;
    SubVal val;
    char buf[0x20];
    int maxw;

    GuiSubTitleDisplay_DestroyTextLines(self);
    p = self->text;
    if (p == 0)
        return 0;
    maxw = (int)self->maxWidth;
    val.a = 0;
    val.b = 1.0f;
    val.c = 1.0f;
    val.d = 1.0f;
    val.e = 1.0f;
    val.f = 0;
    val.g = 0;
    val.h = 0;
    val.i = 0;
    width = 0;
    {
        SubList *nl;
        {
            AllocGuard guard;
            nl = (SubList *)cMemMan_Allocate(0, 0xC, D_004C1EB0, 0x67);
        }
        if (nl)
            std_list_deleter_TextAtom_ctor(nl);
        list = nl;
    }
    for (;;) {
        signed char c = *p;
        if (!c)
            break;
        if (c == '<' && p[1] != '<') {
            signed char t;
            char *d;
            p++;
            if (!*p)
                return 0;
            t = *p;
            p++;
            if (!*p || (*p != '>' && *p != ':'))
                return 0;
            d = buf;
            if (*p != '>')
                p++;
            while (*p != '>') {
                if (*p == 0)
                    return 0;
                *d++ = *p++;
            }
            *d = 0;
            p++;
            switch (t) {
            case 'p':
                if (Libc_Sscanf(buf, D_004C1ED0, &pf) != 1)
                    return 0;
                if (val.i != 0) {
                    Push(list, &val);
                    width += cFont_GetStringWidth(self->font, self->text + val.h, val.i);
                    val.f = width;
                    val.i = 0;
                }
                val.h = p - self->text;
                val.a = pf;
                break;
            case 'c': {
                float cr;
                float cg;
                float cb;
                float ca;
                if (Libc_Sscanf(buf, D_004C1ED8, &r, &g, &b) == 3) {
                    cr = r / 255.0f;
                    cg = g / 255.0f;
                    cb = b / 255.0f;
                    ca = 1.0f;
                } else {
                    cr = D_00587D70;
                    cg = D_00587D74;
                    cb = D_00587D78;
                    ca = D_00587D7C;
                }
                if (val.i != 0) {
                    Push(list, &val);
                    width += cFont_GetStringWidth(self->font, self->text + val.h, val.i);
                    val.f = width;
                    val.i = 0;
                    val.a = 0;
                }
                val.h = p - self->text;
                val.b = cr;
                val.c = cg;
                val.d = cb;
                val.e = ca;
                break;
            }
            case 'n':
                nf = 0;
                Libc_Sscanf(buf, D_004C1ED0, &nf);
                Push(list, &val);
                std_vector_cLList_TextAtomPtr_push_back(self->lines, &list);
                {
                    SubList *nl;
                    {
                        AllocGuard guard;
                        nl = (SubList *)cMemMan_Allocate(0, 0xC, D_004C1EB0, 0xD9);
                    }
                    if (nl)
                        std_list_deleter_TextAtom_ctor(nl);
                    list = nl;
                }
                val.f = 0;
                width = 0;
                val.g += cFont_GetCharH(self->font);
                val.a = nf;
                val.h = p - self->text;
                val.i = 0;
                break;
            }
        } else {
            char *s;
            val.i++;
            s = self->text + val.h;
            if (maxw < width + cFont_GetStringWidth(self->font, s, val.i)) {
                int len = val.i;
                int k;
                bool found = false;
                for (k = len - 1; k >= 0; k--) {
                    if (s[k] == ' ') {
                        val.i = k;
                        Push(list, &val);
                        val.h += k + 1;
                        val.i = len - k - 1;
                        if (val.i < 0)
                            val.i = 0;
                        val.a = 0;
                        found = true;
                        break;
                    }
                }
                if (found == false)
                    Push(list, &val);
                std_vector_cLList_TextAtomPtr_push_back(self->lines, &list);
                {
                    SubList *nl;
                    {
                        AllocGuard guard;
                        nl = (SubList *)cMemMan_Allocate(0, 0xC, D_004C1EB0, 0x111);
                    }
                    if (nl)
                        std_list_deleter_TextAtom_ctor(nl);
                    list = nl;
                }
                val.f = 0;
                width = 0;
                val.g += cFont_GetCharH(self->font);
                val.a = 0;
            }
            p++;
        }
    }
    if (val.i != 0 || val.a != 0.0f)
        Push(list, &val);
    if (list->count != 0) {
        std_vector_cLList_TextAtomPtr_push_back(self->lines, &list);
    } else {
        FreeList(list);
    }
    GuiSubTitleDisplay_CalcLineTimes(self);
    return 1;
}
