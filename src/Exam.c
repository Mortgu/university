#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Exam.h"

int main(int argc, char *argv[]) {
    unsigned int modResult = modulo(8, 4);
    printf("Rest: %i\n", modResult);

    char* string = "string_length";
    printf("Length of string: %i\n", myOwnStrLen(string));

    Rectangle rectangle = {{6, 5}, {0, 1}};
    int isSquare = is_square(&rectangle);
    printf("Rectangle is square: %s\n", isSquare == 0 ? "true" : "false");

    Point points[4] = {{1, 2}, {5, 2}, {1, 0}, {2, 7}};
    Rectangle* surroundingRectangle = surround(points, 3);

    printf("Surrounding rectangle coordinates: (%f, %f) | (%f, %f)\n",
           surroundingRectangle->upperRightCorner.x,
           surroundingRectangle->upperRightCorner.y,
           surroundingRectangle->lowerLeftCorner.x,
           surroundingRectangle->lowerLeftCorner.y);

    free(surroundingRectangle);

    int compareResult = _strcmp_("compareMe", "compareMd");
    printf("Strings are equal: %s\n", compareResult == 0 ? "true" : "false");

    //printNumberMod2(4);

    int list[4] = {1, 45, 2, 5};
    swapElements(&list[1], &list[2]);

    for (int i = 0; i < 4; i++) {
        printf("%i\n", list[i]);
    }

    int i = 255;
    int* p_i = &i;
    printf("%p = %d\n", p_i, *p_i);
    printf("%p = %d\n", ((char*) p_i) + 1, *(((char*) p_i) + 1));
    printf("%p = %d\n", ((char*) p_i) + 2, *(((char*) p_i) + 2));
    printf("%p = %d\n", ((char*) p_i) + 3, *(((char*) p_i) + 3));

    void* p = (int*) &i;
    printf("%p", p);

    return EXIT_SUCCESS;
}

/*
 * Exercise 7 (1): Prints a cross to the console
 *      with the height and width of the number
 */

 void paintCross(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i) {
                printf("*");
            } else if (j == (size - i - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
    }
}

/*
 * Exercise 7 (2): A recursive function implementing modulo operations
 *      without using modulo sign
 */

unsigned int modulo(unsigned int x, unsigned int n) {
    if (n > x) {
        return x;
    } else if (x == n) {
        return 0;
    } else {
        return modulo(x-n, n);
    }
}

/*
 * A recursive function implementing factorial operations
 *      without using factorial-operator
 */

int factorial(int number) {
    if (number == 1) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}

/*
 * A recursive function implementing multiplication operations
 *      without using multiplication-operator
 */

unsigned int multiply(unsigned int a, unsigned int b) {
    if (b == 1) {
        return a;
    } else {
        return a + multiply(a, b - 1);
    }
}

/*
 * Exercise ?: A function that checks if a Rectangle (struct) is a square or not
 */

int is_square(Rectangle* rectangle) {
    double x_diff = fabs(rectangle->upperRightCorner.x - rectangle->lowerLeftCorner.x);
    double y_diff = fabs(rectangle->upperRightCorner.y - rectangle->lowerLeftCorner.y);

    if (x_diff == y_diff) return 1;
    return 0;
}

/*
 * Exercise ?: A function that creates a new rectangle surrounding all points passed to function
 */

Rectangle* surround(Point points[], int n) {
    Point upperRight, lowerLeft;
    Rectangle* rectangle = (Rectangle*) malloc(sizeof(struct Rectangle));

    if (rectangle == NULL) {
        printf("Error allocating memory for rectangle!");
        return NULL;
    }

    upperRight.x = points[0].x;
    upperRight.y = points[0].y;

    lowerLeft.x = points[0].x;
    lowerLeft.y = points[0].y;

    for (int i = 0; i <= n; i++) {
        if (upperRight.x < points[i].x) {
            upperRight.x = points[i].x;
        }

        if (upperRight.y < points[i].y) {
            upperRight.y = points[i].y;
        }

        if (lowerLeft.x > points[i].x) {
            lowerLeft.x = points[i].x;
        }

        if (lowerLeft.y > points[i].y) {
            lowerLeft.y = points[i].y;
        }
    }

    rectangle->upperRightCorner = upperRight;
    rectangle->lowerLeftCorner = lowerLeft;

    return rectangle;
}

/*
* Exercise ?: A function to get the length of a string without the \0 symbol
*/

int myOwnStrLen(const char* string) {
    int length = 0;
    // for (length = 0; string[length] != 0; length++);
    // oder
    while (string[length] != 0) length++;
    return length;
}

/*
 * Task 1a: PG1 Fischer 2021 WS PK
 */

int _strcmp_(char* a, char* b) {
    if (strlen(a) != strlen(b)) {
        return -1;
    }

    for (int i = 0; a[i] != 0; i++) {
        if (a[i] != b[i]) return -1;
    }

    return 0;
}

/*
* Exercise 4 (1. Wiederholung Kontrollstrukturen)
*/

void printNumberMod2(int number) {
    for (int i = -number; i <= number; i+=2) {
        printf("%i ", i);
    }
}

/*
 * Swap Elements
 */

void swapElements(int* indexA, int* indexY) {
    int temp = *indexA;
    *indexA = *indexY;
    *indexY = temp;
}