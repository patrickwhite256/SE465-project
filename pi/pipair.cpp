#include <iostream>
#include <string>

#include "parse.h"

using namespace std;

int main(int argc, char **argv){
    string line;
    bool nullNode = false;

    while(!cin.eof()){
        getline(cin, line);

        if(line.length() > 0){
            LineData *ld = new LineData(line);
            switch(ld->getLineType()) {
                case NODE:
                    nullNode = false;
                    cout << "Function " << ld->getFunctionName() << endl;
                    break;
                case CALL:
                    if(!nullNode){
                        cout << " calls " << ld->getFunctionName() << endl;
                    }
                    break;
                case NODE_NULL:
                    nullNode = true;
                    break;
            }
        }
    }
}
