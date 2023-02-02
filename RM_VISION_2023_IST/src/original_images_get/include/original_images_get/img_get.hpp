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
            img_get(std::string img_source,bool camera_type,
                    std::string img_path,std::string video_path,
                    float white_blance_b,float white_blance_g,
                    float white_blance_r,float exposure_time,
                    float gain);
            cv::Mat image_get(void);
        private:
            std::string img_source;
            std::string img_path;
            std::string video_path;
            camera_processor::camera_deal camera_massager;
    }
}



#endif