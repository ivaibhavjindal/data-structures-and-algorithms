#include <iostream>
#include <cstring>

using namespace std;

void print_array(int arr[], int len)
{
    for (int cur_item_index = 0; cur_item_index < len; cur_item_index++)
        cout << arr[cur_item_index] << " ";
    cout << endl;
}

// count the occurence of each element in array and
// update position as per value in non decreasing order
// Condition: Items must confine in a small range(0, max value) => O(n)
void counting_sort(int arr[], int len, int max_val) // say arr = [9,4,3,7,0,0,1]; len = 7; max_val = 9
{
    // output array to store sorted values
    int sorted_output[len];

    // array to store count of item of each item in array(arr)
    int count[max_val + 1], i;
    memset(count, 0, sizeof(count)); // count = [0(0), 0(1), 0(2), 0(3), 0(4), 0(5), 0(6), 0(7), 0(8), 0(9)] => val(index)

    // count the number of times each item exists and store
    // its value at its index in count array
    for (i = 0; i < len; i++)
        count[arr[i]]++; // count[i] => number of times i is present in arr
    // print_array(count, max_val + 1); // count = [2(0), 1(1), 0(2), 1(3), 1(4), 0(5), 0(6), 1(7), 0(8), 1(9)]

    // update count by adding prev values (cumulative sum count)
    for (i = 1; i <= max_val; i++)
        count[i] += count[i - 1];
    // print_array(count, max_val + 1); // count = [2(0), 3(1), 3(2), 4(3), 5(4), 5(5), 5(6), 6(7), 6(8), 7(9)]

    // place objects at its correct postion and decrease count by 1
    for (i = 0; i < len; ++i)
    {
        // ouput array is sorted
        sorted_output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // print_array(count, max_val + 1); // count = [0(0), 2(1), 3(2), 3(3), 4(4), 5(5), 5(6), 5(7), 6(8), 6(9)]

    // copy sorted output array to original array(arr)
    for (i = 0; i < len; ++i)
        arr[i] = sorted_output[i];
    // arr = sorted_output = [0, 0, 1, 3, 4, 7, 9]
}

int main()
{
    int array_len, max_val;
    cin >> array_len >> max_val;

    // Input numbers into array
    int arr[array_len];
    for (int i = 0; i < array_len; i++)
        cin >> arr[i];

    // sort array
    counting_sort(arr, array_len, max_val);

    // print sorted array
    print_array(arr, array_len);
    return 0;
}
