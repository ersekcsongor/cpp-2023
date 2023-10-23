#include <iostream>
#include "Point.h"
#include "PointSet.h"
#include <iomanip>

using namespace std;
int main() {
    Point p1(0, 0), p2(1, 1);
    cout << p1.distanceTo(p2) << endl;
    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        /*if (n = 8){
            pSet.sortPointsX();
            pSet.printPoints();
        }*/
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }

    return 0;
}
