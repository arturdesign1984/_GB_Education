#include <iostream>
using namespace std;

bool b = true;                      // 1 Byte
char c = 'c';                       // 1 Byte
unsigned char uc = 255U;            // 1 Byte
short int si = 32'767;              // 2 Byte
unsigned short int usi = 65'535U;   // 2 Byte
int i = 2'147'483'647;              // 4 Byte
long long ll = 4'000'000'000'000LL; // 8 Byte
float f = 3.4E+38F;                 // 4 Byte
double d = 1.7E+308;                // 8 Byte

enum valueOfTheCellField{
    X,  // Cross
    O,  // Zero
    S   // Space
    };

struct fieldForXOGame{
    char userName1[10];
    char userName2[10];
    int scoreUser1;
    int scoreUser2;
    short int setNumberOfParties;
    short int currentPartie;
    bool startButton;
    bool selectFirstMovingUser;
};

struct MyVariant
{
    union MyData
    {
        char c;
        int i;
        float f;
    } md;
    int isChar : 1;
    int isInt : 1;
    int isFloat : 1;
    
} mv;


int main()
{
    valueOfTheCellField Field[3][3];        // объявление игового поля 3х3

    for(int i = 0; i < 3; i++){             // инициализация
        for(int j = 0; j < 3; j++){         // массива игрового поля
            Field[i][j] = S;                // значениями "Не занято"
        }
    }
    
    mv.md.f = 3.14F;                        // пример использования
    mv.isChar = 0;                          // структуры
    mv.isFloat = 1;                         // с битовыми полями
    mv.isInt = 0;

    if(mv.isChar){
        cout << mv.md.c << endl;
    } else if(mv.isFloat){
        cout << mv.md.f << endl;
    } else {
        cout << mv.md.i << endl;
    }
    
    return 0;
}