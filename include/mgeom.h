#ifndef MGEOM_H
#define MGEOM_H

#include "Geom_Line.hxx"
#include "TopoDS.hxx"

//#include "geometrywindow.h"

class GeometryWindow;

class MGeom : public Standard_Transient
{
    DEFINE_STANDARD_RTTI_INLINE(MGeom, Standard_Transient)

    static int mgeom_id;

    public:
        MGeom(GeometryWindow* parent);
        virtual ~MGeom();

        virtual TopoDS_Shape getShape() = 0;
        virtual bool calculate() = 0;
        virtual const char* getMgeomType() = 0;
        virtual void showDialog() = 0;
        int getID(){return m_ID;}

    protected:
        GeometryWindow* m_geomwindow;

    private:
        int m_ID;




};

#endif // MGEOM_H
