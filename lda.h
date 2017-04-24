//
// Created by CHEN HU on 4/23/17.
//

#ifndef LDA_LDA_H
#define LDA_LDA_H


#include <string>
#include <vector>
#include "dataLoader.h"

class lda {
    int num_topics;
    int num_docs;
    int vocab_size;
    double alpha;
    double beta;
    int num_iterations;
    dataLoader* data_loader;
    int* topic_table;
    int** topic_word_table;
    int** doc_topic_table;
    std::vector<std::vector<int>*> W;
    std::vector<std::vector<int>*> T;

    std::mt19937 gen;
    std::uniform_real_distribution<double> dis;


public:
    lda(std::string dataFile, int num_topics, double alpha, double beta, int num_iterations);
    ~lda();
    void initialize();
    void runGibbs();
    int resample(std::vector<double> dis);

};


#endif //LDA_LDA_H