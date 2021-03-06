//MaxandMinFinder

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>

//colors being used are
// PINK, YELLOW, ORANGE, BLUE, GREEN, RED, BROWN, PURPLE
using namespace std;
const int ROW = 3;
const int COL = 50;

int maxarray(int array[ROW]) {
    int max = -1;
    for (int count = 0; count < COL; count++) {
        if (array[count] > max && array[count] < 296)
            max = array[count];
    }
    return max;
}


int minarray(int array[]) {
    int min = 300;
    for (int count = 0; count < COL; count++) {
        if (array[count] < min && array[count] > -1)
            min = array[count];
    }
    return min;
}


void populatearrays(ifstream &fin, string color, int colorarray[][COL]) {
    int red, blue, green;
    int count = 0;
    string curcol;
    while (fin >> curcol >> red >> green >> blue) {
        if (string(color) == string(curcol)) {
            colorarray[0][count] = red;
            colorarray[1][count] = green;
            colorarray[2][count] = blue;
            count++;


        }

    }

}

void setnull(int array[ROW][COL]) {
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++)
            array[r][c] = -1;
}

void setmax(int array[ROW][COL]) {
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++)
            if (array[r][c] == -1)
                array[r][c] = 300;
}


int main() {

    string color;

    int pinks[ROW][COL];
    int reds[ROW][COL];
    int greens[ROW][COL];
    int oranges[ROW][COL];
    int blues[ROW][COL];
    int browns[ROW][COL];
    int purples[ROW][COL];
    int yellows[ROW][COL];
    setnull(pinks);
    setnull(reds);
    setnull(greens);
    setnull(oranges);
    setnull(blues);
    setnull(browns);
    setnull(purples);
    setnull(yellows);


    ifstream fin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");
    if (!fin)
        cout << "unable to open";
    string red = "red";
    string yellow = "yellow";
    string green = "green";
    string purple = "purple";
    string brown = "brown";
    string pink = "pink";
    string orange = "orange";
    string blue = "blue";
    populatearrays(fin, blue, blues);

    ifstream pfin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");


    populatearrays(pfin, pink, pinks);
    fin.close();
    ifstream ofin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");
    populatearrays(ofin, orange, oranges);
    ifstream gfin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");


    populatearrays(gfin, green, greens);
    ifstream bfin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");


    populatearrays(bfin, brown, browns);
    ifstream pufin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");

    populatearrays(pufin, purple, purples);
    ifstream yfin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");

    populatearrays(yfin, yellow, yellows);
    ifstream rfin(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgb.txt)");

    populatearrays(rfin, red, reds);


    ofstream fout(R"(C:\Users\joshz\Google Drive\Waterloo\rgbfindergood\rgbout.txt)");

    fout << "MAXIMUMS" << endl;


    fout << setw(10) << "RED:  " << maxarray(reds[0]) << setw(5) << maxarray(reds[1]) << setw(5) << maxarray(reds[2])
         << endl;
    fout << setw(10) << "GREEN:  " << maxarray(greens[0]) << setw(5) << maxarray(greens[1]) << setw(5)
         << maxarray(greens[2]) << endl;
    fout << setw(10) << "BLUE:  " << maxarray(blues[0]) << setw(5) << maxarray(blues[1]) << setw(5)
         << maxarray(blues[2]) << endl;
    fout << setw(10) << "PINK:  " << maxarray(pinks[0]) << setw(5) << maxarray(pinks[1]) << setw(5)
         << maxarray(pinks[2]) << endl;
    fout << setw(10) << "BROWN:  " << maxarray(browns[0]) << setw(5) << maxarray(browns[1]) << setw(5)
         << maxarray(browns[2]) << endl;
    fout << setw(10) << "PURPLE:  " << maxarray(purples[0]) << setw(5) << maxarray(purples[1]) << setw(5)
         << maxarray(purples[2]) << endl;
    fout << setw(10) << "ORANGE:  " << maxarray(oranges[0]) << setw(5) << maxarray(oranges[1]) << setw(5)
         << maxarray(oranges[2]) << endl;
    fout << setw(10) << "YELLOW:  " << maxarray(yellows[0]) << setw(5) << maxarray(yellows[1]) << setw(5)
         << maxarray(yellows[2]) << endl;

    setmax(pinks);
    setmax(reds);
    setmax(greens);
    setmax(oranges);
    setmax(blues);
    setmax(browns);
    setmax(purples);
    setmax(yellows);


    fout << "MINIMUMS" << endl;
    fout << setw(10) << "RED:  " << minarray(reds[0]) << setw(5) << minarray(reds[1]) << setw(5) << minarray(reds[2])
         << endl;
    fout << setw(10) << "GREEN:  " << minarray(greens[0]) << setw(5) << minarray(greens[1]) << setw(5)
         << minarray(greens[2]) << endl;
    fout << setw(10) << "BLUE:  " << minarray(blues[0]) << setw(5) << minarray(blues[1]) << setw(5)
         << minarray(blues[2]) << endl;
    fout << setw(10) << "PINK:  " << minarray(pinks[0]) << setw(5) << minarray(pinks[1]) << setw(5)
         << minarray(pinks[2]) << endl;
    fout << setw(10) << "BROWN:  " << minarray(browns[0]) << setw(5) << minarray(browns[1]) << setw(5)
         << minarray(browns[2]) << endl;
    fout << setw(10) << "PURPLE:  " << minarray(purples[0]) << setw(5) << minarray(purples[1]) << setw(5)
         << minarray(purples[2]) << endl;
    fout << setw(10) << "ORANGE:  " << minarray(oranges[0]) << setw(5) << minarray(oranges[1]) << setw(5)
         << minarray(oranges[2]) << endl;
    fout << setw(10) << "YELLOW:  " << minarray(yellows[0]) << setw(5) << minarray(yellows[1]) << setw(5)
         << minarray(yellows[2]) << endl;


    return 0;
}