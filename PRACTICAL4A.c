#include <stdio.h>

int main() {
    int num,  i;
    unsigned long long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if(num < 0){
        printf("ERROR:FCTORIAL IS NOT DEFINED FOR NEGATIVE NUMBERS.");

    }else{
        for(i = 1; i <= num; ++i){
            factorial *=i;
        }
        printf("%d", factorial);
    }
    return 0;
}