#include <string>
#include "rclcpp/rclcpp.hpp"
#include "my_massages/msg/image.hpp"
#include "camera_deal.hpp"

class image_getter:public rclcpp::Node
{
    private:
        rclcpp::Publisher<my_massages::msg::Image>::SharedPtr img_get;
        void image_catch(void)
        {


            
        }
    public:
        image_getter(std::string name): Node(name)
        {
            RCLCPP_INFO(this->get_logger(),"image_getter is built!");
            this->img_get = this->create_publisher<my_massages::msg::Image>("oringial",1);
        }

};

int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);
    auto Node = std::make_shared<image_getter>("image_getter");
    rclcpp::spin(Node);
    rclcpp::shutdown();
    return 0;
}