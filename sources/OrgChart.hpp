#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

#include "ChartNode.hpp"

namespace ariel
{
    class OrgChart;
    std::ostream &operator<<(std::ostream &out, OrgChart &organization);
} // namespace ariel

// this class would act like a tree data structure
class ariel::OrgChart
{
private:
    ChartNode *root;
    ChartNode *get_node(ChartNode *root, const std::string &title);

public:
    // constructor and destructor
    OrgChart() : root(nullptr) {}
    ~OrgChart() {}

    // iterators
    // --------------------------------------------------------------------
    class level_order_iterator
    {
    private:
        const OrgChart &container;
        ChartNode *node;
        std::queue<ChartNode *> node_queue;

    public:
        // constructor destructor
        level_order_iterator(const OrgChart &organization) : container(organization),
                                                             node_queue(std::queue<ChartNode *>()),
                                                             node(organization.root)
        {
            if (node != nullptr)
            {
                for (ChartNode *child : this->node->get_children())
                {
                    this->node_queue.push(child);
                }
            }
        }
        ~level_order_iterator() {}

        // operations
        bool operator!=(const level_order_iterator &other) const;
        void operator++();
        ChartNode *operator->() const;
        ChartNode &operator*() const;
    };

    // --------------------------------------------------------------------
    class reverse_level_order_iterator
    {
    private:
        const OrgChart &container;
        ChartNode *node;

    public:
        // constructor destructor
        reverse_level_order_iterator(const OrgChart &organization) : container(organization),
                                                               node(organization.root)
        {
        }
        ~reverse_level_order_iterator() {}

        // operations
        bool operator!=(const reverse_level_order_iterator &) const;
        void operator++();
        ChartNode *operator->() const;
        ChartNode &operator*() const;
    };

    // --------------------------------------------------------------------
    class preorder_iterator
    {
    private:
        const OrgChart &container;
        ChartNode *node;
        std::stack<ChartNode *> node_stack;

    public:
        // constructor destructor
        preorder_iterator(const OrgChart &organization) : container(organization),
                                                    node(organization.root),
                                                    node_stack(std::stack<ChartNode *>())
        {
            this->node_stack.push(nullptr);
            if (node != nullptr)
            {
                std::vector<ChartNode *> reverse_list = node->get_children();
                std::reverse(reverse_list.begin(), reverse_list.end());
                for (ChartNode *child : reverse_list)
                {
                    node_stack.push(child);
                }
            }
        }
        ~preorder_iterator() {}

        // operations
        bool operator!=(const preorder_iterator &other) const;
        void operator++();
        ChartNode *operator->() const;
        ChartNode &operator*() const;
    };

    friend class level_order_iterator;
    friend class reverse_level_order_iterator;
    friend class preorder_iterator;
    // --------------------------------------------------------------------

    // methods
    ariel::OrgChart &add_root(const std::string &);                     // add a new root to the chart
    ariel::OrgChart &add_sub(const std::string &, const std::string &); // add a subordinate to someomne in the chart
    level_order_iterator begin_level_order();                           // get the beginning an iterator for level order passage
    level_order_iterator end_level_order();                             // get the ending of an iterator for level order passage
    reverse_level_order_iterator begin_reverse_order();                 // get the beginning an iterator for reverse level order passage
    reverse_level_order_iterator end_reverse_order();                   // get the ending an iterator for reverse level order passage
    preorder_iterator begin_preorder();                                 // get the beginning an iterator for preorder passage
    preorder_iterator end_preorder();                                   // get the ending an iterator for preorder passage

    // operators
    friend std::ostream &ariel::operator<<(std::ostream &out, OrgChart &organization); // override << operator
};
