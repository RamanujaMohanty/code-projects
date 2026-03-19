#include <cstddef>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// struct to store respondent respondents & weights
// composed of name and double vector weights.
struct respondent
{
    string name;
    vector<double> weights;
};

// function to calculate arithmetic mean score
// formula: score = sum(w[ii] * s[ii])
double arithmeticMeanCalc(const vector<double>& s, const vector<double>& w)
{
    double score = 0.0;
    for (size_t ii = 0; ii < s.size(); ++ii)
    {
        score += w[ii] * s[ii];
    }
    return score;
}

// function to calculate geometric mean score
// formula: score = (s[ii] ^ w[ii]) * (s[ii + 1] ^ w[ii + i])
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
    vector<double> s_degrees = {0.90, 0.81, 0.75, 0.41};            // suitability degrees - up to you to choose
    vector<double> correct_w = {0.270, 0.145, 0.455, 0.130};        // correct weights - correct circle percents - up to you
    double correct_s = arithmeticMeanCalc(s_degrees, correct_w);    // correct benchmark score

    // respondent weights stored in a vector of respondent structs
    // Need to enter your provided weights.
    vector<respondent> respondents =
    {
        {"Aaron",   {0.280, 0.150, 0.420, 0.150}},
        {"Evan",    {0.150, 0.125, 0.459, 0.166}},
        {"Mark",    {0.210, 0.135, 0.300, 0.215}}
    };

    // comparison table output
    cout << fixed << setprecision(4);
    cout << "weight assessment: error analysis | (n = 4)\n";
    cout << "correct suitability (s): " << correct_s << "\n\n";
    cout << left << setw(15) << "respondent" << setw(12) << "score (s)" << setw(12)
        << "error (e)" << "rel error (%)" << endl;
    cout << string(55, '-') << endl;

    vector<double> avg_weights(4, 0.0);

    for (const auto& r : respondents)
    {
        double s = arithmeticMeanCalc(s_degrees, r.weights);
        double e = s - correct_s;
        double e_rel = (e / correct_s) * 100.0;

        cout << left << setw(15) << r.name
            << setw(12) << s
            << setw(12) << e
            << e_rel << "%" << endl;

        // Sum weights for point M calculation.
        for (int ii = 0; ii < 4; ++ii)
        {
            avg_weights[ii] += r.weights[ii];
        }
    }

    // Point M analysis (average weights)
    for (int ii = 0; ii < 4; ++ii)
    {
        avg_weights[ii] /= respondents.size();
    }
    double m = arithmeticMeanCalc(s_degrees, avg_weights);

    cout << "\n" << string(55, '-') << endl;
    cout << "Point M (Team Mean suitability): " << m << endl;
    cout << "Difference (M - S): " << m - correct_s << endl;

    return 0;
}
