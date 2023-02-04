#include "camera_deal.hpp"

namespace camera_processor
{
    void camera_deal::para_setting(void)
    {
        if(camera_choose == "dahua")
        {
            std::cout<<"set the dahua camera"<<"11111111111111111111"<<std::endl;
            DahuaCamera::set_exposure_time(this->camera_setting.exposure_time_value);
            DahuaCamera::set_gain(this->camera_setting.gain_value);
            DahuaCamera::set_white_balance(this->camera_setting.white_balance_value[2],
                                           this->camera_setting.white_balance_value[1],
                                           this->camera_setting.white_balance_value[0]);
            std::cout<<"open the dahua camera"<<"22222222222222222222"<<std::endl;
            DahuaCamera::open(0);
        }
        else
        {
            std::cout<<"set the daheng camera"<<"33333333333333333333"<<std::endl;
            DahengCamera::set_exposure_time(this->camera_setting.exposure_time_value);
            DahengCamera::set_gain(this->camera_setting.gain_value);
            DahengCamera::set_white_balance(this->camera_setting.white_balance_value[2],
                                            this->camera_setting.white_balance_value[1],
                                            this->camera_setting.white_balance_value[0]);
            std::cout<<"open the daheng camera"<<"4444444444444444444"<<std::endl;
            DahengCamera::open(0);
        }
    }

    cv::Mat camera_deal::picture_get(void)
    {
        cv::Mat image;
        if(camera_choose == "dahua")
            image = DahuaCamera::next();
        else
            image = DahengCamera::next();
        return image;
    }

}
