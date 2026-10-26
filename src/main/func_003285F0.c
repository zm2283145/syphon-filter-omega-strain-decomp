typedef struct { char d[0x20]; } E285F0;
typedef struct { char pad[0x4C]; int count; E285F0* items; } T285F0;E285F0* GuiSlideShow_GetSection(T285F0* self, int i)
{
    if (i < 0 || self->count <= i) return 0;
    return &self->items[i];
}
