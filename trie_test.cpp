//
// Created by Dipayan Bhattacharya on 2/16/17.
//

#include "trie.hpp"
#include <fstream>
#include <vector>

using namespace std;


void test1() {
    string words[10] = { "public",
                         "pubic",
                         "crane",
                         "cranium",
                         "bland",
                         "blonde",
                         "black",
                         "block",
                         "cost",
                         "costco" };
    Trie trie;
    for(auto word : words) {
        trie.insert(word);
    }

    cout<<"Search result for public : " << (trie.search("public") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"Search result for pubic : " << (trie.search("pubic") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"Search result for cost : " << (trie.search("cost") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"Search result for cos : " << (trie.search("cos") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"Search result for blandy : " << (trie.search("blandy") ? "FOUND" : "NOT FOUND") << endl;
    cout<<endl;
    cout<<"StartsWith result for public : " << (trie.startsWith("public") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"StartsWith result for pub : " << (trie.startsWith("pub") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"StartsWith result for cost : " << (trie.startsWith("cost") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"StartsWith result for cos : " << (trie.startsWith("cos") ? "FOUND" : "NOT FOUND") << endl;
    cout<<"StartsWith result for blandy : " << (trie.startsWith("blandy") ? "FOUND" : "NOT FOUND") << endl;

    vector<string> allWords = trie.getAllWordsInTrie();
    for(string word : allWords) {
        cout<<"Got : \""<<word<<"\""<<endl;
    }
}

void test2(std::string dict_path) {
    ifstream input_file(dict_path);
    Trie trie;
    string line;
    vector<string> wordsList;
    while(getline(input_file, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        bool canInsert = true;
        for(char c : line) {
            if(c < 97 || c > 122) {
                canInsert = false;
                break;
            }
        }
        if(canInsert) {
            wordsList.push_back(line);
        } else {
            cout<<"Skipping "<<line<<endl;
        }
    }
    for(string word : wordsList) {
        trie.insert(word);
    }
    cout<<"The trie is occupying "<<trie.get_mem_size()<<" bytes of memory"<<endl;
}

int main(int argc, char *argv[]) {
    test1();
//    test2("/usr/share/dict/web2");
    return 0;
}
