#include <vector>
typedef std::pair<double, int> nomial;
typedef std::vector<nomial> terms;
class Polynomial
{
	terms poly;
	void ord();
	Polynomial(std::vector<double>, std::vector<int>);
public:
	Polynomial();
	Polynomial(double coefs[], int exps[], int size);
	//系数数组、指数数组和项数
	Polynomial(const Polynomial&);
	Polynomial(const Polynomial&& p);
	~Polynomial();
	Polynomial& operator=(const Polynomial&);
	Polynomial& operator=(const Polynomial&&);
	int degree() const; //最高幂指数
	double evaluate(double x) const; //计算多项式的值
	bool operator==(const Polynomial&) const;
	bool operator!=(const Polynomial&) const;
	Polynomial operator+(const Polynomial&) const ;
	Polynomial operator-(const Polynomial&) const ;
	Polynomial operator*(const Polynomial&) const ;

	Polynomial& operator+=(const Polynomial&) &;
	Polynomial& operator-=(const Polynomial&) &;
	Polynomial& operator*=(const Polynomial&) &;
	friend std::istream& operator >> (std::istream& in, Polynomial& t);
	friend std::ostream& operator << (std::ostream& out, Polynomial&& t);
};
