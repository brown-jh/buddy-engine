#include "InitHelper.h"

class HelloTriangle
{
    public:
        void run(GLFWwindow* window, InitHelper* initHelper);
        float test = 0.0;


    private:
        void mainLoop(GLFWwindow* window, InitHelper* initHelper);
        //drawFrame();

};