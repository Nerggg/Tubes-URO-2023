#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
class ship {
    private:
        string name;
        int health;
    public:
        int damage, range, x, y, xDist, yDist;
        void input(string, int, int, int, int, int);
        void output();
        void forward();
        void backward();
        void right();
        void left();
        void updateDist(int, int);
        bool isDead();
        void takeDamage(int);
};
void printMap(int, int, int, int);
int input, diff, killCount = 0;
int move(int x , int y)
{
    int mov;
    cin >> mov;
    if (x == 5 && mov == 3) {
        cout << "Error, move is out of the map"<<endl;
        return move (x,y);
    } else if (x == -5 && mov == 4) {
        cout << "Error, move is out of the map"<<endl;
        return move (x,y);
    } else if (y == 5 && mov == 1){
        cout << "Error, move is out of the map"<<endl;
        return move (x,y);
    } else if (y==-5 && mov == 2){
        cout << "Error, move is out of the map"<<endl;
        return move (x,y);
    } else {
        return mov;
    }
}
int main()
{
    srand(time(0));
    ship cakru, musuh;
    cout << "Pilih tingkat kesulitan" << endl;
    cout << "[1] Mudah\n[2] Normal\n[3] Sulit\n[4] Sulit Banget\n";
    cin >> diff;
    if (diff == 1)
    {
        cakru.input("Cakru", 10, 2, 2, 0, 0);
        musuh.input("Musuh", 4, 1, 2, -5 + (rand() % 11), -5 + (rand() % 11));       
    }
    else if (diff == 2)
    {
        cakru.input("Cakru", 10, 2, 2, 0, 0);
        musuh.input("Musuh", 4, 2, 2, -5 + (rand() % 11), -5 + (rand() % 11));
    }
    else if (diff == 3)
    {
        cakru.input("Cakru", 10, 2, 2, 0, 0);
        musuh.input("Musuh", 4, 3, 2, -5 + (rand() % 11), -5 + (rand() % 11));
    }
    else if (diff == 4)
    {
        cakru.input("Cakru", 10, 2, 2, 0, 0);
        musuh.input("Musuh", 4, 3, 3, -5 + (rand() % 11), -5 + (rand() % 11));
    }

    while (cakru.isDead() == false)
    {
        system("cls");
        cakru.updateDist(musuh.x, musuh.y);
        musuh.updateDist(cakru.x, cakru.y);
        printMap(cakru.x, cakru.y, musuh.x, musuh.y);
        cakru.output();
        cout << endl;
        musuh.output();
        cout << endl;
        cout << "Sekarang adalah giliran Anda. Apa yang ingin Anda lakukan?" << endl;
        cout << "[1] Bergerak maju\n[2] Bergerak mundur\n[3] Bergerak ke kanan\n[4] Bergerak ke kiri\n[5] Serang musuh\n[6] Diam di tempat\n";
        input = move(cakru.x, cakru.y);

        switch (input)
        {
            case 1:
                cakru.forward();
                break;
            case 2:
                cakru.backward();
                break;
            case 3:
                cakru.right();
                break;
            case 4:
                cakru.left();
                break;
            case 5:
                if (abs(cakru.xDist) <= 2 && abs(cakru.yDist) <= 2)
                {
                    cout << "Serangan kena!" << endl;
                    musuh.takeDamage(cakru.damage);
                    system("pause");
                }
                else
                {
                    cout << "Yah serangan tidak kena!" << endl;
                    system("pause");
                }
                break;
            case 6:
                break;
        }
        cakru.updateDist(musuh.x, musuh.y);
        musuh.updateDist(cakru.x, cakru.y);
        if (musuh.isDead() == false)
        {
            cout << "Sekarang adalah giliran musuh" << endl;
            if (abs(musuh.xDist) <= musuh.range && abs(musuh.yDist) <= musuh.range)
            {
                cakru.takeDamage(musuh.damage);
                cout << "Musuh menyerang kapal Cakru!" << endl;
                system("pause");
            }
            else if (musuh.xDist > musuh.range)
            {
                musuh.right();
                cout << "Musuh bergerak ke kanan" << endl;
                system("pause");
            }
            else if (musuh.xDist < -1*musuh.range)
            {
                musuh.left();
                cout << "Musuh bergerak ke kiri" << endl;
                system("pause");
            }
            else if (musuh.yDist > musuh.range)
            {
                musuh.forward();
                cout << "Musuh bergerak maju" << endl;
                system("pause");
            }
            else if (musuh.yDist < -1*musuh.range)
            {
                musuh.backward();
                cout << "Musuh bergerak mundur" << endl;
                system("pause");
            }
        }
        else
        {
            cout << "Selamat! Kapal musuh telah hancur!" << endl;
            cout << "Oh tidak! Kapal musuh datang lagi!" << endl;
            killCount++;
            if (diff == 1)
            {
                musuh.input("Musuh", 4, 1, 2, -5 + (rand() % 11), -5 + (rand() % 11));       
            }
            else if (diff == 2)
            {
                musuh.input("Musuh", 4, 2, 2, -5 + (rand() % 11), -5 + (rand() % 11));
            }
            else if (diff == 3)
            {
                musuh.input("Musuh", 4, 3, 2, -5 + (rand() % 11), -5 + (rand() % 11));
            }
            else if (diff == 4)
            {
                musuh.input("Musuh", 4, 3, 3, -5 + (rand() % 11), -5 + (rand() % 11));
            }
            system("pause");
        }
    }
    cout << "Yah kapal Anda hancur!" << endl;
    cout << "Permainan bagus!" << endl;
    cout << "Total kapal musuh yang dihancurkan: " << killCount << endl;
}

void ship::input(string n, int h, int d, int r, int posX, int posY)
{
    name = n;
    health = h;
    damage = d;
    range = r;
    x = posX;
    y = posY;
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

void ship::takeDamage(int damage)
{
    health-=damage;
}

void printMap(int xCakru, int yCakru, int xMusuh, int yMusuh)
{
    for (int i = 5; i >= -5; i--)
    {
        for (int j = -5; j <= 5; j++)
        {
            if (xCakru == j && yCakru == i)
            {
                cout << "C";
            }
            else if (xMusuh == j && yMusuh == i)
            {
                cout << "M";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}
