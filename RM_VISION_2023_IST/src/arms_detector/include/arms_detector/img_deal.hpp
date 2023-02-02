#ifndef _IMG_DEAL_HPP_
#define _IMG_DEAL_HPP_

#include <opencv2/opencv.hpp>

#include "arms_detect.hpp"
#include "classifier_shape_of_armor.hpp"

#include <vector>
#include <string>
#include <toml.hpp>


namespace rm_vision
{
    class img_processor
    {
    private:
      rm_vision::armor_detect armor_detector;
      rm_vision::number_classifier classer;      
    public:
      img_processor()=default;
      img_processor(std::string _file_path);

      std::vector<rm_vision::Armor> img_deal(const cv::Mat &img);
    };
}


#endif