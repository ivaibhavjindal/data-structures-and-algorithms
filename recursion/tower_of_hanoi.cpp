#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char source, char destination, char aux)
{
    if (n == 1)
    {
        cout << "Move top disk from pole " << source << " -> " << destination << endl;
    }
    else
    {
        tower_of_hanoi(n - 1, source, aux, destination);
        tower_of_hanoi(1, source, destination, aux);
        tower_of_hanoi(n - 1, aux, destination, source);
    }
}

int main()
{
    char src, dest, aux;
    int disks;
    cout << "Enter Number of Disks: ";
    cin >> disks;
    cout << "Enter Alphabet Name for Source, Destination and spare Pole: ";
    cin >> src >> dest >> aux;
    cout << "Source Pole: " << src << endl;
    cout << "Destination Pole: " << dest << endl;
    cout << "Spare Pole: " << aux << endl;
    tower_of_hanoi(disks, src, dest, aux);
}
