#include <bits/stdc++.h>
using namespace std;

void printOptimalPath(int **path, int cur_station, int cur_line, int stations)
{
    if (cur_station > 0)
    {
        if (cur_station == stations)
        {
            printOptimalPath(path, cur_station - 1, cur_line, stations);
            cout << "line: " << cur_line << " station: " << stations << endl;
        }
        else
        {
            printOptimalPath(path, cur_station - 1, path[cur_line][cur_station], stations);
            cout << "line: " << path[cur_line][cur_station] << " station: " << cur_station << endl;
        }
    }
}

int carAssembly(int stations, int line1[], int line2[], int line1_to_line2[], int line2_to_line1[], int entry[], int exit[])
{
    int time1[stations], time2[stations];
    int **path = new int *[2];
    for (int i = 0; i < 2; i++)
        path[i] = new int[stations];

    // time taken to leave first station in line 1
    time1[0] = entry[0] + line1[0];

    // time taken to leave first station in line 2
    time2[0] = entry[1] + line2[0];

    for (int i = 1; i < stations; ++i)
    {
        if (time1[i - 1] + line1[i] <= time2[i - 1] + line2_to_line1[i] + line1[i])
        {
            path[0][i] = 1;
            time1[i] = time1[i - 1] + line1[i];
        }
        else
        {
            path[0][i] = 2;
            time1[i] = time2[i - 1] + line2_to_line1[i] + line1[i];
        }

        if (time2[i - 1] + line2[i] <= time1[i - 1] + line1_to_line2[i] + line2[i])
        {
            path[1][i] = 2;
            time2[i] = time2[i - 1] + line2[i];
        }
        else
        {
            path[1][i] = 1;
            time2[i] = time1[i - 1] + line1_to_line2[i] + line2[i];
        }
    }

    int final_path, min_time;

    // Consider exit times and return minimum
    if (time1[stations - 1] + exit[0] <= time2[stations - 1] + exit[1])
    {
        final_path = 1;
        min_time = time1[stations - 1] + exit[0];
    }
    else
    {
        final_path = 2;
        min_time = time2[stations - 1] + exit[1];
    }

    cout << "\nPath\n";
    printOptimalPath(path, stations, final_path, stations);

    return min_time;
}

int main()
{
    int num_stations;
    cout << "Enter number of stations: ";
    cin >> num_stations;

    int assembly_line1[num_stations];
    int transfer_line1_to_line2[num_stations] = {0};
    int assembly_line2[num_stations];
    int transfer_line2_to_line1[num_stations] = {0};
    int entry[2];
    int exit[2];

    cout << "Enter entry time for line 1: ";
    cin >> entry[0];
    cout << "Enter entry time for line 2: ";
    cin >> entry[1];
    cout << "Enter exit time from line 1: ";
    cin >> exit[0];
    cout << "Enter exit time from line 2: ";
    cin >> exit[1];

    cout << "Enter time at each station for line 1: ";
    for (int i = 0; i < num_stations; i++)
        cin >> assembly_line1[i];

    cout << "Enter time at each station for line 2: ";
    for (int i = 0; i < num_stations; i++)
        cin >> assembly_line2[i];

    cout << "Enter time to transfer from line 1 to line 2 at each station: ";
    for (int i = 1; i < num_stations; i++)
        cin >> transfer_line1_to_line2[i];

    cout << "Enter time to transfer from line 2 to line 1 at each station: ";
    for (int i = 1; i < num_stations; i++)
        cin >> transfer_line2_to_line1[i];

    int min_time = carAssembly(num_stations, assembly_line1, assembly_line2,
                               transfer_line1_to_line2, transfer_line2_to_line1, entry, exit);
    cout << "\nMinimum time: " << min_time << endl;

    return 0;
}
