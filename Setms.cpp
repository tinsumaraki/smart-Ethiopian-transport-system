#include <iostream>
using namespace std;

class Driver {
public:
    string name;
    int targa;
    int code;

    Driver()   // default constructor - runs automatically for every new Driver
    {
        name = "Unknown";
        targa = 0;
        code = 0;
    }
};

bool isValidTarga(int targa)
{
    return (targa >= 10000 && targa <= 99999);
}

bool isValidCode(int code)
{
    return (code >= 1000 && code <= 9999);
}

float calculateFare(float distance)
{
    if (distance >= 1 && distance <= 3.5)
    {
        return 10;
    }
    else if (distance >= 4 && distance <= 5.5)
    {
        return 15;
    }
    else if (distance >= 6 && distance <= 7.5)
    {
        return 25;
    }
    else
    {
        cout << "Distance out of supported range!\n";
        return 0;
    }
}

// Checks if a code is already used by another registered driver
bool isCodeTaken(Driver drivers[], int count, int code)
{
    for (int i = 0; i < count; i++)
    {
        if (drivers[i].code == code)
        {
            return true;
        }
    }
    return false;
}

// Registers a new driver (with duplicate-code protection)
void registerDriver(Driver drivers[], int &count)
{
    Driver newDriver;

    cout << "\nEnter driver name: ";
    cin.ignore();
    getline(cin, newDriver.name);

    do {
        cout << "Enter targa (5-digit number): ";
        cin >> newDriver.targa;
        if (!isValidTarga(newDriver.targa)) {
            cout << "Invalid! Targa must be exactly 5 digits.\n";
        }
    } while (!isValidTarga(newDriver.targa));

    do {
        cout << "Enter 4-digit code for this driver: ";
        cin >> newDriver.code;

        if (!isValidCode(newDriver.code)) {
            cout << "Invalid! Code must be exactly 4 digits.\n";
        }
        else if (isCodeTaken(drivers, count, newDriver.code)) {
            cout << "This code is already used by another driver! Choose a different one.\n";
        }
    } while (!isValidCode(newDriver.code) || isCodeTaken(drivers, count, newDriver.code));

    drivers[count] = newDriver;
    count++;

    cout << "\nDriver registered successfully!\n";
}

// Passenger looks up driver by code, then pays
void payByCode(Driver drivers[], int count)
{
    int code;
    bool found = false;

    cout << "\nEnter driver's 4-digit code: ";
    cin >> code;

    for (int i = 0; i < count; i++)
    {
        if (drivers[i].code == code)
        {
            found = true;

            cout << "\n--- Driver Found ---\n";
            cout << "Name: " << drivers[i].name << endl;
            cout << "Targa: " << drivers[i].targa << endl;
            cout << "---------------------\n";

            float distance;
            cout << "Enter trip distance (km): ";
            cin >> distance;

            float fare = calculateFare(distance);

            if (fare > 0)
            {
                cout << "Fare = " << fare << " birr\n";

                int confirm;
                cout << "Confirm payment? (1 = Yes, 2 = No): ";
                cin >> confirm;

                if (confirm == 1)
                {
                    cout << "\nPayment of " << fare << " birr sent to " << drivers[i].name << " successfully!\n";
                }
                else
                {
                    cout << "\nPayment cancelled.\n";
                }
            }

            return;
        }
    }

    if (!found)
    {
        cout << "\nNo driver found with this code. Do not proceed with payment.\n";
    }
}

int main()
{
    Driver drivers[10];
    int count = 0;
    int menuChoice;

    do
    {
        cout << "\n===ETHIOPIAN SMART TRANSPORT MANAGEMENT SYSTEM===\n";
        cout << "1. Register Driver\n";
        cout << "2. Pay by Code\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> menuChoice;

        if (menuChoice == 1)
        {
            if (count < 10)
            {
                registerDriver(drivers, count);
            }
            else
            {
                cout << "\nSystem full, cannot register more drivers.\n";
            }
        }
        else if (menuChoice == 2)
        {
            payByCode(drivers, count);
        }
        else if (menuChoice == 3)
        {
            cout << "\nGoodbye!\n";
        }
        else
        {
            cout << "\nInvalid choice, try again.\n";
        }

    } while (menuChoice != 3);

    return 0;
}
