#include "camera_deal.hpp"

namespace camera_processor
{
    void camera_deal::para_setting(void)
    {
        if(this->camera_choose)
        {
            DahuaCamera::set_exposure_time(this->camera_setting.exposure_time_value);
            DahuaCamera::set_gain(this->camera_setting.gain_value);
            DahuaCamera::set_white_balance(this->camera_setting.white_balance_value[2],
                                           this->camera_setting.white_balance_value[1],
                                           this->camera_setting.white_balance_value[0]);
            DahuaCamera::open(0);
        }
        else
        {
            DahengCamera::set_exposure_time(this->camera_setting.exposure_time_value);
            DahengCamera::set_gain(this->camera_setting.gain_value);
            DahengCamera::set_white_balance(this->camera_setting.white_balance_value[2],
                                            this->camera_setting.white_balance_value[1],
                                            this->camera_setting.white_balance_value[0]);
            DahengCamera::open(0);
        }
    }

    cv::Mat camera_deal::picture_get(void)
    {
        cv::Mat image;
        if(this->camera_choose)
            image = DahuaCamera::next();
        else
            image = DahengCamera::next();
        return image;
    }

}
