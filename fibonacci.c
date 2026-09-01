// Fibonacci series
// #include <stdio.h>
// int main()
// {
//     int n1 = 0, n2 = 1, n3, i, number;
//     printf("enter the number of elements");
//     scanf("%d", &number);
//     for (i = 2; i < number; ++i)
//     {
//         n3 = n1 + n2;
//         printf("%d\n", n3);
//         n1 = n2;
//         n2 = n3;
//     }

//     return 0;
// }

// Armstrong number
// #include <stdio.h>
// #include <math.h>

// int num, numberOfDigits, temp, result = 0;
// int Armstrong(int num)
// {

//     while (num != 0)
//     {
//         int digit = num % 10;
//         result += pow(digit, numberOfDigits);
//         num /= 10;
//     }
//     return result;
// }
// int main()
// {
//     printf("enter the number");
//     scanf("%d", &num);
//     temp = num;

//     if (result == num)
//     {
//         printf("The given no. is an armstrong number");
//     }
//     else
//     {
//         printf("It is not an armstrong number");
//     }

//     return 0;
// }