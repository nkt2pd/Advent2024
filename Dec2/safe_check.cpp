#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool small_change(std::vector<int> report_data) {

    int curr_data = 0;
    int last_data = 0;
    int first = 1;

    for(auto i : report_data) {
        if(first == 1) {
            curr_data = i;
            first = 0;
        } else {
            last_data = curr_data;
            curr_data = i;
            if(abs(last_data - curr_data) < 1 || abs(last_data - curr_data) > 3) {
                return false;
            }
        }
    }

    return true;

}

bool monotonic(std::vector<int> report_data) {

    int curr_data = 0;
    int last_data = 0;
    int first = 1;
    int second = 1;
    bool pos = false;
    bool diff = false;

    for(auto i : report_data) {
        if(first == 1) {
            curr_data = i;
            first = 0;
        } else if(second == 1) {
            last_data = curr_data;
            curr_data = i;
            second = 0;
            if(curr_data - last_data > 0) {
                pos = true;
            }
        } else {
            last_data = curr_data;
            curr_data = i;
            diff = curr_data - last_data > 0 ? true : false;

            if(diff != pos) {
                return false;
            }
            
        }
    }

    return true;

}

int main() {

    int safe_reports = 0;
    std::string report;
    std::vector<int> report_data;

    std::ifstream input("input.txt");

    
    std::getline(input, report);
    while(!input.eof()) {

        std::size_t start = 0;
        std::size_t end = 0;
        report_data.clear();
        //feed data from a single report into a vector
        while((end = report.find(" ", start)) != std::string::npos) {
            report_data.push_back(stoi(report.substr(start, end - start)));

            start = end + 1;
        }
        report_data.push_back(stoi(report.substr(start)));

        //check for conditions for a safe report
        //could be made faster by discarding unsafe reports first
        if(small_change(report_data) && monotonic(report_data)) {
            safe_reports++;
        }
        std::getline(input, report);
    }

    std::cout << safe_reports;

    return 0;
}