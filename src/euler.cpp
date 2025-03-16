#include "euler.h"

EulerSimulation::EulerSimulation(
    const double m,
    const double x0,
    const double y0,
    const double vx0,
    const double vy0,
    const double k
) : k(k), m(m), x0(x0),
    y0(y0), vx0(vx0), vy0(vy0)
{
    this->k_m = k/m;
}

pair<vector<double>, vector<double> > EulerSimulation::basic_euler(double dt, const int max_iter) const {
    double x = this->x0;
    double y = this->y0;
    vector<double> X { x }, Y { y };
    double vx = this->vx0;
    double vy = this->vy0;
    double ax = -1 * this->k_m * this->vx0;
    double ay = g - this->k_m * this->vy0;
    for (int iter = 0; iter < max_iter; ++iter) {
        vx = vx + ax * dt;
        vy = vy + ay * dt;
        x = x + vx * dt;
        y = y + vy * dt;
        if (y < 0) {
            double lastY = Y[Y.size()-1];
            if (lastY > threshold) {
                vx -= ax * dt;
                vy -= ay * dt;
                x = X[X.size()-1];
                y = lastY;
                dt *= 0.1;
                if (dt < 1e-6) dt = 1e-6;
                continue;
            }
            break;
        }
        X.push_back(x);
        Y.push_back(y);
        ax = -1 * this->k_m * vx;
        ay = g - this->k_m * vy;
    }
    return pair { X, Y };
}

pair<vector<double>, vector<double>> EulerSimulation::better_euler(double dt, const int max_iter) const {
    double x = this->x0;
    double y = this->y0;
    vector<double> X { x }, Y { y };
    double vx = this->vx0;
    double vy = this->vy0;
    double ax = -1 * this->k_m * this->vx0;
    double ay = g - this->k_m * this->vy0;
    double ax_dt_2 = ax;
    double ay_dt_2 = ay;
    const double dt_2 = dt/2;
    for (int iter = 0; iter < max_iter; ++iter) {
        const double vx_dt_2 = vx + ax * dt_2;
        const double vy_dt_2 = vy + ay * dt_2;
        x = x + vx_dt_2 * dt;
        y = y + vy_dt_2 * dt;
        if (y < 0) {
            double lastY = Y[Y.size()-1];
            if (lastY > threshold) {
                vx -= ax_dt_2 * dt;
                vy -= ay_dt_2 * dt;
                x = X[X.size()-1];
                y = lastY;
                dt *= 0.1;
                if (dt < 1e-6) dt = 1e-6;
                continue;
            }
            break;
        }
        X.push_back(x);
        Y.push_back(y);
        ax_dt_2 = -1 * this->k_m * vx_dt_2;
        ay_dt_2 = g - this->k_m * vy_dt_2;
        vx = vx + ax_dt_2 * dt;
        vy = vy + ay_dt_2 * dt;
        ax = -1 * this->k_m * vx;
        ay = g - this->k_m * vy;
    }
    return pair { X, Y };
}

void EulerSimulation::set_k(const double k) {
    this->k = k;
    this->k_m = k/this->m;
}

double EulerSimulation::get_k() const {
    return this->k_m;
}
