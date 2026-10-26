#pragma cplusplus on
#include "types.h"

struct V4S { float x, y, z, w; };
struct SLine {
    float dur;
    int pad4[3];
    V4S color;
    int x;
    int y;
    int textOff;
    int len;
};
struct SNode {
    SNode* prev;
    SNode* next;
    int pad8[2];
    SLine data;
};
struct SIt {
    SNode* p;
    SIt() {}
    SIt(SNode* n) { p = n; }
    SIt(const SIt& o) { p = o.p; }
    SLine* operator->() { return &p->data; }
    SIt& operator++() { p = p->next; return *this; }
    SIt Post() { SIt t = *this; ++*this; return t; }
    SIt operator++(int) { SIt r = Post2(); return r; }
    SIt Post2() { return Post(); }
};
struct SList { int pad0; SNode head; };
struct FVec { int n; float* d; float& operator[](int i) { return d[i]; } };
struct TextPos { int x, y; };
struct SubW {
    char pad0[0x34];
    float x;
    float y;
    char pad3C[0xC];
    TextPos* obj;
    int font;
    char* text;
    float t;
    char pad58[4];
    int count;
    SList** lists;
    char pad64[8];
    FVec times;
    char pad74[4];
    int maxLines;
};
typedef struct SMtx { __int128 r[4]; } SMtx;
typedef struct SRender {
    char pad0[0xA80];
    SMtx mtx[0x14];
} SRender;

extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern char D_00538C68;
SIt* func_00457FB0(SIt* self, SNode* n);
SNode* func_00457FC0(SList* l);
SNode* func_00457FD0(SNode* h);
char* strncpy(char* d, const char* s, int n);
int Font_GetLineHeight(int font);
void TextObj_Draw(TextPos* o);
void TextObj_SetColour(TextPos* o, V4S* c);
void TextObj_SetText(TextPos* o, char* s);
void GuiWidget_Draw(SubW* w);
void GuiSubTitleDisplay_Draw(SubW* self);
}

static inline SMtx* MtxAt(int i) { return &((SRender*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline SIt Begin(SList* l) { SIt t(func_00457FD0(&l->head)->next); return t; }
static inline SIt End(SList* l) { SIt t; func_00457FB0(&t, func_00457FC0(l)); return t; }
static inline const int& Min(const int& a, const int& b) { return a < b ? a : b; }
static inline void SetPos(TextPos* o, int x, int y) { o->x = x; o->y = y; }
static inline const int& Max(const int& a, const int& b) { return a < b ? b : a; }
static inline bool operator!=(const SIt& a, const SIt& b) { return a.p != b.p; }

void GuiSubTitleDisplay_Draw(SubW* self)
{
    if (self->text && self->count) {
        int first;
        int last;
        int i;
        float alpha;
        float t;
        { int k = D_00538C64; GQR(MtxAt(k + 1), MtxAt(k)); }
        D_00538C64++;
        UM(MtxAt(D_00538C64));
        D_00538C68 = 1;
        first = 0;
        alpha = 1.0f;
        last = self->count - 1;
        if (self->maxLines) {
            int j;
            last = 0;
            for (j = self->times.n - 1; j > 0; j--) {
                if (self->times[j - 1] <= self->t) {
                    last = j;
                    first = j - (self->maxLines - 1);
                    first = first < 0 ? 0 : first;
                    break;
                }
            }
            if (j == self->times.n - 1)
                alpha = 1.0f;
            else if (j == 0)
                alpha = (self->times[j] - self->t) / self->times[j];
            else
                alpha = (self->times[j] - self->t) / (self->times[j] - self->times[j - 1]);
        }
        if (first == 0)
            t = 0.0f;
        else
            t = self->times[first - 1];
        for (i = first; i <= last; i++) {
            SList* l = self->lists[i];
            for (SIt it = Begin(l); it != End(l); it++) {
                char buf[0x100];
                V4S c;
                int nch;
                int y;
                t += it->dur;
                if (!(t <= self->t))
                    goto done;
                nch = (int)(20.0f * (self->t - t));
                if (nch <= 0)
                    goto done;
                nch = nch < it->len ? nch : it->len;
                strncpy(buf, self->text + it->textOff, nch);
                buf[nch] = 0;
                float fy = (float)it->y; y = (int)(self->y - fy);
                if (self->maxLines && !(last - first < self->maxLines - 1)) {
                    float h = (float)Font_GetLineHeight(self->font);
                    y += (float)first * h + (1.0f - alpha) * h;
                }
                float fx = (float)it->x; SetPos(self->obj, (int)(self->x + fx), y);
                c = it->color;
                if (i == first && !(last - first < self->maxLines - 1))
                    c.w = alpha;
                TextObj_SetColour(self->obj, &c);
                TextObj_SetText(self->obj, buf);
                TextObj_Draw(self->obj);
                t += (float)nch / 20.0f;
            }
        }
    done:
        D_00538C64--;
        D_00538C68 = 1;
    }
    GuiWidget_Draw(self);
}
