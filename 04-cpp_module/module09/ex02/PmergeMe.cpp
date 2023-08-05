#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    (void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PmergeMe::sort_deque(std::deque<int> &deq) const {
    // 개수가 1개 이하면 정렬할 필요가 없다.
    if (deq.size() <= 1)
        return;
    // 개수가 홀수일 경우
    int unpaired = -1;
    if (deq.size() % 2) {
        unpaired = deq.back();
        deq.pop_back();
    }
    // pair로 묶어서 정렬
    std::deque<std::pair<int, int> > pairs; // pair로 묶어서 저장할 deque
    for (size_t i = 0; i < deq.size(); i += 2) {
        std::pair<int, int> tp(deq[i], deq[i + 1]); // 두개씩 묶어서
        if (tp.first < tp.second) // 앞에 있는게 더 작으면 swap
            std::swap(tp.first, tp.second);
        pairs.push_back(tp); // 각 pair는 first가 더 큰 값으로 저장됨
    }
    // 첫 번째 원소 정렬
    deq.clear();                           // 원래 deque 비우고
    std::sort(pairs.begin(), pairs.end()); // pair 정렬
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin();
         it != pairs.end(); it++) { // pair를 다시 deque에 저장
        deq.push_back(it->first);
    }

    // 두 번째 원소 정렬
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin();
         it != pairs.end(); it++) { // pair를 다시 deque에 저장
        std::deque<int>::iterator it2 =
            std::upper_bound(deq.begin(), deq.end(), it->second);
        deq.insert(it2, it->second);
    }

    // 홀수 개일 경우
    if (unpaired != -1) { // 정렬된 deque에 저장해둔 unpaired 삽입
        std::deque<int>::iterator it =
            std::upper_bound(deq.begin(), deq.end(), unpaired);
        deq.insert(it, unpaired);
    }
}

void PmergeMe::sort_list(std::list<int> &lst) const {
    // 개수가 1개 이하면 정렬할 필요가 없다.
    if (lst.size() <= 1)
        return;
    // 개수가 홀수일 경우
    int unpaired = -1;
    if (lst.size() % 2) {
        unpaired = lst.back();
        lst.pop_back();
    }
    // pair로 묶어서 정렬
    std::list<std::pair<int, int> > pairs; // pair로 묶어서 저장할 list
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        std::pair<int, int> tp(*it, *(++it)); // 두개씩 묶어서
        if (tp.first < tp.second)            // 앞에 있는게 더 작으면 swap
            std::swap(tp.first, tp.second);
        pairs.push_back(tp); // 각 pair는 first가 더 큰 값으로 저장됨
    }
    // 첫 번째 원소 정렬
    lst.clear();  // 원래 list 비우고
    pairs.sort(); // pair 정렬

    for (std::list<std::pair<int, int> >::iterator it = pairs.begin();
         it != pairs.end(); it++) { // pair를 다시 list에 저장
        lst.push_back(it->first); // lst는 pair의 first를 기준으로 정렬된 상태
    }

    // 두 번째 원소 정렬
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin();
         it != pairs.end(); it++) {
        std::list<int>::iterator it2 = std::upper_bound(
            lst.begin(), lst.end(), it->second); // upper_bound로
                                                 // 삽입할
                                                 // 위치
                                                 // 찾기
        lst.insert(it2, it->second);
    }

    // 홀수 개일 경우
    if (unpaired != -1) { // 정렬된 list에 저장해둔 unpaired 삽입
        std::list<int>::iterator it =
            std::upper_bound(lst.begin(), lst.end(), unpaired);
        lst.insert(it, unpaired);
    }
}

void PmergeMe::print_sorted_sequence(std::deque<int> &deq,
                                     std::list<int> &lst) const {

    // deq와 lst가 제대로 정렬되었는지 비교
    std::deque<int>::iterator deq_it = deq.begin();
    std::list<int>::iterator lst_it = lst.begin();
    while (deq_it != deq.end() && lst_it != lst.end()) {
        if (*deq_it != *lst_it) {
            std::cout << "Error"<< std::endl;
            return;
        }
        deq_it++;
        lst_it++;
    }
    // deq와 lst가 제대로 정렬되었으면 출력
    std::cout << "After:\t";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::calculate(int argc, char *argv[]) const {
    // input 받기
    std::string input;
    for (int i = 1; i < argc; i++) {
        input += argv[i];
        if (i != argc - 1)
            input += " ";
    }

    std::deque<int> deq;
    std::list<int> lst;
    // input 유효성 검사
    if (!isValidInput(input))
        return;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        int num = std::stoi(token);
        deq.push_back(num);
        lst.push_back(num);
    }

    // 정렬 전 상태 출력
    std::cout << "Before:\t";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std:: cout << std::endl;
    // 정렬 전 시각 저장
    std::chrono::system_clock::time_point start, deq_end, lst_end;
    start = std::chrono::system_clock::now();
    sort_deque(deq);
    deq_end = std::chrono::system_clock::now();
    sort_list(lst);
    lst_end = std::chrono::system_clock::now();
    // 정렬된 상태 출력
    print_sorted_sequence(deq, lst);
    int size = deq.size();
    // 정렬 시간 출력
    print_sorting_time(
        std::chrono::duration_cast<std::chrono::nanoseconds>(deq_end - start)
            .count(), size, 
        "deque");
    print_sorting_time(
        std::chrono::duration_cast<std::chrono::nanoseconds>(lst_end - deq_end)
            .count(), size, 
        "list");
}

void PmergeMe::print_sorting_time(long long const &time, int size,
                                  std::string const &type) const {

    std::cout << "Time to process a range of " << size << " elements with std::" << type
              << " : " << time << "ns" << std::endl;
}

bool PmergeMe::isValidInput(std::string const &input) const {
    // input이 숫자로만 이루어져 있는지 검사
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] != ' ' && !std::isdigit(input[i])) {
            std::cout << "Error" << std::endl;
            return false;
        } else if (std::isdigit(input[i]) && std::isdigit(input[i]) < 0) {
            std::cout << "Error" << std::endl;
            return false;
        }
    }
    return true;
}