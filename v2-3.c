/*@File    :  v2-3.c
  @Desc    :  对不同大小的终端进行自适应居中
              1. 获取终端大小
              2. 设置光标移动： \033[nB 光标下移 n 行 ，\033[%nC 光标右移 n 列
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 17:04:27
  @License :  MIT
  @Encoding:  UTF-8  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  char command;
  int index = 1; // 默认选项

  struct winsize windows;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &windows); // 获取终端的行数、列数（高、宽）
  unsigned int halfrow = 0.2 * windows.ws_row;
  unsigned int halfcol = 0.4 * windows.ws_col;

  system("stty -icanon"); // 关闭缓冲区，输入字符无需按回车键直接接受
  printf("\033[2J"); // 隐藏光标，实际效果有限。。
  printf("\033[47;30m"); // 背景色 47-白色，前景色（字体颜色） 30-黑色
  printf("\033[2J"); // 清空控制台，和 system("clear"); 效果还是有点区别的

  while (1) {
    system("clear"); // 清空控制台 printf("\033[2J");

    // 输出菜单项供用户参考
    printf("\033[%dB\033[%dC", halfrow, halfcol); // 光标下移、右移动
    printf("\033[47;32m"); // 背景色 47-白色，前景色（字体颜色） 32-绿色
    printf("   MENU SELECTION DEMO    \n");
    printf("\033[%dC", halfcol); // 光标右移动
    printf("\033[47;30m"); // 背景色 47-白色，前景色（字体颜色） 30-黑色
    printf(" Options:                 \n");
    printf("\033[%dC", halfcol); // 光标右移动
    if (index == 1) {
      printf("\033[47;34m"); // 背景色 47-白色，前景色（字体颜色） 34-蓝色
      printf("    --> 1. Option 1       \n");
      printf("\033[47;30m");
    } else {
      printf("        1. Option 1       \n");
    }
    printf("\033[%dC", halfcol); // 光标右移动
    if (index == 2) {
      printf("\033[47;34m");
      printf("    --> 2. Option 2       \n");
      printf("\033[47;30m");
    } else {
      printf("        2. Option 2       \n");
    }
    printf("\033[%dC", halfcol); // 光标右移动
    if (index == 3) {
      printf("\033[47;34m");
      printf("    --> 3. Option 3       \n");
      printf("\033[47;30m");
    } else {
      printf("        3. Option 3       \n");
    }
    printf("\033[%dC", halfcol); // 光标右移动
    if (index == 4) {
      printf("\033[47;34m");
      printf("    --> 4. Exit           \n");
      printf("\033[47;30m");
    } else {
      printf("        4. Exit           \n");
    }
    printf("\033[15B"); // 光标下移 15行，
                        // 尽管超出了显示范围，但它还是会显示在左下角
    // 让用户进行选择
    command = getchar();
    if (command == 10) { //  enter 10
      break;
    } else if (command == 119) { //  w 119
      if (index > 1) {
        index--;
      }
    } else if (command == 115) { // s 115
      if (index < 4) {
        index++;
      }
    }
  }
  printf("\033[0m"); // 取消前面的设置
  printf("You option is: %d\n", index);
  return 0;
}