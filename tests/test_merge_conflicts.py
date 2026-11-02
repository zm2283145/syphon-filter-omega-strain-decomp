"""merge_units: declaration conflicts between blocks (macro-declared prototypes,
definitions in later blocks, attribute-aligned structs, C++ classes)."""
import shutil
import sys
import unittest

import configure

sys.path.insert(0, str(configure.ROOT / "tools"))
import merge_units as mu  # noqa: E402


def chunk(label, text, cpp=False):
    return mu.Chunk(label, text, "mw38", cpp)


class ClassifyTests(unittest.TestCase):
    def kinds(self, text):
        return [(i.kind, i.names) for i in mu.split_items(text)]

    def test_aligned_struct_is_a_type(self):
        self.assertEqual(self.kinds("struct V { float x, y; } __attribute__((aligned(16)));"),
                         [("type", ["V"])])

    def test_class_and_base_clause_tags(self):
        self.assertEqual(self.kinds("class C { int a; };"), [("type", ["C"])])
        self.assertEqual(self.kinds("struct D : B { int b; };"), [("type", ["D"])])

    def test_struct_tags(self):
        text = "typedef struct A { int a; } A;\nstruct B : A { int b; };\ntypedef struct { int c; } C;\n"
        self.assertEqual(mu.struct_tags(text), {("struct", "A"), ("struct", "B")})


class CallMacroTests(unittest.TestCase):
    def test_reference_parameter_is_not_cast(self):
        self.assertIsNone(mu.call_macro("f", ["void", "f", "(", "V", "&", ")"],
                                        ["void", "f", "(", "V", "*", ")"]))

    def test_proto_sig_ignores_parameter_names(self):
        a = mu.proto_sig("f", "void * f ( void * self , short d )".split())
        b = mu.proto_sig("f", "void * f ( void * , short )".split())
        self.assertEqual(a, b)


@unittest.skipUnless(shutil.which("cpp"), "needs a C preprocessor")
class PinnedPrototypeTests(unittest.TestCase):
    MACRO = "#define DTOR(n, base) void* base(void* self, short d); void* n(void* s, short d) { return base(s, 0); }\n"

    def synth(self, chunks):
        return mu.synthesize(chunks, configure.ROOT / "src", True, "t", cast=True)

    def test_macro_declared_prototype_after_a_block(self):
        a = chunk("func_00100000", "void h(void* m, int f);\nvoid g(void* p) { h(p, 0); }\n")
        b = chunk("func_00100010", self.MACRO + "DTOR(k, h)\n")
        text = self.synth([a, b])
        self.assertIn("#if 0 /* merge_units */\nvoid h(void* m, int f);\n#endif", text)
        self.assertIn("void* h(void* self, short d);", text)
        self.assertIn("#define h(a0, a1) ((void)h((a0), (short)(a1)))", text)

    def test_macro_declared_prototype_before_a_block(self):
        a = chunk("func_00100000", self.MACRO + "DTOR(k, h)\n")
        b = chunk("func_00100010", "void h(void* m, int f);\nvoid g(void* p) { h(p, 0); }\n")
        text = self.synth([a, b])
        self.assertNotIn("void* h(void* self, short d);", text)  # already declared by the macro
        self.assertIn("#define h(a0, a1) ((void)h((a0), (short)(a1)))", text)

    def test_cpp_definition_in_a_later_block(self):
        a = chunk("func_00100000", "#pragma cplusplus on\nextern \"C\" void f(void* p);\n"
                  "void g(void* p) { f(p); }\n", True)
        b = chunk("func_00100010", "#pragma cplusplus on\ntypedef struct H { int a; } H;\n"
                  "extern \"C\" void f(H* h) { h->a = 1; }\n", True)
        text = self.synth([a, b])
        self.assertIn("struct H; /* merge_units */", text)
        self.assertIn("extern \"C\" void f(H* h); /* merge_units */", text)
        self.assertIn("#define f(a0) (f((H *)(a0)))", text)

    def test_cplusplus_only_header_declaration_pins_an_object(self):
        # alloc_guard.h declares g_ProfileLockEnabled unsigned, inside #ifdef __cplusplus
        a = chunk("func_00100000", "extern signed char g_ProfileLockEnabled;\n"
                  "void g(void) { g_ProfileLockEnabled = 1; }\n")
        b = chunk("func_00100010", "#pragma cplusplus on\n#include \"alloc_guard.h\"\n"
                  "extern \"C\" int k(void) { return g_ProfileLockEnabled; }\n", True)
        text = self.synth([a, b])
        self.assertIn("extern unsigned char g_ProfileLockEnabled; /* merge_units */", text)
        self.assertIn("#define g_ProfileLockEnabled (*(signed char*)&g_ProfileLockEnabled)", text)

    def test_unprototyped_redeclaration_is_dropped(self):
        a = chunk("func_00100000", "void f(int a, void* b);\nvoid g(void) { f(1, 0); }\n")
        b = chunk("func_00100010", "int f();\nvoid k(void) { f(2, 0); }\n")
        text = self.synth([a, b])
        self.assertIn("#if 0 /* merge_units */\nint f();\n#endif /* merge_units */\n", text)


if __name__ == "__main__":
    unittest.main()
