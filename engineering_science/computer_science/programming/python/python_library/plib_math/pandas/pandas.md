# Pandas

### 1. DataFrame Basic Operation

##### # Construction

<u>Introduce two approaches to create new `DataFrame`, from dictionary and from nested list.</u>

A `pandas.DataFrame` is no more than a named matrix, which can be constructed by dictionary or two-dimension nested list:

```python
import numpy as np
import pandas as pd


persons_dict = {
    'Name':   ['Robert', 'John', 'Harry'],
    'Age':    [18, 30, 55],
    'Wealth': [2000.0, 100000.0, -100.0],
}

persons_list = [
    ['Robert', 18, 2000.0],
    ['John', 30, 100000.0],
    ['Harry', 55, -100.0],
]

persons = pd.DataFrame(data=persons_dict)
'''
     Name  Age    Wealth
0  Robert   18    2000.0
1    John   30  100000.0
2   Harry   55    -100.0
'''

persons = pd.DataFrame(data=persons_list)
'''
        0   1         2
0  Robert  18    2000.0
1    John  30  100000.0
2   Harry  55    -100.0
'''
```

As shown this two source data format represents two different perspectives of matrix, the dictionary format is field-distributed, each key-value pairs stores one field of database, while list format is record-distributed, each list represents a record.

Notice that the list structure can't provide information about column names from the data structure itself, to name the columns we need to use keyword parameter `columns` to specify:

```python
persons = pd.DataFrame(data=persons_list, columns=['Name', 'Age', 'Wealth'])
'''
     Name  Age    Wealth
0  Robert   18    2000.0
1    John   30  100000.0
2   Harry   55    -100.0
'''
```

With `columns` keyword applied to the dictionary source, we can get those columns we want and ignore others:

```python
persons = pd.DataFrame(data=persons_dict, columns=['Name', 'Wealth'])
'''
     Name    Wealth
0  Robert    2000.0
1    John  100000.0
2   Harry    -100.0
'''
```

If no record indexes are specified, natural integer will be applied, we could change this by using `index` keyword. The type of the row index can be any hashable type:

```python
persons = pd.DataFrame(data=persons_dict, index=[1,2])


persons = pd.DataFrame(data=persons_dict, index=['Person_1', 'Person_2', 'Person_3'])
'''
            Name  Age    Wealth
Person_1  Robert   18    2000.0
Person_2    John   30  100000.0
Person_3   Harry   55    -100.0

'''


persons = pd.DataFrame(data=persons_dict, index=[('Person_1', 1), ('Person_2', 2), ('Person_3', 3)])
'''
                 Name  Age    Wealth
(Person_1, 1)  Robert   18    2000.0
(Person_2, 2)    John   30  100000.0
(Person_3, 3)   Harry   55    -100.0
'''


# We can even use multiple keys to each record, by which we cloud achieve a record by mutliple ways:
persons = pd.DataFrame(data=persons_dict, index=[['Person_1', 'Person_2', 'Person_3'], [1, 2, 3]])
'''
              Name  Age    Wealth
Person_1 1  Robert   18    2000.0
Person_2 2    John   30  100000.0
Person_3 3   Harry   55    -100.0
'''
```

<u>This concluded the basic methods of constructing `pandas.DataFrame`.</u> The full document of `pandas.DataFrame` can be found at [pandas.DataFrame document](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.html).



##### # Fields/Records/Elements Access

###### - Implemented `__sub__` method

The most natural way of achieving a field is its name since the DataFrame type implement the `__sub__` method to get a field:

```python
persons = pd.DataFrame(data=persons_dict)

names = persons['Name']
'''
0    Robert
1      John
2     Harry
Name: Name, dtype: object
'''


# Using this syntax to get a subDataFrame:
names_with_wealth = persons[['Name', 'Wealth']]
'''
     Name  Age
0  Robert   18
1    John   30
2   Harry   55
'''

print(type(names_with_wealth))
# <class 'pandas.core.frame.DataFrame'>
```

###### - `loc` and `iloc` Object

`__sub__` method just provide a simple way to access column. For more precise and powerful access control, Object `dataframe.loc` and `dataframe.iloc` provides an interface for this task, which two are responsible for **name-approach** and **coordinate-approach** respectively.

```python
persons = pd.DataFrame(data=persons_dict, index=['Person_1', 'Person_2'])

person_2_wealth_by_name  = persons.loc['Person_2', 'Wealth']
person_2_wealth_by_index = persons.iloc[1, 2]

print(person_2_wealth_by_name, person_2_wealth_by_index)
```

The usage of these two are basically the same, we'll only give usage of object `loc` for the conciseness and realibility, most of the following example can be moved into `iloc` object painlessly.

As shown above, we could access element by using names of record and field directly. With the **slice** syntax applied, we can get a **subDataFrame** of the `DataFrame`, more than a single element:

```python
persons_copy = persons.loc['Person_1':'Person_2', ['Name', 'Wealth']]

print(persons_copy)
print(type(persons_copy))
'''
            Name    Wealth
Person_1  Robert    2000.0
Person_2    John  100000.0
<class 'pandas.core.frame.DataFrame'>
'''
# Notice that contrary to usual python slices, both the start and the stop are included. This is normal case in the science package of python.
```

This demo demostrates that the name coordinate can be replaced by slice or a list of valid names, by which we could still get a `DataFrame` returned.

If one of the names is omiited, the entire column/row will be selected and returned as `pandas.Series`, which is a built-in type of `pandas`. a `Series` can be considered as a special `DataFrame` which got only 1 field or record.

```python
# Column name is omiited. Equivlant to persons.loc['Person_2']
person_2 = persons.loc['Person_2', :]

print(person_2)
print(type(person_2))
'''
Name        John
Age           30
Wealth    100000
Name: Person_2, dtype: object
<class 'pandas.core.series.Series'>
'''


# Row name is omitted. This is an equivlance to persons['Name']
names = persons.loc[:, 'Name']

print(names)
print(type(names))
'''
Person_1    Robert
Person_2      John
Person_3     Harry
Name: Name, dtype: object
<class 'pandas.core.series.Series'>
'''
```



###### - Access Element From `Series`

After getting the `Series` Object from original `DataFrame`, it's easy to get the element by names or index based on the index of `Series`:

```python
persons = pd.DataFrame(data=persons_dict, index=['Person_1', 'Person_2'])

# Access element in Column Series.
w1 = persons['Wealth'][1]
w2 = persons['Wealth']['Person_2']

# Access element in Row Series.
w3 = persons.iloc[1]['Wealth']
w4 = persons.loc['Person_2']['Wealth']

assert len(set([w1, w2, w3, w4])) == 1
```

<u>This concludes how to access columns/rows/elements through name or index.</u>



##### # Useful Properites and Member Functions

###### - DataType of Columns

It's valid to keep different types for different columns, using `dtypes` attribute to get the types of columns:

```python
print(persons.dtypes)
'''
Name       object
Age         int64
Wealth    float64
dtype: object
'''
```

###### - Names of Columns and Rows 

To get the names of columns or rows, just use attribute `columns` or `index`:

```python
column_names = persons.columns
row_names = persons.index

print(column_names)
print(row_names)
# Index(['Name', 'Age', 'Wealth'], dtype='object')
# Index(['Person_1', 'Person_2'], dtype='object')


print(type(column_names)) # <class 'pandas.core.indexes.base.Index'>
assert type(column_names) == type(row_names)
```

The type of `columns` is `Index`, we can consider it as simple list, the iteration and `in` method are well-supported. If you really want to convert this into a list, instead of manually make a iteration, use `dataframe.columns.values.tolist()` instead. The `values` property get the `np.ndarray` represent of column names, and numpy array support the conversion from array to list.

<u>This concludes several of useful properties and functions of DataFrame. More precisesely, the datatype of columns and the names of columns and rows are included.</u> Some other not-so- frequently used properties and member function will be introduced in [Properties and Function of pandas.DataFrame](Properties and Function of pandas.DataFrame).



##### # Iteration over Fileds or Records

Notice that the default iteration over the DataFrame is just simple **column names**:

```python
[print(properity, sep=', ') for properity in persons]
# Name, Age, Wealth

# Since we could get column by its name, it can be converted to iterate the columns:
for properity in persons:
    print(persons[properity])
```

Anyway this approach is not elegant, use `dataframe.iteritems()` generator and `dataframe.iterrows()` generator to iterate over fields and records:

```python
for properity in persons.iteritems():
    print(properity)
    print(type(properity))
    
'''
('Name', 0    Robert
1      John
Name: Name, dtype: object)
<class 'tuple'>

('Age', 0    18
1    30
Name: Age, dtype: int64)
<class 'tuple'>

('Wealth', 0      2000.0
1    100000.0
Name: Wealth, dtype: float64)
<class 'tuple'>
'''


for person in persons.iterrows():
    print(person)
```

Notice that these two iterations don't generate `Index` object but simple `tuple` structure.







### 2. Further Operations on DataFrame

##### # Comparation

Notice that `np.nan` will not be treated equal during equlity check implemented by `__eq__`, it's recommanded to use `dataframe.equals()` method instead.

```python
df = pd.DataFrame(data=[[1, 2], [3, np.nan]])
print(all(df == df))  # False
print(df == df)
'''
      0      1
0  True   True
1  True  False
'''

print(df.equals(df))  # True
```







### 3. DataFrame IO with Excel/CSV file

##### # Get Data From Excel

There're many details during operation with table file. 

