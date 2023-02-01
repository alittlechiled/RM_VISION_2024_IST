#ifndef _BASICTHREAD_HPP_
#define _BASICTHREAD_HPP_
#include<iostream>
#include <algorithm>
#include <condition_variable>
#include <shared_mutex>
#include <thread>


namespace rm_threading
{
const int MAX_THREADS = 8;
template <typename DataType>
class basicthread
{
    private:
	    DataType* ptr_output_;//�������
	    DataType* ptr_input_;//�������
	    DataType data_[2];//ͬʱֻ����һ����
	    std::shared_mutex mu_read_;//��ȡ����

	    std::condition_variable_any cv_update_;//

	    uint8_t thread_count_ = 0;
	    std::thread::id thread_list_[MAX_THREADS];//�м����߳�
	    bool updated_[MAX_THREADS];//�����߳�

        int get_this_thread_idx()
        {
            auto this_id = std::this_thread::get_id();
            for (int i = 0; i < thread_count_; i++)
            {
                if (thread_list_[i] == this_id) return i;
            }
            thread_list_[thread_count_] = this_id;
            thread_count_ = (thread_count_ + 1) % MAX_THREADS;
            return thread_count_ - 1;
        };
    public:
       basicthread()
        {
            ptr_input_ = &(data_[0]);
            ptr_output_ = &(data_[1]);
            std::fill(updated_, updated_ + MAX_THREADS, false);
        };

        template <typename T = DataType>
        void set(T&& data)
        {
            std::cout << std::this_thread::get_id() <<" "<<data << std::endl;
            *ptr_input_ = std::forward<T>(data);
            std::unique_lock<std::shared_mutex> xlck(mu_read_);  // �������������̲߳��ɶ�д
            std::swap(ptr_output_, ptr_input_);
            std::fill(updated_, updated_ + thread_count_, true);
            xlck.unlock();
            // ����֪ͨ
            cv_update_.notify_all();
        };

        DataType get(bool allow_old_data = false)
        {
            int tid = get_this_thread_idx();

            std::shared_lock<std::shared_mutex> slck(mu_read_);
            if (!allow_old_data && !updated_[tid]) cv_update_.wait(slck, [&] { return updated_[tid]; });

            updated_[tid] = false;
            return *ptr_output_;
        };

        bool updated() { return updated_[get_this_thread_idx()]; }
    };
} 

#endif