#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json loadConfigFromFile(const std::string& filename) {
    json config;
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        throw std::runtime_error("Could not open config file: " + filename);
    }
    configFile >> config;
    configFile.close(); // always close stream after use
    return config;
}

int main() {
    std::cout << "Configuration Manager v2.0" << std::endl;
    try {
        // Create sample config file
        std::ofstream configFile("config.json");
        configFile << R"({
            "app_name": "FileBasedApp",
            "version": "2.0.0",
            "debug_mode": false,
            "max_connections": 200,
            "features": ["logging", "caching", "monitoring"]
        })";
        configFile.close();
        // Load and display configuration
        json config = loadConfigFromFile("config.json");
        std::cout << "\n=== Configuration from File ===" << std::endl;
        std::cout << "App Name: " << config["app_name"] << std::endl;
        std::cout << "Version: " << config["version"] << std::endl;
        std::cout << "Debug Mode: " << config["debug_mode"] << std::endl;
        std::cout << "Max Connections: " << config["max_connections"] << std::endl;
        std::cout << "Features: ";
        for (const auto& feature : config["features"]) {
            std::cout << feature << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
