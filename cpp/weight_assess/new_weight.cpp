#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cstddef>

using namespace std;

double arithmetic_mean_calc(const vector<double>& suits, const vector<double>& weights)
{
    double score = 0.0;
    for (size_t ii = 0; ii < suits.size(); ++ii)
    {
        score += weights[ii] * suits[ii];
    }
    return score;
}

double geometric_mean_calc(const vector<double>& suits, const vector<double>& weights)
{
    double score = 1.0;
    for (size_t ii = 0; ii < suits.size(); ++ii)
    {
        score *= pow(suits[ii], weights[ii]);
    }
    return score;
}

int main()
{
    string experiment_type;
    int n;
    cout << "Enter experiment type (linear | circular): ";
    cin >> experiment_type;
    cout << "Enter n (number of segments): ";
    cin >> n;
    vector<double> suit_degrees(n);
    for (size_t ii = 0; ii < n; ++ii)
    {
        cout << "Enter value " << ii + 1 << ": ";
        cin >> suit_degrees[ii];
    }
    vector<double> correct_weights(n);
    for (size_t ii = 0; ii < n; ++ii)
    {
        cout << "Enter value " << ii + 1 << ": ";
        cin >> correct_weights[ii];
    }
    double correct_benchmark = arithmetic_mean_calc(suit_degrees, correct_weights);
    return 0;
}
