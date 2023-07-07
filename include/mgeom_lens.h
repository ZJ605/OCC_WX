#ifndef MGEOM_LENS_H
#define MGEOM_LENS_H

#include "mgeom.h"

#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "BRepBuilderAPI_Transform.hxx"
#include "BRepPrimAPI_MakeBox.hxx"
#include "BRepPrimAPI_MakeCylinder.hxx"
#include "BRepPrimAPI_MakePrism.hxx"
#include "GC_MakeArcOfCircle.hxx"
#include "GC_MakeSegment.hxx"
#include "GCE2d_MakeSegment.hxx"
#include "Geom2d_Ellipse.hxx"
#include "Geom2d_TrimmedCurve.hxx"
#include "BRepFilletAPI_MakeFillet.hxx"
#include "TopExp.hxx"
#include "TopExp_Explorer.hxx"
#include "TopoDS.hxx"
#include "BRepAlgo.hxx"
#include "BRepAlgoAPI_Fuse.hxx"
#include "Geom_Plane.hxx"
#include "BRepOffsetAPI_MakeThickSolid.hxx"
#include "Geom_CylindricalSurface.hxx"
#include "BRepLib.hxx"
#include "BRepOffsetAPI_ThruSections.hxx"
#include "BRepPrimAPI_MakeBox.hxx"

class MGeom_Lens : public MGeom
{
    DEFINE_STANDARD_RTTI_INLINE(MGeom_Lens, MGeom)

    public:
        MGeom_Lens(GeometryWindow* parent);
        virtual ~MGeom_Lens();

        virtual TopoDS_Shape getShape() Standard_OVERRIDE;
        virtual bool calculate() Standard_OVERRIDE;
    private:

        void create();

        BRepPrimAPI_MakeBox box;

    //parameters for jedna lens
    private:

};

#endif // MGEOM_LENS_H
