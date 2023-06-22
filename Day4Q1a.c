#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

void calculateVolume(struct Box* boxPtr) {
    float volume = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    printf("Volume: %.2f\n", volume);
}

void calculateSurfaceArea(struct Box* boxPtr) {
    float surfaceArea = 2 * ((*boxPtr).length * (*boxPtr).width +(*boxPtr).length * (*boxPtr).height + (*boxPtr).width * (*boxPtr).height);
    printf("Total Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box box;
    struct Box* boxPtr = &box;

    printf("Enter the dimensions of the box:\n");
    printf("Length: ");
    scanf("%f", &box.length);
    printf("Width: ");
    scanf("%f", &box.width);
    printf("Height: ");
    scanf("%f", &box.height);

    printf("\nCalculating...\n");
    calculateVolume(&box);
    calculateSurfaceArea(&box);

    return 0;
}
