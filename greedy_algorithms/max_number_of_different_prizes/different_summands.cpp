#include <iostream>

using namespace std;

// Distribution of candies among maximum possible kids such that
// kid with higher rank gets more candies than one with a lower rank

// Get maximum number of kids in which candies can be distributed
int optimal_number_of_samples(long items_to_distribute)
{
  int number_of_samples = 1;
  // iterate over number of candies until we run out of them
  while (true)
  {
    items_to_distribute -= number_of_samples; // update candies left after distributing to current child

    // if run out of candies or can give last candy to that kid return number of kids we could distribute to
    if (items_to_distribute <= number_of_samples)
      return number_of_samples;

    number_of_samples++; // kid with higher rank gets more candies than one with a lower rank
  }
}

// items distributed over number of samples such that each sample has different number of items
// and the distribution of items is accomodates max possible samples
void print_distribution(long items_to_distribute, int number_of_samples)
{
  // distribute in natural AP series starting from 1 and common diff 1 => 1, 2, 3, ...
  for (int sample = 1; sample < number_of_samples; sample++)
  {
    cout << sample << " ";
  }

  // for the last kid give out all the remaining candies as another kid couldn't be accomadated with leftover candies
  // Summation of this AP = 1 + 2 + 3 + 4 + ... n => (n * (n+1))
  long extra_items = items_to_distribute - ((number_of_samples * (number_of_samples + 1)) / 2);
  cout << number_of_samples + extra_items << endl;
}

int main()
{
  long candies;
  cin >> candies;

  int number_of_kids = optimal_number_of_samples(candies);
  cout << number_of_kids << endl;
  print_distribution(candies, number_of_kids);

  return 0;
}
