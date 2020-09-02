#include <iostream>
#include <vector>

using namespace std;

// O (n^2) approach
// naive multiplication for each term in coeff in first polynomial
// multiply it with each term in second polynomial and store
// result at their (indices_sum) index
// [indices here represent the (next_highest_degree - degree of term + 1) whose coeff is arr[index]]
vector<long long> polynomial_multiplication_naive(int next_highest_degree, const vector<long long> &polynomial1_coefficients, const vector<long long> &polynomial2_coefficients)
{
    vector<long long> coeff_product_arr(2 * next_highest_degree - 1);
    for (size_t poly1_term_degree = 0; poly1_term_degree < next_highest_degree; poly1_term_degree++)
    {
        for (size_t poly2_term_degree = 0; poly2_term_degree < next_highest_degree; poly2_term_degree++)
            coeff_product_arr[poly1_term_degree + poly2_term_degree] += polynomial1_coefficients[poly1_term_degree] * polynomial2_coefficients[poly2_term_degree];
    }
    return coeff_product_arr;
}

void print_array(const vector<long long> &array)
{
    for (size_t i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

int main()
{
    // for x^2 or 2 degree polynomial => degree_plus_one = 3
    int degree_plus_one;
    cin >> degree_plus_one;
    vector<long long> final_product_arr(2 * degree_plus_one - 1), coeff_poly1_arr(degree_plus_one), coeff_poly2_arr(degree_plus_one);

    // degree_index here represent term of degree = (degree of polynomial - degree_index)

    // p1 = 3x^2 + 2x + 5 => coeff_poly1_arr = [3,2,5]
    for (size_t degree_index = 0; degree_index < degree_plus_one; degree_index++)
        cin >> coeff_poly1_arr[degree_index];

    // p1 = 5x^2 + x + 2 => coeff_poly2_arr = [5,1,2]
    for (size_t degree_index = 0; degree_index < degree_plus_one; degree_index++)
        cin >> coeff_poly2_arr[degree_index];

    // final_product_arr = [15, 13, 33, 9, 10] => 15x^4 + 13x^3 + 33x^2 + 9x+ 10
    final_product_arr = polynomial_multiplication_naive(degree_plus_one, coeff_poly1_arr, coeff_poly2_arr);

    print_array(final_product_arr);
}