+
  前面的字符至少出现一次，如 jmzero+qaq 可以匹配 jmzeroqaq, jmzerooooqaq
*
  前面的字符可以不出现，也可以出现一次或多次，如jmzero\*q 可以匹配jmzerq, jmzeroooq
?
  前面的字符至多可以出现一次，如jmz^ero 可以匹配 jmero, jmzero
^
  匹配一个字符串的开头
$
  匹配一个字符串的结尾
[ABC123]
  匹配[]中的所有字符，如[jzc1]，可以匹配 jmzeroqaq123中的j z c 1
[^ABC123]
  匹配除了[]中的所有字符，如[^jzc1]，可以匹配 jmzeroqaq123 中的 m e r o q a 2 3
[A-Z]
  表示一个区间，匹配这个区间内的所有字母，即匹配大写字母，如 [A-Z] 可以匹配 JmZeroQAQ 的 J Z Q A
[a-z]
  表示一个区间，匹配这个区间内的所有字母，即匹配小写字母，如 [a-z] 可以匹配 JmZeroQAQ 的 m e r o
.
  匹配换行符号(\n, \r之类的任何单个字符)
[\s\S]
  匹配所有，\s是匹配所有空白符，\S匹配所有非空白符
\w
  匹配字母，数字，下划线，等价于[A-Za-z0-9_]
\d
  匹配任意一个阿拉伯数字(0-9)
()
  将括号内的东西看成是一个表达式，如 jmze(ro)? 可以匹配 jmzero, jmze
{n}
{n,}
{n, m}
  规定匹配次数
x|y
  匹配x或y，如 (j|f)mzeroqaq 可以匹配 jmzeroqaq 和 fzeroqaq
x|y|z
  作用和上面一样，只不过可以匹配z的情况
\b
  匹配一个单词的边界，如 a word and wordasd 使用 word\b来匹配，只会匹配到 第二个word而不会匹配到wordasd
\B
  匹配非单词边界 如word\B 只会匹配到 wordasd中的word
\d
  匹配一个数字字符
\D
  匹配一个非数字字符
