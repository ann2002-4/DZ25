#include "User.h"

int main()
{
    std::vector<Person> User;
    std::vector<Person::Chat> Messenger;
    string Log;

    PostgreSQL_conn();

    if (MakeSockert() != -1)
    {
        GetLogAndPass(User);
        StartMenu(User, Log, Messenger);
    };

    return 0;
};