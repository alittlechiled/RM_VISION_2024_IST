#include "detect_thread.hpp"

namespace rm_thread
{
    detect_thread::detect_thread(const rm_conf_read::conf_read &conf)
    {
        std::cout<<"[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]"<<std::endl;
        std::cout<<"the conf.detect_setting.model_path is"<<conf.detect_setting.model_path<<std::endl;
        this->armdetecter = rm_vision::img_processor(
        conf.detect_setting.model_path,
        conf.detect_setting.label_path,
        conf.detect_setting.thread_confence,
        conf.detect_setting.color,
        conf.detect_setting.thread_img);
    }

    void detect_thread::run(void)
    {
        while(true)
        {
            cv::Mat img = rm_thread::entitythread<cv::Mat>::get("capture_image");
            std::vector<rm_vision::Armor> res = this->armdetecter.img_deal(img);
            rm_thread::entitythread<std::vector<rm_vision::Armor>>::set("detect_result",std::move(res));
        }
    }

} // namespace rm_thread
