// raytracing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ray.h"

vec3 color(const ray& r)
{
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5*(unit_direction.y() + 1.0);
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main()
{
    int nx = 200;
    int ny = 100;

     FILE* stream;
     freopen_s(&stream, "demo.ppm", "w", stdout);
    //freopen("demo.ppm", "w", stdout);

    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(0.0, 2.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origion(0.0, 0.0, 0.0);

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; j--)
    {
        for (int i = 0; i < nx; i++)
        {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origion, lower_left_corner + u * horizontal + v * vertical);
            vec3 col = color(r);

            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
     fclose(stream);

    return 0;
}

