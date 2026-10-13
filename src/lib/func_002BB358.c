/* Scale x by the num/den ratio of record i, then forward to func_002BB300. */
typedef struct {
    int pad[10];
    unsigned short pad2;
    unsigned short num;
    unsigned short den;
    unsigned short pad3;
    int rest[(0x184 - 0x30) / 4];
} Rec2BB358;

extern Rec2BB358 D_0048BD90[];
extern int func_002BB300(int, int);

int func_002BB358(int i, int x)
{
    Rec2BB358* r = &D_0048BD90[i];
    return func_002BB300(i, x * r->num / r->den);
}
