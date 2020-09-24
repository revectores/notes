# Triangle

### 1. Basic Concepts

##### # Definition

Notes: This document describes the triangle in Euclidean geometry and Euclidean plane.



### 2. Classification

The triangle can be classified according to the sides or the angles.



##### # Classify By Sides

By sides, the triangle can be classified as equilateral triangle, isosceles triangle, and scalene triangle.

- The **equilateral triangle** has all sides the same length. In fact, you can prove that all the angles are also the same, as $60^\circ$.

- The **isosceles triangle** has two sides of equal length. An isosceles triangle also has two angles of the same measure, namely the angles opposite to the two sides of the same length, which named as **isosceles triangle theorem**, which is known and proved by Euclid. Notice that the equilateral triangle is a special isosceles triangle.

- The **scalene triangle** has all its sides of different lengths. Equivalently, it has all angles of different measure.



##### # Classify by Angles

By angles, the triangle can be classified as right triangle, acute triangle, and obtuse triangle.

**Right triangle** has one of its interior angles as the right angle. Right triangle might be the most important triangle, even the most important shape, since all the triangles can be divided into two right triangle, and all the shaped constructed by lines can be expressed by the right triangle eventually. The relation between the sides and angles of a right triangle is the basis for **trigonometry**.

New names are introduced for the right triangle: The side opposite the right angle is called the **hypotenuse**, and the sides adjacent to the right angle are called **legs** or **catheti** (singular: **cathetus**).

A triangle is a **oblique triangle** if it's not a triangle. The **acute triangle** has all its angles acute. The **obtuse triangle** has one angle more than $90^\circ$.

Based on the law of cosine, the sides relation for each shape is: (where the $c$ is the longest side of triangle)

- The right triangle, $a^2 + b^2 = c^2$.

- The acute triangle, $a^2 + b^2 > c^2$.

- The obtuse triangle, $a^2 + b^2 < c^2$.







### 4. Associated Geometry Object

##### # Introduction

Thousands of geometry object (especially points) associated with the triangle, and each of them satisfying some unique property. Often, a special point is constructed by finding three lines associated in a symmetrical way with the three sides (or vertexes) and then proving that the three lines meet in a single point. An important tool for proving the concurrent is **Ceva's theorem**. Similarly, lines associated with a triangle are often constructed by proving that three symmetrically constructed points are collinear, where **Menelaus' theorem** gives a useful general criterion. We'll introduce the most commonly encountered geometry object in this section.



##### # Basic Lines

The **altitude** of a triangle is a straight line through a vertex and perpendicular to the opposite side. The opposite side is called the **base** of the altitude, and the point where the altitude intersects the base (or its extension) is called the **foot** of the altitude. The length of the altitude is the distance between the base and the vertex.

The **angle bisector** of a triangle is a straight line through a vertex which cuts the corresponding angle in half.

The **median** of a triangle is a straight line through a vertex and the midpoint of the opposite side, and divides the triangle into two equal areas.





### 5. Center of Triangle

##### # Circumcenter

The perpendicular bisector of all three sides meet in a single point, which named as the **circumcenter**, usually denoted by $O$. It named as circumcenter because this point is the center of the circumcircle, the circle passing through all the three vertexes.

> Proof that three perpendicular bisectors in a triangle meet in a single point.
>
> Proof. Let the three perpendicular for $AB, BC, CA$ named $l_{1}, l_{2}, l_{3}$ respectively. Notice that $AB$ must not parallel to $BC$, so $l_{1}$ meets $l_{2}$ with some point $P$, with $PA = PB$ and $PB = PC$, as a result $PA = PC$, which infers that $P$ must lies on the perpendicular bisector of $AC$, which is $l_{3}$. This concludes that The three lines meets in a single point P.

The diameter of circumcircle called the circumdiameter, which can be found by **the law of sines**. The radius of the circumcircle called **circumradius**.

$$
D = 2R = \cfrac{a}{\sin{A}} = \cfrac{b}{\sin{B}} = \cfrac{c}{\sin{C}}
$$

Thales' theorem implies that whether the circumcenter lies inside or outside the circle is determined by the (largest) angle of triangle:

- The circumcenter lies inside the triangle iff it's acute.

- The circumcenter lies exactly on the side iff it's right (actually it must be lies on the hypotenuse).

- The circumcenter lies outside the triangle iff it's obtuse.



##### # Orthocenter

The three altitudes of triangles intersect in a single point, denoted by $H$.<img src="Orthocenter_proof.png" alt="Orthocenter_proof" style="zoom:50%; float:right" />

> Proof that three altitudes in a triangle meet in a single point.
>
> As shown, in $\triangle ABC$ the altitudes $AP, BQ, CR$ are constructed.
>
> To apply the Ceva's theorem, we need to 
>
> 
>
>
>












