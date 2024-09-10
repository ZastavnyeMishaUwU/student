#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define CLEAR_SCREEN() system("clear")
#endif

using namespace std;

class StudentCard {
public:
    string name;
    int id;
    string faculty;
    int year;

    StudentCard(string name, int id, string faculty, int year)
        : name(name), id(id), faculty(faculty), year(year) {}

    void displayInfo() const {
        cout << "╔═════════════════════════════╗" << endl;
        cout << "║  ID студента: " << id << endl;
        cout << "║  Ім'я: " << name << endl;
        cout << "║  Факультет: " << faculty << endl;
        cout << "║  Рік навчання: " << year << endl;
        cout << "╚═════════════════════════════╝" << endl;
    }
};

StudentCard createStudentCard(int& nextId) {
    string name;
    string faculty;
    int year;

    int id = nextId;
    nextId++;

    cout << "\n┌─────────────────────────────┐" << endl;
    cout << "│  Створення нової картки      │" << endl;
    cout << "└─────────────────────────────┘" << endl;
    cout << "Введіть ім'я студента: ";
    cin.ignore();
    getline(cin, name);

    cout << "Введіть факультет студента: ";
    getline(cin, faculty);

    cout << "Введіть рік навчання студента: ";
    while (!(cin >> year)) {
        cout << "Будь ласка, введіть ціле число для року навчання: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    return StudentCard(name, id, faculty, year);
}

void viewAllCards(const vector<StudentCard>& cards) {
    CLEAR_SCREEN();
    cout << "\n╔═════════════════════════════╗" << endl;
    cout << "║  Список студентських карток  ║" << endl;
    cout << "╚═════════════════════════════╝\n";
    if (cards.empty()) {
        cout << "Немає студентських карток." << endl;
    }
    else {
        for (const auto& card : cards) {
            card.displayInfo();
        }
    }
    cout << "───────────────────────────────\n";
}

void waitForEnter() {
    cout << "\nНатисніть Enter для продовження...";
    cin.ignore();
    cin.get();
}

int main() {
    vector<StudentCard> studentCards;
    int choice;
    int nextId = 1;

    do {
        CLEAR_SCREEN();
        cout << "╔═════════════════════════════╗" << endl;
        cout << "║   Система студентських карт  ║" << endl;
        cout << "╚═════════════════════════════╝" << endl;
        cout << "1. Створити студентську картку\n";
        cout << "2. Переглянути всі студентські картки\n";
        cout << "3. Вихід\n";
        cout << "───────────────────────────────" << endl;
        cout << "Виберіть опцію: ";
        while (!(cin >> choice)) {
            cout << "Будь ласка, введіть ціле число для вибору: ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        CLEAR_SCREEN();

        switch (choice) {
        case 1: {
            StudentCard newCard = createStudentCard(nextId);
            studentCards.push_back(newCard);
            CLEAR_SCREEN();
            cout << "╔═════════════════════════════╗" << endl;
            cout << "║       Картку створено!      ║" << endl;
            cout << "╚═════════════════════════════╝" << endl;
            waitForEnter();
            break;
        }
        case 2:
            viewAllCards(studentCards);
            waitForEnter();
            break;
        case 3:
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            waitForEnter();
        }
    } while (choice != 3);

    return 0;
}
