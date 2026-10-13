#pragma cplusplus on
#include "types.h"

typedef struct { char d[0xF8]; } T_397170;
struct MapIt_397170 {
    T_397170** node;
    T_397170** mapBegin;
    T_397170** split;
    T_397170** mapEnd;
    MapIt_397170() {}
    MapIt_397170(const MapIt_397170& o) : node(o.node), mapBegin(o.mapBegin), split(o.split), mapEnd(o.mapEnd) {}
    void inc() { if (++node == mapEnd) node = mapBegin; }
};
struct It_397170 {
    MapIt_397170 m;
    T_397170* cur;
    T_397170* end;
};

extern "C" {
extern unsigned int D_004BC478;
void func_00397400(T_397170* p, int flags);
}

static inline const int& imin_397170(const int& a, const int& b) { return b < a ? b : a; }
static inline const unsigned int& umin_397170(const unsigned int& a, const unsigned int& b) { return b < a ? b : a; }

extern "C" void Array_DestroyRange(void* self, It_397170* first, It_397170* last)
{
    if (first->cur != last->cur) {
        unsigned int n;

        T_397170* p;
        T_397170* e;
        T_397170** sp = last->m.split;
        int nodes = last->m.node - first->m.node;
        if (!(last->m.node < sp)) {
            if (first->m.node < sp)
                nodes -= last->m.mapEnd - last->m.mapBegin;
        } else if (!(first->m.node < sp)) {
            nodes += last->m.mapEnd - last->m.mapBegin;
        }
        n = nodes * 8 - (last->end - last->cur) + (first->end - first->cur);
        MapIt_397170 mi(first->m); T_397170*** pe = &mi.mapEnd; T_397170*** pb = &mi.mapBegin;
        p = first->cur;
        e = p + imin_397170(n, first->end - p);
        for (;;) {
            n -= e - p;
            for (; p < e; p++) func_00397400(p, -1);
            if (n == 0) break;
            if (++mi.node == *pe) mi.node = *pb;
            p = *mi.node;
            e = p + umin_397170(n, D_004BC478);
        }
    }
}





