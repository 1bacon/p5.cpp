#include <iostream>
#include <utility>
#include <functional>

#include "p5/p5.hpp"

using namespace p5;

#include <map>


class MainWindow : public PApplet
{
public:
    void start()
    {

        std::vector<std::string> s = {{"a", "b", "c", "d"}};

        StringList m = StringList{VectorIterator<std::string>(s)};

        std::cout << m.getUnique().toString() << "\n";

        // Iterator<std::pair<std::string, int>> i = mk_i(m);

        // i.forEachRemaining( [](const std::pair<std::string, float> &p)
        //                     { std::cout << p.first << ": " << p.second << "\n"; });

        // l.insert(0, List<int>({66,77,88}));
    }
};



int main()
{

    MainWindow p;
    p.start();
    return 0;
}