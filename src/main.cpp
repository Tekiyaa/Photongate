#include "network.hpp"
#include <iostream>

int main() {
    std::cout << "---Project PhotonGate: Engine loaded ---" << std::endl;

    QKDRoutingEngine engine;

    Node n1{"station-berlin", "Berlin OGS"};
    engine.add_node(n1);

    std::cout << "C++ kernel successfully initialized" << std::endl;
    return 0;
}