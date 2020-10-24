# Qt Data Type

### 1. `QString`







### 2. Datetime

<u>Introduce the usage of `QDate` and `QTime`.</u>



##### # Initialization

<u>Introduce the init methods of `QDate` and `QString`, includes manual setting and getting from current time. As also the stringify method.</u>

Set date during initialization or use `setDate()` method: 

```c++
QDate dt1(2020, 10, 10);
QDate dt2;
dt2.setDate(2020, 10, 10);
```

`toString()` method converts `QDate` into `QString`:

```c++
QTextStream out(stdout);
out << dt1.toString("yyyy-MM-dd") << Qt::endl;
// 2020-10-10
```

Same for the `QTime`:

```c++
QTime tm1(20, 26, 40, 100);
QTmie tm2;
tm2.setHMS(20, 26, 40, 100);

out << tm1.toString("hh:mm:ss.zzz") << Qt::endl;
// 20:26:40.100
```

Use `currentDate()` and `currentTime()` method to get the current date/time:

```C++
QDate cd = QDate::currentDate();
QTime ct = QTime::currentTime();
```



##### # Operation

<u></u>

Comparison is supported for `QDate` and `QTime`:

```c
QDate dt1(2020, 10, 10);
QDate dt2(2020, 9, 9);
QTime tm1(18, 00, 00);
QTime tm2(20, 26, 40);

out << (dt1 > dt2) << (tm1 < tm2) << Qt::endl;
```







