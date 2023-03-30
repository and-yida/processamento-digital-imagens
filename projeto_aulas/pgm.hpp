#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct image {
    string type;
    int w, h, bits;
    vector<vector<uint8_t>> data;
};

void eatComment(ifstream &file) {
    char linebuf[1024];
    char ppp;
    while (ppp = file.peek(), ppp == '\n' || ppp == '\r')
        file.get();
    if (ppp == '#')
        file.getline(linebuf, 1023);
}

void loadPgm(image &img, const string &name) {
    ifstream file(name.c_str(), ios::in);
    if (file.fail()) {
        cout << "Erro ao abrir o arquivo " << name << endl;
        return;
    }
    eatComment(file);
    file >> img.type;
    eatComment(file);
    file >> img.w;
    eatComment(file);
    file >> img.h;
    eatComment(file);
    file >> img.bits;
    img.data.resize(img.w, vector<uint8_t>(img.h));
    for (int i = 0; i < img.w; i++) {
        for (int j = 0; j < img.h; j++) {
            int v;
            file >> v;
            img.data[i][j] = v;
        }
    }
    file.close();
}

void savePgm(image &img, const string &name) {
    ofstream file(name.c_str(), ios::out);
    if (file.fail()) {
        cout << "Erro ao abrir o arquivo " << name << endl;
        return;
    }
    file << img.type << endl
         << img.w << ' ' << img.h << endl
         << img.bits << endl;
    for (int i = 0; i < img.w; i++) {
        for (int j = 0; j < img.h; j++) {
            file << +img.data[i][j] << endl;
        }
    }
    file.close();
}

void printHeader(image img) {
    cout << "PGM type:   " << img.type << endl;
    cout << "PGM width:  " << img.w << endl;
    cout << "PGM height: " << img.h << endl;
    cout << "PGM bits:   " << img.bits << endl;
}

void cloneHeader(image img, image &out) {
    out.type = img.type;
    out.bits = img.bits;
    out.w = img.w;
    out.h = img.h;
    out.data.clear();
    out.data.resize(img.w, vector<uint8_t>(img.h));
}

void printData(image img) {
    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            cout << setw(3);
            cout << +img.data[i][j] << ' ';
        }
        cout << endl;
    }
}

void turnImage90(image img1, image &img2) {
    cloneHeader(img1, img2);
    for (int i = 0; i < img1.h; i++) {
        for (int j = 0; j < img1.w; j++) {
            img2.data[j][img1.w-1-i] = img1.data[i][j];
        }
    }
}

void turnImageMinus90(image img1, image &img2) {
    cloneHeader(img1, img2);
    for (int i = 0; i < img1.h; i++) {
        for (int j = 0; j < img1.w; j++) {
            img2.data[img1.h-j-1][i] = img1.data[i][j];
        }
    }
}

void turn180(image img1, image &img2) {
    cloneHeader(img1, img2);
    for (int i = 0; i < img1.h; i++) {
        for (int j = 0; j < img1.w; j++) {
            img2.data[img1.w-i-1][img1.h-j-1] = img1.data[i][j];
        }
    }
}

void negative(image img1, image &img2) {
    cloneHeader(img1, img2);
    for (int i = 0; i < img1.h; i++) {
        for (int j = 0; j < img1.w; j++) {
            img2.data[i][j] = 255 - img1.data[i][j];
        }
    }
}

void brighten(image img1, image &img2) {
    int p;
    cloneHeader(img1, img2);
    cout << "Forneca o parametro: " << endl;
    cin >> p;
    for (int i = 0; i < img1.h; i++) {
        for (int j = 0; j < img1.w; j++) {
            if (img1.data[i][j] * p > 255) {
                img2.data[i][j] = 255;
            }
            else {
            img2.data[i][j] = img1.data[i][j] * p;
            }
        }
    }
}

void normalize(image img, image &out) {
    cloneHeader(img, out);
    int max = 0, min = 255;
    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            if (img.data[i][j] > max) max = img.data[i][j];
            if (img.data[i][j] < min) min = img.data[i][j];
        }
    }
    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            out.data[i][j] = (img.data[i][j] - min) * 255 / (max - min);
        }
    }
}

