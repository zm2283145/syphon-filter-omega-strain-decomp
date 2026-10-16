/* Model_SetupExtraTable: relocate the extra-table entry list and each entry's
 * {ptr, n, data[n]} record chain from file offsets to pointers. */
typedef struct Ent { int id; int *data; } Ent;
typedef struct Hdr {
    char pad0[0x10];
    int x10;
    char pad14[4];
    int x18;
    int count;
    char pad20[0x38];
    Ent *ents;
    char pad5C[0xC];
    int x68;
} Hdr;
typedef struct Model {
    char *base;
    Hdr *hdr;
} Model;
void Model_SetupExtraTable(Model *m)
{
    int i;
    int *q;
    if (!m->hdr->x18 || !m->hdr->x10) return;
    m->hdr->ents = (Ent *)((int)m->base + (int)m->hdr->ents);
    for (i = 0; i < m->hdr->count; i++) {
        Ent *e = &m->hdr->ents[i];
        e->data = (int *)((int)m->base + (int)e->data);
        q = e->data;
        while (q[0]) {
            *(int **)q = (int *)((int)m->base + (int)*(int **)q);
            {
                int n = q[1];
                q += 2;
                asm { .set reorder } /* scheduling barrier: keeps q += 2 ahead of the n*4 shift */
                q += n;
            }
        }
    }
    m->hdr->x68 = -1;
}
