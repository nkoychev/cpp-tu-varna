#include <iostream>
#include <vector>
using namespace std;

void printElements();
bool isEmpty();

class User
{
public:
    string name;
    string surname;
    string address;
    string phoneNumber;
    double payment;
    User(string a, string b, string c, string d, double e)
    {
        name = a;
        surname = b;
        address = c;
        phoneNumber = d;
        payment = e;
    }
};

vector<User> usersArr;
int main()
{
    User user0("Ivan", "Petrov", "ul.Kitka", "0889458632", 32.99);
    User user1("Petar", "Danov", "ul.Zdrave", "0886950325", 56.54);
    usersArr.push_back(user0);
    usersArr.push_back(user1);
    printElements();

    return 0;
}

void printElements()
{
    if (!isEmpty())
    {
        cout << "Елементите във вектора/масива са: \n";
        for (int i = 0; i < usersArr.size(); i++)
        {
            cout << usersArr[i].name << " " << usersArr[i].surname << " ," << usersArr[i].address
                 << ", " << usersArr[i].phoneNumber << ", за плащане: " << usersArr[i].payment << endl;
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