#include <iostream>
#include <vector>

using namespace std;

// O(n * log(n)) approach could be to first sort item values and corresponding weights
// on basis of value per weight(unit) in O(n * log(n)) time and then iterate over it
// in descending order fashion (max value per unit first) to calculate max loot in O(n) time

// O(n ^ 2) Approach
// calculate minimum number of refills needed to travel from one point to other
int compute_min_refills(int distance_to_empty, int end_point, int stops[])
{
    int refills = 0;
    int cur_stop = 0;
    while (end_point > cur_stop)
    {
        int possible_stop_in_available_fuel = cur_stop;

        // calculate farthest reachable refill station
        while (possible_stop_in_available_fuel < end_point && stops[possible_stop_in_available_fuel + 1] - stops[cur_stop] <= distance_to_empty)
        {
            possible_stop_in_available_fuel++;
        }

        // Cannot reach even the next refill station
        if (possible_stop_in_available_fuel == cur_stop)
            return -1;

        else if (possible_stop_in_available_fuel < end_point) // else no point to refill
        {
            refills++; // reach farthest reachable stop and get refilled
            //     cout << "Current stop: " << cur_stop << endl;
            //     cout << "Possible Stop: " << possible_stop_in_available_fuel << endl;
            //     cout << "After refilling at Possible stop, Total refills : " << refills << endl;
        }
        cur_stop = possible_stop_in_available_fuel;
    }

    // cout << "Total refills: " << refills << endl
    return refills;
}

int main()
{
    int distance = 0;
    cin >> distance;
    int max_distance_to_refill = 0;
    cin >> max_distance_to_refill;
    int total_number_of_refill_stations = 0;
    cin >> total_number_of_refill_stations;

    int stops[total_number_of_refill_stations];
    stops[0] = 0; // first stop at current location

    // refill stations are from stops[1] -> stops[total_number_of_refill_stations]
    for (int i = 1; i <= total_number_of_refill_stations; ++i)
        cin >> stops[i];
    stops[total_number_of_refill_stations + 1] = distance; //last stop or total distance to travel

    cout << compute_min_refills(max_distance_to_refill, total_number_of_refill_stations + 1, stops) << "\n";

    return 0;
}
