#include "InitHelper.h"

class HelloTriangle
{
    public:
        void run(GLFWwindow* window, InitHelper* initHelper);
        float test = 0.0;
        float x = 0.0;
        float y = 0.0;

        bool w_flag = false;
        bool s_flag = false;
        bool a_flag = false;
        bool d_flag = false;


    private:
        void mainLoop(GLFWwindow* window, InitHelper* initHelper);
        //drawFrame();

};