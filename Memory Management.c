#include<stdio.h>
#include<conio.h>

void main() {
    int i, j, temp, b[10], c[10], arr[10], n, ch, a;
    printf("\t\t Memory Management\n");
    printf("Enter the number of blocks:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter the size of block %d:", i);
        scanf("%d", &b[i]);
        c[i] = b[i];
    }
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the size of each process:\n");
    for (i = 1; i <= n; i++) {
        printf("Process %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n1.First fit\n2.Best fit\n3.Worst fit\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (b[j] >= arr[i]) {
                        printf("Process %d is allocated to block %d.\n", i, j);
                        b[j] -= arr[i];
                        break;
                    }
                }
                if (j > n) {
                    printf("Process %d cannot be allocated.\n", i);
                }
            }
            break;
        case 2:
            for (i = 1; i <= n; i++) {
                for (j = 1; j < n; j++) {
                    if (b[j] > b[j + 1]) {
                        temp = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp;
                    }
                }
            }
            for (i = 1; i <= n; i++) {
                if (b[i] >= arr) {
                    a = b[i];
                    break;
                }
            }
            for (i = 1; i <= n; i++) {
                if (c[i] == a) {
                    printf("Arriving block is allocated to block %d.", i);
                }
            }
            break;
        case 3:
             for (i = 1; i <= n; i++) {
                for (j = 1; j < n; j++) {
                    if (b[j] < b[j + 1]) {
                        temp = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp;
                    }
                }
            }
            for (i = 1; i <= n; i++)
                printf("%d", b[i]);
            break;
        default:
            printf("Enter a valid choice:");
    }
    getch();
}
