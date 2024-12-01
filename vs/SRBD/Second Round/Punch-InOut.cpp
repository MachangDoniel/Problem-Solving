#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Convert HH:MM time format to minutes since midnight
int timeToMinutes(const string& time) {
    int h, m;
    sscanf(time.c_str(), "%d:%d", &h, &m);
    return h * 60 + m;
}

string calculateWorkingDay(const vector<pair<char, string>>& punches) {
    const int DAY_START = timeToMinutes("07:00");
    const int FIRST_HALF_END = timeToMinutes("11:00");
    const int SECOND_HALF_START = timeToMinutes("14:00");
    const int LUNCH_START = timeToMinutes("13:00");
    const int LUNCH_END = timeToMinutes("14:00");
    
    const int OVERTIME_THRESHOLD = 12 * 60; // 12 hours
    const int FULL_DAY_THRESHOLD = 8 * 60;  // 8 hours
    const int HALF_DAY_THRESHOLD = 4 * 60;   // 4 hours

    int W = 0;  // Total working hours in minutes
    int firstPunchTime = -1;
    bool inOffice = false;
    bool firstHalfLost = false;

    // Variable to store the time of the last punch-in
    int lastPunchInTime = -1;

    for (const auto& punch : punches) {
        char action = punch.first;
        int timeInMinutes = timeToMinutes(punch.second);

        if (action == '>') {  // Punch In
            if (firstPunchTime == -1) {
                firstPunchTime = timeInMinutes;  // Record the first punch-in time
            }

            // Check if the first punch-in is late
            if (timeInMinutes > FIRST_HALF_END) {
                firstHalfLost = true;  // Lost the 1st Half
            }

            inOffice = true;

            // Set last punch-in time
            lastPunchInTime = timeInMinutes;

        } else if (action == '<') {  // Punch Out
            if (inOffice) {
                int effectiveEndTime = timeInMinutes;

                // Adjust for lunch break
                if (effectiveEndTime > LUNCH_START && effectiveEndTime < LUNCH_END) {
                    effectiveEndTime = LUNCH_END;  // Ignore lunch hour
                }

                // Calculate working duration only if the punch-in is after the working start
                if (lastPunchInTime >= DAY_START) {
                    W += effectiveEndTime - lastPunchInTime;
                }

                inOffice = false;  // Reset office status
                lastPunchInTime = -1;  // Reset last punch-in time
            }
        }
    }

    // Evaluate the working day status
    if (firstPunchTime == -1 || firstPunchTime > timeToMinutes("15:00")) {
        return "Absent";
    }

    string result;
    bool isLate = false;

    // Determine the working day result based on W
    if (W >= OVERTIME_THRESHOLD) {
        result = "Overtime";
    } else if (W >= FULL_DAY_THRESHOLD) {
        result = "Full Day";
    } else if (W >= HALF_DAY_THRESHOLD) {
        result = firstHalfLost ? "2nd Half" : "1st Half";
    } else {
        return "Absent";
    }

    // Late check for eligible cases
    if ((result == "Full Day" || result == "1st Half" || result == "Overtime") && firstPunchTime > timeToMinutes("10:30")) {
        isLate = true;  // Late for Full Day or 1st Half
    }
    if (result == "2nd Half" && firstPunchTime > timeToMinutes("14:30")) {
        isLate = true;  // Late for 2nd Half
    }

    return result + (isLate ? " ~" : "");  // Append late symbol if applicable
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<pair<char, string>> punches(N);

        for (int i = 0; i < N; ++i) {
            char action;
            string time;
            cin >> action >> time;
            punches[i] = {action, time};
        }

        string result = calculateWorkingDay(punches);
        cout << result << endl;  // Output result for each case
    }

    return 0;
}
