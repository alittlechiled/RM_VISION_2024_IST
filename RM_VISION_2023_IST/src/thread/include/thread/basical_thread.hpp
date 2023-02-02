#ifndef _BASICAL_THREAD_HPP_
#define _BASICAL_THREAD_HPP_

#include <functional>//一系列的函数对象的操作
#include <thread>

#define DECL_WORKTHTREAD(name)                    \
  class name                                      \
  {                                               \
   private:                                       \
    std::thread thread_;                          \
    void run(void);                               \
                                                  \
   public:                                        \
    void up(void)                                 \
    {                                             \
      auto running = std::bind(&name::run, this); \
      thread_ = std::thread(running);             \
    }                                             \
                                                  \
   private:

#define DECL_WORKTHTREAD_END() \
  }                            \
  ;

namespace rm_thread
{
    

}



#endif