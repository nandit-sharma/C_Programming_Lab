// Armstrong number

#include <stdio.h>
#include <math.h>

int main() {
    int start, end;
    printf("Enter the starting value: ");
    scanf("%d", &start);
    printf("Enter the end value: ");
    scanf("%d", &end);

    for (int i = start; i <= end; i++) {
        int num = i;
        int sum = 0;
        int numDigits = 0;
        int originalNum = num;

        while (num != 0) {
            num /= 10;
            numDigits++;
        }

        num = originalNum;
    while (num != 0) {
            int digit = num % 10;
            sum += pow(digit, numDigits);
            num /= 10;
        }

        if (sum == originalNum) {
            printf("%d is an Armstrong number.\n", originalNum);
        }
    }

    return 0;
}
