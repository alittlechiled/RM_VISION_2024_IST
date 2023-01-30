#include "include/arms_detect.hpp"

namespace rm_vision
{
    cv::Mat armor_detect::preprocessImage(const cv::Mat & rgb_img)
    {
        cv::Mat gray_img;
        cv::cvtColor(rgb_img,gray_img,cv::COLOR_BGR2GRAY);

        cv::Mat bin_img;
        cv::threshold(gray_img,bin_img,this->min_lightness,255,cv::THRESH_BINARY);

        std::vector<cv::Mat> channals;
        cv::split(rgb_img,channals);

        cv::Mat grayimg;
        if(this->color_detect)
        {
            grayimg = channals[0]-channals[2];
        }
        else
        {
            grayimg = channals[2]-channals[0];
        }

        cv::Mat bin_grayimg1;
        cv::threshold(grayimg,bin_grayimg1,110,255,cv::THRESH_BINARY);

        cv::Mat element1 = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(10,10));
        dilate(bin_grayimg1,bin_grayimg1,element1);

        cv::Mat max_color = bin_img & bin_grayimg1;

        cv::Mat element2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
        cv::dilate(max_color,max_color,element2);

        cv::Mat element4 = getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2));
        cv::erode(max_color, max_color, element4);//for high expouse time picture

        return max_color;//These codes are 
    }

    std::vector<rm_vision::Light> armor_detect::find_lights(const cv::Mat &bin_img,const cv::Mat &rgb_img)
    {
        std::vector<cv::Vec4i> hierarchy;
	    std::vector<std::vector<cv::Point>> lightContours;
	    cv::findContours(bin_img,lightContours, hierarchy,cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        std::vector<rm_vision::Light> Lights;
        for(const auto lightContour:lightContours)
        {
            if(lightContour.size()<10) continue;

            auto r_rect = cv::minAreaRect(lightContour);
            auto light = Light(r_rect);
            if(is_light(light))
            {
                auto rect = light.boundingRect();
                if(rect.x>0 && rect.width>0 && 
                   rect.y>0 && rect.height>0 &&
                   rect.width < rgb_img.cols && rect.height < rgb_img.rows &&
                   rect.x+rect.width<rgb_img.cols && rect.y +rect.height<rgb_img.rows)
                   {
                        int red_n=0,bule_n=0;
                        auto roi = rgb_img(rect);
                        for(int x=0;x<roi.cols;x++){
                            for(int y=0;y<roi.rows;y++){
                                if(cv::pointPolygonTest(lightContour,cv::Point2f(x+rect.x,y+rect.y),false)>=0)
                                red_n += roi.at<cv::Vec3b>(y,x)[0];
                                bule_n += roi.at<cv::Vec3b>(y,x)[0];
                            }
                        }
                        light.color = red_n>bule_n?RED:BULE;
                   }
                else continue;
                Lights.push_back(light);
            }
            else continue;
        }

        return Lights;
    }
    
    std::vector<rm_vision::Armor>  armor_detect::find_armor(const std::vector<rm_vision::Light> &Lights)
    {
        std::vector<rm_vision::Armor> Armors;
        for(auto light_1=Lights.begin();light_1!=Lights.end();light_1++){
            for(auto light_2=Lights.begin()+1;light_1!=Lights.end();light_1++){
                if(light_1->color!=this->color_detect || light_2->color!=this->color_detect) continue;
                if(have_third(*light_1,*light_2,Lights)) continue;
                auto arm = Armor(*light_1,*light_2);
                if(!is_armor(arm)) continue;
                Armors.push_back(arm);
            }
        }

        return Armors;
    }

    bool rm_vision::armor_detect::is_light(const rm_vision::Light &light)
    {
        double ratio = light.width/light.length;
        bool ratio_ok = l.max_ratio>ratio && l.min_ratio<ratio;

        bool angel_ok = l.max_angle>light.tilt_angle;

        bool is_light = ratio_ok & angel_ok;

        return is_light;
    }

    bool rm_vision::armor_detect::have_third(const rm_vision::Light &light_l,const rm_vision::Light &light_r,
                                            const std::vector<rm_vision::Light> &Lights)
    {
        auto points = std::vector<cv::Point2f>{light_l.top,light_l.bottom,light_r.top,light_r.bottom};

        auto bounding_rect = cv::boundingRect(points);

        for(const auto test_light:Lights){
            if(test_light.center == light_l.center || test_light.center == light_r.center) continue;
            if(bounding_rect.contains(test_light.top)||bounding_rect.contains(test_light.bottom)||bounding_rect.contains(test_light.center))
            return true;
        }
        return false;
    }

    bool rm_vision::armor_detect::is_armor(const rm_vision::Armor &arm)
    {
        rm_vision::Light light_l = arm.left_light;
        rm_vision::Light light_r = arm.right_light;
        double lenght_ratio = light_l.length>light_r.length?:light_l.length/light_r.length;
        bool lenght_ratio_ok = lenght_ratio>this->a.min_light_ratio;
        double avg_length = (light_l.length+light_r.length)/2;
        double distance = cv::norm(light_l.center-light_r.center);
        double distance_ratio = distance/avg_length;
        bool distance_ratio_ok = (distance_ratio>this->a.min_small_center_distance&&distance_ratio<this->a.max_small_center_distance)
                                ||(distance_ratio>this->a.min_large_center_distance&&distance_ratio<this->a.max_large_center_distance);
        cv::Point2f diff = light_l.center-light_r.center;
        double angle = std::abs(std::atan(diff.y/diff.x))/CV_PI*180;
        bool angle_ok = angle <this->a.max_angle;

        bool arm_ok = angle_ok&distance_ratio_ok&lenght_ratio_ok;

        return arm_ok;
    }

    void rm_vision::armor_detect::extract_img_of_number(std::vector<rm_vision::Armor> &Armors,
                                                        const cv::Mat &bin_img)
    {
        const int light_length = 12;
        const int warp_height = 28;
        const int small_armor_width = 32;
        const int large_armor_width = 54;

        const cv::Size roi_size(20,28);

        for(auto &armor:Armors)
        {
            cv::Point2f arm_points[4] = {
                armor.left_light.bottom,armor.left_light.top,
                armor.right_light.top,armor.right_light.bottom
            };
            const int top_light_y = (warp_height - light_length) / 2 - 1;
            const int bottom_light_y = top_light_y + light_length;
            const int warp_width = armor.armor_type == SMALL ? small_armor_width : large_armor_width;
            cv::Point2f target_vertices[4] = {
            cv::Point(0, bottom_light_y),
            cv::Point(0, top_light_y),
            cv::Point(warp_width - 1, top_light_y),
            cv::Point(warp_width - 1, bottom_light_y),};
            cv::Mat number_image;
            auto rotation_matrix = cv::getPerspectiveTransform(arm_points, target_vertices);
            cv::warpPerspective(bin_img, number_image, rotation_matrix, cv::Size(warp_width, warp_height));
            number_image =number_image(cv::Rect(cv::Point((warp_width - roi_size.width) / 2, 0), roi_size));
            armor.number_img = number_image;
        }
    }

}