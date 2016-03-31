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
	//ϵ�����顢ָ�����������
	Polynomial(const Polynomial&);
	Polynomial(const Polynomial&& p);
	~Polynomial();
	Polynomial& operator=(const Polynomial&);
	Polynomial& operator=(const Polynomial&&);
	int degree() const; //�����ָ��
	double evaluate(double x) const; //�������ʽ��ֵ
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
