//attributes-parser

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    cin.ignore();
    map<string, string> attr;
    vector<string> tag_stack;
    while(n--) {
        string tags;
        getline(cin, tags);
        if(tags[1] == '/') {
            tag_stack.pop_back();
        } else {
            int i = 1;
            string tag_name;
            while(i < tags.size() && tags[i] != ' ' && tags[i] != '>') {
                tag_name += tags[i];
                i++;
            }
            tag_stack.push_back(tag_name);
            string full_tag;
            for(int j = 0; j < tag_stack.size(); j++) {
                if(j > 0) full_tag += ".";
                full_tag += tag_stack[j];
            }
            while(i < tags.size() && tags[i] != '>') {
                while(i < tags.size() && tags[i] == ' ') i++;
                string attr_name, attr_value;
                while(i < tags.size() && tags[i] != ' ' && tags[i] != '=' && tags[i] != '>') {
                    attr_name += tags[i];
                    i++;
                }
                while(i < tags.size() && (tags[i] == ' ' || tags[i] == '=' || tags[i] == '\"')) i++;
                while(i < tags.size() && tags[i] != '\"' && tags[i] != '>') {
                    attr_value += tags[i];
                    i++;
                }
                while(i < tags.size() && (tags[i] == '\"' || tags[i] == ' ')) i++;
                if(!attr_name.empty()) {
                    attr[full_tag + "~" + attr_name] = attr_value;
                }
            }
        }
    }
    // Xử lý q truy vấn
    while(q--) {
        string query;
        getline(cin, query);
        if(attr.find(query) != attr.end()) {
            cout << attr[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
