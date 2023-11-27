//
// Created by Csongor on 11/27/2023.
//

#ifndef LAB10_SZEMELY_H
#define LAB10_SZEMELY_H
#include <iostream>
using namespace std;
class Szemely{
public:
    Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv);
    virtual void print(ostream& os)const;

private:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
};
ostream& operator<<(ostream& os,const Szemely& sz);





#endif //LAB10_SZEMELY_H
