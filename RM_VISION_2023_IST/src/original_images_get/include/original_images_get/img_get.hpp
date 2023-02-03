#ifndef _IMG_GET_HPP_
#define _IMG_GET_HPP_

#include "camera_deal.hpp"
#include <opencv2/opencv.hpp>
#include <string>


namespace camera_processor
{
    class img_get
    {
        public:
            img_get()=default;
            img_get(std::string img_source,bool camera_choose,
                    std::string img_path,std::string video_path,
                    double white_blance_b,double white_blance_g,
                    double white_blance_r,double exposure_time,
                    double gain);
            cv::Mat image_get(void);
        private:
            std::string img_source;
            std::string img_path;
            std::string video_path;
            camera_processor::camera_deal camera_massager;
    };
}



#endif