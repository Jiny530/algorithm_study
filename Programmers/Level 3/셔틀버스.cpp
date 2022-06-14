#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b)
{
    return getMinute(a) < getMinute(b);
}
int getMinute(string times)
{
    int hour = (times[0] - '0')*10 + times[1] - '0';
    int min = (times[3] - '0')*10 + times[4] - '0';

    return hour*60 + min;
}
string digitFormat(int n)
{
    if (n < 10) return "0" + to_string(n);
    else return to_string(n);
}

string solution(int n, int t, int m, vector<string> timetable) 
{
    string answer = "";
    sort(timetable.begin(), timetable.end(), cmp);

    int crew = 0;
    for (int s = 0; s < n; s++)
    {
        int departure = 9 * 60 + t * s;
        int passenger = 0;

        for (int i = crew; i < timetable.size(); i++)
        {
            if (getMinute(timetable[i]) <= departure && passenger < m) passenger++;
            else break;
        }
        crew += passenger;

        if (s == n - 1)
        {
            if (passenger < m)
            {
                answer = digitFormat(departure/ 60) + ":" + digitFormat(departure % 60);
            }
            else 
            {
                int hour, min;
                istringstream ss(timetable[crew-1]);
                ss >> hour >> min;
                
                int latestTime = hour * 60 + min - 1;
                answer = digitFormat(latestTime / 60) + ":" + digitFormat(latestTime % 60);
            }
        }
    }

    return answer;
}