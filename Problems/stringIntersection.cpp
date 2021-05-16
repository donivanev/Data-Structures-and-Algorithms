////
//// Created by bozhidar on 1/6/21.
////
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <sstream>
//
//using namespace std;
//
//std::vector<std::string> readString(std::string &str) {
//    std::vector<std::string> temp;
//    std::unordered_map<std::string,bool> map;
//    std::stringstream stream(str);
//
//    std::string cur;
//    while (stream >> cur) {
//        if (cur[cur.length() - 1] == ',' || cur[cur.size() - 1] == '.') {
//            cur.pop_back();
//        }
//        if(!map[cur]){
//            map[cur] = true;
//            temp.push_back(cur);
//        }
//    }
//    return temp;
//}
//
//
//
//
//int main() {
//    std::string str1, str2;
//    std::unordered_map<std::string, bool> map;
//
//    std::getline(std::cin, str1);
//    std::vector<std::string> first = readString(str1);
//
//    std::getline(std::cin, str2);
//    std::vector<std::string> other = readString(str2);
//
//    for(auto & i : first){
//        map[i] = true;
//    }
//
//    for(auto & i : other){
//        if(!map[i]){
//            std::cout << i << " ";
//        }
//    }
//
//
//    return 0;
//}
