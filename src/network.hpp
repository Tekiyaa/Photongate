#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Node {
    std::string id;
    std::string name;
};

struct Link {
    std::string id;
    std::string source_id;
    std::string target_id
    double latency_ms;
    double qber = 0.02;

    double get_routing_cost() const{
        if(qber >= 0.11){
            return 999999.0;
        }
        return latency_ms * (1.0 +(qber * 10.0))
    }

    
};

class QKDRoutingEngine {
public:
    void add_node(const Node& node);
    void add_link(const Link& link);

    void injective_eve_attack(const std::string& link_id);

    std:vector<Link> get_links_from(const std::string& node_id);

private:
    std::unordered_map<std::string, Node> nodes;
    std::unordered_map<std::string, std::vector<Link>> adjacency_list;
    std::unordered_map<std::string, Link*> link_lookups;


};

#endif






