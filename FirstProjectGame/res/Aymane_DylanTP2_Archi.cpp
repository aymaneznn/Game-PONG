#include <iostream>
#include <string.h>
using namespace std;

void copieMemoire(void* d, void* s, int taille) {

    for (int i = 0; i < taille; i++) {
        *((char*)d + i) = *((char*)s + i);
    }
}

int main(void) {
    int tabA[10];
    int tabB[10];
    for (int i = 0; i < 10; i++){
        tabA[i] = i;
    }
    for (int i = 0; i < 10; i++){
        tabB[i] = i + 5;
    }
    // avant le passage de la fonction copieMemoire
    cout << tabA[0] << " " << tabA[9] << endl;
    cout << tabB[0] << " " << tabB[9] << endl;

    copieMemoire(tabB, tabA, sizeof(tabA));

    // apres le passage de la fonction copieMemoire
    cout << tabA[0] << " " << tabA[9] << endl;
    cout << tabB[0] << " " << tabB[9] << endl;

    return 0;
}
