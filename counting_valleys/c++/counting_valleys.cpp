#include <iostream>
#include <string>
#include <vector>

int countingValleys(std::string path);

int main()
{
    std::vector<std::string> cases = {
        "UUDUDDDDUUUDDDDUUU",
        "DDDUUUDDDUUUUDDDUUU"
    };
    for(int i = 0; i < cases.size(); i++)
    {
        std::cout << "Number of valleys traversed: "
            << countingValleys(cases.at(i)) << std::endl;
    }
    return 0;
}

int countingValleys(std::string path)
{
    bool above = true;
    int pos = 0;
    int valleys = 0;
    for(int i = 0; i < path.length(); i++)
    {
        if(path[i] == 'U') { pos++; }
        else { pos--; }
        if((pos < 0) && above) { above = false; }
        else if((pos >= 0) && !above) {
            above = true;
            valleys++;
        }
    }
    return valleys;
}
