#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];   

    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int even_sum = 0;
    int odd_sum = 0;

   
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            even_sum = even_sum + arr[i];
        } else {
            odd_sum = odd_sum + arr[i];
        }
    }

    printf("\nSum of even numbers = %d\n", even_sum);
    printf("Sum of odd numbers = %d\n", odd_sum);

    return 0;
}