/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern Quad4Ext* func_00393D10(Quad4Ext* q);
extern Quad4Ext* func_00393D40(Quad4Ext* q);
extern Quad4* func_00393EC0(Quad4* q);

Rel* func_00393CC0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Quad4Ext* func_00393CE0(Quad4Ext* q) {
    func_00393D10(q);
    return q;
}

Quad4Ext* func_00393D10(Quad4Ext* q) {
    func_00393D40(q);
    return q;
}

Quad4Ext* func_00393D40(Quad4Ext* q) {
    func_00393EC0(&q->q);
    q->unk10 = 0;
    q->unk14 = 0;
    return q;
}
