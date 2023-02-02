#include "pnp.hpp"

namespace rm_vision
{
    pnp_solver::pnp_solver(const std::array<double, 9> & camera_matrix,
                       const std::vector<double> & distortion_coefficients)
    : camera_matrix_(cv::Mat(3, 3, CV_64F, const_cast<double *>(camera_matrix.data())).clone()),
        dist_coeffs_(cv::Mat(1, 5, CV_64F, const_cast<double *>(distortion_coefficients.data())).clone())
    {
        double small_half_x = this->ARMOR_SIZE.kSmallArmorWidth / 2.0;
        double small_half_y = this->ARMOR_SIZE.kSmallArmorHeight / 2.0;
        double big_half_x = this->ARMOR_SIZE.kBigArmorWidth / 2.0;
        double big_half_y = this->ARMOR_SIZE.kBigArmorHeight / 2.0;

        small_armor_points_.emplace_back(cv::Point3f(-small_half_x, small_half_y, 0));
        small_armor_points_.emplace_back(cv::Point3f(-small_half_x, -small_half_y, 0));
        small_armor_points_.emplace_back(cv::Point3f(small_half_x, -small_half_y, 0));
        small_armor_points_.emplace_back(cv::Point3f(small_half_x, small_half_y, 0));

        big_armor_points_.emplace_back(cv::Point3f(-big_half_x, big_half_y, 0));
        big_armor_points_.emplace_back(cv::Point3f(-big_half_x, -big_half_y, 0));
        big_armor_points_.emplace_back(cv::Point3f(big_half_x, -big_half_y, 0));
        big_armor_points_.emplace_back(cv::Point3f(big_half_x, big_half_y, 0));
    }

    std::pair<bool,cv::Point3f> pnp_solver::solve_pnp(const Armor & armor)
    {
        std::vector<cv::Point2f> image_armor_points;
        cv::Point3f shift = cv::Point3f(0,0,0);
        // Fill in image points
        image_armor_points.emplace_back(armor.left_light.bottom);
        image_armor_points.emplace_back(armor.left_light.top);
        image_armor_points.emplace_back(armor.right_light.top);
        image_armor_points.emplace_back(armor.right_light.bottom);

        // Solve pnp
        cv::Mat rvec, tvec;
        auto object_points = armor.armor_type == SMALL ? small_armor_points_ : big_armor_points_;
        bool success = cv::solvePnP(
            object_points, image_armor_points, camera_matrix_, dist_coeffs_, rvec, tvec, false,
            cv::SOLVEPNP_IPPE);//提取出旋转矩阵和位移矩阵
        if(success)
        {
            shift = cv::Point3f(tvec.at<float>(0) * 0.001,
                                tvec.at<float>(1) * 0.001,
                                tvec.at<float>(2) * 0.001);
        }
        return std::pair(success,shift);
    }

    double pnp_solver::dis_to_cen(const cv::Point2f & image_point)
    {
        float cx = camera_matrix_.at<double>(0, 2);
        float cy = camera_matrix_.at<double>(1, 2);
        return cv::norm(image_point - cv::Point2f(cx, cy));
    }

    void pnp_solver::arms_distance_count(std::vector<Armor> &armors)
    {
        double distance;
        std::stringstream new_text;

        for(int i = 0;i<armors.size();i++)
        {
            armors[i].distance_to_center = dis_to_cen(armors[i].center);
            new_text<<armors[i].classfication_result<<"distance"<<armors[i].distance_to_center;
        }
            
    }
}
