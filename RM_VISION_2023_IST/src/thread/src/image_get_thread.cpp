#include "image_get_thread.hpp"

namespace rm_thread
{
    img_get_thread::img_get_thread(const rm_conf_read::conf_read &conf)
    {
        img_getter = camera_processor::img_get(
            conf.camera_setting.camera_or_img,
            conf.camera_setting.camera_choose,
            conf.camera_setting.image_path,
            conf.camera_setting.video_path,
            conf.camera_setting.w_b_b,
            conf.camera_setting.w_b_g,
            conf.camera_setting.w_b_r,
            conf.camera_setting.ex_time,
            conf.camera_setting.gain
        );
    }

    void img_get_thread::run()
    {
        while(true)
        {
            cv::Mat img;
            img = img_getter.image_get();
            rm_thread::entitythread<cv::Mat>::set("capture_image", img);
        }
    }
} // namespace rm_thread
