import unittest

from relation import Relation, dependency_generater


class TestRelation(unittest.TestCase):

    def test_closure(self):
        pass

    def test_get_attributes_closure(self):
        complete_attrs = set(list('ABCDEFGHI'))
        dep_pairs = [('A', 'B'), ('A', 'C'), ('CG', 'H'), ('CG', 'I'), ('B', 'H')]
        deps = dependency_generater(dep_pairs)

        r = Relation(attrs=complete_attrs, deps=deps)

        attrs = set(['A', 'G'])
        expect_closure = set(['A', 'B', 'C', 'G', 'H', 'I'])
        closure = r.get_attrs_closure(attrs)
        self.assertEqual(expect_closure, closure)


if __name__ == '__main__':
    unittest.main()
