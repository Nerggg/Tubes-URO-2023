#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
const int map_size = 10;
class ship {
        private:
            string name;
            int health, damage, range;
        public:
            int x, y, xDist, yDist;
            void input(string, int, int, int, int, int, int, int);
            void output();
            void forward();
            void backward();
            void right();
            void left();
            void updateDist(int, int);
            bool isDead();
};
int main()
{
    srand(time(0));
    ship cakru, musuh;
    cakru.input("Cakru", 10, 2, 2, 0, 0, 0, 0);
    musuh.input("Musuh", 4, 1, 2, -5 + (rand() % 11), -5 + (rand() % 11), 0, 0);
    cakru.updateDist(musuh.x, musuh.y);
    musuh.updateDist(cakru.x, cakru.y);
    cakru.output();
    cout << endl;
    musuh.output();
    cout << endl;
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
    cout << "Jarak dengan Musuh: " << "(" << xDist << "," << yDist << ")" << endl;

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

bool ship::isDead()
{
    if (health <=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ship::updateDist(int xEnemy, int yEnemy)
{
    xDist = xEnemy - x;
    yDist = yEnemy - y;
}
