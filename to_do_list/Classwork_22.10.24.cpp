#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#pragma warning(disable:4996)
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Time {
    int second;
    int minute;
    int hour;
};

struct Spisok {
    string title;
    string description;
    string priority;
    Date NewDate;
    Time NewTime;
};

vector <Spisok> to_do_list;

void AddingAcase() {
    Spisok delo;
    cout << "Enter title name: ";
    cin >> delo.title;
    cout << "Enter title description: ";
    cin >> delo.description;
    cout << "Enter a description of the title: ";
    cin >> delo.priority;
    string data;
    cout << "Enter data: ";
    cin >> data;
    delo.NewDate.day = stoi(data.substr(0, 2));
    delo.NewDate.month = stoi(data.substr(3, 5));
    delo.NewDate.year = stoi(data.substr(6, 10));
    string time;
    cout << "Enter time: ";
    cin >> time;
    delo.NewTime.second = stoi(time.substr(0, 2));
    delo.NewTime.minute = stoi(time.substr(3, 5));
    delo.NewTime.hour = stoi(time.substr(6, 8));
    cout << " ";
    to_do_list.push_back(delo);
}

void print_Spisok(Spisok& sp)
{
    cout << sp.title << endl;
    cout << sp.description << endl;
    cout << sp.priority << endl;
    cout << sp.NewDate.day << "." << sp.NewDate.month << "." << sp.NewDate.year << endl;
    cout << sp.NewTime.hour << ":" << sp.NewTime.minute << ":" << sp.NewTime.second << endl;
}

void SearchInTheToDoList(string& TheName) {
    bool c = 0;

    for (int i = 0; i < to_do_list.size(); i++) {
        if (TheName == to_do_list[i].title) {
            print_Spisok(to_do_list[i]);
            c = 1;
            break;
        }
    }
    if (c == 0)
        cout << "No such to-do list was found" << endl;
}

void case_search() {
    Date when;
    string data;
    cout << "Введите дату(DD.MM.YYYY) для поиска конкретного дела: ";
    cin >> data;
    when.day = stoi(data.substr(0, 2));
    when.month = stoi(data.substr(3, 5));
    when.year = stoi(data.substr(6, 10));
    bool t = false;
    for (int i = 0; i < to_do_list.size(); i++) {
        if (to_do_list[i].NewDate.day == when.day && to_do_list[i].NewDate.month == when.month && to_do_list[i].NewDate.year == when.year) {
            print_Spisok(to_do_list[i]);
            t = true;
            break;
        }
    }
    if(t==false) {
        cout << "Date foundn't!!!!!!" << endl;
        t = false;
    }
}

void searchdesc(string descriptionn) {
    bool hmf = 0;
    cout << "Найденые дела: " << endl;
    for (int i = 0; i < to_do_list.size(); i++) {
        if (descriptionn == to_do_list[i].description) {
            print_Spisok(to_do_list[i]);
            hmf=1;
            break;
        }
    }
    if (hmf == 0) {
        cout << "Не найдено дел с таким описанием" << endl;
    }
}

void searchInSpisok() {
    Date when;
    string data;
    cout << "Введите дату(DD.MM.YYYY) для поиска на 7 дней вперёд: ";
    cin >> data;
    when.day = stoi(data.substr(0, 2));
    when.month = stoi(data.substr(3, 5));
    when.year = stoi(data.substr(6, 10));
    int c = 0;
    string buf = "";
    tm date{};
    date.tm_mday = when.day;
    date.tm_mon = when.month - 1;
    date.tm_year = when.year - 1900;
    time_t timeDate = mktime(&date);
    time_t next = timeDate + 86400;
    char ch[100];
    while (c != 7) {
        for (int i = 0; i < to_do_list.size(); i++) {
            if (to_do_list[i].NewDate.day == when.day && to_do_list[i].NewDate.month == when.month && to_do_list[i].NewDate.year == when.year) {
                print_Spisok(to_do_list[i]);
            }
        }
        if (strftime(ch, sizeof(ch), "%y %m %d", localtime(&next))) {
            buf += ch[0];
            buf += ch[1];
            when.year = stoi("20" + buf);
            buf = "";
            buf += ch[3];
            buf += ch[4];
            when.month = stoi(buf);
            buf = "";
            buf += ch[6];
            buf += ch[7];
            when.day = stoi(buf);
            buf = "";
        }
        next += 86400;
        c++;
    }
}

void sortByMonth() {
    Date when;
    string data;
    cout << "Введите дату(DD.MM.YYYY) для сортировки по месяцу: ";
    cin >> data;
    when.day = stoi(data.substr(0, 2));
    when.month = stoi(data.substr(3, 5));
    when.year = stoi(data.substr(6, 10));
    vector <Spisok> to_do_listBuf;
    bool flag = 0;
    while (flag == 0) {
        for (int i = 1; i < to_do_list.size(); i++) {
            if (to_do_list[i].NewDate.month == when.month && to_do_list[i].NewDate.year == when.year && to_do_list[i].NewDate.day < to_do_list[i - 1].NewDate.day) {
                for (int j = 0; j < to_do_list.size(); j++) {
                    if (j < i - 1) {
                        to_do_listBuf.push_back(to_do_list[j]);
                    }
                    else if (j == i - 1) {
                        to_do_listBuf.push_back(to_do_list[i]);
                        to_do_listBuf.push_back(to_do_list[j]);
                        j++;
                    }
                    else if (j > i - 1) {
                        to_do_listBuf.push_back(to_do_list[j]);
                    }
                }
                flag = 1;
                to_do_list.clear();
                to_do_list = to_do_listBuf;
                to_do_listBuf.clear();
            }
        }
        if (flag == 1)
            flag = 0;
        else
            flag = 1;
    }
}

void changeNote(Spisok& newNote) {
    string request, newStr;
    cout << "Enter what to change(title, description, priority, date, time)" << endl;
    cin >> request;
    if (request == "title") {
        cout << "Enter new title:" << endl;
        cin >> newStr;
        newNote.title = newStr;
    }
    else if (request == "description:") {
        cout << "Enter new description" << endl;
        cin >> newStr;
        newNote.description = newStr;
    }
    else if (request == "priority") {
        cout << "Enter new priority:" << endl;
        cin >> newStr;
        newNote.priority = newStr;
    }
    else if (request == "date") {
        cout << "Enter new date(at first day, when month and year):" << endl;
        int day, month, year;
        cin >> day;
        cin >> month;
        cin >> year;
        newNote.NewDate.day = day;
        newNote.NewDate.month = month;
        newNote.NewDate.year = year;
    }
    else if (request == "time") {
        cout << "Enter new time(at first seconds, when minutes and hours)" << endl;
        int seconds, minutes, hours;
        cin >> seconds;
        cin >> minutes;
        cin >> hours;
        newNote.NewTime.second = seconds;
        newNote.NewTime.minute = minutes;
        newNote.NewTime.hour = hours;
    }
    else {
        cout << "File did not open(";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int point;
    string name, descriptionn;
    while (1) {
        cout << "\tВыберите действие:\n1. Добавление дела\t2. Удаление дела\n3. Вывод дела\t4. Редактирование дела\n5. Поиск дела\t6. Сортировка дел по месяцу" << endl;
        cin >> point;
        switch (point) {
        case 1:
            AddingAcase();
            break;
        case 2:

            break;
        case 3:
            for (int i = 0; i < to_do_list.size(); i++) {
                print_Spisok(to_do_list[i]);
            }
            break;
        case 4:

            break;
        case 5:
            int pointer;
            cout << "\tВыберите признак, по которому будет совершаться поиск:\n1. По названию\t2. По описанию\n3. По дате(конкретного дела)\t4. По дате(на 7 дней вперёд)\n" << endl;
            cin >> pointer;
            switch (pointer) {
            case 1:
                cin >> name;
                SearchInTheToDoList(name);
                break;
            case 2:
                cin >> descriptionn;
                searchdesc(descriptionn);
                break;
            case 3:
                case_search();
                break;
            case 4:
                searchInSpisok();
                break;
            default:
                break;
            }
            break;
        case 6:
            sortByMonth();
            break;
        default:
            break;
        }
        int choice;
        cout << "Хотите продолжить работу?\n1. да\t2.нет" << endl;
        cin >> choice;
        if (choice == 2)
            break;
    }
    system("pause");
}