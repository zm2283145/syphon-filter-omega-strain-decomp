typedef struct Item { char pad[0x10]; int idx; } Item;
typedef struct Ui { char pad[0x20]; Item *focus; } Ui;
typedef struct Self { char pad[0x6C]; void *items[24]; } Self;
extern Ui *func_004147A0(void);
extern void func_00414B30(Ui *ui, void *w);

void func_0034D770(Self *self, int dir)
{
    Item *f;
    int idx;
    int col;
    int row;

    f = func_004147A0()->focus;
    if (f == 0 || (idx = f->idx) == -1)
        return;
    col = idx % 4;
    row = idx / 4;
    switch (dir) {
    case 0:
        col--;
        break;
    case 1:
        col++;
        break;
    case 2:
        row--;
        break;
    case 3:
        row++;
        break;
    }
    col = col < 0 ? 3 : (col >= 4 ? 0 : col);
    row = row < 0 ? 5 : (row >= 6 ? 0 : row);
    func_00414B30(func_004147A0(), self->items[row * 4 + col]);
}

