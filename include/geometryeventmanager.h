#ifndef GEOMETRYEVENTMANAGER_H
#define GEOMETRYEVENTMANAGER_H

#include "Standard_Handle.hxx"
#include "AIS_ViewController.hxx"

class GeometryWindow;
class MGeom;

class GeometryEventManager : public Standard_Transient
{
    DEFINE_STANDARD_RTTI_INLINE(GeometryEventManager, Standard_Transient)

    public:
        GeometryEventManager(GeometryWindow*);

        void onUpdateGeometry();

    private:

        GeometryWindow* m_geometrywindow;

};

#endif // GEOMETRYEVENTMANAGER_H
