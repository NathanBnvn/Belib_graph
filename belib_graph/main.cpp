#include <iostream>
#include <cjson/cJSON.h>
#include <gd.h>

using namespace std;

int main()
{

    FILE *fp = fopen("Documents/belib.json", "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    } else {
        cout << "File load" << endl;
    }


    cout << "Hello World!" << endl;
    return 0;
}
