#ifndef TOUR_PLANNER_H
#define TOUR_PLANNER_H

#include "../models/models.h"

#include <map>
#include <set>
#include <vector>
#include <string>

class TourPlanner
{
private:
    std::vector<std::string> cityName;
    std::map<std::string, int> cityId;
    std::vector<std::vector<Edge>> adj;
    std::vector<std::vector<long long>> directCost;
    std::vector<std::vector<std::string>> directMode;

    int getCityId(const std::string &name);
    void undirectedEdge(const std::string &from, 
                        const std::string &to, 
                        long long cost, 
                        std::string &mode);
    void rebuildAdjacencyList();

    std::vector<int> bfs(int start) const;
    std::vector<long long> dijkstra(int source, std::vector<int> &parent) const;
    std::vector<std::vector<long long>> floydWarshall() const;
    void articulationBridgeDfs( int u,
                                int parent,
                                int &timer,
                                std::vector<int> &visited,
                                std::vector<int> &discover,
                                std::vector<int> &low,
                                std::set<std::string> &articulationPoints,
                                std::vector<std::pair<std::string, std::string>> &bridge
                            );
    std::vector<std::string> reconstractPath(int source, int target, const std::vector<int>& parent) const;
    std::vector<std::string> describePathSegments(const std::vector<std::string> &path) const;

public:
    bool loadRoutes(const std::string &filename);
    bool loadTour(const std::string &filename, std::vector<int> &mustVisit);
    bool validateReachability(const std::vector<int> &mustVisit) const;
    bool solveTour(const std::vector<int> &mustVisit, std::vector<int> &bestOrder, std::vector<RouteLeg> &legs, long long &bestCost) const;
    void analyzeCriticalNetworkParts(std::set<std::string> &articulationPoints, std::vector<std::pair<std::string, std::string>> &bridges) const;
    void writeOutputs(const std::string &reportFile, const std::string &csvFile, const std::vector<int> &mustVisit, const std::vector<int> &order, const std::vector<RouteLeg> &legs, long long totalCost, const std::set<std::string> &articulationPoints, const std::vector<std::pair<std::string, std::string>> &bridges) const;

};

#endif