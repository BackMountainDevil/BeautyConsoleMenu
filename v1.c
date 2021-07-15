/*@File    :  v1.c
  @Desc    :  控制台菜单的 v1 版演示
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 11:08:54
  @License :  MIT
  @Encoding:  UTF-8  */

#include <stdio.h>

int main() {
  printf("|   MENU SELECTION DEMO    |\n"); // 输出菜单项供用户参考
  printf("| Options:                 |\n");
  printf("|        1. Option 1       |\n");
  printf("|        2. Option 2       |\n");
  printf("|        3. Option 3       |\n");
  printf("|        4. Exit           |\n");
  printf("Select option: ");
  int option = -1;
  do {
    scanf("%d", &option); // 让用户进行选择

    if (option < 1 || option > 4) { // 不合理的选择就重新选择
      printf("Unknown option: %d. Please select again: ", option);
    }
  } while (option < 1 || option > 4);

  return 0;
}