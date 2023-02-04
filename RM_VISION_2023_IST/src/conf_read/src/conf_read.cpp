#include "conf_read.hpp"

namespace rm_conf_read
{

      std::vector<std::string> Impl::split_string(const std::string str, const char split_char = '.')
      {
            std::vector<std::string> res;
            int begin = 0;
            for (int end = 0; end < str.size(); end++)
            {
                  if (str[end] == split_char)
                  {
                  res.push_back(str.substr(begin, end));
                  begin = end + 1;
                  }
            }
            if (begin < str.size()) 
                  res.push_back(str.substr(begin));
            return res;
      }//该函数将字符串从指定的特定字符劈开

      template <typename T>
      T Impl::dot_find_or(std::string dotkeys, T fallback)
      {
            auto keys = split_string(dotkeys, '.');//将键提取出来
            toml::value value = data_;
            for (int i = 0; i < keys.size(); i++)
            {
                  std::string key = keys[i];
                  try
                  {
                        value = toml::find(std::move(value), key);
                  }
                  catch (const std::exception &e)
                  {
                        break;
                  }
                  if (i == keys.size() - 1) return toml::get<T>(value);
            }
            return fallback;
      }//将toml文件里键对应的值给提取出来

      template <typename T>
      void Impl::print_kv(std::string key, const T &value)
      {
            std::cout<<key<<value<<std::endl;
      }//打印键值对

      template <typename T>
      void Impl::print_kv(std::string key, const std::vector<T> &vec)
      {
            print_kv(key, fmt::format("[{}]", fmt::join(vec, ", ")));
      }


    conf_read::conf_read(): pimpl{std::make_unique<Impl>()} {}

    conf_read::~conf_read() = default;

    void conf_read::read(const std::string &path)
    {
          pimpl->path_ = path;
          pimpl->data_ = toml::parse(path);

        #define READ_CONFIG(name, type, fallback)           \
          name = pimpl->dot_find_or<type>(#name, fallback); \
          pimpl->print_kv(#name, name);
          std::cout<<"------------------------------------------------------------"<<std::endl;
          
          READ_CONFIG(camera_setting.camera_or_img,std::string,"camera");
          READ_CONFIG(camera_setting.video_path,std::string,"");
          READ_CONFIG(camera_setting.image_path,std::string,"");
          READ_CONFIG(camera_setting.camera_choose,std::string,"dahua");
          READ_CONFIG(camera_setting.ex_time,toml::floating,4000.0);
          READ_CONFIG(camera_setting.gain,toml::floating,1.0);
          READ_CONFIG(camera_setting.w_b_b,toml::floating,1.0);
          READ_CONFIG(camera_setting.w_b_g,toml::floating,1.0);
          READ_CONFIG(camera_setting.w_b_r,toml::floating,1.0);
          
          READ_CONFIG(detect_setting.color,toml::boolean,true);
          READ_CONFIG(detect_setting.thread_img,toml::integer,125);

          READ_CONFIG(detect_setting.model_path,std::string,"/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/arms_detector/model/fc.onnx");
          READ_CONFIG(detect_setting.label_path,std::string,"/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/arms_detector/model/label.txt");
          READ_CONFIG(detect_setting.thread_confence,toml::floating,4000.0);
          std::cout<<detect_setting.model_path<<std::endl;
          std::cout<<detect_setting.label_path<<std::endl;
          

          std::cout<<"------------------------------------------------------------"<<std::endl;
        #undef READ_CONFIG
    }//将toml文件里的对应数值读取到在config.cpp文件里创建的结构体
}  // namespace rm_config
