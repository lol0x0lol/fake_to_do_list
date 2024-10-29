#include "Find.h"

void Find_Name_Case(const vector <Case>& case_stock)
{
	string search_case_name;
	cout << "Как называется дело, которое Вы ищите?" << endl;
	getline(cin >> ws, search_case_name);

	for (const Case& p : case_stock)
	{
		if (search_case_name == p.name)
		{
			cout << p << endl;
		}
	}
}

void Find_Preopetet_Case(const vector <Case>& case_stock)
{
	string search_case_preoretet;
	cout << "Приоритет дела, которое Вы ищите?" << endl;
	getline(cin >> ws, search_case_preoretet);

	for (const Case& p : case_stock)
	{
		if (search_case_preoretet == p.preoperet)
		{
			cout << p << endl;
		}
	}
}

void Find_Discription_Case(const vector <Case>& case_stock)
{
	string search_case_discription;
	cout << "Описание дела, которое Вы ищите?" << endl;
	getline(cin >> ws, search_case_discription);

	for (const Case& p : case_stock)
	{
		if (search_case_discription == p.discription)
		{
			cout << p << endl;
		}
	}
}

void Find_Data_Time_Case(const vector <Case>& case_stock)
{
	Data search_data_case = InputData();
	string search_case_time;

	cout << "Введите  время дела, которое Вы ищите?" << endl;
	cin >> search_case_time;

	for (Case p : case_stock)
	{
		if ((search_data_case == p.data) && (search_case_time == p.time))
		{
			cout << p << endl;
		}
	}
}