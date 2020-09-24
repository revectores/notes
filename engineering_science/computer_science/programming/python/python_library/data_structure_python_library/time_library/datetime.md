# Datetime

`datetime.date`, `datetime.time` and `datetime.datetime` are three time-point representing and processing classes provided by the `datetime` package, as well as the `timedelta` package which represents the time interval. These packages have pretty good designs with following features:

- OOP design, the data structure and interface are human-readable.
- The operations and calculation of time are supported well.
- Flexible Format & Deformat approach.



### 1. Basic Usage of `datetime` Package Toolkits

##### # Package Import

The same as the other packages, two import method used for `datetime`:

```python
import datetime
```

```python
from datetime import datetime, date, time, timedelta
```

Notice that there exists a `time` package in the python standard library also. We should avoid the name confliction between packages. In order to keep the conciseness, we'll use the second method to accomplish our notes and not to use the `time` package of STL.



##### # Initialization and Data Access

```python
from datetime import datetime, timedelta

now = datetime.now()
datetime_datetime_demo = datetime(
  year=2019, month=9,   day=17,
  hour=20,   minute=10, second=40
)
# These two initializations create `datetime` objects:
type(now)   # <class 'datetime.datetime'>
print(now)  # datetime.datetime(2019, 11, 12, 22, 28, 15, 427165)
print(datetime_demo) # datetime.datetime(2019, 9, 17, 20, 10, 40)
```

With the initialization finished, we're able to access each comp.