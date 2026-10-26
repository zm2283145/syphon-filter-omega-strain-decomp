typedef struct { char pad[0x30]; int f30; int f34; } ScfObj_620;
int VU0CheckStores(ScfObj_620 *o)
{
    if (o != 0 && o->f30 != 0 && o->f34 != 0) return 0;
    return 0x181A;
}