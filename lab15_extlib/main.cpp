#include <iostream>
#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    std::cout << "Configuration Manager v1.0" << std::endl;
    
    // Sample JSON string: 
    std::string configData = R"({
        "app_name": "MyApplication",
        "version": "1.2.3", 
        "debug_mode": true,
        "max_connections": 100,
        "database": {
            "host": "localhost",
            "port": 5432
        }
    })";
    std::cout << "Raw config Data: " << std::endl;
    std::cout << configData << std::endl;
    
    // JSON parsing here
    try {
        json config = json::parse(configData);
        std::cout << "App name: " << config["app_name"] << std::endl;
        std::cout << "Version: " << config["version"] << std::endl;
        std::cout << "Debug mode: " << config["debug_mode"] << std::endl;
        std::cout << "Max connections: " << config["max_connections"] << std::endl;
        if (config.contains("database")) {
            std::cout << "Database Host: " << config["database"]["host"] << std::endl;
            std::cout << "Database Port: " << config["database"]["port"] << std::endl;
        }
    } catch(const json::exception& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
