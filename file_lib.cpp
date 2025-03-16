

#include <bits/stdc++.h>
using std::vector;
using std::string;


typedef struct File
{
    vector<vector<string>> allRows;
    vector<int> shape;
    int size;


    void stripLine(string rawLine);
    vector<string> splitLine(string rawLine, string delim);
    void readCSV(string fileName);

} File;


void File :: stripLine(string rawLine)
{
    rawLine[strcspn(rawLine.c_str(), "\r\n")]  = 0;
    return;
}


vector<string> File :: splitLine(string rawLine, string delim)
{

    char* token;
    vector<string> splitVector;
    token = strtok(rawLine.data(), delim.c_str());
    while(token != NULL)
    {
        string buff = token;
        stripLine(buff);
        splitVector.push_back(buff);
        token = strtok(NULL, delim.c_str());
    }

    return splitVector;
}


void File :: readCSV(string fileName)
{
    std::ifstream userFile;
    userFile.open(fileName);
    string lineBuffer;
    string delimeter = ",";
    while(std::getline(userFile, lineBuffer))
    {
        stripLine(lineBuffer);
        vector<string> splitBuffer = splitLine(lineBuffer, delimeter);
        allRows.push_back(splitBuffer);
    }

    userFile.close();
    return;
}