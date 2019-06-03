#ifndef csvwriter_h
#define csvwriter_h

#include <fstream>
#include <vector>

class CSVwriter {
    std::string fileName;
    std::string delimeter;
    int linesCount;
    
public:
    std::vector<std::string> algNames;
    
    CSVwriter(std::string filename, std::string delm = ",") :
    fileName(filename), delimeter(delm), linesCount(0)
    {}
    
    template<typename T>
    void addDatainRow(T first1, T last1, T first2, T first3, T first4, T first5);
};

template<typename T>
void CSVwriter::addDatainRow(T first1, T last1, T first2, T first3, T first4, T first5) {
    std::fstream file;
    file.open(fileName, std::ios::out | (linesCount ? std::ios::app : std::ios::trunc));
    //
    for (int i = 0; i < 5; ++i) {
        file << algNames[i];
        if (i != 4) {
            file << delimeter;
        }
    }
    file << std::endl;
    //
    while (first1 != last1) {
        file << *first1 << delimeter;
        file << *first2 << delimeter;
        file << *first3 << delimeter;
        file << *first4 << delimeter;
        file << *first5;
        //
        if (++first1 != last1) {
            file << std::endl;
            ++first2;
            ++first3;
            ++first4;
            ++first5;
        }
    }
    ++linesCount;
    file.close();
}

#endif /* csvwriter_h */


