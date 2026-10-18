#pragma opt_strength_reduction off
typedef struct {
    unsigned char key;
    char p1[5];
    unsigned short a;
    unsigned short b;
    char pA[2];
} KbEntry;

typedef struct {
    KbEntry *items;
    int count;
    int p8;
    int pC;
} KbTable;

typedef struct {
    char p0[0x64];
    int count;
    void **widgets;
    char p6C[0x8];
    int count74;
    int *types;
    char p7C[0x4];
    char vec80[0x8];
    int *index;
    char p8C[0x4];
    KbTable *tab;
    int mode;
    int f98;
    unsigned char b9C;
} KbSelf;

extern KbTable D_0052AF60[];
extern int D_004926C0;
extern char D_004B8CF0[];
extern void PtrVector_Resize(void *v, int n, int *fill);
extern void GuiTextWidget_SetText(void *w, char *s, int a, int b);
extern void GuiKeyboard_Relabel(KbSelf *self, unsigned int flags);

void GuiKeyboard_ApplyLayout(KbSelf *self, unsigned char mode)
{
    int i;
    int j;
    int off;
    self->f98 = 0;
    self->mode = mode;
    self->tab = &D_0052AF60[mode];
    PtrVector_Resize(self->vec80, *(volatile int *)&self->count, &D_004926C0);
    for (i = 0; i < *(volatile int *)&self->count; i++)
        self->index[i] = -1;
    if (self->count == self->count74) {
        if (self->tab) {
            self->b9C = 0;
            for (i = 0; i < self->count; i++) {
                KbTable *t;
                KbEntry *e;
                int key;
                int n;
                t = self->tab;
                n = t->count;
                j = 0;
                if (j < n) {
                    e = t->items;
                    key = self->types[i];
                    do {
                        if (e->key == key) {
                            self->index[i] = j;
                            GuiTextWidget_SetText(self->widgets[i], D_004B8CF0, 0, j);
                            break;
                        }
                        j++;
                        e++;
                    } while (j < n);
                }
            }
            {
                int k;
                int off;
                k = 0;
                if (k < self->tab->count) {
                    off = 0;
                    do {
                        KbEntry *e = (KbEntry *)((char *)self->tab->items + off);
                        if (e->a != 0xFFFF || e->b != 0xFFFF)
                            self->b9C = 1;
                        k++;
                        off += sizeof(KbEntry);
                    } while (k < self->tab->count);
                }
            }
        }
        GuiKeyboard_Relabel(self, 0);
    }
}






