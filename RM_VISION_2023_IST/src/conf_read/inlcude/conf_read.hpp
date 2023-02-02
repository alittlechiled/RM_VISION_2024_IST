#ifndef _CONF_READ_HPP_
#define _CONF_READ_HPP_

#include <toml.hpp>
#include "img_get.hpp"
#include "img_deal.hpp"


namespace rm_conf_read
{
    class conf_read
    {
        public:
          Config();//构造函数
          ~Config();//默认析构函数
          void read(const std::string &path);
          struct camera_setting
          {
            
          };
          struct 
          {

          };

        private:
          class Impl;
          std::unique_ptr<Impl> pimpl;


    }   
}

#endif