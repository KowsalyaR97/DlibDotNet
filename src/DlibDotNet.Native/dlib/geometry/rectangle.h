#ifndef _CPP_GEOMETRY_RECTANGLE_H_
#define _CPP_GEOMETRY_RECTANGLE_H_

#include <dlib/geometry/rectangle.h>
#include <dlib/geometry/vector.h>
#include <dlib/image_io.h>
#include "../shared.h"

using namespace dlib;

extern "C" __declspec(dllexport) rectangle* rectangle_new()
{
    return new rectangle();
}
 
extern "C" __declspec(dllexport) rectangle* rectangle_new1(const int left, const int top, const int right, const int bottom)
{
     return new rectangle(left, top, right, bottom);
}

extern "C" __declspec(dllexport) rectangle* rectangle_new2(const unsigned int width, const unsigned int height)
{
    return new rectangle(width, height);
}

extern "C" __declspec(dllexport) rectangle* rectangle_new3(const point* p)
{
    return new dlib::rectangle(*p);
}
    
extern "C" __declspec(dllexport) rectangle* rectangle_new4(const point* p1, const point* p2)
{
    return new rectangle(*p1, *p2);
}

extern "C" __declspec(dllexport) void rectangle_delete(const rectangle* rect)
{
    delete rect;
}

extern "C" __declspec(dllexport) int rectangle_left(rectangle* rect)
{
    return rect->left();
}

extern "C" __declspec(dllexport) int rectangle_top(rectangle* rect)
{
    return rect->top();
}

extern "C" __declspec(dllexport) int rectangle_right(rectangle* rect)
{
    return rect->right();
}

extern "C" __declspec(dllexport) int rectangle_bottom(rectangle* rect)
{
    return rect->bottom();
}

extern "C" __declspec(dllexport) void rectangle_set_left(rectangle* rect, int value)
{
    rect->set_left(value);
}

extern "C" __declspec(dllexport) void rectangle_set_top(rectangle* rect, int value)
{
    rect->set_top(value);
}

extern "C" __declspec(dllexport) void rectangle_set_right(rectangle* rect, int value)
{
    rect->set_right(value);
}

extern "C" __declspec(dllexport) void rectangle_set_bottom(rectangle* rect, int value)
{
    rect->set_bottom(value);
}

extern "C" __declspec(dllexport) point* rectangle_tl_corner(rectangle* rect)
{
    return new point(rect->tl_corner());
}

extern "C" __declspec(dllexport) point* rectangle_bl_corner(rectangle* rect)
{
    return new point(rect->bl_corner());
}

extern "C" __declspec(dllexport) point* rectangle_tr_corner(rectangle* rect)
{
    return new point(rect->tr_corner());
}

extern "C" __declspec(dllexport) point* rectangle_br_corner(rectangle* rect)
{
    return new point(rect->br_corner());
}

extern "C" __declspec(dllexport) unsigned int rectangle_width(rectangle* rect)
{
    return rect->width();
}

extern "C" __declspec(dllexport) unsigned int rectangle_height(rectangle* rect)
{
    return rect->height();
}

extern "C" __declspec(dllexport) unsigned int rectangle_area(rectangle* rect)
{
    return rect->area();
}

extern "C" __declspec(dllexport) bool rectangle_is_empty(rectangle* rect)
{
    return rect->is_empty();
}

extern "C" __declspec(dllexport) bool rectangle_contains(rectangle* rect, point* point)
{
    return rect->contains(*point);
}

extern "C" __declspec(dllexport) bool rectangle_contains1(rectangle* rect, int x, int y)
{
    return rect->contains(x, y);
}

extern "C" __declspec(dllexport) rectangle* rectangle_centered_rect(int x, int y, unsigned int width, unsigned int height)
{
    const rectangle result = centered_rect(x, y, width, height);
    return new rectangle(result);
}

extern "C" __declspec(dllexport) rectangle* rectangle_centered_rect1(point* p, unsigned int width, unsigned int height)
{
    const rectangle result = centered_rect(*p, width, height);
    return new rectangle(result);
}

extern "C" __declspec(dllexport) rectangle* rectangle_centered_rect2(rectangle* rect, unsigned int width, unsigned int height)
{
    const rectangle result = centered_rect(*rect, width, height);
    return new rectangle(result);
}

extern "C" __declspec(dllexport) rectangle* rectangle_intersect(rectangle* rect, rectangle* target)
{
    const rectangle result = rect->intersect(*target);
    return new rectangle(result);
}

extern "C" __declspec(dllexport) point* rectangle_center(rectangle* rect)
{
    const point result = center(*rect);
    return new point(result);
}

extern "C" __declspec(dllexport) dpoint* rectangle_dcenter(rectangle* rect)
{
    const dpoint result = dcenter(*rect);
    return new dpoint(result);
}

extern "C" __declspec(dllexport) int rectangle_get_rect(array2d_type img_type, void* img, rectangle** rect)
{
    int err = ERR_OK;

    switch(img_type)
    {
        case array2d_type::UInt8:
            *rect = new dlib::rectangle(get_rect(*((array2d<uint8_t>*)img)));
            break;
        case array2d_type::UInt16:
            *rect = new dlib::rectangle(get_rect(*((array2d<uint16_t>*)img)));
            break;
        case array2d_type::Float:
            *rect = new dlib::rectangle(get_rect(*((array2d<float>*)img)));
            break;
        case array2d_type::Double:        
            *rect = new dlib::rectangle(get_rect(*((array2d<double>*)img)));
            break;
        case array2d_type::RgbPixel:
            *rect = new dlib::rectangle(get_rect(*((array2d<rgb_pixel>*)img)));
            break;
        case array2d_type::HsiPixel:
            *rect = new dlib::rectangle(get_rect(*((array2d<hsi_pixel>*)img)));
            break;
        case array2d_type::RgbAlphaPixel:
            *rect = new dlib::rectangle(get_rect(*((array2d<rgb_alpha_pixel>*)img)));
            break;
        default:
            err = ERR_INPUT_ARRAY_TYPE_NOT_SUPPORT;
            break;
    }

    return err;
}

extern "C" _declspec(dllexport) int rectangle_get_rect2(matrix_element_type type, void* img, rectangle** rect)
{
    int err = ERR_OK;

    switch(type)
    {
        case matrix_element_type::UInt8:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<uint8_t>>*)img)));
			break;
        case matrix_element_type::UInt16:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<uint16_t>>*)img)));
			break;
        case matrix_element_type::UInt32:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<uint32_t>>*)img)));
			break;
        case matrix_element_type::Int8:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<int8_t>>*)img)));
			break;
        case matrix_element_type::Int16:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<int16_t>>*)img)));
			break;
        case matrix_element_type::Int32:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<int32_t>>*)img)));
			break;
        case matrix_element_type::Float:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<float>>*)img)));
			break;
        case matrix_element_type::Double:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<double>>*)img)));
			break;
        case matrix_element_type::RgbPixel:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<rgb_pixel>>*)img)));
			break;
        case matrix_element_type::HsiPixel:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<hsi_pixel>>*)img)));
			break;
        case matrix_element_type::RgbAlphaPixel:
            *rect = new dlib::rectangle(get_rect(*((array2d<matrix<rgb_alpha_pixel>>*)img)));
			break;
        default:
            err = ERR_INPUT_ELEMENT_TYPE_NOT_SUPPORT;
            break;
    }
    
    return err;
}

#pragma region operator

extern "C" __declspec(dllexport) void* rectangle_operator_add(rectangle* rect, rectangle* rhs)
{
    const rectangle result = *rect + *rhs;
    return new rectangle(result);
}

// extern "C" __declspec(dllexport) void* rectangle_operator_sub(rectangle* rect, rectangle* rhs)
// {
//     const rectangle result = *rect - *rhs;
//     return new rectangle(result);
// }

extern "C" __declspec(dllexport) bool rectangle_operator_equal(rectangle* rect, rectangle* rhs)
{
    return *rect == *rhs;
}

#pragma endregion operator

#endif