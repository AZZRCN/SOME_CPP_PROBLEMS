#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    if(argc!=2){
        return 0;
    }
    string t = string(argv[1]);
    t.pop_back();
    t.pop_back();
    t.pop_back();
    string command = 
    string("")+
    "ffmpeg -i \""+
    argv[1]+
    "\" -c copy \""+
    t+
    "mp4\"";
    puts(command.c_str());
    system(command.c_str());
}