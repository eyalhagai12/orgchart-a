#include "OrgChart.hpp"
#include "ChartNode.hpp"

using ariel::ChartNode;
using ariel::OrgChart;

std::string s1 = "";
ChartNode def(s1);

// level order iterator
bool OrgChart::level_order_iterator::operator!=(const level_order_iterator &other) const
{
    return this->node != other.node;
}
void OrgChart::level_order_iterator::operator++()
{
    this->node = this->node_queue.front();
    this->node_queue.pop();

    if (this->node != nullptr)
    {
        for (ChartNode *child : this->node->get_children())
        {
            this->node_queue.push(child);
        }
    }
}
ChartNode *OrgChart::level_order_iterator::operator->() const { return this->node; }
ChartNode &OrgChart::level_order_iterator::operator*() const { return *this->node; }

// reverse level order iterator
bool OrgChart::reverse_level_order_iterator::operator!=(const reverse_level_order_iterator &other) const { return false; }
void OrgChart::reverse_level_order_iterator::operator++() {}
ChartNode *OrgChart::reverse_level_order_iterator::operator->() const { return &def; }
ChartNode &OrgChart::reverse_level_order_iterator::operator*() const { return def; }

// preorder iterator
bool OrgChart::preorder_iterator::operator!=(const preorder_iterator &other) const { return this->node != other.node; }
void OrgChart::preorder_iterator::operator++()
{
    this->node = this->node_stack.top();
    this->node_stack.pop();

    if (this->node != nullptr)
    {
        std::vector<ChartNode *> reverse_list = this->node->get_children();
        std::reverse(reverse_list.begin(), reverse_list.end());
        for (ChartNode *child : reverse_list)
        {
            this->node_stack.push(child);
        }
    }
}
ChartNode *OrgChart::preorder_iterator::operator->() const { return this->node; }
ChartNode &OrgChart::preorder_iterator::operator*() const { return *this->node; }