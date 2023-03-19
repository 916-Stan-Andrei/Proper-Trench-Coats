#include <iostream>
#include "UserInterface.h"

int main()
{
    Repository repo{};
    Service serv{ repo };
    UserInterface UI{ serv };
    UI.run_app();

    return 0;
}

