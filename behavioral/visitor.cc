#include "iostream"
#include "vector"

using std::vector;
using std::cout;
using std::endl;

class BankAccount;
class Loan;

struct Visitor // Abstract Visitor
{
	virtual void Visit(BankAccount * a) = 0;
	virtual void Visit(Loan * l)  = 0;
	virtual ~Visitor() {}
};

class Asset // Element
{

public:
	virtual void Accept(Visitor * v) = 0;
	virtual ~Asset() {}
};

struct BankAccount: public Asset // ConcreteElement
{
	int savings;
	int monthlyRate;
public:
	BankAccount(int s, int r): savings(s), monthlyRate(r) {}
	virtual void Accept(Visitor * v) { v->Visit(this); }
};


struct Loan: public Asset // ConcreteElement
{
	int debt;
	int monthlyDebt;
public:
	Loan(int s, int r): debt(s), monthlyDebt(r) {}
	virtual void Accept(Visitor * v) { v->Visit(this); }
};


class Person // Client
{
	std::vector<Asset * > assets;
public:
	void AddAsset(Asset * a) { assets.push_back(a); }
	void Calculate(Visitor * v) { for (int i = 0; i < assets.size(); ++i) assets[i]->Accept(v); }
};

struct NetIncome: public Visitor // ConcreteVisitor
{
	int totalIncome;
public:
	NetIncome(): totalIncome(0) {}
	virtual void Visit(BankAccount * a) { totalIncome += a->savings; }
	virtual void Visit(Loan * l)  { totalIncome -= l->debt; }
};

struct MonthlyIncome: public Visitor // ConcreteVisitor
{
	int totalIncome;
public:
	MonthlyIncome(): totalIncome(0) {}
	virtual void Visit(BankAccount * a) { totalIncome += a->monthlyRate; }
	virtual void Visit(Loan * l)  { totalIncome -= l->monthlyDebt * 2; }
};

int main(int argc, char const * argv[])
{
	Person p;
	p.AddAsset(new BankAccount(1000, 20));
	p.AddAsset(new BankAccount(4000, 30));
	p.AddAsset(new BankAccount(4000, 30));
	NetIncome net;
	p.Calculate(&net);
	cout << "Total income " << net.totalIncome << endl;

	MonthlyIncome january;
	p.Calculate(&january);
	cout << "In January we've got " << january.totalIncome << endl;

	return 0;
}