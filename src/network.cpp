#include "network.hpp"
#include <iostream>

void QKDRoutingEngine::add_node(const Node& node) {
    nodes[node.id] = node;
    std::cout << "[C++] Knoten registriert: " << node.name << std::endl;
}

void QKDRoutingEngine::add_link(const Link& link) {
    adjacency_list[link.source_id].push_back(link);
    Link& inserted_link = adjacency_list[link.source_id].back();
    link_lookups[link.id] = &inserted_link;
    std::cout << "[C++] Laser-Link verknüpft: " << link.id << std::endl;
}

void QKDRoutingEngine::inject_eve_attack(const std::string& link_id) {
    if (link_lookups.find(link_id) != link_lookups.end()) {
        link_lookups[link_id]->qber = 0.15; // Fehlerrate auf 15% hochjagen
        std::cout << "[WARNUNG] Eve-Angriff auf Link injiziert: " << link_id << std::endl;
    };
}

std::vector<Link> QKDRoutingEngine::get_links_from(const std::string& node_id) {
    if (adjacency_list.find(node_id) != adjacency_list.end()) {
        return adjacency_list[node_id];
    }
    return std::vector<Link>();
}
