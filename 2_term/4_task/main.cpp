#include <BMP.hpp>
#include <iostream>

int main()
{
    vk::images::BMP original_image(1920, 1080);
    original_image.Fill({ 255,0,0 });
    original_image.Save("original.bmp");

    std::string letter;
    std::cin >> letter;
    original_image.ENCODE(letter);
    original_image.DECODE();

    original_image.Save("out.bmp");

    return 0;
}


   