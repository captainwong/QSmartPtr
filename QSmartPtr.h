#pragma once

#include <memory>
#include <functional>
#include <QWidget>



template <class T>
inline void q_default_deleter(T* t) {
	if (t) { delete t; t = nullptr; }
}

#define define_qt_smart_ptr(type, name) \
typedef std::unique_ptr<type, std::function<void(type*)>> name; \
template <class parent_type, class... arg_types> \
inline name create_##name(parent_type* parent, arg_types... args) { \
	return name(new type(parent, args...), q_default_deleter<type>); \
}

//template <class unique_ptr, class class_type, class parent_type, class... arg_types>
//inline unique_ptr qsmart_create(parent_type* parent, arg_types... args) {
//	return unique_ptr(new class_type(parent, args...), q_default_deleter<class_type>);
//}

namespace qptr {

define_qt_smart_ptr(QWidget, qwidget)

}

#include "QSmartPtr/timer.h"
#include "QSmartPtr/label.h"
#include "QSmartPtr/lineedit.h"
#include "QSmartPtr/layout.h"



