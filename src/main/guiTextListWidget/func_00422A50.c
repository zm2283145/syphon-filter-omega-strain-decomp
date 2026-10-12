#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "tstr_types.h"

extern "C" {
void func_0013BCB0(void* d, const void* s);
extern char D_004BF5C0[];
extern char D_004BF618[];
void func_00422F10(TextListEntry* d, unsigned int n, const TextListEntry* v);
void func_00422F80(TextListEntry* f, TextListEntry* l, TextListEntry* d);
}

typedef struct Vec22 {
    unsigned int cap;
    unsigned int count;
    TextListEntry* data;
} Vec22;

extern "C" {
void func_00422ED0(Vec22* a, Vec22* b);
void func_00423000(Vec22* v, int flag);
}

static inline void construct(TextListEntry* p, const TextListEntry* v)
{
    if (p) {
        func_0013BCB0(p, v);
        p->unk0C = v->unk0C;
        p->unk10 = v->unk10;
    }
}

#define T TextListEntry
extern "C" void func_00422A50(Vec22* v, T* pos, unsigned int n, const T* value)
{
    if (n == 0)
        return;
    if (n > 0x4CCCCC || v->count > 0x4CCCCC - n) {
        func_00123BE8(D_00489738->stream, D_004BF5C0);
        func_00121B60();
    }
    if (v->count + n <= v->cap) {
        T* p; T* q; T* src; T* dst; T* end;
        end = v->data + v->count;
        unsigned int after = end - pos;
        if (after < n) {
            p = end;
            for (; after < n; n--) {
                construct(p, value);
                p++;
                v->count++;
            }
            for (q = pos; q < end; q++, p++) {
                construct(p, q);
                v->count++;
            }
        } else {
            src = end - n;
            dst = end;
            for (; src < end; src++, dst++) {
                construct(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            func_00422F80(pos, pos + (after - n), end);
        }
        func_00422F10(pos, n, value);
    } else {
        Vec22 tmp;
        T* dst;
        unsigned int newCap;
        T** tdata;
        T* src;
        unsigned int* tcount;
        T* srcEnd;
        unsigned int need;
        tcount = &tmp.count;
        tdata = &tmp.data;
        tmp.cap = 0;
        *tcount = 0;
        *tdata = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < 0x266666)
                newCap *= 2;
            else
                newCap = 0x4CCCCC;
        }
        *tdata = (T*)TStr_Alloc(newCap * sizeof(T), D_004BF618, 0x5C);
        tmp.cap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = *tdata;
        for (; src < pos; src++, dst++) {
            construct(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            construct(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            construct(dst, src);
            (*tcount)++;
        }
        func_00422ED0(&tmp, v);
        func_00423000(&tmp, -1);
    }
}
