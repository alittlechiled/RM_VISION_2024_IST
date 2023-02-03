#ifndef _ARMS_DETECT_HPP_
#define _ARMS_DETECT_HPP_
#include "arm_and_light.hpp"

#include <algorithm>
#include <cmath>
#include <vector>

namespace rm_vision
{
    class armor_detect
    {
        public:
            armor_detect()=default;
            armor_detect(bool color,unsigned int lightness);
            armor_detect operator=(armor_detect a_d);
            cv::Mat preprocessImage(const cv::Mat & rgb_img);
            std::vector<rm_vision::Light> find_lights(const cv::Mat &bin_img,const cv::Mat &rgb_img);
            std::vector<rm_vision::Armor> find_armor(const std::vector<rm_vision::Light> &Lights);
            void extract_img_of_number(std::vector<rm_vision::Armor> &Armors,const cv::Mat &bin_img);
            bool color_detect;
        private:
            stand_light l;
            stand_armor a;
            unsigned int min_lightness;
            bool is_light(const rm_vision::Light &light);
            bool have_third(const rm_vision::Light &light_l,const rm_vision::Light &light_r,const std::vector<rm_vision::Light> &Lights);
            bool is_armor(const rm_vision::Armor &arm);
    };

}

#endif