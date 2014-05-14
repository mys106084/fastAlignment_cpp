#ifndef DOCS_H
#define DOCS_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "split.h"
using namespace std;

class Docs
{
    public:
        Docs();
        virtual ~Docs();
        void Inputcorpus();
        void Inputdev();

        // Fixed URLS
        string url_e;
        string url_f;
        string url_dev_e;
        string url_dev_f;
        string url_dev_out;
        string url_dev_gold;
        //
        int sum_sentences;
        int sum_sentences_dev;
        int sum_e;
        int sum_f;
        //

        map < string, int > wordmap_e;
        map < string, int > wordmap_f;

        vector <int*>  sentences_e;
        vector <int*>  sentences_f;

        vector <int> lengths_e;
        vector <int> lengths_f;

        vector <int*>  sentences_dev_e;
        vector <int*>  sentences_dev_f;

        vector <int> lengths_dev_e;
        vector <int> lengths_dev_f;
    protected:
    private:
};

#endif // DOCS_H
