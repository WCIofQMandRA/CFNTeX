# CFNTeX——允许使用中文文件名的LaTeX
多数LaTeX发行版不允许使用含有中文的文件名。CFNTeX是针对XeLaTeX的“补丁”，允许用户在XeLaTeX中使用中文文件名。
```tex
%编译后的文件为README.pdf
\documentclass{ctexart}
\usepackage{geometry}
\usepackage{xltxtra}
\usepackage[hidelinks,unicode]{hyperref}
\setCJKmainfont{Source Han Serif SC}
\geometry{a4paper,hmargin=2.5cm,vmargin=2cm}
\newcommand{\CFNTeX}{{CFN\TeX}}
\renewcommand{\today}{2019年5月19日}
\pagestyle{empty}
\begin{document}
\title{\bf \CFNTeX\\\flushright\Large——允许使用中文文件名的\LaTeX}
\author{WCI of QM and RA}
\date{\today}
\maketitle

多数\LaTeX 发行版不允许使用含有中文的文件名。\CFNTeX 是针对\XeLaTeX 的“补丁”，允许用户在\XeLaTeX 中使用中文文件名。
\end{document}
```
