#include "functions.h"

int main() {
    cout << "Hello, Lab_01" << endl;

    /*
     * 1-es
     * int n = 0;
    cout << "Enter a osszeg";
    cin >> n;
    cout << "The osszeg of bits in " << n <<" is "<< countBit(n);

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }*/
    /*
    2-es
    int osszeg = 5;
    int order = 3;

    bool success = setBit(osszeg, order);

    if (success) {
        cout << "A bit beállítása sikerült. Az új szám: " << osszeg << endl;
    } else {
        cout << "Hibás sorszám. A bit nem lett beállítva." << endl;
    }*/
    /*3-as
    int n = 5;
    double a[n] = {1, 2, 3, 4, 5};
    cout << mean(a, n) << endl;
    */
    /*    //4-es
    double a[10]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << stddev(a, 10) << endl;*/
    /*//5-os
    double a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pair<double, double> p = max2(a, 10);
    cout << p.first << " " << p.second << endl;*/
    /*//string-1
    double osszeg = 0;
    istringstream inputstream("1 2 3 alma 4");
    string word;
    while (inputstream >> word) {
        istringstream wordstream(word);
        double number;
        if (wordstream >> number) {
            osszeg += number;
        }
        cout << "Osszeg : " << osszeg << endl;
        return 0;*/
    /*//string 2
    char a[] = "Alma van a 12 fan 23";
    cout << a << " szovegben levo szavak szama : "<< countWord(a) << endl;*/
    /* //string-3
     string text = "alma van a 12 fan";
     cout << code(text) << endl;
     string text2 = code(text);
     cout << decode(text2) << endl;*/
    /*//string-4
    string line;
    getline(cin, line);

    string result = capitalizeWords(line);
    cout << capitalizeWords(line) << endl;
*/
    return 0;
}
