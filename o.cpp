#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
const int map_size = 10;
class ship {
        private:
            string name;
            int health, damage, range, x, y, xDist, yDist;
        public:
            void input(string, int, int, int, int, int, int, int);
            void output();
            void forward();
            void backward();
            void right();
            void left();
};
int main()
{
    srand(time(0));
    ship cakru, musuh;
    cakru.input("Cakru", 10, 2, 2, 0, 0, 0, 0);
    cakru.output();
    cout << endl;
    musuh.input("Musuh", 4, 1, 2, -5 + (rand() % 11), -5 + (rand() % 11), 0 , 0);
    musuh.output();
}

void ship::input(string n, int h, int d, int r, int posX, int posY, int xD, int yD)
{
    name = n;
    health = h;
    damage = d;
    range = r;
    x = posX;
    y = posY;
    xDist = xD;
    yDist = yD;
}

void ship::output()
{
    cout << "Nama Kapal: " << name << endl;
    cout << "Nyawa: " << health << endl;
    cout << "Damage: " << damage << endl;
    cout << "Jarak Serangan: " << range << endl;
    cout << "Posisi: " << "(" << x << "," << y << ")" << endl;
    cout << "Jarak dengan Lawan: " << "(" << xDist << "," << yDist << ")" << endl;
}

void ship::forward()
{
    y+=1;
}

void ship::backward()
{
    y-=1;
}

void ship::right()
{
    x+=1;
}

void ship::left()
{
    x-=1;
}
