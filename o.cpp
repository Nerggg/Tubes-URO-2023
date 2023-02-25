#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

// Membuat class ship dengan atribut name, health, damage, range, posisi dalam x dan y.

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
        bool isCrash(int, ship);
        bool isDead();
        void takeDamage(int);
};
void printMap(int, int, int, int);
int input, diff, killCount = 0;
int main()
{   // Menginisialisasi nilai "srand" (sebuah fungsi dalam library "cstdlib") dengan nilai waktu saat ini menggunakan "time(0)". Ini digunakan agar fungsi "rand" pada program dapat menghasilkan nilai acak yang berbeda setiap kali program dijalankan.
    srand(time(0));

    ship cakru, musuh; // Membuat objek "cakru" dan "musuh" dari kelas "ship"
    cout << "Pilih tingkat kesulitan" << endl;
    cout << "[1] Mudah\n[2] Normal\n[3] Sulit\n[4] Sulit Banget\n";
    cin >> diff; // Input tingkat kesulitan

    // Isi semua data objek berdasarkan tingkat kesulitan

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

    // Selama cakru belum mati, lakukan loop
    while (cakru.isDead() == false)
    {
        system("cls"); // Clear screen
        cakru.updateDist(musuh.x, musuh.y); // Update posisi cakru
        musuh.updateDist(cakru.x, cakru.y); // Update posisi musuh

        // Print map sederhana

        printMap(cakru.x, cakru.y, musuh.x, musuh.y);
        cakru.output();
        cout << endl;
        musuh.output();
        cout << endl;
        cout << "Sekarang adalah giliran Anda. Apa yang ingin Anda lakukan?" << endl;
        cout << "[1] Bergerak maju\n[2] Bergerak mundur\n[3] Bergerak ke kanan\n[4] Bergerak ke kiri\n[5] Serang musuh\n[6] Diam di tempat\n";
        cin >> input;
        while (cakru.isCrash(input,musuh) == true)
        {
            system("cls");
            printMap(cakru.x, cakru.y, musuh.x, musuh.y);
            cakru.output();
            cout << endl;
            musuh.output();
            cout << endl;
            cout << "Sekarang adalah giliran Anda. Apa yang ingin Anda lakukan?" << endl;
            cout << "[1] Bergerak maju\n[2] Bergerak mundur\n[3] Bergerak ke kanan\n[4] Bergerak ke kiri\n[5] Serang musuh\n[6] Diam di tempat\n";
            cin >> input;
        }
        switch (input)
            cin >> input;   // Input action yang akan dilakukan cakru
        switch (input)  // Lakukan action sesuai input action
        {
            case 1: // Bila dipilih 1, maka cakru akan maju
                cakru.forward();
                break;
            case 2: // Bila dipilih 2, maka cakru akan mundur
                cakru.backward();
                break;
            case 3: // Bila dipilih 3, maka cakru akan bergerak ke kanan
                cakru.right();
                break;
            case 4: // Bila dipilih 4, maka cakru akan bergerak ke kiri
                cakru.left();
                break;
            case 5: // Bila dipilih 5, maka cakru akan menyerang
                if (abs(cakru.xDist) <= 2 && abs(cakru.yDist) <= 2) // Apabila posisi terhadap kapal musuh sesuai range, maka serangan kena

                {
                    cout << "Serangan kena!" << endl;
                    musuh.takeDamage(cakru.damage);
                    system("pause");
                }

                else    // apabila posisi cakru terhadap kapal musuh tidak sesuai range, maka serangan tidak kena.

                {
                    cout << "Yah serangan tidak kena!" << endl;
                    system("pause");
                }
                break;

            case 6: // Bila dipilih 6, cakru tidak melakukan apa apa
                break;
        }

        // Update kondisi musuh dan cakru
        cakru.updateDist(musuh.x, musuh.y);
        musuh.updateDist(cakru.x, cakru.y);
        if (musuh.isDead() == false)    // Jika musuh belum mati, maka giliran musuh untuk bergerak
        {
            cout << "Sekarang adalah giliran musuh" << endl;
            if (abs(musuh.xDist) <= musuh.range && abs(musuh.yDist) <= musuh.range) // Jika posisi musuh terhadap cakru sesuai range, maka musuh akan menyerang.
            {
                cakru.takeDamage(musuh.damage); // Cakru akan menerima damage dari musuh dan health berkurang
                cout << "Musuh menyerang kapal Cakru!" << endl;
                system("pause");
            }
            else if (musuh.xDist > musuh.range) // Jika posisi horizontal musuh belum sesuai dengan rangenya, maka musuh akan bergerak secara horizontal

            {
                musuh.right();
                cout << "Musuh bergerak ke kanan" << endl;
                system("pause");
            }

            else if (musuh.xDist < -1*musuh.range)  // Jika posisi horizontal musuh belum sesuai dengan rangenya, maka musuh akan bergerak secara horizontal

            {
                musuh.left();
                cout << "Musuh bergerak ke kiri" << endl;
                system("pause");
            }

            else if (musuh.yDist > musuh.range) // Jika posisi vertikal musuh belum sesuai dengan rangenya, maka musuh akan bergerak secara vertikal

            {
                musuh.forward();
                cout << "Musuh bergerak maju" << endl;
                system("pause");
            }

            else if (musuh.yDist < -1*musuh.range)  // Jika posisi vertikal musuh belum sesuai dengan rangenya, maka musuh akan bergerak secara vertikal

            {
                musuh.backward();
                cout << "Musuh bergerak mundur" << endl;
                system("pause");
            }
        }

        else    // Jika musuh pertama sudah hancur, maka generate musuh selanjutnya dan tambahkan kill count

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

    // Keluar dari loop saat kapal cakru sudah hancur, dan tampilkan kill count-nya

    cout << "Yah kapal Anda hancur!" << endl;
    cout << "Permainan bagus!" << endl;
    cout << "Total kapal musuh yang dihancurkan: " << killCount << endl;
}

// Mengisi nilai atribut kapal, seperti nama, kesehatan, serangan, jarak serangan, dan posisi.

void ship::input(string n, int h, int d, int r, int posX, int posY)
{
    name = n;
    health = h;
    damage = d;
    range = r;
    x = posX;
    y = posY;
}

// Menampilkan informasi dari kapal, seperti nama, kesehatan, serangan, jarak serangan, posisi, dan jarak dengan musuh.
void ship::output()
{
    cout << "Nama Kapal: " << name << endl;
    cout << "Nyawa: " << health << endl;
    cout << "Damage: " << damage << endl;
    cout << "Jarak Serangan: " << range << endl;
    cout << "Posisi: " << "(" << x << "," << y << ")" << endl;
    cout << "Jarak dengan Musuh: " << "(" << xDist << "," << yDist << ")" << endl;

}

// Memindahkan kapal ke depan.
void ship::forward()
{
    y+=1;
}

// Memindahkan kapal ke belakang.
void ship::backward()
{
    y-=1;
}

// Memindahkan kapal ke kanan.
void ship::right()
{
    x+=1;
}

// Memindahkan kapal ke kiri.
void ship::left()
{
    x-=1;
}

bool ship::isCrash(int move, ship musuh)
{
    switch(move)
    {
        case 1:
            if (y+1 == musuh.y && x == musuh.x)
            {
                cout << "Kapal tidak bisa maju karena akan menabrak kapal musuh!" << endl;
                system("pause");
                return true;
            }
        case 2:
            if (y-1 == musuh.y && x == musuh.x)
            {
                cout << "Kapal tidak bisa mundur karena akan menabrak kapal musuh!" << endl;
                system("pause");
                return true;
            }
        case 3:
            if (x+1 == musuh.x && y == musuh.y)
            {
                cout << "Kapal tidak bisa ke kanan karena akan menabrak kapal musuh!" << endl;
                system("pause");
                return true;
            }
        case 4:
            if (x-1 == musuh.x && y == musuh.y)
            {
                cout << "Kapal tidak bisa ke kiri karena akan menabrak kapal musuh!" << endl;
                system("pause");
                return true;
            }
    }
    return false;
}

// Mengecek apakah kapal sudah mati atau belum dengan melihat jumlah health, jika health <= 0 maka True.

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

// Menghitung jarak terhadap enemy

void ship::updateDist(int xEnemy, int yEnemy)
{
    xDist = xEnemy - x;
    yDist = yEnemy - y;
}

// Mengurangi health sebesar jumlah serangan apabila serangan kena

void ship::takeDamage(int damage)
{
    health-=damage;
}

// Menampilkan virtual map sederhana

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