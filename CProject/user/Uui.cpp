#include "Uui.h"
#include "../exceptions.h"
#include <iostream>
#include <thread>
#include <termios.h>
#include <unistd.h>
#define RED "\033[31m"
#define RESET "\033[0m"

using namespace std;

UIUser::UIUser(ControllerUser &ctrl) : ctrl(ctrl){}

void UIUser::printMenu() {

    cout << R"(
Press:
    1. play by presenter
    2. play watchlist
    3. open watchlist
    4. exit
)";
}

void UIUser::start() {

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
                getchar();
            }
        }

        switch (option.at(0) - '0') {

            case 1:
                this->search();
                continue;

            case 2:
                this->playWatchList();
                continue;

            case 3:
                this->open();
                continue;

            case 4:
                break;

            default:
                cout << RED << "This option doesn't exist.\n" << RESET;
                continue;
        }

        break;
    }
}

void UIUser::search() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    string presenter;
    cout << "Presenter: ";
    getline(std::cin, presenter);

    vector<string> matches = this->ctrl.findAll(presenter);

    if (matches.size() == 0) {
        cout << RED << "\nThe list is empty.\n" << RESET;
        getchar();
        return;
    }

    // get the attrs of the current terminal input
    termios old_t{};
    tcgetattr(STDIN_FILENO, &old_t);

    //create a new terminal which doesn't show the input
    termios new_t = old_t;
    new_t.c_lflag &= ~ECHO;

    //set the attrs of the new terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);

    bool stop = false;
    bool ok = true;
    for(int i = 0; ok; i++, stop = false) {

        Video& video = this->ctrl.getElement(matches[i]);
        //make an operation to run parallel with the reading from console and operations done
        thread pv{&Video::printVideoUser, &video, ref(stop)};

        char c;
        do{
            //get only a character
            c = (char)getchar();

            switch (c) {
                case '1':
                    video.setIs_Liked(this->ctrl.like(video.getLink(), video.getIs_Liked()));
                    break;

                case '2':
                    video.setIs_Added(this->ctrl.addToWatchList(video.getLink()));
                    break;

                case '4':
                    ok = false;
                    break;

                case '5':
                    video.open(video.getLink());
            }

        }while(c != '3' && c != '4');

        //stop the other operation and wait for it to join
        stop = true;
        pv.join();

        if (i == matches.size() - 1)
            i = -1;
    }

    getchar();
    //set terminal back to the old one
    tcsetattr(STDIN_FILENO, TCSANOW, &old_t);

    cout << "\n\n";
}

void UIUser::playWatchList() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    vector<Video> matches = this->ctrl.getWatchList();

    if (matches.size() == 0) {
        cout << RED << "\nThe watchlist is empty.\n" << RESET;
        getchar();
        return;
    }

    termios old_t{};
    tcgetattr(STDIN_FILENO, &old_t);
    termios new_t = old_t;
    new_t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);

    bool stop = false;
    for(int i = 0, ok = 1; i < matches.size() && ok == 1; i++, stop = false) {

        thread pv{&Video::printVideoUser, &matches[i], ref(stop)};

        char c;
        do{
            c = (char)getchar();

            switch (c) {
                case '1':
                    matches[i].setIs_Liked(this->ctrl.like(matches[i].getLink(), matches[i].getIs_Liked()));
                    break;

                case '2':
                    matches[i].setIs_Added(this->ctrl.addToWatchList(matches[i].getLink()));
                    break;

                case '4':
                    ok = 0;
                    break;

                case '5':
                    matches[i].open(matches[i].getLink());
            }

        }while(c != '3' && c != '4');

        stop = true;
        pv.join();
    }

    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_t);

    cout << "\n\n";
}

void UIUser::open() {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    try {
        ctrl.open("3");
    }
    catch (RepoError &error) {
        cout << RED << error.getMessage() << "\n" << RESET;
        getchar();
    }
}

