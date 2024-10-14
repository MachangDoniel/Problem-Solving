#include <iostream>
#include <vector>
#include <utility> // For std::pair
using namespace std;

int main() {
    // Step 1: Input Jim's usage and recovery times for each machine
    vector<pair<int, int>> jimTimes(10); // (usage time, recovery time)
    for (int i = 0; i < 10; ++i) {
        cin >> jimTimes[i].first >> jimTimes[i].second;
    }
    
    // Step 2: Input other users' times for each machine
    vector<pair<pair<int, int>, int>> otherUsers(10); // ((usage time, recovery time), start time)
    for (int i = 0; i < 10; ++i) {
        int u, r, t;
        cin >> u >> r >> t;
        otherUsers[i] = make_pair(make_pair(u, r), t); // Store as pair of pairs
    }

    long long totalTime = 0; // This will track when Jim finishes on each machine

    // Step 3: Simulate Jim's workout through the machines
    for (int cycle = 0; cycle < 3; ++cycle) { // 3 cycles
        for (int machine = 0; machine < 10; ++machine) { // 10 machines
            int usageTime = jimTimes[machine].first;
            int recoveryTime = jimTimes[machine].second;
            int otherUsageTime = otherUsers[machine].first.first;
            int otherRecoveryTime = otherUsers[machine].first.second;
            int otherStartTime = otherUsers[machine].second;

            // At the beginning of the first machine, Jim starts at time 0
            if (machine == 0 && cycle == 0) {
                totalTime = 0; // Starting at time 0 for the first machine in the first cycle
            } else {
                // Add recovery time from the previous machine to total time
                totalTime += jimTimes[machine - 1].first; // Previous machine usage time
                totalTime += jimTimes[machine - 1].second; // Previous machine recovery time
            }

            // Calculate when the other user finishes their usage
            int otherFinishTime = otherStartTime; // Start from their start time
            while (otherFinishTime <= totalTime) {
                otherFinishTime += otherUsageTime + otherRecoveryTime; // Calculate their next finish time
            }

            // Determine when Jim can start using the machine
            if (totalTime < otherFinishTime) {
                // If Jim arrives before the other user is finished, he has to wait
                totalTime = otherFinishTime; // Jim waits until the other user finishes
            }

            // Now Jim uses the machine
            totalTime += usageTime; // Jim uses the machine

            // After using the machine, if it's not the last machine in the last cycle, add recovery time
            if (!(machine == 9 && cycle == 2)) {
                totalTime += recoveryTime; // Add recovery time unless it's the last usage of the last machine
            }
        }
    }

    // Step 4: Output the total time when Jim finishes
    cout << totalTime << endl;

    return 0;
}
