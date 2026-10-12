typedef struct N8480 { struct N8480 *next; int a; int id; } N8480;
unsigned int D_00492CD8[1] = { 0x0 };
N8480 *func_00358480(int id)
{
    N8480 *n;
    for (n = (*(N8480 **)D_00492CD8); n; n = n->next)
        if (id == n->id) return n;
    return 0;
}