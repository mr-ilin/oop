#include <vector>
#include <map>
#include <iostream>
#include "allocator.h"

template <int N> int factorial(){
    return N*factorial<N-1>();
}
template <> int factorial<0>(){
    return 1;
}

using map_type_with_allocator = 
std::map<int,int,std::less<int>,mai::allocator<std::pair<const int,int>,10>>;


template <int N> void fill_map(map_type_with_allocator &map){
    map.insert(std::pair<int,int>(N,factorial<N>()));
    fill_map<N-1>(map);
}

template <> void fill_map<0>(map_type_with_allocator &map){
    map.insert(std::pair<int,int>(0,factorial<0>()));
}

auto main() ->int{

 // заполняем значением факториала
 map_type_with_allocator my_map_with_allocator;
 fill_map<9>(my_map_with_allocator);

 for(auto p:my_map_with_allocator) std::cout << p.first << " " << p.second << std::endl;
 return 0;
}