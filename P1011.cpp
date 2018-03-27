/* ¸´ÊıÀà */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class CMP{
    //friend
    friend inline CMP operator +(const CMP&, const CMP&);
    friend inline CMP operator -(const CMP&, const CMP&);
    friend inline CMP operator *(const CMP&, const CMP&);
    friend inline CMP operator /(const CMP&, const CMP&);
    friend istream& operator >>(istream&, CMP&);
    friend ostream& operator <<(ostream&, const CMP&);
public:
    //constructor
    CMP() : x(0.0), y(0.0) {}
    CMP(const double &xx, const double &yy) : x(xx), y(yy) {}
    CMP(const int &xx, const int &yy) : x(xx), y(yy) {}
    CMP(const CMP &cmp) : x(cmp.x), y(cmp.y) {}

    //operator
    CMP& operator =(const CMP&);
    CMP& operator +=(const CMP&);
    CMP& operator -=(const CMP&);
    CMP& operator *=(const CMP&);
    CMP& operator /=(const CMP&);
    CMP operator ~() const;//conjugation
    CMP operator -() const;//minus

    double SquareModule() const { return (x * x + y * y); }
    double Module() const { return sqrt(x * x + y * y); }
private:
    double x, y;
};

CMP& CMP::operator =(const CMP &rhs){
    x = rhs.x;
    y = rhs.y;
    return *this;
}
CMP CMP::operator ~() const{
    return CMP(x, -y);
}
CMP CMP::operator -() const{
    return CMP(-x, -y);
}
CMP inline operator +(const CMP &lhs, const CMP &rhs){
    return CMP(lhs.x + rhs.x, lhs.y + rhs.y);
}
CMP inline operator -(const CMP &lhs, const CMP &rhs){
    return CMP(lhs.x - rhs.x, lhs.y - rhs.y);
}
CMP inline operator *(const CMP &lhs, const CMP &rhs){
    return CMP(lhs.x * rhs.x - lhs.y * rhs.y, lhs.x * rhs.y + lhs.y * rhs.x);
}
CMP inline operator /(const CMP &lhs, const CMP &rhs){
    CMP ret = lhs * ~rhs;
    return CMP(ret.x / rhs.SquareModule(), ret.y / rhs.SquareModule());
}
CMP& CMP::operator +=(const CMP &rhs){
    x += rhs.x;
    y += rhs.y;
    return *this;
}
CMP& CMP::operator -=(const CMP &rhs){
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}
CMP& CMP::operator *=(const CMP &rhs){
    double tx = x * rhs.x - y * rhs.y;
    double ty = x * rhs.y + y * rhs.x;
    x = tx;
    y = ty;
    return *this;
}
CMP& CMP::operator /=(const CMP &rhs){
    CMP cmp = *this / rhs;
    *this = cmp;
    return *this;
}
istream& operator >>(istream &is, CMP& cmp){
    is >> cmp.x >> cmp.y;
    return is;
}
ostream& operator <<(ostream &os, const CMP& cmp){
    os << setiosflags(ios::fixed) << setprecision(2) << cmp.x << ' ' << cmp.y;
    return os;
}

int main(){
    CMP z1, z2;
    cin >> z1 >> z2;
    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    cout << (z1 += z2) << endl;
    cout << (z1 -= z2) << endl;
    cout << (z1 *= z2) << endl;
    cout << (z1 /= z2) << endl;
    return 0;
}
