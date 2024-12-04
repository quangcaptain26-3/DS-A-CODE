#include <stdio.h>

int main() {
    int n, i = 0, sum = 0;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    while (n != 0) {
        if (i % 2 == 0) {
            sum += n % 10;
        }
        n /= 10;
        i++;
    }

    printf("Tong cac chu so o vi tri chan: %d\n", sum);
    return 0;
}
