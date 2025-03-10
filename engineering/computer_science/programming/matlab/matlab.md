# MATLAB

### 1. Basis

##### # Format

Semicolon is used to control whether to print the result of expression will be printed in the terminal (strange enough). Not print if semicolon is provided.

Use `%` to specifiy comments.

```matlab
% This is one-line comment.
%{
This is multi-line comments.
Hello, I'm also the comments.
%}
```



##### # WorkSpace

MATLAB provides a visualized workspace to store the variables' value. Use `whos` to show the variables in the workspace. Use `save` and `load` to save and load the workspace, so you can recover the variables' value you solve before. (use extention `.mat`). A special variable `ans` is saved if a expression is not associated with an assignment, and will continue to exist in the workspace. The previous `ans` will be replaced if new unassigned result occurs.

```matlab
a = 1;
b = 2;
a + b;       % The result of this expression is stored in `ans`
ans			 % 3
a + b + ans  % 6, and it updates `ans`.
ans			 % 6
```

You can use the direction keys to go through the history commands.







### 2. Matrix

Matrix is the first-class member in Matlab. All the variables are matrix. Single number is `1*1` matrix, and strings are `1*len(str)` matrix (each element stores one `char`).

The function is designed to act on matrix, as so on the single variable as the `1*1` matrix.

Matrix Initialization:

```matlab
% Manually
a = [1,2,3; 4,5,6; 7,8,9];

% Tool Functions
zeros(2,3); ones(2,3); rand(2,3);

% Colon Approach
a = 0: 5;  % [0,1,2,3,4,5]
a = 0: 0.2: 1;  % [0, 0.2, 0.4, 0.6, 0.8, 1.0]
% Notice that left/right endpoints are both included.

```

Matrix Subscripting:

```matlab
a = [1,2,3; 4,5,6; 7,8,9];

% Matlab Start Index from 1.
a(2,2);  % Multidimensional indexing
a(5);		 % Linear indexing


% Accessing non-exist index raise error, while the assignment will cause a matrix extension.
a(4,4) = 10
```

Some other usages of matrix including colon `:`  is similiar with Python.



##### # Common Opeartion

```matlab
a = rand(3,3);
c = sin(a);
b = a + 1;
adds = a + b;
```

Notice that the simple `*` opearator between matrix represents normal matrix multipication, use `.*` instead to the element-level multiplication. Besides multiplication, division and power also comply with this rule. This is different with numpy for Python, which use simple `*` as element-level multiplication to make the behaviour among operators fit.



##### # Matrix Special Operation

```matlab
% Transposition
b = a';
```



##### # Concerntration

Using submatrix as element to profrom the concerntration. Notice the row or column must fit.

```matlab
a = [1,2,3; 4,5,6; 7,8,9];
A = [a,a];
B = [a;a];
```







### 3. Graph

##### # 2-Dimensional

```matlab
x = 0: pi/100: 2*pi;
y = sin(x);
plot(x,y);  % Use two 1-demensional matrix to generate 2d graph
```

Serval Configuration can be applied into the graph, which are actived synchronously.

```matlab
xlabel('x');
ylabel('sin(x)');
title('Plot of the Sine Function');
```

Different `plot` command generate different graphes. Use `hold on/off` command to control if you want to `plot` in the same graph.

##### # 3-Dimensional

As the `begin:step:end` command in the 2D occasion, we use `meshgrid` command to construct a group.

