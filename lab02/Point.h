//
// Created by Csongor on 10/2/2023.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H
class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
};

#endif //LAB2_POINT_H
