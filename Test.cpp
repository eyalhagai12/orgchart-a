#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include <vector>

using namespace ariel;
using namespace std;

TEST_CASE("Level Order")
{
    OrgChart chart;
    chart.add_root("CEO")
        .add_sub("CEO", "CTO")
        .add_sub("CEO", "CCO")
        .add_sub("CTO", "COP")
        .add_sub("CCO", "CPK")
        .add_sub("CPK", "CTT");

    vector<string> titles = {"CEO", "CTO", "CCO", "COP", "CPK", "CTT"};
    size_t idx = 0;
    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); ++it)
    {
        CHECK_EQ((*it).get_data(), titles.at(idx));
        idx++;
    }

    CHECK_EQ(idx, 6);
}

TEST_CASE("Reverse Level Order")
{
    OrgChart chart;
    chart.add_root("CEO")
        .add_sub("CEO", "CTO")
        .add_sub("CEO", "CCO")
        .add_sub("CTO", "COP")
        .add_sub("CCO", "CPK")
        .add_sub("CPK", "CTT");

    vector<string> titles = {"CTT", "CPK", "COP", "CCO", "CTO", "CEO"};
    size_t idx = 0;
    for (auto it = chart.begin_reverse_order(); it != chart.end_reverse_order(); ++it)
    {
        CHECK_EQ((*it).get_data(), titles.at(idx));
        idx++;
    }
}

TEST_CASE("Preorder")
{
    OrgChart chart;
    chart.add_root("CEO")
        .add_sub("CEO", "CTO")
        .add_sub("CEO", "CCO")
        .add_sub("CTO", "COP")
        .add_sub("CCO", "CPK")
        .add_sub("CPK", "CTT");

    vector<string> titles = {"CEO", "CTO", "COP", "CCO", "CPK", "CTT"};
    size_t idx = 0;
    for (auto it = chart.begin_preorder(); it != chart.end_preorder(); ++it)
    {
        CHECK_EQ((*it).get_data(), titles.at(idx));
        idx++;
    }

    CHECK_EQ(idx, 6);
}

TEST_CASE("Change Root")
{
    OrgChart chart;
    chart.add_root("CEO")
        .add_sub("CEO", "CTO")
        .add_sub("CEO", "CCO")
        .add_sub("CTO", "COP")
        .add_sub("CCO", "CPK")
        .add_sub("CPK", "CTT");

    vector<string> titles = {"CEO", "CTO", "CCO", "COP", "CPK", "CTT"};
    size_t idx = 0;
    auto end = chart.end_level_order();
    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); ++it)
    {
        CHECK_EQ((*it).get_data(), titles.at(idx));
        idx++;
    }

    // change root
    chart.add_root("CCC");
    vector<string> titles2 = {"CCC", "CTO", "CCO", "COP", "CPK", "CTT"};
    idx = 0;
    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); ++it)
    {
        CHECK_EQ((*it).get_data(), titles2.at(idx));
        idx++;
    }
}