#include <stdio.h>
#include <math.h>
#define PI 3.14159265

struct point{
	float x;
	float y; 
	float z;
};

struct cone{
	struct point base_center;
	struct point vertex;
	float vertex_angle;
};

float get_distant(struct point a, struct point b){
	return sqrt((pow((a.x-b.x), 2)+ pow((a.y-b.y), 2) + pow((a.z-b.z), 2)));
};

float get_radius(struct cone cone){
	return tan(cone.vertex_angle*PI/180)*get_distant(cone.base_center, cone.vertex);
};

float get_area(struct cone cone){
	float radius = get_radius(cone);
	float height = get_distant(cone.base_center, cone.vertex);
	return PI*radius*(radius+sqrt(pow(height, 2) + pow(radius, 2)));
};

float get_perimeter(struct cone cone){
	float radius = get_radius(cone);
	float height = get_distant(cone.base_center, cone.vertex);
	return (PI*pow(radius, 2)*height)/3;
};


int main(void){
	struct point a = {0, 4, 3};
	struct point b = {0, 0, 0};
	struct cone cone = {a, b, 30};
	printf("%f\n", get_perimeter(cone));
	return 0;
}








