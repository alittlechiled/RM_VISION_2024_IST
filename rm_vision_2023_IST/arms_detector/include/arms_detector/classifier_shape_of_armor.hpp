#ifndef _CLASSIFIER_SHAPE_OF_ARMOR_HPP_
#define _CLASSIFIER_SHAPE_OF_ARMOR_HPP_
#include <opencv2/opencv.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <cstddef>

#include "arm_and_light.hpp"
#include "arms_detect.hpp"

namespace rm_vision
{
    class number_classifier
    {
        public:
            number_classifier()=default;
            number_classifier(const std::string &model_path,const std::string &label_path,const double &thr);
            void do_class(std::vector<Armor> arms);
        private:
            double threshold;
            cv::dnn::Net net;
            std::vector<std::string> shapes;
    };
}

#endif
