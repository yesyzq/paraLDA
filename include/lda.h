//
// Created by CHEN HU on 4/23/17.
//

#ifndef PARALDA_LDA_H
#define PARALDA_LDA_H


#include <string>
#include <vector>
#include <random>
#include <mpi.h>
#include "dataLoader.h"
#include "Communicator.h"

class lda {
    int num_topics;
    int num_docs;
    int vocab_size;
    double alpha;
    double beta;
    int num_iterations;
    dataLoader* data_loader;
    int memory_size;
    int* local_table_memory;
    int* global_table_memory[2];
    int* local_topic_table;
    int* global_topic_table[2];
    int** local_word_topic_table;
    int** global_word_topic_table[2];
    int** doc_topic_table;
    std::vector<std::vector<int>> W;
    std::vector<std::vector<int>> T;
    std::string output;

    int current;

    MPI_Comm MPI_COMM_WORKER;

    double* vocab_temp;
    double* topic_temp;

    int rank;
    int comm_size;
    int master_count;

    Communicator *communicator;

    std::mt19937 gen;
    std::uniform_real_distribution<double> dis;



public:
    lda(std::string dataFile, std::string output, int num_topics,
        double alpha, double beta, int num_iterations, int rank, int comm_size, int master_count, MPI_Comm MPI_COMM_WORKER);
    ~lda();
    void initialize();
    void runGibbs();
    int resample(std::vector<double> multi_dis);
    int resample(std::vector<double> multi_dis, double prob);
    double getLocalLogLikelihood();
    double getGlobalLogLikelihood();
    double logDirichlet(double* X, int N);
    double logDirichlet(double x, int N);
    void printTopicWord();
    void printDocTopic();

};


#endif //LDA_LDA_H
