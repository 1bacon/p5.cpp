#pragma once

#include <string>
#include "p5/data/Dict.t.hpp"
#include "p5/data/List.t.hpp"

namespace p5
{

    typedef List<std::string> StringList;
    typedef List<float> FloatList;
    typedef List<double> DoubleList;
    typedef List<int> IntList;
    typedef List<long> LongList;

    typedef Dict<std::string, std::string> StringDict;
    typedef Dict<std::string, float> FloatDict;
    typedef Dict<std::string, double> DoubleDict;
    typedef Dict<std::string, int> IntDict;
    typedef Dict<std::string, long> LongDict;



}