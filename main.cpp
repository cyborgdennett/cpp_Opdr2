#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

//using namespace std;

/* Requirements:
 *  Deze code heeft een struct Vec3D nodig met daarin de x,y en z waardes.
 *  Vec3D heeft een constructor nodig.
 *  Een Vec3D en een float moet geprint worden met show().
 *  De volgende functies moeten met een Vec3D worden uitgerekend:
 *      minus, add, sub, mul, div, norm(afstand vanaf origin), unit(norm van 1), dot(inproduct van twee vectors) en cross(uitproduct van twee vectors)
 *
 * Testspecs:
 *  Om te testen of de functies werken, zal iedere functie een unit test krijgen met een vooraf uitgerekende uitkomst.
 *  Om de boundaries te checken zal ik een paar keer buiten de maxvalue van float raken om te zien wat er gebeurd.
 *
 * Design:
 *  Om de code zo compact mogelijk te houden, gebruik ik waar kan, eerder gebruikte functies.
 */

struct Vec3D {float x, y, z;};

Vec3D vec3D(float x, float y, float z){
    Vec3D self;
    self.x = x;
    self.y = y;
    self.z = z;
    return self;
}
void show(std::string label, Vec3D const &self){std::cout << label << ":\t" << self.x << " " << self.y << ' ' << self.z << std::endl;}
void show(std::string label, float scalar){std::cout << label << ":\t" << std::fixed << std::setprecision(3) << scalar << std::endl;}
void show(){std::cout << std::endl;}
Vec3D minus(Vec3D const &self){return vec3D(-self.x,-self.y,-self.z);}
Vec3D add(Vec3D const &self, Vec3D const &other){return vec3D(self.x+other.x,self.y+other.y,self.z+other.z);}
Vec3D sub(Vec3D const &self, Vec3D const &other){return vec3D(self.x-other.x,self.y-other.y,self.z-other.z);}
Vec3D mul(Vec3D const &self, float scalar){return vec3D(self.x*scalar,self.y*scalar,self.z*scalar);}
Vec3D div(Vec3D const &self, float scalar){return vec3D(std::fmod(self.x,scalar),std::fmod(self.y,scalar),std::fmod(self.z,scalar));}
float norm(Vec3D const &self){return std::sqrt(self.x*self.x + self.y*self.y + self.z*self.z);}
Vec3D unit(Vec3D const &self){float n = 1/norm(self); return vec3D(self.x*n, self.y*n, self.z*n);}
float dot(Vec3D const &self, Vec3D const &other){Vec3D a = unit(self); Vec3D b = unit(other); return a.x*b.x + a.y*b.y + a.z*b.z;}
Vec3D cross(Vec3D const &self, Vec3D const &other){Vec3D a = unit(self); Vec3D b = unit(other); return vec3D(a.y*b.z - a.z*b.y, a.x*b.z - a.z*b.x, a.x*b.y - a.y*b.x);}


int main() {
    Vec3D vector1 = vec3D(0,0,0);
    Vec3D vector2 = vec3D(1,1,0);
    Vec3D vector3 = vec3D(1,0,1);
    show("vector1", vector1);//0 0 0 verwacht
    show();
    vector1 = add(vector1,vector2);
    show("vector1 add", vector1);//1 1 0 verwacht
    show();
    vector1 = add(vector1,vector3);
    show("vector1 add", vector1);//2 1 1 verwacht
    show();
    vector1 = minus(vector1);
    show("vector1 minus", vector1);//-2 -1 -1 verwacht
    show();
    vector1 = sub(vector1,vector2);
    show("vector1 sub", vector1);//-3 -2 -1 verwacht
    show();
    vector1 = mul(vector1,2.f);
    show("vector1 mul", vector1);//-6 -4 -2 verwacht
    show();
    vector1 = div(vector1,5.f);
    show("vector1 div", vector1);//-1 -4 -2 verwacht
    show();
    show("vector1 norm", norm(vector1));//de wortel van (1^2 + 4^2 + 2^2) = 4.58257
    show();
    vector1 = unit(vector1);
    show("vector1 unit", vector1);//verwacht wordt dat x,y en z met 1/4.58 wordt vermenigvuldigd. x:-1*1/4.58=-.218 y:-4*1/4.58=-.873 z: -2*1/4.58=-.436
    show();
    vector1 = vec3D(0,0,1);
    vector3 = vec3D(1,0,0);
    show("vector1 dot", dot(vector1,vector3));//verwacht word 0
    show();
    vector1 = cross(vector1,vector2);
    show("vector1 cross", vector1);
    show();

    return 0;
}
