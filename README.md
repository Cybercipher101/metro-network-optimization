# 🚇 Dehradun Metro Network Optimization System

This project is a C++ application designed to simulate and optimize a proposed metro network for **Dehradun**, Uttarakhand. It enables users to explore stations, view metro connections, and calculate the shortest routes between stations using graph algorithms like **Dijkstra's Algorithm**. It also includes extensions for **Minimum Spanning Tree (MST)** and **Ford-Fulkerson Algorithm** for network efficiency and flow analysis.

---

## 📌 Project Objectives

- Model the Dehradun Metro using graph-based structures
- Help users find optimal routes in the network
- Optimize infrastructure with MST
- Analyze maximum flow using Ford-Fulkerson Algorithm

---

## 🧠 Features

- ✅ Load metro station connectivity from CSV
- ✅ Display available metro stations
- ✅ Show complete metro map with connections and distances
- ✅ Calculate shortest path (in distance) using Dijkstra’s Algorithm
- ✅ Modular and scalable code structure
- ✅ Compute **Minimum Spanning Tree (MST)** of the metro graph
- ✅ Estimate **maximum flow** using **Ford-Fulkerson Algorithm**
- 🔜 Future scope includes:
  - Real-time updates (delays, closures)
  - GUI-based visualization
  - Dynamic route adjustment during runtime

---

## 📁 Folder Structure

MetroNetworkOptimizationSystem/
│
├── data/ # Metro data
│ └── metro_map.csv # CSV with station connectivity and distances
│
├── include/ # Header files
│ ├── graph.h # Graph class & algorithms
│ └── metro_system.h # Route-finding and UI interface
│
├── src/ # Source code files
│ ├── main.cpp # Entry point and menu
│ ├── graph.cpp # Core graph logic (Dijkstra, MST, Ford-Fulkerson)
│ └── metro_system.cpp # Route handling and input/output logic
│
├── ui/ # Optional: CLI/GUI interface logic
│ └── ui.cpp
│
├── test/ # Test cases
│ └── test_cases.cpp
│
└── README.md
