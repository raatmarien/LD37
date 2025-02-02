#ifndef CIRCLE_H
#define CIRCLE_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Circle
{
    public:
        Circle(Vector2f pos, std::array<unsigned char, 8> momDNA,
                             std::array<unsigned char, 8> dadDNA);
        void update(double dt);
        void draw(RenderWindow* window);

        void moveTo(Vector2f goalPos) { this->goalPos = goalPos; };

        unsigned char getr()      { return r; };
        unsigned char getg()      { return g; };
        unsigned char getb()      { return b; };
        unsigned char getRadius() { return radius; };
        unsigned char getSpeed()  { return speed; };

        Vector2f getPos() { return pos; };
        bool isMoving() { return moving; };
        bool isBreeding() { return lastBreedAge > age - 10; };
        void setBreeding(bool breeding) { this->lastBreedAge = age; };
        std::array<unsigned char, 8> getMomDNA() { return momDNA; };
        std::array<unsigned char, 8> getDadDNA() { return dadDNA; };
        float getAge() { return age; };
        void setAge(float age) { this->age = age; };
    protected:
    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char radius;
        unsigned char speed;

        std::array<unsigned char, 8> momDNA{ {0, 0, 0, 0, 0, 0, 0, 0} };
        std::array<unsigned char, 8> dadDNA{ {0, 0, 0, 0, 0, 0, 0, 0} };

        Vector2f pos;
        Vector2f goalPos {-1, -1};

        bool moving = false;
        bool breeding = false;

        float age = 0;
        float lastBreedAge = -10;
};

#endif // CIRCLE_H
