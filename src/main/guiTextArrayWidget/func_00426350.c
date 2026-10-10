#include "guiTextArrayWidget_types.h"

extern void func_00424750(guiTextArrayWidget* self, unsigned int columns, unsigned int rows);
extern void func_00426600(guiTextArrayWidget* self, unsigned int columns, unsigned int rows);

/* Update the base dimensions and rebuild the cells only when the shape changes. */
void func_00426350(guiTextArrayWidget* self, unsigned int columns, unsigned int rows)
{
    if (columns != self->columns || rows != self->rows) {
        func_00424750(self, columns, rows);
        func_00426600(self, columns, rows);
    }
}
