#include "PmergeMe.hpp"

double get_Current_Time() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (ts.tv_sec * 1e6 + ts.tv_nsec / 1e3);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./PmergeMe <N1> <N2> ... <Nn>" << std::endl;
        return 0;
    }
    
    PmergeMe_t pmergeme;
    pmergeme.arr = NULL;
    pmergeme.size = 0;
    try
    {
        check_init(argc, argv, pmergeme);

        pmergeme.list_start_time = get_Current_Time();
        pmergeme.sorted_list = merge_insert_with_list(pmergeme);
        pmergeme.list_end_time = get_Current_Time();

        pmergeme.deque_start_time = get_Current_Time();
        pmergeme.sorted_deque = merge_insert_with_deque(pmergeme);
        pmergeme.deque_end_time = get_Current_Time();

        print_status(pmergeme);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    delete[] pmergeme.arr;
    return 0;
}