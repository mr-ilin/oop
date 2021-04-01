#include "square.h"
#include "list.h"
#include <iostream>
#include <algorithm>

auto main() -> int {

    List<Square<int>> list;

    Square<int> s1(std::pair<int,int>(0,0),std::pair<int,int>(10,0),std::pair<int,int>(10,10),std::pair<int,int>(0,10)),
                s2(std::pair<int,int>(0,0),std::pair<int,int>(20,0),std::pair<int,int>(20,20),std::pair<int,int>(0,20)),
                s3(std::pair<int,int>(0,0),std::pair<int,int>(30,0),std::pair<int,int>(30,30),std::pair<int,int>(0,30)),
                s4(std::pair<int,int>(0,0),std::pair<int,int>(40,0),std::pair<int,int>(40,40),std::pair<int,int>(0,40));
    list.push_back(s1);
    list.push_back(s2);
    list.push_back(s3);
    list.push_back(s4);

    for(auto i:list ) std::cout << i << std::endl;

    int count = std::count_if(list.begin(),list.end(),
    [](auto &value) -> bool{
        std::pair<int,int> distance {value.c.first-value.a.first,value.c.second-value.a.second};
        return (distance.first*distance.second)>=400;
    });

    std::cout << "squares greater 400:" << count <<std::endl;
    std::cout << list.begin()->a.first << std::endl;

    std::cout << "erase" << std::endl;
    list.erase(++++list.begin());
    for(auto i:list ) std::cout << i << std::endl;

    Square<int> s5(std::pair<int,int>(10,10),std::pair<int,int>(10,10),std::pair<int,int>(10,10),std::pair<int,int>(10,10));
    
    std::cout << "insert" << std::endl;
    auto val = list.insert(++++list.begin(),s5);
    for(auto i:list ) std::cout << i << std::endl;

    std::cout << "erase" << std::endl;
    list.erase(val);
    for(auto i:list ) std::cout << i << std::endl;
    return 1;
}