#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class bigint {
private:
    vector<unsigned int> _vNumber;

    int toInt() const 
    {
        int res = 0;
        int mult = 1;
        for (size_t i = 0; i < _vNumber.size() && i < 10; i++) {
            res += _vNumber[i] * mult;
            mult *= 10;
        }
        return res;
    }

public:
    bigint() 
    {
        _vNumber.push_back(0);
    }

    bigint(unsigned int Number) 
    {
        if (Number == 0) _vNumber.push_back(0);
        while (Number > 0) {
            _vNumber.push_back(Number % 10);
            Number /= 10;
        }
    }

    bigint(const bigint &OldObj) : _vNumber(OldObj._vNumber) {}

    bigint &operator=(const bigint &OldObj) 
    {
        if (this != &OldObj) _vNumber = OldObj._vNumber;
        return *this;
    }

    bigint operator+(const bigint &Obj2) const {
        bigint result(*this);
        result += Obj2;
        return result;
    }

    bigint &operator+=(const bigint &Obj2) {
        int carry = 0;
        size_t i = 0;
        while (i < Obj2._vNumber.size() || carry) {
            if (i == _vNumber.size()) _vNumber.push_back(0);
            int sum = _vNumber[i] + carry;
            if (i < Obj2._vNumber.size()) sum += Obj2._vNumber[i];
            _vNumber[i] = sum % 10;
            carry = sum / 10;
            i++;
        }
        return *this;
    }

    bigint &operator++() {
        return *this += 1;
    }

    bigint operator++(int) {
        bigint temp(*this);
        ++(*this);
        return temp;
    }

    bigint operator<<(int shift) const {
        bigint result(*this);
        result <<= shift;
        return result;
    }

    bigint &operator<<=(int shift) {
        if (_vNumber.size() == 1 && _vNumber[0] == 0) return *this;
        _vNumber.insert(_vNumber.begin(), shift, 0);
        return *this;
    }

    bigint &operator>>=(const bigint &shiftObj) {
        int shift = shiftObj.toInt();
        for (int i = 0; i < shift && _vNumber.size() > 1; i++) {
            _vNumber.erase(_vNumber.begin());
        }
        return *this;
    }

    bool operator==(const bigint &other) const {
        return _vNumber == other._vNumber;
    }

    bool operator!=(const bigint &other) const {
        return !(*this == other);
    }

    bool operator<(const bigint &other) const {
        if (_vNumber.size() != other._vNumber.size())
            return _vNumber.size() < other._vNumber.size();
        for (int i = (int)_vNumber.size() - 1; i >= 0; i--) {
            if (_vNumber[i] != other._vNumber[i])
                return _vNumber[i] < other._vNumber[i];
        }
        return false;
    }

    bool operator>(const bigint &other) const { return other < *this; }
    bool operator<=(const bigint &other) const { return !(*this > other); }
    bool operator>=(const bigint &other) const { return !(*this < other); }

    const vector<unsigned int>& GetNumber() const {
        return _vNumber;
    }
};

ostream &operator<<(ostream &os, const bigint &p) {
    const vector<unsigned int> &v = p.GetNumber();
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        os << v[i];
    }
    return os;
}


int main()
{
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;

    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    std::cout << "a =" << a << std::endl;
    std::cout << "d =" << d << std::endl;

    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;
    std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;
}
