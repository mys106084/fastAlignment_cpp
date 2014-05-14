#include "Docs.h"

Docs::Docs()
{
    //url_e="data//corpus.en";
    //url_f="data//corpus.es";
    url_e="data//corpus_full.en";
    url_f="data//corpus_full.es";
    url_dev_e="data//dev.en";
    url_dev_f="data//dev.es";

    url_dev_out="data//dev.out";
    url_dev_gold="data//dev.key";

}

Docs::~Docs()
{
    //dtor
}


void Docs::Inputcorpus()
{
    sum_sentences=0;

    string line;
    vector <string> words;
    const char* urle = url_e.c_str();

    ifstream fin_e(urle);
    while(!fin_e.eof())
    {
        getline(fin_e,line);
        split( words, line, " " );
        int *p_tmp = new int[words.size()]; // define a corresponding length pointer
        sentences_e.push_back(p_tmp);
        lengths_e.push_back(words.size());
        for(int i=0;i<words.size();i++)
        {
            wordmap_e.insert(make_pair(words[i],wordmap_e.size())); //C++ will ignore the later same value
            sentences_e.back()[i] = wordmap_e[words[i]];
        }
        sum_sentences++;
        if (sum_sentences==1000000)
            break;
    }
    sum_sentences=0;
    const char* urlf = url_f.c_str();
    ifstream fin_f(urlf);
    while(!fin_f.eof())
    {
        getline(fin_f,line);
        split( words, line, " " );
        int *p_tmp = new int[words.size()];
        sentences_f.push_back(p_tmp);
        lengths_f.push_back(words.size());
        for(int i=0;i<words.size();i++)
        {
            wordmap_f.insert(make_pair(words[i],wordmap_f.size())); //C++ will ignore the later same value
            sentences_f.back()[i] = wordmap_f[words[i]];
        }
        sum_sentences++;
        if (sum_sentences==1000000)
            break;
    }

    sum_e = wordmap_e.size();
    sum_f = wordmap_f.size();

    cout<<"Sentences:"<<sum_sentences<<endl;
    cout<<"f Words:"<<sum_f<<endl;
    cout<<"e Words:"<<sum_e<<endl;
}

void Docs::Inputdev()
{
    string line;
    vector <string> words;

    sum_sentences_dev=0;
    const char* urldeve = url_dev_e.c_str();
    ifstream fin_e(urldeve);
    while(!fin_e.eof())
    {
        getline(fin_e,line);
        split( words, line, " " );
        int *p_tmp = new int[words.size()]; // define a corresponding length pointer
        sentences_dev_e.push_back(p_tmp);
        lengths_dev_e.push_back(words.size());
        for(int i=0;i<words.size();i++)
        {
            // if words[i] not in wordmap_e[], the value will be 0, so we don't have to do judgement
            wordmap_e.insert(make_pair(words[i],-2));
            sentences_dev_e.back()[i] = wordmap_e[words[i]];
        }
        sum_sentences_dev++;
    }

    const char* urldevf = url_dev_f.c_str();
    ifstream fin_f(urldevf);
    while(!fin_f.eof())
    {
        getline(fin_f,line);
        split( words, line, " " );
        int *p_tmp = new int[words.size()]; // define a corresponding length pointer
        sentences_dev_f.push_back(p_tmp);
        lengths_dev_f.push_back(words.size());
        for(int i=0;i<words.size();i++)
        {
            // if words[i] not in wordmap_e[], the value will be 0, so we don't have to do judgement
            wordmap_f.insert(make_pair(words[i],-2));
            sentences_dev_f.back()[i] = wordmap_f[words[i]];
        }
    }


}

/*
int main()
{
    Docs docs;
    docs.Inputcorpus();

    return 1;
}
*/
