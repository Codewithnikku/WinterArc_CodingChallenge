#include <iostream>
#include <string>
using namespace std;

class CountDaysSpentTogether {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        auto getDay = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;

            for (int i = 0; i < month - 1; i++) {
                total += days[i];
            }

            return total;
        };

        int a1 = getDay(arriveAlice);
        int a2 = getDay(leaveAlice);
        int b1 = getDay(arriveBob);
        int b2 = getDay(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};


int main() {
    CountDaysSpentTogether cdst;
    string aliceArrive = "08-15", aliceLeave = "08-18";
    string bobArrive = "08-16", bobLeave = "08-19";
    cout << "Days Count: " << cdst.countDaysTogether(aliceArrive, aliceLeave, bobArrive, bobLeave) << endl;    
}