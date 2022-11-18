#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
   public:
    Brain();
    Brain(Brain const& src);
    ~Brain();

    Brain& operator=(Brain const& rhs);

   private:
    std::string _ideas[100];
};

#endif /* *********************************************************** BRAIN_H \
        */