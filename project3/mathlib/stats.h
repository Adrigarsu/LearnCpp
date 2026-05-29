//
// Created by adrig on 26/05/2026.
//

#ifndef LEARNC_STATS_H
#define LEARNC_STATS_H


class stats {
public:
    double mean(double * values[], int size) ;
    double median(double * values[], int size) ;
    double std_deviation(double * values[], int size);
};


#endif //LEARNC_STATS_H