#include <stdio.h>
#include <stdlib.h>

class Point3d {
public:
    virtual ~Point3d();
    // static Point3d origin;
    float x, y, z;
};

int main() {
    printf("&Point3d::x = %p\n", &Point3d::x);
    printf("&Point3d::y = %p\n", &Point3d::y);
    printf("&Point3d::z = %p\n", &Point3d::z);
    return 0;
}
