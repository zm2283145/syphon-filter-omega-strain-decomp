"""merge_units: free operator functions are named by operator and parameters (overloads never collide)."""
import sys
import unittest

import configure

sys.path.insert(0, str(configure.ROOT / "tools"))
import merge_units  # noqa: E402


class OperatorNameTests(unittest.TestCase):
    def names(self, text):
        return [(i.kind, i.names) for i in merge_units.split_items(text)]

    def test_free_operator(self):
        self.assertEqual(self.names("static inline V operator * ( float s , V v ) { return v; }"),
                         [("func", ["operator*(floats,Vv)"])])

    def test_overloads_differ(self):
        a = self.names("static inline V operator*(float s, V v) { return v; }")[0][1][0]
        b = self.names("static inline C operator*(float k, const C& y) { return y; }")[0][1][0]
        self.assertNotEqual(a, b)

    def test_call_operator(self):
        self.assertEqual(self.names("bool operator()(int a) { return a; }"), [("func", ["operator()(inta)"])])

    def test_plain_function(self):
        self.assertEqual(self.names("int g(int x) { return x; }"), [("func", ["g"])])


if __name__ == "__main__":
    unittest.main()
