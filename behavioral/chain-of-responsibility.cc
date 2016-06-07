#include "iostream"

using std::cout;
using std::endl;

class Worker // This is handler/concrete handler in this example there is no need in inheritance.
{
	const char * name;
	int limit;
	Worker * supervisor;
public:
	Worker(const char * n, int a): name(n), limit(a), supervisor(0) {}
	void SetSupervisor(Worker * w) { supervisor = w; }
	bool Approve(int a) const;
};

bool Worker::Approve(int a) const // All logicical manipulations go here. Everything else defines structure of the program.
{
	if (a <= limit) return true;
	cout << name << " can't approve " << a << "$." << endl;
	if (!supervisor) return false;
	cout << "Transfering request to " << supervisor->name  << "." << endl;
	return supervisor->Approve(a);
}

int main(int argc, char const * argv[])
{
	Worker manager("Paul", 0);
	Worker seniorManager("Andrew", 100);
	Worker boss("Peter", 1000);

	manager.SetSupervisor(&seniorManager);
	seniorManager.SetSupervisor(&boss);

	int sum = 150;
	const char * answer = manager.Approve(sum) ? "Approved!" : "Rejected.";

	cout << "The answer for " << sum  << "$" << " is: " << answer << endl;
	return 0;
}