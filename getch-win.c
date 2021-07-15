/*@File    :  getch-win.c
  @Desc    :  getch() 在 Windows 下的使用以及部分结果
              [C语言实现一个Window控制台带彩色，且可以用方向键选择并确认的菜单式列表(一)Engineer-Bruce_Yang
              2017-08-22](https://yangyuanxin.blog.csdn.net/article/details/77485367)
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 14:54:29
  @License :  MIT
  @Encoding:  UTF-8  */

#include <conio.h>
#include <stdio.h>

int main() {
  char option;
  while (1) {
    option = getch();
    printf("You input is %c-%d\n", option, option);
  }
  return 0;
}

/*
You input is 0-48
You input is 1-49
You input is 2-50
You input is 8-56
You input is 9-57
You input is a-97
You input is b-98
You input is c-99
You input is x-120
You input is y-121
You input is z-122

上下左右，结果和 网上看到的不同，多了 -0 这一行，可以自己过滤掉
You input is -0
You input is H-72

You input is -0
You input is P-80

You input is -0
You input is K-75

You input is -0
You input is M-77

Esc 退出键，而博客代码中是 27
You input is 7

Enter 回车键，博客代码中是 13
-13 input is
 */