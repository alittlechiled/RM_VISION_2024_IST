#include "img_get.hpp"

namespace camera_processor
{
    img_get::img_get(std::string img_source,std::string camera_choose,
                    std::string img_path,std::string video_path,
                    double white_blance_b,double white_blance_g,
                    double white_blance_r,double exposure_time,
                    double gain)
    {
        this->img_source = img_source;
        if(this->img_source == "camera")
        {
            camera_processor::camera_para para;
            para.exposure_time_value = exposure_time;
            para.gain_value = gain;
            para.white_balance_value[0] = white_blance_b;
            para.white_balance_value[1] = white_blance_g;
            para.white_balance_value[2] = white_blance_r; 
            this->camera_massager = camera_deal(para,camera_choose);
        }
        else if (this->img_source == "picture")
            this->img_path = img_path;
        else
            this->video_path = video_path;
    }

    cv::Mat img_get::image_get(void)
    {
        cv::Mat img;
        if (img_source == "picture")
        {
            img = cv::imread(img_path);
        }
        else if(img_source == "video")
        {

        }
        else if(img_source == "camera")
        {
            img = camera_massager.picture_get();
        }
        return img;

    }
}