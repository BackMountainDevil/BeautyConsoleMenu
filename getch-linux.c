/*@File    :  getch-linux.c
  @Desc    :  getch() 在 Linux 下的使用以及部分结果，编译需要
              加 -l curses，详见 makefile
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 14:53:56
  @License :  MIT
  @Encoding:  UTF-8  */

#include <curses.h>
#include <stdio.h>

int main() {
  initscr();
  char option;
  printf("please input keyboard num\n");
  while (1) {
    option = getch();
    printf("You input is: %c-%d\n", option, option);
    // fflush(stdout);
  }
  endwin();
  return 0;
}

/*
部分输出结果， 下面的结果已经删除了乱七八糟的空格
0～9、a～z 与 win getch（） 结果一致，
方向键、回车键则都不同

0You input is: 0-48
1You input is: 1-49
aYou input is: a-97
bYou input is: b-98
xYou input is: x-120
yYou input is: y-121
zYou input is: z-122

回车
You input is:
              -10

Esc 退出
^[You input is: 7

上
^[You input is: 7
[You input is: [-91
AYou input is: A-65
下
^[You input is: 7
[You input is: [-91
BYou input is: B-66
左
^[You input is: 7
[You input is: [-91
DYou input is: D-68
右
^[You input is: 7
[You input is: [-91
CYou input is: C-67
 */