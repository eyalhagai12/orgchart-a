#include <iostream>
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

int main(int argc, char const *argv[])
{
    OrgChart chart;
    chart.add_root("CEO")
        .add_sub("CEO", "CTO");
    return 0;
}
