typedef struct { __int128 v; float a; float b; signed char f; } MM24;
#pragma push
#pragma optimization_level 3
MM24 *MoveMsg_Set(MM24 *m, __int128 *v, float a, float b, int flag) {
    signed char c;
    m->v = *v;
    m->a = a;
    m->b = b;
    /* barrier: empty asm keeps the branchy bool (b + delay slot) shape */
    if (flag) { c = 1; asm { .set reorder } } else c = 0;
    m->f = c;
    return m;
}
#pragma pop