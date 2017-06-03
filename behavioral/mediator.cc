#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::set;

class Aircraft;

class FlightCotroller
{
	set<Aircraft *> planes;
public:
	void RegisterAircraft(Aircraft * );
	void ReceiveAltitude(Aircraft * );
};


class Aircraft
{
	string name;
	int altitude;
	FlightCotroller * controllCenter;

public:
	Aircraft(string s, int a, FlightCotroller * f): name(s), altitude(a), controllCenter(f)
	{
		controllCenter->RegisterAircraft(this);
	}

	int GetAltitude() const { return altitude; }
	void SetAltitude(int a)
	{
		altitude = a;
		controllCenter->ReceiveAltitude(this);
	}
	string GetName() const { return name; }

};

void FlightCotroller::RegisterAircraft(Aircraft * a)
{
	if (a) planes.insert(a);
}

void FlightCotroller::ReceiveAltitude(Aircraft * a)
{
	for (set<Aircraft *>::iterator i = planes.begin(); i != planes.end(); ++i)
	{
		if (*i == a) continue;
		if ( abs(a->GetAltitude() - (*i)->GetAltitude()) > 1000 )  continue;

		cout << "Warning: " << a->GetName() << " approaches to " << (*i)->GetName() << ". Changing it's location immediately." << endl;
		a->SetAltitude(a->GetAltitude() + 1000);
	}

}


int main(int argc, char const * argv[])
{
	FlightCotroller flightcontroll;
	Aircraft plane("NY-376", 9000, &flightcontroll);
	Aircraft bplane("CA-379", 5000, &flightcontroll);
	Aircraft h("MA-567-GA", 3000, &flightcontroll);

	plane.SetAltitude(3000);

	return 0;
}