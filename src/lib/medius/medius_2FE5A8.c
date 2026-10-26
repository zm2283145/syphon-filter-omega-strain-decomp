/*
 * lib/medius: 2 files, 002FE5A8-002FE720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FE5A8 */
typedef struct { char p[0x3C]; void *h3C; char q[0x38]; void *conn[2]; } S2FE5A8;
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern S2FE5A8 **D_004908F4;
extern int rt_circ_buf_destroy(void *);
extern int rt_memory_free(void *);
extern void *memset(void *, int, unsigned int);
extern void KM_Destroy(int);
int rt_msg_client_free_connection_index(unsigned short id)
{
    unsigned int i;
    char *e;
    if (D_004908EC != 1) return 5;
    if (id >= D_004908F0) return 2;
    if (D_004908F4[id] != 0) {
        for (i = 0; i < 2; i++) {
            e = ((struct { char pad[0x70]; char *arr[2]; } *)((char *)D_004908F4[id] + 8))->arr[i];
            if (e) {
                rt_circ_buf_destroy(e + 0x50);
                rt_circ_buf_destroy(((struct { char pad[0x70]; char *arr[2]; } *)((char *)D_004908F4[id] + 8))->arr[i] + 0x68);
                rt_memory_free(&D_004908F4[id]->conn[i]);
            }
        }
        if (D_004908F4[id]->h3C) rt_memory_free(&D_004908F4[id]->h3C);
        memset(D_004908F4[id], 0, 0x98);
        rt_memory_free(&D_004908F4[id]);
        D_004908F4[id] = 0;
    }
    KM_Destroy(id);
    return 0;
}
/* merge_units: end func_002FE5A8 */

/* merge_units: begin func_002FE720 */
typedef struct C2FE720 { char pad[6]; unsigned short id; } C2FE720;
typedef struct {
    unsigned short id; short pad;
    int f4;
    unsigned int f8;
    char pad2[0x78 - 0xC];
    C2FE720 *sub[2];
    C2FE720 *main;
} O2FE720;
extern int rt_msg_client_is_valid_channel(C2FE720 *);
int rt_msg_client_is_valid_connection(O2FE720 *o)
{
    unsigned int i;
    C2FE720 *p;
    if (o == 0) return 0;
    if (o->f8 < 2) return 0;
    if (!rt_msg_client_is_valid_channel(o->main)) return 0;
    for (i = 0; i < 2; i++) {
        p = o->sub[i];
        if (p) {
            if (o->id != p->id) return 0;
            if (!rt_msg_client_is_valid_channel(p)) return 0;
        }
    }
    return 1;
}
/* merge_units: end func_002FE720 */
