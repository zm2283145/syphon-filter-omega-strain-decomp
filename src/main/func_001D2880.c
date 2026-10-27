/* Saves slot idx's 3-row matrix (+0x80) into its output block (+0xD0); lq/sq quad copies as asm. */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V& operator=(const V& o) { const V* ps = &o; V* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct M3 { V r[3]; };
struct Slot { char pad[0x80]; M3 saved; char pad2[0x20]; M3 out; };
extern "C" Slot UpperBodyNodeTable[];
#pragma opt_propagation off
extern "C" void cHumanIkRoutine_UpdateHipBeforeDoingLegIk(void* self, int idx)
{
    Slot* s = &UpperBodyNodeTable[idx]; const M3* o = &s->saved; M3* d = &s->out; *d = *o;
}

