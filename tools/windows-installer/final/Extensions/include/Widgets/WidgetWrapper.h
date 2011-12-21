#ifndef WIDGETWRAPPER_H
#define WIDGETWRAPPER_H

#include "SFGUI/SharedPtr.hpp"


/**
 * WidgetWrapper allows the extension to use C++0x functionnalities (std::shared_ptr) inside Game Develop without "say" it to its internal compilator.
**/
template<class T>
class WidgetWrapper
{
    public:
        WidgetWrapper(sfg::SharedPtr<T>&);

        /**
         * Get the smart pointer
        **/
        inline sfg::SharedPtr<T>& Get() {return obj;};

    private:
        sfg::SharedPtr<T> obj; ///< smart pointer stored
};

template<class T>
WidgetWrapper<T>::WidgetWrapper(sfg::SharedPtr<T> &object)
{
    obj = object;
}

#endif
