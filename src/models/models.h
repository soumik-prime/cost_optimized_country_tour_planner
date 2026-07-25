#ifndef MODELS_H
#define MODELS_H

#include<limits>
#include<string>
#include<vector>

const long long INF = std::numeric_limits<long long>::max()/4;

struct Edge {
    int to;
    long long cost;
    std::string mode;
};

struct RouteLeg {
    std::string from;
    std::string to;
    long long cost;
    std::vector<std::string> path;
    std::vector<std::string> segmentDescriptions;
};


#endif