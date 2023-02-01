#ifndef _ENTITYTHREAD_HPP_
#define _ENTITYTHREAD_HPP_
#include <unordered_map>

#include "basicthread.hpp"

namespace rm_threading
{
    template <typename DataType>
    class entitythread
    {
    private:
        static entitythread<DataType> instance_;
        entitythread() {};
        std::unordered_map<std::string, basicthread<DataType>> varmap_{ MAX_THREADS * 8 };

    public:
        static bool exist(const std::string& name) { return instance_.varmap_.count(name); };

        template <typename T = DataType>
        static void set(std::string name, T&& var)
        {
            instance_.varmap_[name].set(std::forward<T>(var));
        };

        template <typename... Args>
        static DataType get(std::string name, Args &&... args)
        {
            return instance_.varmap_[name].get(std::forward<Args>(args)...);
        };
        static bool updated(std::string name) { return instance_.varmap_[name].updated(); }
    };
    template <typename T>

    entitythread<T> entitythread<T>::instance_{};
}  // namespace rm_threading

#endif