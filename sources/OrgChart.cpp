#include "OrgChart.hpp"

using ariel::ChartNode;
using ariel::OrgChart;

OrgChart &OrgChart::add_root(const std::string &root)
{
    if (this->root == nullptr)
    {
        this->root = new ChartNode(root);
    }
    else
    {
        this->root->set_data(root);
    }
    return *this;
}

ChartNode *OrgChart::get_node(ChartNode *root, const std::string &title)
{
    if (root->get_data() == title)
    {
        return root;
    }
    else if (root->get_children().size() == 0)
    {
        return nullptr;
    }

    for (ChartNode *node : root->get_children())
    {
        ChartNode *result = get_node(node, title);
        if (result != nullptr)
        {
            return result;
        }
    }

    return nullptr;
}

OrgChart &OrgChart::add_sub(const std::string &parent, const std::string &subordinate)
{
    ChartNode *new_node = new ChartNode(subordinate);
    ChartNode *node = this->get_node(this->root, parent);
    if (node != nullptr)
    {
        node->add_child(new_node);
    }
    return *this;
}

OrgChart::level_order_iterator OrgChart::begin_level_order() { return OrgChart::level_order_iterator(*this); }

OrgChart::level_order_iterator OrgChart::end_level_order() { return OrgChart::level_order_iterator(OrgChart()); }

OrgChart::reverse_level_order_iterator OrgChart::begin_reverse_order() { return OrgChart::reverse_level_order_iterator(*this); }

OrgChart::reverse_level_order_iterator OrgChart::end_reverse_order() { return OrgChart::reverse_level_order_iterator(OrgChart()); }

OrgChart::preorder_iterator OrgChart::begin_preorder() { return OrgChart::preorder_iterator(*this); }

OrgChart::preorder_iterator OrgChart::end_preorder() { return OrgChart::preorder_iterator(OrgChart()); }

std::ostream &ariel::operator<<(std::ostream &out, ChartNode &node) { return out; }

std::ostream &ariel::operator<<(std::ostream &out, OrgChart &organization) { return out; }