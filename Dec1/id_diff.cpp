#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

int main() {

    int small_diff = 0;
    int diff = 0;
    int sim = 0;

    std::vector<int> list1;
    std::vector<int> list2;

    //split the lists
    std::string buffer;
    std::ifstream input("input.txt");

    input >> buffer;
    while(!input.eof()) {
        
        list1.push_back(std::stoi(buffer));
        input >> buffer;
        list2.push_back(std::stoi(buffer));
        input >> buffer;
    }

    //sort the lists from smallest to largest
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    //compare the lists
    for(int i = 0; i < list1.size(); i++) {
        small_diff = std::abs(list1[i] - list2[i]);
        diff += small_diff;
        small_diff = 0;
    }

    std::cout << "Total Distance: " << diff << std::endl;

    //now check the similarity score

    for(int i = 0; i < list1.size(); i++) {
        sim += list1[i]*std::count(list2.begin(), list2.end(), list1[i]);
    }

    std::cout << "Similarity Score: " << sim << std::endl;
}