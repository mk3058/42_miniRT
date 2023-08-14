#include "parser/parser.h"
#include "object/object.h"

#include <stdio.h>

void print_cartesian(t_cartesian c) {
    printf("x: %lf, y: %lf, z: %lf\n", c.x, c.y, c.z);
}

void print_light(t_light *light) {
    printf("Light:\n");
    printf("\tOrigin: ");
    print_cartesian(light->origin);
    printf("\tBrightness: %lf\n", light->brightness);
    printf("\tColor: ");
    print_cartesian(light->color);
}

void print_sphere(t_sphere *sphere) {
    printf("Sphere:\n");
    printf("\tOrigin: ");
    print_cartesian(sphere->origin);
    printf("\tRadius: %lf\n", sphere->radius);
    printf("\tColor: ");
    print_cartesian(sphere->color);
}

void print_plane(t_plane *plane) {
    printf("Plane:\n");
    printf("\tOrigin: ");
    print_cartesian(plane->origin);
    printf("\tNormal Vector: ");
    print_cartesian(plane->n_vec);
    printf("\tColor: ");
    print_cartesian(plane->color);
}

void print_cylinder(t_cylinder *cylinder) {
    printf("Cylinder:\n");
    printf("\tCenter: ");
    print_cartesian(cylinder->center);
    printf("\tAxis: ");
    print_cartesian(cylinder->axis);
    printf("\tRadius: %lf\n", cylinder->radius);
    printf("\tHeight: %lf\n", cylinder->height);
    printf("\tColor: ");
    print_cartesian(cylinder->color);
}

void print_objects(t_object *object) {
    while (object != NULL) {
        switch (object->type) {
            case LIGHT:
                print_light((t_light *)object->obj);
                break;
            case SPHERE:
                print_sphere((t_sphere *)object->obj);
                break;
            case PLANE:
                print_plane((t_plane *)object->obj);
                break;
            case CYLINDER:
                print_cylinder((t_cylinder *)object->obj);
                break;
        }
        object = object->next;
    }
}

void print_element(t_element element) {
    printf("Camera:\n");
    printf("\tOrigin: ");
    print_cartesian(element.camera.origin);
    printf("\tDirection Vector: ");
    print_cartesian(element.camera.d_vec);
    printf("\tFOV: %lf\n\n", element.camera.fov);

    printf("Ambient:\n");
    printf("\tBrightness: %lf\n", element.ambient.brightness);
    printf("\tColor: ");
    print_cartesian(element.ambient.color);
	printf("\n");

    printf("[Lights]\n");
    print_objects(element.light);

    printf("\n[Objects]\n");
    print_objects(element.object);
}
