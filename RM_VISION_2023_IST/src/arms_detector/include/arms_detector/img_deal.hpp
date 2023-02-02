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
      img_processor(const std::string &model_path,const std::string &label_path,const double &thr,const bool &color,const unsigned int &lightness);

      std::vector<rm_vision::Armor> img_deal(const cv::Mat &img);
    };
}


#endif