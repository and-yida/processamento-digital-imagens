#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "pgm.hpp"

using namespace std;

int main()
{
    image img1, img2;

    loadPgm(img1, "lena256.pgm");

    //turn180(img1, img2);

    //turnImageMinus90(img1, img2);

    turnImage90(img1, img2);

    //negative(img1, img2);

    //brighten(img1, img2);

    savePgm(img2, "imagem_90.pgm");

    system("visualizar imagem_90.pgm");

    return 0;
}
