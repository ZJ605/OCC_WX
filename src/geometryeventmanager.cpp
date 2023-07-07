#include "geometryeventmanager.h"

#include "geometrywindow.h"

GeometryEventManager::GeometryEventManager(GeometryWindow* win) : m_geometrywindow(win)
{
    //ctor
}

void GeometryEventManager::onUpdateGeometry()
{
    m_geometrywindow->onUpdateGeometry();
}
