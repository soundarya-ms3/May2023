#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

void readComplex(struct Complex* num) {
    printf("Enter the real part: ");
    scanf("%f", &(num->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(num->imaginary));
}

void writeComplex(struct Complex num) {
    printf("Complex Number: %.2f + %.2fi\n", num.real, num.imaginary);
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex product;
    product.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    product.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return product;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("\nEnter the second complex number:\n");
    readComplex(&num2);


    printf("\nResult of addition:\n");
    sum = addComplex(num1, num2);
    writeComplex(sum);

    printf("\nResult of multiplication:\n");
    product = multiplyComplex(num1, num2);
    writeComplex(product);

    return 0;
}
