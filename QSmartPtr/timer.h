#pragma once
#include "../QSmartPtr.h"

#include <QTimer>

template <>
inline void q_default_deleter(QTimer* t) {
	if (t) {
		t->stop();
		delete t;
		t = nullptr;
	}
}

namespace qptr {

//typedef std::unique_ptr<QTimer, std::function<void(QTimer*)>> qtimer;
//
//inline qtimer create_qtimer() {
//	return qtimer(new QTimer(), q_default_deleter<QTimer>);
//}

define_qt_smart_ptr(QTimer, qtimer)

};

