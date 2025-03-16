#include <stdexcept>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <functional>
#include <fmt/ranges.h>
#include "save_data.h"

inline void save(const vector<double> &x, const vector<double> &y, const string &name) {
    if (x.size() != y.size())
        throw std::runtime_error("save(): size mismatch");
    std::stringstream ss;
    for (int i = 0; i < x.size(); i++)
        ss << x[i] << "," << y[i] << '\n';
    std::filesystem::create_directories("../data_output");
    std::fstream file("../data_output/" + name, std::ios::out | std::ios::trunc);
    file << ss.str();
}

void launch(const double k, const string& pref, const function<pair<vector<double>, vector<double>>()> &func) {
    auto [fst, snd] = func();

    fmt::println("len = {} {}", fst.size(),  fst);
    fmt::println("len = {} {}", snd.size(), snd);

    const string k_string = fmt::format("{:.1f}", k);
    const string title = pref + "_k=" + k_string + ".csv";

    save(fst, snd, title);
}