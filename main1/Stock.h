#pragma once
#include "struct.h"
#include "Input.h"
#include <map>

void InputCaseStock(vector <Case>& case_stock);
void DeleteStock(vector <Case>& case_stock);
ostream& operator<< (ostream& output, const vector<Case>& mass);