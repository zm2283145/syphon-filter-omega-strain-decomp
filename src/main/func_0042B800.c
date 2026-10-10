extern void operator_delete(void* allocation);

/* Empty deleting destructor; the object's concrete type is not yet known. */
void* func_0042B800(void* self, short deleteFlag) {
    if (self != 0 && deleteFlag > 0) {
        operator_delete(self);
    }
    return self;
}
