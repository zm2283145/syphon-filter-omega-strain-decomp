#pragma cplusplus on

typedef union TextStringValue {
    struct {
        unsigned int word;
        unsigned int length;
        char* data;
    } longString;
    struct {
        unsigned int isLong : 1;
        unsigned int length : 7;
    } shortString;
    char inlineData[12];
} TextStringValue;

typedef struct TextStringAllocator {
    char unused;
} TextStringAllocator;

extern "C" {
void String_Reserve(TextStringValue* string, unsigned int capacity);
TextStringValue* String_Replace(TextStringValue* string, unsigned int position,
                                unsigned int count, const char* first,
                                const char* last, TextStringAllocator allocator);
}

/* Copy inline string bytes directly and allocate owned storage for long strings. */
extern "C" TextStringValue* func_00423160(TextStringValue* self, const TextStringValue* source)
{
    TextStringAllocator allocator;
    if (!(source->longString.word & 1)) {
        *self = *source;
    } else {
        self->longString.word = 0;
        self->longString.length = 0;
        self->longString.data = 0;
        String_Reserve(self, source->longString.length);
        String_Replace(self, 0, 0, source->longString.data,
                       source->longString.data + source->longString.length, allocator);
    }
    return self;
}

/* Replace a substring with the complete inline or heap-backed source string. */
extern "C" TextStringValue* func_004231F0(TextStringValue* self, unsigned int position,
                                       unsigned int count, const TextStringValue* source)
{
    TextStringAllocator allocator;
    const char* data;
    unsigned int length;
    if (!(source->longString.word & 1)) {
        data = (const char*)source + 1;
        length = (unsigned char)source->shortString.length;
    } else {
        data = source->longString.data;
        length = source->longString.length;
    }
    return String_Replace(self, position, count, data, data + length, allocator);
}
