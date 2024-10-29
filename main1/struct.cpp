#include "struct.h"

bool operator == (Data date1, Data date2)
{
	if ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& cout, const Case& thing)
{
	cout << thing.name << endl;
	cout << thing.preoperet << endl;
	cout << thing.discription << endl;
	cout << thing.data.day << "." << thing.data.month << "." << thing.data.year << endl;
	cout << thing.time << endl;

	return cout; //ÎÁßÇÀÒÅËÜÍÎ
}