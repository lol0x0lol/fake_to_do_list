#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Data
{
	int day;
	int month;
	int year;
};

struct Case
{
	string name;
	string preoperet;
	string discription;
	Data data;
	string time;

};

bool operator == (Data date1, Data date2);
ostream& operator<<(ostream& cout, const Case& thing);
