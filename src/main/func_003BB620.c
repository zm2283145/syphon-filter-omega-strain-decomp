/* Set the 1-bit field at bit 5 and the 3-bit field at bits 6..8 of the 64-bit
 * register word at +0x58 from flag bits 2/3 of g_DrawMode. */
typedef struct {
    char pad[0x58];
    unsigned long reg;              /* 0x58 */
} Obj003BB620;

extern int g_DrawMode;

unsigned long* Gs_MakeTex1(Obj003BB620* self)
{
    unsigned int enable;
    unsigned int mode;
    unsigned char bit4;
    unsigned char bit8;
    int flags;
    enable = 0;
    mode = 0;
    flags = g_DrawMode;
    bit4 = (flags & 4) != 0;
    bit8 = (flags & 8) != 0;
    if (flags & 0xC) {
        enable = 1;
        if (bit4) mode = 4;
        else if (bit8) mode = 5;
    }
    self->reg &= ~(unsigned long)0x1E0;
    self->reg |= ((unsigned long)enable << 5) | ((unsigned long)mode << 6);
    return &self->reg;
}
