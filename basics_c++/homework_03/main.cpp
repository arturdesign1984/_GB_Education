#include <iostream>

using namespace std;

int a = 2,
    b = 3,
    c = 4,
    d = 5;

extern int aa;
extern int bb;
extern int cc;
extern int dd;

int main(){
    // 01
    float result = a*(b+(static_cast <float>(c)/d));

    cout << result << endl;

    // 04
    float result2 = aa*(bb+(static_cast <float>(cc)/dd));

    cout << result2 << endl;

    // 02
    int number, result3;
    cin >> number;
    result3 = (number <= 21) ? 21-number : (number-21)*2;

    cout << result3 << endl;

    // 03
    int counter = 1;
    int massive[3][3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                massive[i][j][k] = counter++;
            }
        }
    }
    int *pointer = nullptr;
    pointer = &massive[1][1][1];
    cout << *pointer << endl;

    return 0;
}
