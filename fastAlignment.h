#ifndef FASTALIGNMENT_H
#define FASTALIGNMENT_H
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Docs.h"
#include <fstream>
#include <cmath>
using namespace std;

class fastAlignment
{
    public:
        int iterations;
        int iter;
        double infinitesimal;
        int sum_sentences;
        int sum_sentences_dev;


        // Tuning Paremeters
        double nullprob;
        double dirT;
        double lamb;

        double emp_feat;
        double mode_feat;

        map < int, double> count_e;
        vector<map < int, double> >  count_fe;

        vector<map < int, double> > prob_t;

        // Docs Object
        Docs docs;

        // Functionsw
        fastAlignment();
        virtual ~fastAlignment();

        double GetT(int &i,int j);
        double GetQ(const unsigned i, const unsigned j, const unsigned l, const unsigned m,double z);
        void UpdateCounts();
        void UpdateCountsInit();
        void Increment(int &i,int j, double delta);
        void Increment(int j, double delta);
        void ComputeT();
        void ComputeLambda();
        void EM();
        void DEV();

        double arithmetico_geometric_series(const double a_1, const double g_1, const double r, const double d, const unsigned n);
        double ComputeZ(const unsigned i, const unsigned l, const unsigned m, const double alpha);
        double UnnormalizedProb(const unsigned i, const unsigned j, const unsigned l, const unsigned m, const double alpha);
        double Feature(const unsigned i, const unsigned j, const unsigned l, const unsigned m);


    protected:
    private:
};

#endif // FASTALIGNMENT_H
