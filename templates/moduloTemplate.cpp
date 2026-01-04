// --------------------------------- MODULO TEMPLATE ---------------------------------
template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0){ value = x % mod; if (value < 0) value += mod; }
    modular& operator+=(const modular& other){ if ((value += other.value) >= mod) value -= mod; return *this; }
    modular& operator-=(const modular& other){ if ((value -= other.value) < 0) value += mod; return *this; }
    modular& operator*=(const modular& other){ value = value * other.value % mod; return *this; }
    modular& operator/=(const modular& other){      //O(logn)
        long long a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0) a += mod;
        value = value * a % mod;
        return *this;
    }
    friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
    friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
    friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
    friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
    modular& operator++() { return *this += 1; }
    modular& operator--() { return *this -= 1; }
    modular operator++(int) { modular res(*this); *this += 1; return res; }
    modular operator--(int) { modular res(*this); *this -= 1; return res; }
    modular operator-() const { return modular(-value); }
    bool operator==(const modular& rhs) const { return value == rhs.value; }
    bool operator!=(const modular& rhs) const { return value != rhs.value; }
    bool operator<(const modular& rhs) const { return value < rhs.value; }
    bool operator>(const modular& rhs) const { return value > rhs.value; }
    bool operator<=(const modular& rhs) const { return value <= rhs.value; }
    bool operator>=(const modular& rhs) const { return value >= rhs.value; }
};
template <long long mod>
string to_string(const modular<mod>& x) { return to_string(x.value); }
template <long long mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) { return stream << x.value; }
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) { stream >> x.value; x.value %= mod; if (x.value < 0) x.value += mod; return stream; }
typedef modular<MOD> modType;       //change MOD from here ****
modType mpow(modType a, long long n) {      //O(logn)
    modType res = 1;
    while (n > 0){
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}
vector<modType> fact(1, 1);
vector<modType> finv(1, 1);
modType C(int n, int k) {
    if (n < k || k < 0)
        return modType(0);
    while ((int) fact.size() < n + 1){
        fact.push_back(fact.back() * (int) fact.size());
        finv.push_back(modType(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}
/*
Features:
• Modular: Addition, Subtraction, Multiplication, Division
• Modular Binary Exponention
• Modular nCr (choose)

Limitations:
• If MOD value is not strong (big prime), many of the templates calculations will be incorrect.
*/

// ----------------------------------------------------------------------------------------
 