#include<stdio.h>

typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

// считать RGB-формат с консоли
Color getColor(){
    Color z;
    scanf("%hhd%hhd%hhd", &z.red, &z.green, &z.blue);
    return z;
}

unsigned long long convertToHTML(Color z){
    return z.red * 256 * 256 + z.green * 256 + z.blue; 
}

// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long html)
{
    Color z2;
    z2.blue = html % 256;
    z2.green = ((html - z2.blue) / 256) % 256;
    z2.red = html / 256 / 256 % 256;
    return z2;
}

void printRGB(Color z){
    printf("%d %d %d\n", z.red, z.green, z.blue);
}

void printHTML(Color z){
    printf("%X%X%X\n", z.red, z.green, z.blue);
}

int main(){
    Color z, z2;
    unsigned long long html;

    z = getColor();
    printRGB(z);

    html = convertToHTML(z);
    printf("%llu\n", html);
    printHTML(z);

    z2 = convertToRGB(html);
    printRGB(z2);

    return 0;
}