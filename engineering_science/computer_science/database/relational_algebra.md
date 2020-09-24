# Relational Algebra

##### # Select Operation

Select operation $\sigma$
$$
\sigma_{dept\_name = "Physics" \and salary > 90000}(instructor)
$$
comparison between attributes is allowed, for example, to find those department whose name is exactly the building name, we use
$$
\sigma_{dept\_name = building}(department)
$$


##### # Project Operation

$$
\Pi_{ID,name,salary}(instructor)
$$

operations is allowed for the projection operation, for example, to list the month salary instead of year:
$$
\Pi_{ID, name, salary/12}(instructor)
$$


##### # Cartesian-Product Operation

$$
\sigma_{instructor.ID = teachers.ID}(instructor \times teachers)
$$

