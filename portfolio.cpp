#include <stdio.h>
#include <math.h>
#include <iostream>
#define PI 3.14159265

struct point{
	double x;
	double y; 
	double z;
};

struct cone{
	struct point base_center;
	struct point vertex;
	double vertex_angle;
};

/* this function calculate the distant between 2 points */
float get_distant(struct point a, struct point b){
	return sqrt((pow((a.x-b.x), 2)+ pow((a.y-b.y), 2) + pow((a.z-b.z), 2)));
};
/* end of function */

/* This function calculate the radius of the cone given */
float get_radius(struct cone cone){
	return tan(cone.vertex_angle*PI/180)*get_distant(cone.base_center, cone.vertex);
};
/* end of function */

/* This function calculate the surface area of the cone given */
float get_area(struct cone cone){
	double radius = get_radius(cone);
	double height = get_distant(cone.base_center, cone.vertex);
	return PI*radius*(radius+sqrt(pow(height, 2) + pow(radius, 2)));
};
/* end of function */

/* This function calculate the perimeter of the cone given */
float get_perimeter(struct cone cone){
	double radius = get_radius(cone);
	double height = get_distant(cone.base_center, cone.vertex);
	return (PI*pow(radius, 2)*height)/3;
};
/* end of function */


void readFile() {

    FILE *source;

    double xtip, ytip, ztip, xbase, ybase, zbase, angle;

    char file_name[100];
    scanf("%s", file_name);
    source = fopen(file_name, "r");

    double l = fscanf(source, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf", &xtip, &ytip, &ztip, &xbase, &ybase, &zbase, &angle);

    while (l != EOF) {
    	/* construct cones from file */
        struct point base = {xbase, ybase, zbase};
        struct point tip = {xtip, ytip, ztip};
        struct cone cone = {base, tip, angle};

        double area = get_area(cone);
        double perimeter = get_perimeter(cone);

        printf("The surface area of the Cone is: %.2f\n" , area);
        printf("The Volume of the Cone is: %.2f\n", perimeter);
        printf("\n");

        l = fscanf(source, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf", &xtip, &ytip, &ztip, &xbase, &ybase, &zbase, &angle);

    }   /* end of while (l != EOF) */

    fclose(source);

}   /* end of void readFile(char sourceFile[]) */

int main(void){

	readFile();
	return 0;
}








