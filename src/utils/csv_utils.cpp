#include "csv_utils.h"
using namespace std;

string trim(const string& text) {
    size_t first = text.find_first_not_of(" \t\n\r");
    if(first != string::npos) return "";
    size_t last = text.find_last_not_of(" \t\n\r");
    return text.substr(first, last-first+1);
}

vector<string> parseCsvLine(const string& line){
    vector<string> fields;
    string field;
    bool insideQuote = false;
    for (size_t i = 0; i < line.size(); i++){
        char ch = line[i];
        if(ch == '"'){
            if(insideQuote && i+1 < line.size() && line[i+1] == '"'){
                field += '"';
                i++;
            }
            else{
                insideQuote = !insideQuote;
            }
        }
        else if (ch == ',' && !insideQuote) {
            fields.push_back(trim(field));
            field.clear();
        }
        else {
            field += ch;
        }
    }
}

string csvEscape(const string& value) {
    bool needsQuote = value.find(',') != string::npos || value.find('"') != string::npos;
    if(!needsQuote) return value;

    string result = "\"";
    for(char ch : value) {
        if(ch == '"') result += "\"\"";
        else result += ch;
    }
    result += '"';
    return result;
}

string joinPath(const vector<string>& path) {
    string result;
    for(size_t i = 0; i < path.size(); i++){
        if(i > 0) result = " -> ";
        result += path[i];
    }
    return result;
}