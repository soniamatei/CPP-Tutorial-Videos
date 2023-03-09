#include <iostream>
#include "lab_activity.h"
#include "administrator/ui.h"
#include "administrator/video.h"
#include "user/Uui.h"
#include "user/csv_repo.h"
#include "user/html_repo.h"
#include "user/textu_repo.h"
#include "exceptions.h"
#include "administrator/text_repo.h"
#define RED "\033[31m"
#define RESET "\033[0m"

//using namespace std;
//
//int main() {
//
////    testSort();
////
//    string stream1, stream2;
//
//    cout << R"(
//Press:
//    1. memory administrator repository
//    2. text file administrator repository
//
//Enter a stream: )";
//    getline(cin, stream1);
//    cout << "\x1B[2J\x1B[3J\x1B[H";
//
//    cout << R"(
//Press:
//    1. memory user repository
//    2. text file user repository
//    3. csv user repository
//    4. html user repository
//
//Enter a stream: )";
//
//    getline(cin, stream2);
//
//    RepositoryAdministrator* repoAdmin = nullptr;
//    RepositoryUser* repoUser = nullptr;
//
//    if (stream1 == "1")
//        repoAdmin = new RepositoryAdministrator;
//    else if (stream1 == "2")
//        repoAdmin = new TextRepository;
//    else return 1;
//
//    if (stream2 == "1")
//        repoUser = new RepositoryUser;
//    else if (stream2 == "2")
//        repoUser = new TextURepository;
//    else if (stream2 == "3")
//        repoUser = new CsvRepository;
//    else if (stream2 == "4")
//        repoUser = new HtmlRepository;
//    else return 1;
//
//    ControllerAdministrator ctrlAdmin{*repoAdmin};
//    UIAdministrator uiAdmin{ctrlAdmin};
//
//    ControllerUser ctrlUser{*repoAdmin, *repoUser};
//    UIUser uiUser{ctrlUser};
//
//    string option;
//    while (true) {
//
//        cout << "\x1B[2J\x1B[3J\x1B[H";
//
//        cout << R"(
//Press:
//    1. administrator mode
//    2. user mode
//    3. exit application
//)";
//        while (true) {
//            try {
//                cout << "\nEnter an option: ";
//                getline(cin, option);
//                cout << "\n";
//
//                if (option.size() != 1)
//                    throw(ValidatorError("Invalid option."));
//
//                break;
//            }
//            catch (ValidatorError& error){
//                cout << RED << error.getMessage() << "\n" << RESET;
//            }
//        }
//
//        switch (option.at(0) - '0') {
//
//            case 1:
//                uiAdmin.start();
//                continue;
//
//            case 2:
//                uiUser.start();
//                continue;
//
//            case 3:
//                break;
//
//            default:
//                cout << RED << "This option doesn't exist.\n" << RESET;
//                getchar();
//                continue;
//        }
//        break;
//    }
//
//    return 0;
//}
