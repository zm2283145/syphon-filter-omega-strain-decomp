typedef struct Item { char pad[0x10]; int idx; } Item;
typedef struct Ui { char pad[0x20]; Item *focus; } Ui;
typedef struct Self { char pad[0x6C]; void *items[24]; } Self;
extern Ui *Gui_GetScreenStack(void);
extern void GuiScreen_SetFocus(Ui *ui, void *w);

void GuiRatings_MoveGrid(Self *self, int dir)
{
    Item *f;
    int idx;
    int col;
    int row;

    f = Gui_GetScreenStack()->focus;
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
    GuiScreen_SetFocus(Gui_GetScreenStack(), self->items[row * 4 + col]);
}

