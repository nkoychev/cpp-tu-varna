#include <iostream>
#include <vector>
using namespace std;

void printElements();
bool isEmpty();
void vectorSize();

class User
{
public:
    string name;
    string surname;
    string neighbourhood;
    string street;
    string strNum;
    string phoneNumber;
    double payment;
    User(string a, string b, string c, string d, string e, string f, double g)
    {
        name = a;
        surname = b;
        neighbourhood = c;
        street = d;
        strNum = e;
        phoneNumber = f;
        payment = g;
    }
};
vector<User> usersArr;
void createUser();

int main()
{
    User user0("Иван", "Петров", "Левски", "Китка", "23б", "0889458632", 32.99);
    User user1("Петър", "Митков", "Трошево", "Здраве", "54", "0886950325", 56.54);
    usersArr.push_back(user0);
    usersArr.push_back(user1);
    int initChoice, choice;
    do
    {

        cout << "\n0. Quit" << endl;
        cout << "1. Създайте потребител " << endl;
        cout << "2. Размер на масива " << endl;
        cout << "3. Елементи в масива " << endl;
        cout << "4. Справка за абонат " << endl;
        cout << "5. Търсене по улица " << endl;
        cout << "6. Сортиране по сума за плащане " << endl;
        cout << "Вашият избор: ";

        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            cout << "Return 0!\n";
            return 0;
        case 1:
            createUser();
            // inputIntegers();
            break;
        case 2:
            vectorSize();
            break;
        case 3:
            cout << "Елементи в масива: " << endl;
            printElements();
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        default:
            cout << "Невалиден избор!";
            break;
        }
        if (choice >= 0 && choice <= 6)
        {
#ifdef __linux__
            system("read");
#else
            system("pause");
#endif
        }
    } while (choice != 0);

    return 0;
}

void printElements()
{
    if (!isEmpty())
    {
        cout << "Елементите във вектора/масива са: \n";
        for (int i = 0; i < usersArr.size(); i++)
        {
            cout << usersArr[i].name << " " << usersArr[i].surname << " ,ж.к. " << usersArr[i].neighbourhood
                 << " , ул. " << usersArr[i].street << ", №" << usersArr[i].strNum
                 << ", тел. " << usersArr[i].phoneNumber << ", за плащане: " << usersArr[i].payment << endl;
        }
        cout << endl;
    }
}

bool isEmpty()
{
    if (usersArr.empty())
    {
        cout << "Масивът е празен! \n"
             << endl;
        return true;
    }
    else
    {
        return false;
    }
}
void vectorSize()
{
    if (!isEmpty())
    {
        cout << "Размер на масива: " << usersArr.size() << endl;
    }
}

void createUser()
{
    string name;
    string surname;
    string neighbourhood;
    string street;
    string strNum;
    string phoneNumber;
    double payment;

    cout << "Име: " << endl;
    cin >> name;
    cout << "Фамилия: " << endl;
    cin >> surname;
    cout << "Квартал: " << endl;
    cin >> neighbourhood;
    cout << "Улица: " << endl;
    cin >> street;
    cout << "Номер: " << endl;
    cin >> strNum;
    cout << "Тел. Номер: " << endl;
    cin >> phoneNumber;
    cout << "За Плащане: " << endl;
    cin >> payment;

    User newUser(name, surname, neighbourhood, street, strNum, phoneNumber, payment);
    usersArr.push_back(newUser);
}