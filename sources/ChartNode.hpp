#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace ariel
{
    class ChartNode;
    std::ostream &operator<<(std::ostream &out, const ChartNode &node);
} // namespace ariel

class ariel::ChartNode
{
private:
    std::string data;
    std::vector<ChartNode *> children;

public:
    // constructor destructor
    ChartNode(const std::string &data) : data(data) {}
    ~ChartNode()
    {
        for (ChartNode *child : this->children)
        {
            delete child;
        }
    }

    // friends
    friend std::ostream &ariel::operator<<(std::ostream &out, const ChartNode &node);

    // methods
    size_t size();
    std::string get_data();
    void set_data(const std::string &);
    std::vector<ChartNode *> get_children();
    void add_child(ChartNode *node);
};
