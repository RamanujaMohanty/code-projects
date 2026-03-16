#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct respondent
{
    string name;
    vector<double> weights;
};

double arithmeticMeanCalc(const vector<double>& s, const vector<double>& w)
{
    double score = 0.0;
    for (size_t ii = 0; ii < s.size(); ++ii)
    {
        score += w[ii] * s[ii];
    }
    return score;
}

double geometricMeanCalc(const vector<double>& s, const vector<double>& w)
{
    double score = 1.0;
    for (size_t ii = 0; ii < s.size(); ++ii)
    {
        score *= pow(s[ii], w[ii]);
    }
    return score;
}

int main()
{
    vector<double> s_degrees = {0.90, 0.81, 0.75, 0.41};
    vector<double> correct_w = {0.270, 0.145, 0.455, 0.130};
    double correct_s = arithmeticMeanCalc(s_degrees, correct_w);
    vector<respondent> respondents = {
        {"Aaron",   {0.280, 0.150, 0.420, 0.150}},
        {"Evan",    {0.250, 0.125, 0.459, 0.166}},
        {"Mark",    {0.250, 0.135, 0.300, 0.215}}
    };
    return 0;
}
