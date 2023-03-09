#include "ui.h"
#include "iostream"
#include "../exceptions.h"
#include "../validators.h"
#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"

using namespace std;

UIAdministrator::UIAdministrator(ControllerAdministrator& ctrl) : ctrl(ctrl){}

void UIAdministrator::printMenu() {

    cout << R"(
Press:
    1. add
    2. remove
    3. update
    4. print all
    5. sort
    6. exit
    )";
}

void UIAdministrator::start() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    string option;
    while (true) {

        cout << "\x1B[2J\x1B[3J\x1B[H";

        printMenu();

        while (true) {
            try {
                cout << "\nEnter an option: ";
                getline(cin, option);
                cout << "\n";

                if (option.size() != 1)
                    throw(ValidatorError("Invalid option."));

                break;
            }
            catch (ValidatorError& error){
                cout << RED << error.getMessage() << "\n" << RESET;
            }
        }

        switch (option.at(0) - '0') {

            case 1:
                this->add();
                continue;

            case 2:
                this->remove();
                continue;

            case 3:
                this->update();
                continue;

            case 4:
                printAll();
                continue;

            case 5:
                sortList();
                continue;

            case 6:
                break;

            default:
                cout << RED << "This option doesn't exist.\n" << RESET;
                getchar();
                continue;
        }

        break;
    }
}

void UIAdministrator::add() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    string title, presenter, minutes, seconds, likes, link;
    int m, s, l;


    try {
        while (true) {
            try {

                cout << "Enter the title: ";
                getline(cin, title);

                cout << "Enter the presenter: ";
                getline(cin, presenter);

                cout << "Enter the minutes: ";
                getline(cin, minutes);

                if (Validator::validateIsNumber(minutes) == 0)
                    throw(ValidatorError("\nMinutes need to be integers.\n"));

                cout << "Enter the seconds: ";
                getline(cin, seconds);

                if (Validator::validateIsNumber(seconds) == 0)
                    throw(ValidatorError("\nSeconds need to be integers.\n"));

                cout << "Enter the likes: ";
                getline(cin, likes);

                if (Validator::validateIsNumber(minutes) == 0)
                    throw(ValidatorError("\nLikes need to be integers.\n"));

                cout << "Enter the link: ";
                getline(cin, link);

                if (Validator::validateIsLink(link) == 0)
                    throw(ValidatorError("\nLink must not contain spaces.\n"));

                if( Validator::validateNotEmpty(title) == 0 ||
                    Validator::validateNotEmpty(presenter) == 0 ||
                    Validator::validateNotEmpty(minutes) == 0 ||
                    Validator::validateNotEmpty(seconds) == 0 ||
                    Validator::validateNotEmpty(likes) == 0 ||
                    Validator::validateNotEmpty(link) == 0)

                    throw(ValidatorError("\nAll inputs must not be empty.\n"));

                break;
            }
            catch (ValidatorError& error){
                cout << RED << error.getMessage() << "\n" << RESET;
            }
        }

        ControllerAdministrator::to_digit(m, minutes);
        ControllerAdministrator::to_digit(s, seconds);
        ControllerAdministrator::to_digit(l, likes);

        this->ctrl.add(title, presenter, m, s, l, link);
    }
    catch (AddError& error) {
        cout << RED << error.getMessage() << RESET;
        getchar();
    }
}

void UIAdministrator::remove() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    string link;

    try {
        while (true) {
            try {

                cout << "Enter the link: ";
                getline(cin, link);

                if (Validator::validateIsLink(link) == 0)
                    throw(ValidatorError("\nLink must not contain spaces.\n"));

                if(Validator::validateNotEmpty(link) == 0)
                    throw(ValidatorError("\nAll inputs must not be empty.\n"));

                break;
            }
            catch (ValidatorError& error){
                cout << RED << error.getMessage() << "\n" << RESET;
            }
        }

        this->ctrl.remove(link);

        cout << GREEN << "DONE.\n" << RESET;
        getchar();
    }
    catch (RemoveError& error) {
        cout << RED << error.getMessage() << RESET;
        getchar();
    }
}

void UIAdministrator::update() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    string new_title, new_presenter, new_minutes, new_seconds, new_likes, new_link, link;
    int m, s, l;

    try {
        while(true) {
            try {

                cout << "Enter the link: ";
                getline(cin, link);

                if (Validator::validateIsLink(link) == 0)
                    throw(ValidatorError("\nLink must not contain spaces.\n"));

                cout << "\nEnter the new title: ";
                getline(cin, new_title);

                cout << "Enter the new presenter: ";
                getline(cin, new_presenter);

                cout << "Enter the new minutes: ";
                getline(cin, new_minutes);

                if (Validator::validateIsNumber(new_minutes) == 0)
                    throw(ValidatorError("\nMinutes need to be integers.\n"));

                cout << "Enter the new seconds: ";
                getline(cin, new_seconds);

                if (Validator::validateIsNumber(new_seconds) == 0)
                    throw(ValidatorError("\nSeconds need to be integers.\n"));

                cout << "Enter the new likes: ";
                getline(cin, new_likes);

                if (Validator::validateIsNumber(new_likes) == 0)
                    throw(ValidatorError("\nLikes need to be integers.\n"));

                cout << "Enter the new link: ";
                getline(cin, new_link);

                if (Validator::validateIsLink(new_link) == 0)
                    throw(ValidatorError("\nLink must not contain spaces.\n"));

                if( Validator::validateNotEmpty(new_title) == 0 ||
                    Validator::validateNotEmpty(new_presenter) == 0 ||
                    Validator::validateNotEmpty(new_minutes) == 0 ||
                    Validator::validateNotEmpty(new_seconds) == 0 ||
                    Validator::validateNotEmpty(new_likes) == 0 ||
                    Validator::validateNotEmpty(new_link) == 0 ||
                    Validator::validateNotEmpty(link) == 0)

                    throw(ValidatorError("\nAll inputs must not be empty.\n"));

                break;
            }
            catch (ValidatorError& error) {
                cout << RED << error.getMessage() << "\n"<< RESET;
            }
        }

        ControllerAdministrator::to_digit(m, new_minutes);
        ControllerAdministrator::to_digit(s, new_seconds);
        ControllerAdministrator::to_digit(l, new_likes);

        this->ctrl.update(link, new_title, new_presenter, m, s, l, new_link);

        cout << GREEN << "DONE.\n" << RESET;
        getchar();
    }
    catch (UpdateError& error)  {
        cout << RED << error.getMessage() << RESET;
        getchar();
    }
}

void UIAdministrator::printAll() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    std::vector<Video> data = this->ctrl.getData();

    for(auto i = data.begin(); i < data.end(); i++)
        i->printVideoAdministrator();

    getchar();

    cout << "\n\n";
}

RepositoryAdministrator &UIAdministrator::getRepo() {

    return this->ctrl.getRepo();
}

void UIAdministrator::sortList() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    try {
        string option;
        cout << R"(
Press:
    1. sort ascending order by title
    2. sort descending order by likes

Enter an option: )";
        getline(cin, option);

        std::vector<Video> data = this->ctrl.sortDataAndReturn(option);

        for(auto i = data.begin(); i < data.end(); i++)
            i->printVideoAdministrator();

        getchar();

        cout << "\n\n";;
    }
    catch(MsgError& error){
        cout << RED << error.getMessage() << RESET;
    }
}
