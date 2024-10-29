#include "Stock.h"

void InputCaseStock(vector <Case>& case_stock)
{
	int n = 0;
	cout << "������� ��� �� ������ ��������?" << endl;
	cin >> n;
	case_stock.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		Case thing = InputCase();
		case_stock.push_back(thing);
	}
}

void DeleteStock(vector <Case>& case_stock)
{
	string n;
	cout << "��� ���������� ���� ������� �� ������ �������?" << endl;
	getline(cin >> ws, n);
	int size = case_stock.size();

	for (int i = 0; i < size; ++i)
	{
		if (case_stock[i].name == n)
		{
			case_stock.erase(case_stock.begin() + i); //
			--size;
		}
	}
}

ostream& operator<< (ostream& output, const vector<Case>& mass)
{
	output << "������ ���� ���: " << endl;

	for (const auto& s : mass)
	{
		output << s << endl;
	}

	return output; //�����������
}