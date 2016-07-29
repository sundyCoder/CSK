#Sundy
##Latex Tutorial
###Lesson 1. Basic Introduction
	eg:
	\documentclass{article}
	\title{My first document}
	\author{Sundy}
	\date{\today}
	
	\begin{document}
	\pagenumbering{gobble}
	\maketitle
	\newpage
	
	 Hello World!
	\pagenumbering{}
	\end{document}
###Output:
![](http://i.imgur.com/P4W9iW7.png)
###Summary:
- A document has a preamble and document part
- The document environment must be defined
- Commands beginning with a backslash \, environments have a begin and end tag
- Useful settings for pagenumbering:
	gobble numbers
	arabic numbers
	roman numbers

###Lession 2. Adding paragraphs and sections
	\documentclass{article}
	\title{My first document}
	\author{Sundy}
	\date{\today}
	
	\begin{document}
	\pagenumbering{gobble}
	\maketitle
	\newpage
	\pagenumbering{arabic}
	
	 \section{Section}
	  Hello World!
	
	\subsection{Subsection} % (fold)
	structuring a document is easy!
	
	\subsubsection{Subsubsection}
	More text
	
	\paragraph{Paragraph}
	some more text
	\subparagraph{Subparagraph}
	Even more text
	
	\section{Another Section}
	New Section
	
	\end{document}
###Output:
![](http://i.imgur.com/pTSdPWT.png)	

###summary:
1. LaTeX uses the commands **\section**, **\subsection** and **\subsubsection** to define sections in your document
1. The sections will have successive numbers and appear in the table of contents
1. Paragraphs are not numbered and thus don't appear in the table of contents

###Lession 3.Adding more functions to LaTeX
1.Math equation
	documentclass{article}
	
	\begin{document}
	
	\begin{equation}
	  f(x) = x^2
	\end{equation}
	
	\end{document}
Output:
![](http://i.imgur.com/zhdWeDE.png)
2.Including packages.
	documentclass{article}
	
	\usepackage{amsmath}
	
	\begin{document}
	
	\begin{equation*}
	  f(x) = x^2
	\end{equation*}	

Output:

![](http://i.imgur.com/GR6RHHI.png)

加了包之后，我们发现公式后面的(1)不见了。
###Summary:
1. Packages add new functions to LaTeX
2. All packages must be included in the preamble
3. Packages add features such as support for pictures, links and bibliography

###Lesson 4. Typesetting math in LaTeX
####1. Inline Math
在文字之间嵌入数学公式:

		...
		This formula $f(x) = x^2$ is an example.
		...
也就是公式放在2个$之间。
####2. Equations
The equation and align environment

	\begin{align*}
	  1 + 2 &= 3\\
	  1 &= 3 - 2
	\end{align*}

####3. Fractions
	\begin{align*}
	  f(x) &= x^2\\
	  g(x) &= \frac{1}{x}\\
	  F(x) &= \int^a_b \frac{1}{3}x^3
	\end{align*}
####4. Matrices
	\left[
	\begin{matrix}
	1 & 0\\
	0 & 1
	\end{matrix}
	\right]
####5. Scaling of Parentheses, Brackets 
	\left(\frac{1}{\sqrt{x}}\right)
###Summary

1. LaTeX is a powerful tool to typeset math
2. Embed formulas in your text by surrounding them with dollar signs $
1. The equation environment is used to typeset one formula
1. The align environment will align formulas at the ampersand & symbol
1. Single formulas must be seperated with two backslashes \\
1. Use the matrix environment to typeset matrices
1. Scale parentheses with \left( \right) automatically
1. All mathematical expressions have a unique command with unique syntax
1. Notable examples are:
	1. \int^a_b for integral symbol
	1. \frac{u}{v} for fractions
	1. \sqrt{x} for square roots
1. Characters for the greek alphabet and other mathematical symbols such as \lambda

###Lesson 5.Adding figures in LaTeX - Embed an image/picture
	\begin{figure}[h!]
	  \includegraphics[width=\linewidth]{boat.jpg}
	  \caption{A boat.}
	  \label{fig:boat}
	\end{figure}

Force the picture to a certain position - Set the float

At some point, you will notice that the figure doesn't necessarily show up in the exact place as you put your code in the .tex file. If your document contains a lot of text, it's possible that LaTeX will put the picture on the next page, or any other page where it finds sufficient space. To prevent this behavior, it's necessary to set the float value for the figure environment.

Setting the float by adding [h!] behind the figure environment \begin tag will force the figure to be shown at the location in the document. Possible values are:

	h (here) - same location
	t (top) - top of page
	b (bottom) - bottom of page
	p (page) - on an extra page
	! (override) - will force the specified location
However, I have only used the [h!] option so far. The float package (\usepackage{float}) allows to set the option to [H], which is even stricter than [h!].

###Summary

1. Use the graphicx package and figure environment to embed pictures
1. Pictures will be numbered automatically
1. Change the width of your image by using \includegraphics[width=\linewidth]{}
1. Refer to pictures in your document by setting a \label and using the \ref tag
1. Set the position of your image by adding a float option such as [h!]

###Lesson 6.Generate a table of contents in LaTeX
	\begin{figure}
	  \caption{Dummy figure}
	\end{figure}
	
	\begin{table}
	  \caption{Dummy table}
	\end{table}
	...
	\begin{appendix}
	  \listoffigures
	  \listoftables
	\end{appendix}

###Summary
1. Autogenerate a table of content using \tableofcontents
1. Create lists of your figures and tables with \listoffigures and \listoftables
1. Always compile twice to see the changes

###Lesson 7. Bibliography in LaTeX with Bibtex/Biblatex
Random copy a bib information from google scholar, and then save it as example.bib.

For example:

	@INPROCEEDINGS{583135, 
	author={G. Dudek and M. Jenkin and E. Milios and D. Wilkes}, 
	booktitle={Intelligent Robots and Systems '93, IROS '93. Proceedings of the 1993 IEEE/RSJ International Conference on}, 
	title={A taxonomy for swarm robots}, 
	year={1993}, 
	volume={1}, 
	pages={441-447 vol.1}, 
	keywords={cooperative systems;autonomous agents;linear speedup;mobile robots;swarm robots;Computer science;Costs;Environmental economics;Intelligent robots;Mobile robots;Planets;Robot kinematics;Robot sensing systems;Robustness;Taxonomy}, 
	doi={10.1109/IROS.1993.583135}, 
	month={Jul},}

Save it as example.bib

In latex, write the code as below:

	Random citation \cite{583135} embeddeed in text.
	\newpage
	\bibliography{example} 
	\bibliographystyle{ieeetr}

###Output:
![](http://i.imgur.com/Z5mr7Lx.png)

###Summary

1. Generate a bibliography with BibTeX and BibLaTeX
1. First define a .bib file using: \bibliography{BIB_FILE_NAME} (do not add .bib)
1. For BibTeX put the \bibliography statement in your document, for BibLaTeX in the preamble
1. BibTeX uses the \bibliographystyle command to set the citation style
1. BibLaTeX chooses the style as an option like: \usepackage[backend=bibtex,style=verbose-trad2]{biblatex}
1. BibTeX uses the \cite command, while BibLaTeX uses the \autocite command
1. The \autocite command takes the page number as an option: \autocite[NUM]{}

###Lesson 7b. LaTeX Footnotes - Quick Explanation
So how to use footnotes? LaTeX offers the \footnote command and referencing works using the \label and \ref commands.

The following code shows some example text and how to add a footnote with a label:

	...
	This is some example text\footnote{\label{myfootnote}Hello footnote}.
	...

After compilation you will see the footnote appearing on the bottom of your page. It's imperative, that the label is contained within the footnote itself, otherwise the label will refer to the section (or subsection). Footnotes are numbered automatically. If you want to refer to them later on, you can use the \ref command as follows:

	...
	I'm referring to footnote \ref{myfootnote}.
	...

###Summary
1. Create footnotes with the \footnote command and label them with \label
1. Make sure that the label is contained within the braces of the footnote command
1. Use the \ref command to refer to footnotes

###Lesson 8.Tables in LaTeX - Quick Guide with Code Examples
	\documentclass{article}
	
	\begin{document}
	
	\begin{table}[h!]
	  \centering
	  \caption{Caption for the table.}
	  \label{tab:table1}
	  \begin{tabular}{l|c||r}
	    1 & 2 & 3\\
	    \hline
	    a & b & c\\
	  \end{tabular}
	\end{table}
	
	\end{document}
###Output:
![](http://i.imgur.com/nqOxEWF.png)


Example2:

	\begin{table}[h!]
	  \centering
	  \caption{Caption for the table.}
	  \label{tab:table1}
	  \begin{tabular}{ccc}
	    \toprule
	    Some & actual & content\\
	    \midrule
	    prettifies & the & content\\
	    as & well & as\\
	    using & the & booktabs package\\
	    \bottomrule
	  \end{tabular}
	\end{table}

Include: \usepackage{booktabs}, otherwise, there will be a error.

###Summary

1. LaTeX offers the table and tabular environment for table creation
1. The table environment acts like a wrapper for the tabular similar to the figure environment
1. Alignment and vertical separators are passed as an argument to the tabular environment (e.g. \begin{tabular}{l|c||r})
1. It's possible to align the content left (l), centered (c) and right (r), where the number of alignment operators has to match the desired number of columns
1. The columns can be seperated by adding | in between the alignment operators
1. Rows can be seperated using the \hline command and columns using the ampersand & symbol
1. The newline \\ operator indicates the end of a row
1. It's possible to refer to tables using \ref and \label

###Lesson 9. Tables from .csv in LaTeX with pgfplotstable
Use the package pgfplotstable to read tables from .csv files automatically and add them to your document.

	\begin{table}[h!]
	  \begin{center}
	    \caption{Autogenerated table from .csv file.}
	    \label{table1}
	    \pgfplotstabletypeset[
	      multicolumn names, % allows to have multicolumn names
	      col sep=comma, % the seperator in our .csv file
	      display columns/0/.style={
			column name=$Value 1$, % name of first column
			column type={S},string type},  % use siunitx for formatting
	      display columns/1/.style={
			column name=$Value 2$,
			column type={S},string type},
	      every head row/.style={
			before row={\toprule}, % have a rule at top
			after row={
				\si{\ampere} & \si{\volt}\\ % the units seperated by &
				\midrule} % rule under units
				},
			every last row/.style={after row=\bottomrule}, % rule at bottom
	    ]{table.csv} % filename/path to file
	  \end{center}
	\end{table}

###Summary

1. LaTeX can generate tables from .csv files automatically
1. Copy and paste the above snippet and packages to get it to work hassle free
1. To add new columns, simply duplicate the display column line and change the number and name
1. Add new units using the \siunitx command and the ampersand seperator as shown above
1. Have a .csv file seperated with comma as column seperator and newline as row seperator
1. Does only work for tables smaller than one page

###Lesson 10. Plots in LaTeX - Visualize data with pgfplots
The pgfplots package from tikz/pgf enabled you to plot data directly from .csv files in LaTeX.

	...
	\usepackage{tikz}
	\usepackage{pgfplots}
	...
	\pgfplotsset{compat=newest}
	\usepgfplotslibrary{units}
	...
	\begin{figure}[h!]
	  \begin{center}
	    \begin{tikzpicture}
	      \begin{axis}[
	          width=\linewidth, % Scale the plot to \linewidth
	          grid=major, 
	          grid style={dashed,gray!30},
	          xlabel=X Axis $U$, % Set the labels
	          ylabel=Y Axis $I$,
	          x unit=\si{\volt}, % Set the respective units
	          y unit=\si{\ampere},
	          legend style={at={(0.5,-0.2)},anchor=north},
	          x tick label style={rotate=90,anchor=east}
	        ]
	        \addplot 
	        % add a plot from table; you select the columns by using the actual name in
	        % the .csv file (on top)
	        table[x=column 1,y=column 2,col sep=comma] {table.csv}; 
	        \legend{Plot}
	      \end{axis}
	    \end{tikzpicture}
	    \caption{My first autogenerated plot.}
	  \end{center}
	\end{figure}
	...

####Output:
![](http://i.imgur.com/QtWyiRd.png)

###Summary
1. Plotting is easy with pgfplots, it plots data directly from .csv files
1. Select a column by the actual name from the .csv file using table[x=column 1,y=column 2…

###Lesson 11. Draw pictures in LaTeX - With tikz/pgf
The pgf/tikz package allows you to draw pictures from within your LaTeX document to keep the style consistent throughout your document.

###The syntax of Tikz

To demonstrate the basic syntax, we will have a closer look at the line that draws the red rectangle in our picture:

\draw [red,dashed] (-2.5,2.5) rectangle (-1.5,1.5) node [black,below] {Start};

	\documentclass{article}
	
	\usepackage{tikz}
	
	\begin{document}
	\begin{figure}[h!]
	  \begin{center}
	    \begin{tikzpicture}
	      \draw [red,dashed] (-2.5,2.5) rectangle (-1.5,1.5) node [black,below] {Start}; % Draws a rectangle
	      \draw [thick] (-2,2) % Draws a line
	      to [out=10,in=190] (2,2)
	      to [out=10,in=90] (6,0) 
	      to [out=-90,in=30] (-2,-2);    
	      \draw [fill] (5,0.1) rectangle (7,-0.1) node [black,right] {Obstacle}; % Draws another rectangle
	      \draw [red,fill] (-2,-2) circle [radius=0.2] node [black,below=4] {Point of interest}; % Draws a circle
	    \end{tikzpicture}
	    \caption{Example graphic made with tikz.}
	  \end{center}
	\end{figure}
	\end{document}

###Output:
![](http://i.imgur.com/2tO3Ocb.png)

###Summary

1. Tikz can be used to draw graphics from within the LaTeX document
1. No graphical user interface, instead pictures are programmed
1. Extensive documentation available in the Tikz manual
1. Many examples can be found on the internet
1. Extensions available to easy creation of diagrams, flowcharts and so forth


###Lesson 12. Circuit diagrams in LaTeX - Using Circuitikz
Add neat circuit diagrams to your paper with circuitikz, extending tikz with electric components.
	\documentclass{article}
	
	\usepackage{tikz}
	\usepackage{circuitikz}
	
	\begin{document}
	
	\begin{figure}[h!]
	  \begin{center}
	    \begin{circuitikz}
	      \draw (0,0)
	      to[V,v=$U_q$] (0,2) % The voltage source
	      to[short] (2,2)
	      to[R=$R_1$] (2,0) % The resistor
	      to[short] (0,0);
	    \end{circuitikz}
	    \caption{My first circuit.}
	  \end{center}
	\end{figure}
	
	\end{document}

###Output:
![](http://i.imgur.com/WNhhPzW.png)

###Summary:
1. Circuitikz provides an environment to draw electric circuit diagrams
1. The syntax is similar to the plain Tikz syntax
1. A list of all symbols is available in the circutikz manual

###Lesson 13. Source code highlighting in LaTeX using the listings package (lstlisting)

The listings package offers source code highlighting for various languages. Learn by example how to use it in your LaTeX documents.

The listings package is a powerful way to get nice source code highlighting in LaTeX. It's fairly easy to use and there's good documentation available on how to use it.

The output of the listings package will pretty much look like this after some setup:
	\documentclass{article}
	
	\usepackage{listings}
	\usepackage{color}
	
	\renewcommand\lstlistingname{Quelltext} % Change language of section name
	
	\lstset{ % General setup for the package
		language=Perl,
		basicstyle=\small\sffamily,
		numbers=left,
	 	numberstyle=\tiny,
		frame=tb,
		tabsize=4,
		columns=fixed,
		showstringspaces=false,
		showtabs=false,
		keepspaces,
		commentstyle=\color{red},
		keywordstyle=\color{blue}
	}
	
	\begin{document}
	\begin{lstlisting}
	#!/usr/bin/perl
	print S(@ARGV);sub S{$r=(@_[0]%4==0&&@_[0]%100!=0)||@_[0]%400=0;}
	
	#include <stdio.h>
	int main(vodi){
		printf("Hello World!\n");
		return 0;
	}
	\end{lstlisting}
	\end{document}

###Output:
![](http://i.imgur.com/iyJkvh6.png)


I first use the include the color and listings package and then set up the language of the package headings to german using \renewcommand\lstlistingname{Quelltext}. This is not necessary if you're planning to use it in English.

Afterwards I set up the general layout for the package with the \lstset command. The options I set there should be self-explanatory. Note that it's required to manually set the colors for keywords and comments, otherwise the output would be only black on white. The desired output must then be embedded within a listings environment.

Assuming we have a Perl script saved in a file script.pl, we could also simply use the following syntax to get the same result:

	\lstinputlisting{script.pl}

This will keep your LaTeX source clean and you can still use all features of the package.

###Summary

1. After some initial setup, all source code can be embedded in a lstlistings environment
1. A list of all languages and more documentation is available in the manual of the listings package
1. Use the \lstlinputlisting{FILENAME} command to read the content of source files directly into a lstlistings environment.


**Original website**:[https://www.latex-tutorial.com/tutorials/quick-start/](https://www.latex-tutorial.com/tutorials/quick-start/)

###**Appendix - Source Code.**
	\documentclass{article}
	\usepackage{amsmath}
	\usepackage{graphicx}
	\usepackage{booktabs} % For \toprule, \midrule and \bottomrule
	\usepackage{siunitx} % Formats the units and values
	\usepackage{pgfplotstable} % Generates table from .csv
	\usepackage{pgfplots}
	\usepackage{tikz}
	\usepackage{circuitikz}
	\usepackage{listings}
	\usepackage{color}
	
	\pgfplotsset{compat=newest} % Allows to place the legend below plot
	\usepgfplotslibrary{units} % Allows to enter the units nicely
	
	%source code listing
	\renewcommand\lstlistingname{Quelltext} % Change language of section name
	
	\lstset{ % General setup for the package
		language=Perl,
		basicstyle=\small\sffamily,
		numbers=left,
	 	numberstyle=\tiny,
		frame=tb,
		tabsize=4,
		columns=fixed,
		showstringspaces=false,
		showtabs=false,
		keepspaces,
		commentstyle=\color{red},
		keywordstyle=\color{blue}
	}
	
	% Setup siunitx:
	\sisetup{
	  round-mode          = places, % Rounds numbers
	  round-precision     = 2, % to 2 places
	}
	
	\title{My first document}
	\author{Sundy}
	\date{\today}
	
	\begin{document}
	\pagenumbering{gobble}
	\maketitle
	\newpage
	\pagenumbering{arabic}
	
	 \section{Section}
	  Hello World!
	
	\subsection{Subsection} % (fold)
	structuring a document is easy!
	
	\subsubsection{Subsubsection}
	More text
	
	\paragraph{Paragraph}
	some more text
	\subparagraph{Subparagraph}
	Even more text
	
	\section{Equation Section}
	\begin{equation*}
	  f(x) = x^2
	\end{equation*}
	
	This formula $f(x) = x^2$ is an example
	\subsection{Equation and align}
	\begin{align*}
	  1 + 2 &= 3\\
	  1 &= 3 - 2
	\end{align*}
	\subsection{Fractions}
	\begin{align*}
	  f(x) &= x^2\\
	  g(x) &= \frac{1}{x}\\
	  F(x) &= \int^a_b \frac{1}{3}x^3
	\end{align*}
	
	\subsection{Scaling of Parentheses, Brackets}
	\begin{align*}
	f(x) = \left(\frac{1}{\sqrt{x}}\right)
	\end{align*}
	
	\section{Image/Picture Figure}
	\newpage
	\begin{figure}[h!]
	  \includegraphics[width=\linewidth]{boat.jpg}
	  \caption{A boat.}
	  \label{fig:boat}
	\end{figure}
	
	\newpage
	\tableofcontents
	\newpage
	\section{Table}
	
	\begin{figure}
	  \caption{Dummy figure}
	\end{figure}
	
	\begin{table}
	  \caption{Dummy table}
	\end{table}
	
	\begin{appendix}
	  \listoffigures
	  \listoftables
	\end{appendix}
	
	This is some example text\footnote{\label{myfootnote}Hello footnote}.
	
	I'm referring to footnote \ref{myfootnote}.
	
	\begin{table}[h!]
	  \centering
	  \caption{Caption for the table.}
	  \label{tab:table1}
	  \begin{tabular}{l|c||r}
	    1 & 2 & 3\\
	    \hline
	    a & b & c\\
	  \end{tabular}
	\end{table}
	
	\begin{table}[h!]
	  \centering
	  \caption{Caption for the table.}
	  \label{tab:table1}
	  \begin{tabular}{ccc}
	    \toprule
	    Some & actual & content\\
	    \midrule
	    prettifies & the & content\\
	    as & well & as\\
	    using & the & booktabs package\\
	    \bottomrule
	  \end{tabular}
	\end{table}
	
	Random citation \cite[sundy]{583135} embeddeed in text.
	
	\begin{table}[h!]
	  \begin{center}
	    \caption{Autogenerated table from .csv file.}
	    \label{table1}
	    \pgfplotstabletypeset[
	      multicolumn names, % allows to have multicolumn names
	      col sep=comma, % the seperator in our .csv file
	      display columns/0/.style={
			column name=$Value 1$, % name of first column
			column type={S},string type},  % use siunitx for formatting
	      display columns/1/.style={
			column name=$Value 2$,
			column type={S},string type},
	      every head row/.style={
			before row={\toprule}, % have a rule at top
			after row={
				\si{\ampere} & \si{\volt}\\ % the units seperated by &
				\midrule} % rule under units
				},
			every last row/.style={after row=\bottomrule}, % rule at bottom
	    ]{table.csv} % filename/path to file
	  \end{center}
	\end{table}
	
	\newpage
	\begin{figure}[h!]
	  \begin{center}
	    \begin{tikzpicture}
	      \begin{axis}[
	          width=\linewidth, % Scale the plot to \linewidth
	          grid=major, % Display a grid
	          grid style={dashed,gray!30}, % Set the style
	          xlabel=X Axis $U$, % Set the labels
	          ylabel=Y Axis $I$,
	          x unit=\si{\volt}, % Set the respective units
	          y unit=\si{\ampere},
	          legend style={at={(0.5,-0.2)},anchor=north}, % Put the legend below the plot
	          x tick label style={rotate=90,anchor=east} % Display labels sideways
	        ]
	        \addplot 
	        % add a plot from table; you select the columns by using the actual name in
	        % the .csv file (on top)
	        table[x=column 1,y=column 2,col sep=comma] {table.csv}; 
	        \legend{Plot}
	      \end{axis}
	    \end{tikzpicture}
	    \caption{My first autogenerated plot.}
	  \end{center}
	\end{figure}
	
	\newpage
	\begin{figure}[h!]
	  \begin{center}
	    \begin{tikzpicture}
	      \begin{axis}[
	          width=\linewidth, % Scale the plot to \linewidth
	          grid=major, 
	          grid style={dashed,gray!30},
	          xlabel=X Axis $U$, % Set the labels
	          ylabel=Y Axis $I$,
	          x unit=\si{\volt}, % Set the respective units
	          y unit=\si{\ampere},
	          legend style={at={(0.5,-0.2)},anchor=north},
	          x tick label style={rotate=90,anchor=east}
	        ]
	        \addplot 
	        % add a plot from table; you select the columns by using the actual name in
	        % the .csv file (on top)
	        table[x=column 1,y=column 2,col sep=comma] {table.csv}; 
	        \legend{Plot}
	      \end{axis}
	    \end{tikzpicture}
	    \caption{My first autogenerated plot.}
	  \end{center}
	\end{figure}
	
	
	\newpage
	\begin{figure}[h!]
	  \begin{center}
	    \begin{tikzpicture}
	      \draw [red,dashed] (-2.5,2.5) rectangle (-1.5,1.5) node [black,below] {Start}; % Draws a rectangle
	      \draw [thick] (-2,2) % Draws a line
	      to [out=10,in=190] (2,2)
	      to [out=10,in=90] (6,0) 
	      to [out=-90,in=30] (-2,-2);    
	      \draw [fill] (5,0.1) rectangle (7,-0.1) node [black,right] {Obstacle}; % Draws another rectangle
	      \draw [red,fill] (-2,-2) circle [radius=0.2] node [black,below=4] {Point of interest}; % Draws a circle
	    \end{tikzpicture}
	    \caption{Example graphic made with tikz.}
	  \end{center}
	\end{figure}
	
	\newpage
	\begin{figure}[h!]
	  \begin{center}
	    \begin{circuitikz}
	      \draw (0,0)
	      to[V,v=$U_q$] (0,2) % The voltage source
	      to[short] (2,2)
	      to[R=$R_1$] (2,0) % The resistor
	      to[short] (0,0);
	    \end{circuitikz}
	    \caption{My first circuit.}
	  \end{center}
	\end{figure}
	
	\newpage
	\begin{lstlisting}
	#!/usr/bin/perl
	print S(@ARGV);sub S{$r=(@_[0]%4==0&&@_[0]%100!=0)||@_[0]%400=0;}
	
	#include <stdio.h>
	int main(vodi){
		printf("Hello World!\n");
		return 0;
	}
	\end{lstlisting}
	
	\newpage
	\bibliography{example} 
	\bibliographystyle{ieeetr}
	\end{document}
	
	
