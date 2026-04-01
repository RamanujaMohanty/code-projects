#include <cstddef>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

// function to calculate arithmetic mean score
// formula: score = sum(w[i] * s[i])
double arithmetic_mean_compute(const std::vector<double>& p_scores, const std::vector<double>& p_weights){
    double score = 0.0;
    for (size_t i = 0; i < p_scores.size(); i++) {
        score += p_weights[i] * p_scores[i];
    }

    return score;
}

int main() {
    vector<double> s_degrees = {0.70, 0.15, 0.10, 0.05};            // suitability degrees - up to you to choose
    vector<double> correct_w = {0.270, 0.145, 0.455, 0.130};        // correct weights - correct circle percents - up to you
    double correct_s = arithmetic_mean_compute(s_degrees, correct_w);    // correct benchmark score

    // Hash table to represent our dataset
    // Key = string (the name)
    // Value = array of doubles (the weights)
    std::unordered_map<std::string, std::vector<double>> data_weights;
    data_weights.insert({"Ram", {0.185, 0.215, 0.440, 0.160}});
    data_weights.insert({"Evan", {0.310, 0.125, 0.345, 0.220}});
    data_weights.insert({"Mark", {0.260, 0.175, 0.285, 0.280}});


    // comparison table output
    cout << fixed << setprecision(4);
    cout << "weight assessment: error analysis | (n = 4)\n";
    cout << "correct suitability (s): " << correct_s << "\n\n";
    cout << left << setw(15) << "respondent" << setw(12) << "score (s)" << setw(12)
        << "error (e)" << "rel error (%)" << endl;
    cout << string(55, '-') << endl;

    vector<double> avg_weights(4, 0.0);

    for (const auto&[name, weights] : data_weights) {
        double s = arithmetic_mean_compute(s_degrees, weights);
        double e = s - correct_s;
        double e_rel = (e / correct_s) * 100.0;

        cout << left << setw(15) << name
            << setw(12) << s
            << setw(12) << e
            << e_rel << "%" << endl;

        // Sum weights for point M calculation.
        for (int i = 0; i < 4; i++) {
            avg_weights[i] += weights[i];
        }
    }

    // Point M analysis (average weights)
    for (size_t i = 0; i < 4; i++) {
        avg_weights[i] /= static_cast<double>(data_weights.size());
    }
    double m = arithmetic_mean_compute(s_degrees, avg_weights);

    cout << "\n" << string(55, '-') << endl;
    cout << "Point M (Team Mean suitability): " << m << endl;
    cout << "Difference (M - S): " << m - correct_s << endl;

    return 0;
}
