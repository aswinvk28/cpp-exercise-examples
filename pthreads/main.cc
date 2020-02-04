#include <pthreads.h>


struct ThreadData {
    std::vector<float> sum;
    int m;
};
struct ThreadParams {
    long n;
    long m;
    int NUM_THREADS;
    struct ThreadData * thread_data;
    int num_split;
    int features;
    int feature;
    int parameter;
    int ratio;
    float* data;
} thread_params;

void create_multithread_series_def(int ratio, int parameter, int features, pthread_t* thr, ThreadParams *thread_params) {
    thread_params->parameter = parameter;
    thread_params->ratio = ratio;
    int i = 1;
    while(i <= features) {
        thread_params->feature = i;
        pthread_create(&thr[i], NULL, create_thread_def_ratio_data, (void*) thread_params);
        create_thread_def_ratio_data((void*) thread_params);
        i++;
    }
    i = 1;
    int result;
    while(i <= features) {
        result = pthread_join(thr[i], NULL);
        printf("Result thread no. %d: value %d \t", i, result);
        i++;
    }
    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {

    // main code

    int num_threads = 64;
    
    pthread_t thr[num_threads];

}