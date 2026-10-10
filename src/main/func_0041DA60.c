typedef struct GuiWidgetValueSlot {
    char pad00[0x10];
    int value;
} GuiWidgetValueSlot;

extern GuiWidgetValueSlot* func_0041DB80(void* self, const char* name);

/* Set a named widget's value when that widget exists. */
int func_0041DA60(void* self, const char* name, int value)
{
    GuiWidgetValueSlot* widget = func_0041DB80(self, name);
    if (widget) {
        widget->value = value;
        return 1;
    }
    return 0;
}
