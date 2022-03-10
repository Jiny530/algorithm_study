#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> parking_hour;
    map<int, int> parking_time;
    pair<map<int, int>::iterator, bool> inserter;

    set<int> parking_cars;
    set<int>::iterator set_iter;

    int hour, min, car_num;
    int end = 23 * 60 + 59;
    string in_out;
    for (int i = 0; i < records.size(); i++)
    {
        records[i][2] = ' ';
        istringstream ss(records[i]);

        ss >> hour >> min >> car_num >> in_out;
        if (in_out == "IN")
        {
            parking_hour[car_num] = hour * 60 + min;
            parking_cars.insert(car_num);
        }
        else
        {
            int time = hour * 60 + min - parking_hour[car_num];
            inserter = parking_time.insert({ car_num, time });

            if (!inserter.second) parking_time[car_num] += time;

            set_iter = parking_cars.find(car_num);
            parking_cars.erase(set_iter);
        }
    }

    for (set_iter = parking_cars.begin(); set_iter != parking_cars.end(); set_iter++)
    {
        int time = end - parking_hour[*set_iter];
        inserter = parking_time.insert({ *set_iter, time });

        if (!inserter.second) parking_time[*set_iter] += time;
    }

    map<int, int>::iterator iter;

    for (iter = parking_time.begin(); iter != parking_time.end(); iter++)
    {
        int fee = fees[1];
        if (iter->second > fees[0]) fee += (iter->second - fees[0] + fees[2] - 1) / fees[2] * fees[3];
        answer.push_back(fee);
    }


    return answer;
}
