from itertools import chain, combinations


def power_set(A):
    if not A: return {frozenset()}
    a = A.pop()
    B = power_set(A)
    return B.union([b.union([a]) for b in B])


def dependency_generater(attr_pairs: list[tuple[str]]) -> set[tuple[frozenset]]:
    return set([(frozenset(list(p)), frozenset(list(q))) for p, q in attr_pairs])


class Relation:
    def __init__(self, attrs: set, deps: set[tuple[frozenset]]):
        self.attrs = attrs
        self.deps  = deps
    
    @property
    def trivial_deps(self):
        pass

    @property
    def deps_closure(self):
        closure = self.deps
        modified = True

        while modified:
            modified = False
            for dep in deps:
                pass


    def get_attrs_closure(self, attrs):
        assert attrs <= self.attrs
        attrs_closure = attrs
        modified = True

        while modified:
            modified = False
            for p, q in self.deps:
                if p <= attrs_closure and not q <= attrs_closure:
                    attrs_closure = attrs_closure.union(q)
                    modified = True

        return attrs_closure


if __name__ == '__main__':
    print(power_set(set([1,2,3])))
