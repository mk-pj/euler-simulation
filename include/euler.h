#ifndef EULER_H
#define EULER_H

#include <vector>

#define g (-9.81)
#define threshold 0.1

using std::vector, std::pair;

class EulerSimulation {
public:
    EulerSimulation(double, double, double, double, double, double=1.0);
    void set_k(double k);
    [[nodiscard]] double get_k() const;
    [[nodiscard]] pair<vector<double>, vector<double>> basic_euler(double, int=100000) const;
    [[nodiscard]] pair<vector<double>, vector<double>> better_euler(double, int=100000) const;
private:
    double k;
    double k_m;
    const double m;
    const double x0, y0;
    const double vx0, vy0;
};


#endif
