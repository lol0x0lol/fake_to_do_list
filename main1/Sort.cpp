#include "Sort.h"

void Sort_data(const vector <Case>& case_stock)
{
	map<string, Case> sorted_case;

	for (Case p : case_stock)
	{
		string data = to_string(p.data.year) + "." + to_string(p.data.month) + "." + to_string(p.data.day);
		sorted_case.insert({ data,p });
	}

	for (const auto& [d, cs] : sorted_case)
	{
		cout << cs << endl;
	}
}

void Sort_Preopetet(const vector <Case>& case_stock)
{
	map<string, const Case&> sorted_case;

	for (const Case& p : case_stock)
	{
		string preoperet = p.preoperet;
		sorted_case.insert({ preoperet, p });
	}

	for (const auto& [d, cs] : sorted_case)
	{
		cout << cs << endl;
	}
}