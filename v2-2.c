/*@File    :  v2-2.c
  @Desc    :  上次的菜单用箭头表示选择，这里用颜色来加强表示
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 16:07:55
  @License :  MIT
  @Encoding:  UTF-8  */
#include <stdio.h>
#include <stdlib.h>

int main() {
  char command;
  int index = 1; // 默认选项

  system("stty -icanon"); // 关闭缓冲区，输入字符无需按回车键直接接受
  printf("\033[2J"); // 隐藏光标，实际效果有限。。
  printf("\033[47;30m"); // 背景色 47-白色，前景色（字体颜色） 30-黑色
  printf("\033[2J"); // 清空控制台，和 system("clear"); 效果还是有点区别的

  while (1) {
    system("clear"); // 清空控制台 printf("\033[2J");

    // 输出菜单项供用户参考
    printf("\033[47;32m   MENU SELECTION DEMO    \n");
    printf("\033[47;30m Options:                 \n");
    if (index == 1) {
      printf("\033[47;34m    --> 1. Option 1       \033[47;30m\n");
    } else {
      printf("        1. Option 1       \n");
    }
    if (index == 2) {
      printf("\033[47;34m    --> 2. Option 2       \033[47;30m\n");
    } else {
      printf("        2. Option 2       \n");
    }
    if (index == 3) {
      printf("\033[47;34m    --> 3. Option 3       \033[47;30m\n");
    } else {
      printf("        3. Option 3       \n");
    }
    if (index == 4) {
      printf("\033[47;34m    --> 4. Exit           \033[47;30m\n");
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