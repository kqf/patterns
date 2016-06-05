#include <iostream>
#include <string>
#include <stack>


using std::cout;
using std::endl;
using std::string;
using std::stack;

class Memento;
class State
{
	string data;
public:
	State(const char * s): data(s) {}
	void UpdateState(const char * s) { data = s; }
	void DumpState() const { cout << "Current state is " << data << endl; }
	Memento SaveToMemento() const;
	void RestoreFromMomento(const  Memento &);
};

// Now it's very silly but in principle we can save deltas here.
class Memento
{
public:
	Memento(State s):  state(s) {}
	State GetSavedState() const { return state; }
private:
	State state;
};

void State::RestoreFromMomento(const  Memento & m)
{
	data = m.GetSavedState().data;
}

Memento State::SaveToMemento() const
{
	return  Memento(*this);
}

class Caretaker
{
	State mainState;
	stack<Memento> previousStates;

public:
	Caretaker(): mainState("InitialState"), previousStates() { Save(); }
	void Undo() { if (previousStates.empty()) return; mainState.RestoreFromMomento( previousStates.top() ); previousStates.pop(); }
	void Save() { previousStates.push(mainState.SaveToMemento()); }
	void DoSomeJob();
};

void Caretaker::DoSomeJob()
{
	mainState.DumpState();
	mainState.UpdateState("NewRandomState");
	Save();
	mainState.UpdateState("New Pseudorandom State");
	mainState.DumpState();
	Save();
	cout << "Trying to undo the changes" << endl;
	Undo();
	mainState.DumpState();
	Undo();
	mainState.DumpState();
	Undo();
	mainState.DumpState();
	Undo();
	mainState.DumpState();
}


int main(int argc, char const * argv[])
{
	Caretaker processes;
	processes.DoSomeJob();

	return 0;
}