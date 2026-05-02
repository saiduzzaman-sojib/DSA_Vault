#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// =========================================================
// PART 1: HEADERS & PROTOTYPES (Member 1)
// =========================================================

// Helper Functions
double transform_x(double t, double a, double b);
double scale_weight(double w, double a, double b);

// Gaussian Algorithms
double solve_gauss_2(function<double(double)> f, double a, double b);
double solve_gauss_3(function<double(double)> f, double a, double b);
double solve_gauss_4(function<double(double)> f, double a, double b);

// Comparison Algorithms
double solve_trapezoidal(function<double(double)> f, double a, double b, int n);
double solve_simpson(function<double(double)> f, double a, double b, int n);

// Math & Data
double target_function(double x);
double exact_solution(double a, double b);
void log_results(const string& filename, const vector<string>& methods, const vector<double>& errors);

// =========================================================
// PART 2: HELPER UTILITIES (Member 2)
// =========================================================
// Maps standard interval [-1, 1] to user's interval [a, b]

double transform_x(double t, double a, double b) {
    return ((b - a) * t + (b + a)) / 2.0;
}

double scale_weight(double sum, double a, double b) {
    // Scale the final integral by (b-a)/2
    return ((b - a) / 2.0) * sum;
}

// =========================================================
// PART 3: 2-POINT GAUSSIAN (Member 3)
// =========================================================
double solve_gauss_2(function<double(double)> f, double a, double b) {
    const double t = 0.577350269; // 1/sqrt(3)
    const double w = 1.0;

    double sum = w * f(transform_x(-t, a, b)) + 
                 w * f(transform_x(t, a, b));

    return scale_weight(sum, a, b);
}

// =========================================================
// PART 4: 3-POINT GAUSSIAN (Member 4)
// =========================================================
double solve_gauss_3(function<double(double)> f, double a, double b) {
    const double t1 = 0.0; 
    const double t2 = 0.774596669; // sqrt(3/5)
    
    const double w1 = 0.888888889; // 8/9
    const double w2 = 0.555555556; // 5/9

    double sum = w1 * f(transform_x(t1, a, b)) +
                 w2 * f(transform_x(-t2, a, b)) +
                 w2 * f(transform_x(t2, a, b));

    return scale_weight(sum, a, b);
}

// =========================================================
// PART 5: 4-POINT GAUSSIAN (Member 5)
// =========================================================
double solve_gauss_4(function<double(double)> f, double a, double b) {
    const double t1 = 0.339981044; const double w1 = 0.652145155;
    const double t2 = 0.861136312; const double w2 = 0.347854845;

    double sum = w1 * f(transform_x(-t1, a, b)) + w1 * f(transform_x(t1, a, b)) +
                 w2 * f(transform_x(-t2, a, b)) + w2 * f(transform_x(t2, a, b));

    return scale_weight(sum, a, b);
}

// =========================================================
// PART 6: TRAPEZOIDAL RULE (Member 6)
// =========================================================
double solve_trapezoidal(function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        sum += 2.0 * f(a + i * h);
    }

    return (h / 2.0) * sum;
}

// =========================================================
// PART 7: SIMPSON'S RULE (Member 7)
// =========================================================
double solve_simpson(function<double(double)> f, double a, double b, int n) {
    if (n % 2 != 0) n++; 
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2.0 * f(a + i * h);
        else
            sum += 4.0 * f(a + i * h);
    }

    return (h / 3.0) * sum;
}

// =========================================================
// PART 8: TEST FUNCTIONS (Member 8)
// =========================================================
// Target: x * e^x
double target_function(double x) {
    return x * exp(x);
}

// Exact Solution: e^x * (x - 1)
double exact_solution(double a, double b) {
    double F_b = exp(b) * (b - 1.0);
    double F_a = exp(a) * (a - 1.0);
    return F_b - F_a;
}

// =========================================================
// PART 9: DATA LOGGER (Member 9)
// =========================================================
void log_results(const string& filename, const vector<string>& methods, const vector<double>& errors) {
    ofstream file(filename);
    
    if (file.is_open()) {
        file << "Method,Error\n"; 
        for (size_t i = 0; i < methods.size(); ++i) {
            file << methods[i] << "," << errors[i] << "\n";
        }
        file.close();
        cout << "\n[Success] Analysis exported to " << filename << endl;
    } else {
        cerr << "[Error] Could not open file for writing." << endl;
    }
}

// =========================================================
// PART 10: MAIN DRIVER (Member 10)
// =========================================================
int main() {
    cout << "=== Gaussian Quadrature Project (Group B3) ===" << endl;

    // 1. Setup
    double a = 0.0;
    double b = 1.5;
    
    // 2. Exact Value
    double exact = exact_solution(a, b);
    cout << "Integrating x*e^x from " << a << " to " << b << endl;
    cout << "Exact Integral Value: " << exact << "\n" << endl;

    // 3. Compute Approximations
    double g2 = solve_gauss_2(target_function, a, b);
    double g3 = solve_gauss_3(target_function, a, b);
    double g4 = solve_gauss_4(target_function, a, b);
    double trap = solve_trapezoidal(target_function, a, b, 4);
    double simp = solve_simpson(target_function, a, b, 4);

    // 4. Store Data
    vector<double> results = {g2, g3, g4, trap, simp};
    vector<double> errors = {
        abs(g2 - exact), abs(g3 - exact), abs(g4 - exact),
        abs(trap - exact), abs(simp - exact)
    };
    vector<string> names = {"Gauss-2", "Gauss-3", "Gauss-4", "Trapezoidal", "Simpson"};

    // 5. Print Table
    cout << left << setw(15) << "Method" << " | " << "Result" << " | " << "Error" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for(size_t i = 0; i < names.size(); i++) {
        cout << left << setw(15) << names[i] 
             << " | " << setw(10) << setprecision(6) << results[i] 
             << " | " << scientific << errors[i] << defaultfloat << endl;
    }

    // 6. Save for Graphs
    log_results("results.csv", names, errors);

    // Keep console open (optional)
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
