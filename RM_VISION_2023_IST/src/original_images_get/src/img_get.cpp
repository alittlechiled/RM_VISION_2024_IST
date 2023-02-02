#include "img_get.hpp"

namespace camera_processor
{
    img_get::img_get(std::string img_source,bool camera_choose,
                    std::string img_path,std::string video_path,
                    double white_blance_b,double white_blance_g,
                    double white_blance_r,double exposure_time,
                    double gain)
    {
        this->img_source = img_source;
        if(this->img_source == "camera")
        {
            camera_processor::camera_para para;
            camera_processor::camera_type type;
            para.exposure_time_value = exposure_time;
            para.gain_value = gain;
            para.white_balance_value = {white_blance_b,white_blance_g,white_blance_r};

            type = camera_choose;  
            camera_massager(para,type);
        }
        else if (this->img_source == "picture")
            this->img_path = img_path;
        else
            this->video_path = video_path;
    }

    cv::Mat img_get::image_get(void)
    {
        



    }
}