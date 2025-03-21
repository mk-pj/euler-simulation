#include "euler.h"
#include "save_data.h"

int main() {
    constexpr double step = 0.05;
    const string basic_pref = "basic";
    const string better_pref = "better";
                                       //m  x  y  vx vy
    const auto sim = new EulerSimulation(1, 0, 0, 5, 20);
    for (int i = 0; i <= 10; ++i) {
        const double k = 0.1*i;
        sim->set_k(k);
        launch(k, basic_pref, [&sim]() { return sim->basic_euler(step); });
        launch(k, better_pref, [&sim]() { return sim->better_euler(step); });
    }
    return 0;
}