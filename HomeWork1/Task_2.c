#include <stdio.h>

int main() {
    char *text1 = "Let's";
    char *text2 = "go";
    char *text3 = "to walk";

    // Вывод строк с отступами и переводом строк
    printf("%s\n", text1);
    printf("  %s\n", text2);
    printf("    %s\n", text3);

    return 0;
}
