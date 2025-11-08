#include <stdio.h>

int main() {
    int a[50], b[50], c[100];
    int n1, n2, i, j, k;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements: ", n1);
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements: ", n2);
    for(j = 0; j < n2; j++)
        scanf("%d", &b[j]);

    i = j = k = 0;
    while(i < n1 && j < n2) {
        if(a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i < n1)
        c[k++] = a[i++];

    while(j < n2)
        c[k++] = b[j++];

    printf("Merged array: ");
    for(i = 0; i < n1 + n2; i++)
        printf("%d ", c[i]);

    return 0;
}
