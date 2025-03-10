# Amortized Analysis

In an amortized analysis, we average the time required to perform a sequence of data-structure operations over all the operations performed. Amortized analysis differs from average-case analysis in that probability is not involoved. Instead, it gurantees the average perforamce of each operation in the worst case.

Two simple problems that we'll apply amortized analysis to later:

- 

There are three methods to proceed amortized analysis:

- **Aggregate analysis**, in which we determine an upper bound $T(n)$ on the total cost of a sequence of $n$ operations. The average cost per operation is then $T(n)/n$.
- **Accounting Method**, in which we assign an amortized cost of each operation, store some overcharge as "prepaid credit" in the data structure (conceptually), and use this to pay for later operations.
- **Potential Method**, in which we define a



##### 

