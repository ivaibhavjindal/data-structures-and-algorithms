#include <iostream>
#include <vector>

using namespace std;

// Suppose Given Segments
// 4 7
// 1 3
// 2 5
// 5 6

// Four Segments => start_arr(4,1,2,5), end_arr(7,3,5,6)

// Modified Bubble Sort i.e. Sort as Per end_arr item (end point of segments)
//  and Move the whole segment at new location

// After Sorting
// 1 3
// 2 5
// 5 6
// 4 7

// Take a points array(in brackets below), add initial end_arr item (cur_point) to it (3), then iterate over and
// check if the cur_point lies in segment else update points array and cur_point with end point of that segment
// 1 3 => 1(3)                        cur_point = 3
// 2 5 => 3 >=2 && 3<=5 => 1(3)       cur_point = 3
// 5 6 => 3 !>=5 && 3<=6 => 2(3, 6)   cur_point = 6
// 4 7 => 6 >=4 && 6 <= 7 => 2 (3, 6) cur_point = 6

// Required min number of points = 2 and points array => (3, 6)

// O(n^2) Approach
void sort_segments_array_and_print_min_points(int array_length, long start_array[], long end_array[])
{
  // Modified bubble sort (O(n^2))
  for (int i = 0; i < array_length - 1; i++)
  {
    for (int j = i + 1; j < array_length; j++)
    {
      // sorting based on end_array item (segment end points)
      if (end_array[i] > end_array[j])
      {
        // swap whole segment(start and end array) to new location
        long temp1 = start_array[j];
        long temp2 = end_array[j];
        start_array[j] = start_array[i];
        start_array[i] = temp1;
        end_array[j] = end_array[i];
        end_array[i] = temp2;
      }
    }
  }

  // Initialise points_array and store cur_point value
  long cur_point = end_array[0];
  vector<long> points_array;
  points_array.push_back(cur_point);

  // Iterate over all segments (O(n))
  for (int cur_segment_index = 1; cur_segment_index < array_length; cur_segment_index++)
  {
    // Update points_array and cur_point value if cur_point not lies in cur_segment
    if (!(cur_point >= start_array[cur_segment_index] && cur_point <= end_array[cur_segment_index]))
    {
      cur_point = end_array[cur_segment_index];
      points_array.push_back(cur_point);
    }
  }

  cout << points_array.size() << endl; // min number of points to cover all segments
  // Print one possible set of points covering all segments (O(n))
  for (auto points_iterator = points_array.begin(); points_iterator != points_array.end(); ++points_iterator)
    cout << *points_iterator << " ";
  cout << endl;
}

int main()
{
  int num_segments;
  cin >> num_segments;

  // Store start point of segment in start_arr and end point in end_arr
  long start_arr[num_segments], end_arr[num_segments];
  for (int point_index = 0; point_index < num_segments; ++point_index)
    cin >> start_arr[point_index] >> end_arr[point_index];

  sort_segments_array_and_print_min_points(num_segments, start_arr, end_arr);

  return 0;
}