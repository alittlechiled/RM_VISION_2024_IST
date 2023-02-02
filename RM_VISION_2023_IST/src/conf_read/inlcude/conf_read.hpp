#ifndef _CONF_READ_HPP_
#define _CONF_READ_HPP_

#include <toml.hpp>
#include <iostream>
#include "img_get.hpp"
#include "img_deal.hpp"


namespace rm_conf_read
{
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
            bool camera_choose;
            std::string video_path;
            std::string image_path;
          };
          struct detect_setting
          {
            std::string model_path;
            std::string label_path;
            unsigned int thread_img;
            double thread_confence;
            bool color;
          };
        private:
          class Impl;
          std::unique_ptr<Impl> pimpl;


    }   
}

#endif