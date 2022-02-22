#include <iostream>
#include <string.h>
using namespace std;

int sommePara(int a, int b, int (*ptr) (int, int)){
    return (*ptr)(a, b);
}

int somme(int a, int b){
    return a + b;
}

int mult(int a, int b){
    return a * b;
}

int jsp(int a, int b){
    return a  * a * b;
}

int main(void){
    cout << sommePara(5, 2, somme) << endl;
    cout << sommePara(5, 2, mult) << endl;
    cout << sommePara(5, 2, jsp) << endl;

    return 0;
}
