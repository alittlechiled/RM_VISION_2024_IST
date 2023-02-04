#ifndef _CONF_READ_HPP_
#define _CONF_READ_HPP_

#include "toml.hpp"
#include <fmt/core.h>
#include <iostream>
#include <fmt/ranges.h>

namespace rm_conf_read
{
    class Impl
    {
      public:
          toml::value data_;
          std::string path_;
          std::vector<std::string> split_string(const std::string str, const char split_char);
          template <typename T>
          T dot_find_or(std::string dotkeys, T fallback);
          
          template <typename T>
          void print_kv(std::string key, const T &value);

          template <typename T>
          void print_kv(std::string key, const std::vector<T> &vec);
    };

    class conf_read
    {
        public:
          conf_read();//构造函数
          ~conf_read();//默认析构函数
          void read(const std::string &path);
          struct camera_setting
          {
            std::string camera_or_img;
            double ex_time;
            double gain;
            double w_b_b;
            double w_b_g;
            double w_b_r;
            std::string camera_choose;
            std::string video_path;
            std::string image_path;
          } camera_setting;
          struct detect_setting
          {
            std::string model_path;
            std::string label_path;
            double thread_confence;
            bool color;
            unsigned int thread_img;
          } detect_setting;
        private:
          std::unique_ptr<Impl> pimpl;
    };
}

#endif