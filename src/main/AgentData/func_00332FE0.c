extern int func_003309C0(__int128 key);
typedef struct { char pad[0xB08]; int bits[1]; } AgentD2FE0;
int func_00332FE0(AgentD2FE0* self, __int128 key)
{
    int i = func_003309C0(key);
    if (i > -1)
        return ((self->bits[i / 32] >> (i & 31)) & 1) != 0;
    asm { .set reorder } /* barrier: keeps retail block layout */ return 0;
}