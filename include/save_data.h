#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include <vector>
#include <string>
#include <functional>

using std::vector, std::string, std::function, std::pair;

void save(const vector<double>&, const vector<double>&, const string&);

void launch(double, const string&, const function<pair<vector<double>, vector<double>>()>&);

#endif //SAVE_DATA_H
