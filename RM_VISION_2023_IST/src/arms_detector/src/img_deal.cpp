#include "img_deal.hpp"

namespace rm_vision
{
    img_processor::img_processor(std::string _file_path)
    {
        


    }

    std::vector<rm_vision::Armor> img_processor::img_deal(const cv::Mat &img)
    {
        cv::Mat cp_img;
        std::vector<rm_vision::Light> lights;
        std::vector<rm_vision::Armor> armors;
        img.copyTo(cp_img);
        cv::Mat bin_img = armor_detector.preprocessImage(cp_img);
        lights = armor_detector.find_lights(bin_img,cp_img);
        armors = armor_detector.find_armor(lights);
        armor_detector.extract_img_of_number(armors,bin_img);
        classer.do_class(armors);

        return armors;
    }

    



} // namespace rm_vision
