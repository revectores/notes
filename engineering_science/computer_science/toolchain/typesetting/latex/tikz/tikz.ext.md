# Tikz

### 1. Tikz Introduction

The instructions to draw tikz picture shall be in the `tikzpicture` block:

```latex
\begin{tikzpicture}
\end{tikzpicture}
```

We'll omit the this tikz block identifier in our following demos, as also other requisite LaTeX block for conciseness.





### 2. Tikz Basic Shapes



##### # Tikz Draw Line

Line can be drawn by two coordinates given:

```latex
\draw (-1, 0) -- (1, 0);
\draw (0, -1) -- (0, 1);
```

```latex_src
\documentclass[tikz,border=5pt]{standalone}
\usepackage{tikz}
\begin{document}
\begin{tikzpicture}
	\draw (0, 0) -- (0, 1);
	\draw (0, 1) -- (1, 1);
	\draw (1, 1) -- (0, 0);
\end{tikzpicture}
\end{document}
```

The properties of line can be configured like this, as also many other objects:

```latex
\draw [cyan] (0, 0) -- (0, 1);
\draw [densely dotted] (0, 1) -- (1, 1);
\draw [->] (1, 1) -- (0, 0);
```

```latex_src
\documentclass[tikz,border=5pt]{standalone}
\usepackage{tikz}
\begin{document}
\begin{tikzpicture}
	\draw [cyan] (0, 0) -- (0, 1);
	\draw [densely dotted] (0, 1) -- (1, 1);
	\draw [->] (1, 1) -- (0, 0);
\end{tikzpicture}
\end{document}
```

Here we change the color, style, and add an arrow to the three sides of triangle respectively.

Besides, there are many other properties of lines:

- Color
- Line Style
- Arrow

Refer to []() for the complete document of the line styles



###### # Tikz Draw Arc

An arc is defined by start position, initial & terminated angles, and radius:

```latex
	\draw (0, 0) arc (0:90:2);
```

```latex_src
\documentclass[tikz,border=5pt]{standalone}
\usepackage{tikz}
\begin{document}
\begin{tikzpicture}
	\draw (0, 0) arc (0: 90: 1);
	\draw (-1, 1) arc (90: 0: 1);
\end{tikzpicture}
\end{document}
```



##### # Tikz Draw Dot

Use `\node` to draw dots:

```latex
\node[circle, fill, inner sep = 1pt] at (1, 1){};
\node[circle, fill, inner sep = 1pt] at (0, 1){};
\node[circle, fill, inner sep = 1pt] at (0, 0){};
```


```latex_src
\documentclass[tikz,border=5pt]{standalone}
\usepackage{tikz}
\begin{document}
\begin{tikzpicture}
	\node[circle, fill, inner sep = 1pt] at (1, 1){};
	\node[circle, fill, inner sep = 1pt] at (0, 1){};
	\node[circle, fill, inner sep = 1pt] at (0, 0){};
\end{tikzpicture}
\end{document}
```

We can draw some complex graph by combining the three components:

```latex_src
\documentclass[tikz,border=5pt]{standalone}
\usepackage{tikz}
\usetikzlibrary{positioning,shapes.multipart,shapes,arrows.meta,arrows}


\begin{document}

\begin{tikzpicture}
    % equidistant points and arc
    \foreach \x [count=\p] in {0,...,5} {
        \node[shape=circle, fill=black, scale=0.5] (\p) at (\x*60:2) {};};
    \foreach \x [count=\p] in {0,...,5} {
        \draw (\x*60:2.4) node {\p};
        \draw[-{Stealth}] (\p) arc (\x*60:(\x+1)*60:2);
        % \draw (-30-\x*60:2.4) node {$\bar{\p}$};
    };

    \draw[-{Stealth}] (1) -- (5);
\draw[dashed] (1) -- (3) -- (5) -- (1);
    %\draw [dotted, gray] (-2.6,0) -- (2.6,0);
    %\draw [dotted, gray] (0,-2.15) -- (0,2.15);
\end{tikzpicture}

\end{document}
```
