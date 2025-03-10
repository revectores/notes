# Partial Quicksort for Paging

Many APIs implements paging mechanism, that is, recevies `pageNum` and `pageSize` in parameters and only return a slice of ordered results. If the data source is a relational database, this is usually implemented by applying `limit` and `offset` in SQL. While not all of the services store data locally, they may depend on one or more data sources that does not support sorting instead.

In this case, we may probably need to sort the results in memory by ourself then cut the required slice. Notice that the actual requirement is only a **correct range of sorted slice**, instead of sorting the entire array. Hence a variation of quicksort can be applied, which is similar to the variation of quicksort applied to the Top-K problem, but we consider both sides of edges:

```go
package utils

import (
	"golang.org/x/exp/constraints"
)

func swap[T any](elements []T, i, j int) {
	elements[i], elements[j] = elements[j], elements[i]
}

func partition[T constraints.Ordered](elements []T, left, right int) int {
	pivot := elements[right-1]
	target := left
	for cur := left; cur < right; cur += 1 {
		if elements[cur] < pivot {
			swap(elements, target, cur)
			target += 1
		}
	}
	swap(elements, target, right-1)
	return target
}

func partialQuicksort[T constraints.Ordered](elements []T, start, end, left, right int) {
	if start >= end || left >= right || right < start || end < left {
		return
	}
	pivot := partition(elements, left, right)
	partialQuicksort(elements, start, end, left, pivot)
	partialQuicksort(elements, start, end, pivot+1, right)
}

func GetSortedSubSeq[T constraints.Ordered](elements []T, start, end int) []T {
	partialQuicksort(elements, start, end, 0, len(elements))
	return elements[start:end]
}

```

Since partition process places the pivot into the correct position (that is, all smaller elements wil be placed on the left, and all larger elements will be placed on the right), once all the numbers inside sliced range are determined by partition process, they must be the expected numbers with sorted sequence.

Some test codes:

```go
package utils

import (
	"testing"

	"github.com/stretchr/testify/require"
	"golang.org/x/exp/constraints"

	"code.byted.org/lang/gg/gslice"
)

func Range[T constraints.Integer](start, end T) []T {
	elements := make([]T, 0)
	for c := start; c < end; c += 1 {
		elements = append(elements, c)
	}
	return elements
}

func TestGetSortedSubSeq(t *testing.T) {
	as := require.New(t)
	elements, expected := Range(0, 100), Range(45, 55)

	gslice.Shuffle(elements)
	subseq := GetSortedSubSeq(elements, 45, 55)
	as.Equal(subseq, expected)

	gslice.Shuffle(elements)
	seq := GetSortedSubSeq(elements, 0, 100)
	gslice.Sort(elements)
	as.Equal(seq, elements)
}
```

