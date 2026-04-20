

#include <stdio.h>

int main() {
    int i, j, s, n=4 ;  
    


    for(i = 1; i <= n; i++) {

       
        if(i == 1)
            s = 1;
        else if(i == 2)
            s = 3;
        else
            s = i + 1;

        
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }

       
        for(j = 1; j <= s; j++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
// #include <stdio.h>

// int main() {
//     int i, j, k, n;

//     printf("Enter n: ");
//     scanf("%d", &n);

//     for(i = 1; i <= n; i++) {

       
//         for(j = 1; j <= n - i; j++) {
//             printf(" ");
//         }

       
//         for(k = 1; k <= 2*i - 1; k++) {
//             printf("* ");
//         }

//         printf("\n");
//     }

//     return 0;
// }