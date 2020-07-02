#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../lib/templated/sort.h"
#include "../lib/inherited/IComparable/IComparable.h"
#include "../lib/inherited/IComparable/Point.h"

void templated_interface() {
    std::string command, param1, param2;
    auto data = std::vector<std::pair<int, int>>();
    std::cout << "This interface works by simple commands which enter submenues for entering parameters: " << std::endl;
    std::cout << "\t add params: x y adds a new Point at x and y. Ex.: add <Enter> 5 10\n"
                 "\t remove x y removes all Points with coordinates x,y\n"
                 "\t sort sorts all points\n"
                 "\t clear clears the current list of points"
                 "\t quit exits to the preceding menu" << std::endl;
    while (command != "q") {
        std::cout << "{";
        for(auto point : data)
            std::cout << " (" << point.first << " " << point.second << ")";
        std::cout << " }" << std::endl;
        std::cin >> command;
        if (command == "add") {
            std::cin >> param1 >> param2;
            data.emplace_back(stoi(param1), stoi(param2));
        } else if (command == "remove") {
            std::cin >> param1 >> param2;
            auto to_be_removed = std::pair(stoi(param1), stoi(param2));
            data.erase(std::remove(data.begin(), data.end(), to_be_removed), data.end());
        }else if(command == "sort"){
            sort_it(data.begin(), data.end(), [](auto &a, auto &b) -> bool {
                return sqrt(a.first * a.first + a.second * a.second) <
                       sqrt(b.first * b.first + b.second * b.second);
            });
        } else if (command == "clear"){
            data.clear();
        }else if(command == "quit"){
            return;
        }
    }
}

void inherited_interface(){
    std::string command;
    int param1, param2;
    ComparableCollection data;
    std::cout << "This interface works by simple commands which enter submenues for entering parameters: " << std::endl;
    std::cout << "\t add params: x y adds a new Point at x and y. Ex.: add <Enter> 5 10\n"
                 "\t remove x y removes all Points with coordinates x,y\n"
                 "\t sort sorts all points\n"
                 "\t clear clears the current list of points"
                 "\t quit exits to the preceding menu" << std::endl;
    while (command != "q") {
        std::cout << "{";
        for(auto &point : data){
            auto p = (Point*)point.get();
            std::cout << " (" << p->get_x() << " " << p->get_y() << ")";
        }
        std::cout << " }" << std::endl;
        std::cin >> command;
        if (command == "add") {
            std::cin >> param1 >> param2;
            data.push_back(std::make_unique<Point>(param1, param2));
        } else if (command == "remove") {
            std::cin >> param1 >> param2;
            data.erase(std::remove_if(data.begin(), data.end(), [=](auto& point){
                auto p = (Point*)point.get();
                return p->get_x() == param1 && p->get_y() == param2;
            }), data.end());
        }else if(command == "sort"){
            data.sort();
        } else if (command == "clear"){
            data.clear();
        }else if(command == "quit"){
            return;
        }
    }
}

void launch_app() {
    auto choice = 'n';
    while (true) {
        std::cout << "Select t for templated or i for inherited" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 't':
                templated_interface();
                break;
            case 'i':
                inherited_interface();
                break;
            default:
                break;
        }
    }
}

