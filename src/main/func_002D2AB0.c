/* Returns 1 when the attached object's flag bytes 0x2D and 0x2C are set and 0x2E is clear. */
typedef struct { char p0[0x2C]; unsigned char b2C, b2D, b2E; } C2D2AB0;
typedef struct { char p0[0x60]; C2D2AB0* c; } B2D2AB0;
typedef struct { char p0[0x1E8]; B2D2AB0* b; } A2D2AB0;
#pragma push
#pragma optimization_level 1
#pragma schedule on
unsigned char cNetNPC_IsNodeInActiveTerrain(A2D2AB0* a)
{
    B2D2AB0* b = a->b;
    if (b) {
        C2D2AB0* c;
        unsigned char r;
        r = 0;
        c = b->c;
        if (c) { int ok = c->b2D && c->b2C && !c->b2E; if (ok) r = 1; }
        return r;
    }
    return 0;
}
#pragma pop
